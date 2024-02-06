/*
 * Copyright (C) 2024 Dominik Drexler
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FLATMEMORY_TYPES_TUPLE_HPP_
#define FLATMEMORY_TYPES_TUPLE_HPP_
 
#include "../byte_stream.hpp"
#include "../byte_stream_utils.hpp"

#include "../layout.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"
#include "../types.hpp"
#include "uint16.hpp"

#include <algorithm>
#include <cassert>
#include <tuple>
#include <iostream>


namespace flatmemory
{
    /**
     * Dispatcher for tuple.
    */
    template<typename... Ts>
    struct Tuple {
        Tuple() { }  // Non-trivial constructor
        ~Tuple() { } // Non-trivial destructor
    };


    /**
     * Layout
    */
    template<typename... Ts>
    class Layout<Tuple<Ts...>> {
        private:
        /*
        template<size_t I>
            static constexpr void calculate_layout_impl(std::array<offset_type, sizeof...(Ts) + 1>& layout, size_t cur_pos) {
                if constexpr (I < sizeof...(Ts)) {
                    using T = std::tuple_element_t<I, std::tuple<Ts...>>;
                    constexpr bool is_dynamic = is_dynamic_type<T>::value;
                    constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
                    if constexpr (is_trivial) {
                        cur_pos += compute_amount_padding(cur_pos, alignof(T));
                        cur_pos += sizeof(T);
                    } else {
                        if constexpr (is_dynamic) {
                            cur_pos += compute_amount_padding(cur_pos, alignof(offset_type));
                            cur_pos += sizeof(offset_type);
                        } else {
                            cur_pos += compute_amount_padding(cur_pos, Layout<T>::alignment);
                            cur_pos += Layout<T>::size;
                        }
                    }
                    //layout[I] = cur_pos;
                    calculate_layout_impl<I + 1>(layout, cur_pos);
                }
            }
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> calculate_layout() {
                std::array<offset_type, sizeof...(Ts) + 1> layout;
                layout[0] = 0;
                calculate_layout_impl<0>(layout, 0);
                return layout;
            }

        */
            /**
             * For static data types, the offset will point to the actual data.
             * For dynamic data types, the offset will point to an offset to the actual data.
            */
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> calculate_layout() {
                std::array<offset_type, sizeof...(Ts) + 1> layout{0};
                size_t index = 0;
                offset_type cur_pos = 0;

                // First element must work with alignment.
                layout[0] = cur_pos;

                ([&] {
                    // TODO need access to I-th type
                    constexpr bool is_dynamic = is_dynamic_type<Ts>::value;
                    constexpr bool is_trivial = is_trivial_and_standard_layout_v<Ts>;
                    if constexpr (is_trivial) {
                        cur_pos += compute_amount_padding(cur_pos, alignof(Ts));
                        cur_pos += sizeof(Ts);
                    } else {
                        if constexpr (is_dynamic) {
                            cur_pos += compute_amount_padding(cur_pos, alignof(offset_type));
                            cur_pos += sizeof(offset_type);
                        } else {
                            cur_pos += compute_amount_padding(cur_pos, Layout<Ts>::alignment);
                            cur_pos += Layout<Ts>::size;
                        }
                    }
                    layout[++index] = cur_pos;
                }(), ...);

                return layout;
            }

            static constexpr size_t calculate_alignment() {
                size_t alignment = 0;
                ([&] {
                    constexpr bool is_trivial = is_trivial_and_standard_layout_v<Ts>;
                    if constexpr (is_trivial) {
                        alignment = std::max(alignment, alignof(Ts));
                    } else {
                        alignment = std::max(alignment, Layout<Ts>::alignment);
                    }
                }(), ...);
                return alignment;
            }

        public:
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> offsets = calculate_layout();

            static constexpr size_t alignment = calculate_alignment();
    };

    
    /**
     * Type traits
     * 
     * A tuple is dynamic if at least one of its nested builders is dynamic.
    */
    template<typename... Ts>
    struct is_dynamic_type<Tuple<Ts...>> : std::bool_constant<(is_dynamic_type<Ts>::value || ...)> {};


    /**
     * Builder
    */
    template<typename... Ts> 
    class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>> {
        private:
            std::tuple<typename maybe_builder<Ts>::type...> m_data;
            ByteStream m_buffer;
            ByteStream m_dynamic_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            template<std::size_t I = 0>
            void finish_rec_impl() {
                // Write padding to satisfy alignment requirements
                m_buffer.write_padding(Layout<Tuple<Ts...>>::offsets[I] - m_buffer.get_size());

                std::cout << m_buffer.get_size() << " " << Layout<Tuple<Ts...>>::offsets[I] << std::endl;
                assert(m_buffer.get_size() == Layout<Tuple<Ts...>>::offsets[I]);

                // offset is the first position to write the dynamic data
                offset_type offset = Layout<Tuple<Ts...>>::offsets.back();
                if constexpr (I < sizeof...(Ts)) {
                    constexpr bool is_dynamic = is_dynamic_type<std::tuple_element_t<I, std::tuple<Ts...>>>::value;
                    constexpr bool is_trivial = is_trivial_and_standard_layout_v<std::tuple_element_t<I, std::tuple<Ts...>>>;
                    if constexpr (is_trivial) {
                        auto& value = std::get<I>(m_data);
                        m_buffer.write(value);
                    } else {
                        // Recursively call finish
                        auto& nested_builder = std::get<I>(m_data);
                        nested_builder.finish();
                        
                        if constexpr (is_dynamic) {
                            m_buffer.write(offset);
                            m_dynamic_buffer.write(nested_builder.get_data(), nested_builder.get_size());     
                            offset += nested_builder.get_size();
                        } else {
                            m_buffer.write(nested_builder.get_data(), nested_builder.get_size());
                        }
                    }

                    // Call finish of next data
                    finish_rec_impl<I + 1>();
                }
            }


            void finish_impl() {
                // Build header and dynamic buffer
                finish_rec_impl<0>();
                // Concatenate all buffers
                m_buffer.write(m_dynamic_buffer.get_data(), m_dynamic_buffer.get_size());  
                // Write alignment padding
                m_buffer.write_padding(compute_amount_padding(m_buffer.get_size(), Layout<Tuple<Ts...>>::alignment));
            }


            template<std::size_t I = 0>
            void clear_rec_impl() {
                if constexpr (I < sizeof...(Ts)) {
                    auto& builder = std::get<I>(m_data);
                    builder.clear();

                    // Call clear of next data
                    clear_rec_impl<I + 1>();
                }
            }


            void clear_impl() {
                // Clear all nested builders.
                clear_rec_impl<0>();
                // Clear this builder.
                m_buffer.clear(),
                m_dynamic_buffer.clear();
            }

            uint8_t* get_data_impl() { return m_buffer.get_data(); }
            size_t get_size_impl() const { return m_buffer.get_size(); }

        public:
            template<std::size_t I>
            auto& get_builder() {
                return std::get<I>(m_data);
            }
    };


    /**
     * View
    */
    template<typename... Ts>
    class View<Tuple<Ts...>> {
    private:
        template<size_t I>
        using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;

        uint8_t* m_data;

    public:
        View(uint8_t* data) : m_data(data) {}

        /**
         * Returns a View to the I-th element.
         * 
         * If the I-th type is dynamic we must add the offset to the actual data first.
        */
        // For trivial types
        template<std::size_t I, typename = std::enable_if_t<is_trivial_and_standard_layout_v<element_type<I>>>>
        auto& get() {
            offset_type offset = Layout<Tuple<Ts...>>::offsets[I];
            return *reinterpret_cast<element_type<I>*>(m_data + offset);
        }

        // For non-trivial types
        template<std::size_t I, typename = std::enable_if_t<!is_trivial_and_standard_layout_v<element_type<I>>>>
        auto get() {
            offset_type offset = Layout<Tuple<Ts...>>::offsets[I];
            if constexpr (is_dynamic_type<element_type<I>>::value) {
                offset = read_value<offset_type>(m_data + offset);
            }
            return View<std::tuple_element_t<I, std::tuple<Ts...>>>(m_data + offset);
        }
    };
}


#endif
