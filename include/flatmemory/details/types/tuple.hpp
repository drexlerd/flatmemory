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
#include "../layout_utils.hpp"
#include "../layout.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"

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
    template<IsTriviallyCopyableOrCustom... Ts>
    struct Tuple : public Custom {
        Tuple(const Tuple& other) {}  // Non-trivial copy-constructor
    };


    /**
     * Layout
    */
    template<IsTriviallyCopyableOrCustom... Ts>
    class Layout<Tuple<Ts...>> {
        private:
            /**
             * Helper function to calculate array that contains alignment requirements
             * with additional max overall alignment requirement at the end.
            */
            template<size_t... Is>
            static consteval std::array<offset_type, sizeof...(Ts) + 1> calculate_header_alignments(std::index_sequence<Is...>) {
                std::array<offset_type, sizeof...(Ts) + 1> alignments{};
                ([&] {
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    alignments[Is] = calculate_header_alignment<T>();
                }(), ...);
                alignments[sizeof...(Ts)] = calculate_final_alignment<Ts...>();
                return alignments;
            }
           
            /**
             * Compute the header_offsets for each type T
            */
            template<size_t... Is>
            static consteval std::array<offset_type, sizeof...(Ts) + 1> calculate_header_offsets_impl(std::index_sequence<Is...>) {
                std::array<offset_type, sizeof...(Ts) + 1> layout{};
                std::array<offset_type, sizeof...(Ts) + 1> alignments = calculate_header_alignments(std::index_sequence<Is...>{});
                size_t cur_pos = 0;
                layout[0] = cur_pos;
                ([&] {
                    // The size of the i-th element (looks correct)
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    cur_pos += calculate_header_type_size<T>();

                    // The padding dependent on the alignment of the i+1-th element
                    // or the maximum alignment, when reaching the last element
                    cur_pos += calculate_amoung_padding(cur_pos, alignments[Is + 1]);

                    layout[Is + 1] = cur_pos;
                }(), ...);
                layout[sizeof...(Ts)] = cur_pos;
                return layout;
            }

            static consteval std::array<offset_type, sizeof...(Ts) + 1> calculate_header_offsets() {
                return calculate_header_offsets_impl(std::make_index_sequence<sizeof...(Ts)>{});
            }

        public:
            static constexpr size_t size = sizeof...(Ts);

            static constexpr std::array<offset_type, sizeof...(Ts) + 1> header_offsets = calculate_header_offsets();

            static constexpr size_t final_alignment = calculate_final_alignment<Ts...>();

            void print() const {
                for (size_t i = 0; i < header_offsets.size(); ++i) {
                    std::cout << "i: " << i << " " << header_offsets[i] << std::endl;
                }
                std::cout << "final_alignment: " << final_alignment << std::endl;
            }
    };


    /**
     * Builder
    */
    template<IsTriviallyCopyableOrCustom... Ts> 
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
                    constexpr bool is_trivial = IsTriviallyCopyable<std::tuple_element_t<I, std::tuple<Ts...>>>;
                    if constexpr (is_trivial) {
                        auto& value = std::get<I>(m_data);
                        m_buffer.write(value);
                    } else {
                        // Recursively call finish
                        auto& nested_builder = std::get<I>(m_data);
                        nested_builder.finish();
                        m_buffer.write(offset);
                        m_dynamic_buffer.write(nested_builder.buffer().data(), nested_builder.buffer().size());    
                        offset += nested_builder.buffer().size();
  
                    }
                    // Write the padding to satisfy alignment requirements
                    m_buffer.write_padding(Layout<Tuple<Ts...>>::header_offsets[I + 1] - m_buffer.size());
                    // Recursive call to next type
                    finish_rec_impl<I + 1>(offset);
                }
            }


            void finish_impl() {
                // Build header and dynamic buffer
                finish_rec_impl<0>(Layout<Tuple<Ts...>>::header_offsets.back());
                // Concatenate all buffers
                m_buffer.write(m_dynamic_buffer.data(), m_dynamic_buffer.size()); 
                // Write alignment padding
                m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), Layout<Tuple<Ts...>>::final_alignment));
            }


            template<std::size_t I = 0>
            void clear_rec_impl() {
                if constexpr (I < sizeof...(Ts)) {
                    constexpr bool is_trivial = IsTriviallyCopyable<std::tuple_element_t<I, std::tuple<Ts...>>>;
                    if constexpr (!is_trivial) {
                        auto& builder = std::get<I>(m_data);
                        builder.clear();
                    }

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


            ByteStream& get_buffer_impl() { return m_buffer; }
            const ByteStream& get_buffer_impl() const { return m_buffer; }

        public:
            template<std::size_t I>
            auto& get() {
                return std::get<I>(m_data);
            }
    };


    /**
     * View
    */
    template<IsTriviallyCopyableOrCustom... Ts>
    class View<Tuple<Ts...>> {
    private:
        template<size_t I>
        using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
        template<size_t I>
        using element_view_type = View<std::tuple_element_t<I, std::tuple<Ts...>>>;

        uint8_t* m_buf;

        /**
         * Default constructor to make view a trivial data type and serializable
        */
        View() = default;

        template<typename>
        friend class Builder;

    public:
        /**
         * Constructor to interpret raw data created by its corresponding builder
        */
        View(uint8_t* data) : m_buf(data) {
            assert(m_buf);
        }

        /**
         * Returns a View to the I-th element.
         * 
         * If the I-th type is dynamic we must add the offset to the actual data first.
        */
        template<std::size_t I>
        decltype(auto) get() {
            assert(m_buf);
            assert(I < Layout<Tuple<Ts...>>::size);
            constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
            if constexpr (is_trivial) {
                return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::header_offsets[I]);
            } else {
                return element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::header_offsets[I]));
            }
        }
    };
}


#endif
