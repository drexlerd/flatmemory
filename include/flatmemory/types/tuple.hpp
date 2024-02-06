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

#include <algorithm>
#include <cassert>
#include <tuple>
#include <iostream>
#include <string>


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
            /**
             * Compute the amount of bytes needed to store the header of type T
             *   - For trivial type T use sizeof(T)
             *   - For dynamic custom type T use sizeof(offset_type) since we store the data with an offset
             *   - For static custom type T use Layout<T>::size which is computed in the Layout of type T.
            */
            template<typename T>
            static constexpr size_t compute_type_size() {
                constexpr bool is_dynamic = is_dynamic_type<T>::value;
                constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
                if constexpr (is_trivial) {
                    return sizeof(T);
                } else {
                    if constexpr (is_dynamic) {
                        return sizeof(offset_type);
                    } else {
                        return Layout<T>::size;
                    }
                }
            }

            /**
             * Compute alignmented needed to be added to cur_pos to obtain correct alignment for storing type T
             *   - For trivial type T use alignof(T)
             *   - For dynamic custom type T use alignof(offset_type) since we store the data with an offset
             *   - For static custom type T use Layout<T>::alignment which is computed in the Layout of type T.
            */
            template<typename T>
            static constexpr size_t compute_alignment() {
                constexpr bool is_dynamic = is_dynamic_type<T>::value;
                constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
                if constexpr (is_trivial) {
                    return alignof(T);
                } else {
                    if constexpr (is_dynamic) {
                        return alignof(offset_type); 
                    } else {
                        return Layout<T>::alignment;
                    }
                }
            }


            /**
             * Calculate aligments of all types and append the maximum alignment
             * to ensure that we correctly pad after all elements.
            */
            template<size_t... Is>
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> calculate_alignments(std::index_sequence<Is...>) {
                std::array<offset_type, sizeof...(Ts) + 1> alignments{};
                ([&] {
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    alignments[Is] = compute_alignment<T>();
                }(), ...);
                alignments[sizeof...(Ts)] = calculate_alignment();
                return alignments;
            }

            /**
             * Compute the maximum alignment to ensure that storing N objects in sequence have correct alignment
            */
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
           
            /**
             * Compute the offsets for each type T
            */
            template<size_t... Is>
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> calculate_layout_impl(std::index_sequence<Is...>) {
                std::array<offset_type, sizeof...(Ts) + 1> layout{};
                std::array<offset_type, sizeof...(Ts) + 1> alignments = calculate_alignments(std::index_sequence<Is...>{});
                size_t cur_pos = 0;
                layout[0] = cur_pos;
                ([&] {
                    // The size of the i-th element (looks correct)
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    cur_pos += compute_type_size<T>();

                    // The padding dependent on the alignment of the i+1-th element
                    // or the maximum alignment, when reaching the last element
                    cur_pos += compute_amount_padding(cur_pos, alignments[Is + 1]);

                    layout[Is + 1] = cur_pos;
                }(), ...);
                layout[sizeof...(Ts)] = cur_pos;
                return layout;
            }

            static constexpr std::array<offset_type, sizeof...(Ts) + 1> calculate_layout() {
                return calculate_layout_impl(std::make_index_sequence<sizeof...(Ts)>{});
            }

        public:
            static constexpr std::array<offset_type, sizeof...(Ts) + 1> offsets = calculate_layout();

            static constexpr size_t alignment = calculate_alignment();

            void print() const {
                std::cout << "alignment: " << alignment << std::endl;
                for (size_t i = 0; i < offsets.size(); ++i) {
                    std::cout << "i: " << i << " " << offsets[i] << std::endl;
                }
            }
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

            template<std::size_t I>
            void finish_rec_impl(offset_type offset) {
                if constexpr (I < sizeof...(Ts)) {
                    // Write the data.
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
                    // Write the padding to satisfy alignment requirements
                    m_buffer.write_padding(Layout<Tuple<Ts...>>::offsets[I + 1] - m_buffer.get_size());
                    // Recursive call to next type
                    finish_rec_impl<I + 1>(offset);
                }
            }


            void finish_impl() {
                // Build header and dynamic buffer
                finish_rec_impl<0>(Layout<Tuple<Ts...>>::offsets.back());
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
        template<std::size_t I>
        decltype(auto) get() {
            if constexpr (is_trivial_and_standard_layout_v<element_type<I>>) {
                offset_type offset = Layout<Tuple<Ts...>>::offsets[I];
                return *reinterpret_cast<element_type<I>*>(m_data + offset);
            } else {
                Layout<Tuple<Ts...>>().print();
                offset_type offset = Layout<Tuple<Ts...>>::offsets[I];
                if constexpr (is_dynamic_type<element_type<I>>::value) {
                    offset = read_value<offset_type>(m_data + offset);
                }
                return View<std::tuple_element_t<I, std::tuple<Ts...>>>(m_data + offset);
            }
        }
    };
}


#endif
