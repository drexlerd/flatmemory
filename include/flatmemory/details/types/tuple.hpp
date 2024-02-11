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

#include "../byte_buffer.hpp"
#include "../byte_buffer_utils.hpp"
#include "../layout_utils.hpp"
#include "../layout.hpp"
#include "../builder.hpp"
#include "../view_const.hpp"
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
     * Dispatcher for Tuple.
    */
    template<IsTriviallyCopyableOrCustom... Ts>
    struct Tuple : public Custom 
    {
        /// @brief Non-trivial copy-constructor
        /// @param other 
        Tuple(const Tuple& other) {}
    };


    /**
     * Layout
    */
    template<IsTriviallyCopyableOrCustom... Ts>
    class Layout<Tuple<Ts...>> 
    {
        private:



            /**
             * Helper function to calculate array that contains alignment requirements
             * with additional max overall alignment requirement at the end.
            */
            template<size_t... Is>
            static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_header_alignments(std::index_sequence<Is...>) {
                std::array<size_t, sizeof...(Ts) + 1> alignments{};
                ([&] {
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    // We use offset alignment for non trivial types
                    alignments[Is] = calculate_header_alignment<T>();
                }(), ...);
                alignments[sizeof...(Ts)] = final_alignment;
                return alignments;
            }


            template<typename T>
            static consteval size_t calculate_header_offset_type_size() {
                constexpr bool is_trivial = IsTriviallyCopyable<T>;
                if constexpr (is_trivial) {
                    return sizeof(T);
                } else {
                    return sizeof(offset_type);
                }
            }

            struct ElementData {
                size_t position;
                size_t end;
                size_t padding;
                size_t data_alignment;

                void print() const {
                    std::cout << "position: " << position << " end: " << end << " padding: " << padding << std::endl;
                }
            };

            struct LayoutData {
                size_t buffer_size_position;
                size_t buffer_size_end;
                size_t buffer_size_padding;

                size_t element_datas_position;
                std::array<ElementData, sizeof...(Ts)> element_datas;

                void print() const {
                    std::cout << "LayoutData:\n"
                              << "buffer_size_position: " << buffer_size_position << "\n"
                              << "buffer_size_end: " << buffer_size_end << "\n"
                              << "buffer_size_padding: " << buffer_size_padding << "\n"
                              << "element_datas_position: " << element_datas_position << std::endl;
                    for (const auto& element_data : element_datas) {
                        element_data.print();
                    }
                }
            };

            template<size_t... Is>
            static consteval LayoutData calculate_layout_data(std::index_sequence<Is...>) {
                constexpr std::array<size_t, sizeof...(Ts) + 1> alignments = calculate_header_alignments(std::make_index_sequence<sizeof...(Ts)>{});

                size_t buffer_size_position = 0;
                size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
                size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, alignments[0]);

                size_t current_position = buffer_size_end + buffer_size_padding;

                std::array<ElementData, sizeof...(Ts)> element_datas{};
                ([&] {
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    size_t position = current_position;
                    size_t end = position + calculate_header_offset_type_size<T>();
                    size_t padding = calculate_amount_padding(end, alignments[Is + 1]);
                    size_t alignment = calculate_data_alignment<T>();
                    element_datas[Is] = ElementData{position, end, padding, alignment};
                    current_position = end + padding;
                }(), ...);

                size_t element_datas_position = current_position;

                return LayoutData{
                    buffer_size_position, 
                    buffer_size_end, 
                    buffer_size_padding,
                    element_datas_position,
                    element_datas};
            }

           

        public:
            static constexpr size_t size = sizeof...(Ts);

            static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, Ts...>();

            static constexpr LayoutData layout_data = calculate_layout_data(std::make_index_sequence<sizeof...(Ts)>{});

            void print() const {
                std::cout << "final_alignment: " << final_alignment << std::endl;
                layout_data.print();
            }

    };


    /**
     * Builder
    */
    template<IsTriviallyCopyableOrCustom... Ts> 
    class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>> 
    {
        private:
            std::tuple<typename maybe_builder<Ts>::type...> m_data;
            ByteBuffer m_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            template<size_t... Is>
            void finish_iterative_impl(std::index_sequence<Is...>) {
                Layout<Tuple<Ts...>>().print();

                offset_type data_offset = Layout<Tuple<Ts...>>::layout_data.element_datas_position;
                buffer_size_type buffer_size = data_offset;
                ([&] {
                    using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
                    constexpr auto& element_data = Layout<Tuple<Ts...>>::layout_data.element_datas[Is];
                    constexpr bool is_trivial = IsTriviallyCopyable<T>;
                    if constexpr (is_trivial) {
                        auto& value = std::get<Is>(m_data);
                        m_buffer.write(element_data.position, value);
                    } else {
                        // write offset
                        m_buffer.write(element_data.position, data_offset);
        
                        // write data
                        auto& nested_builder = std::get<Is>(m_data);
                        nested_builder.finish();
                        buffer_size_type nested_buffer_size = read_value<buffer_size_type>(nested_builder.buffer().data());
                        m_buffer.write(data_offset, nested_builder.buffer().data(), nested_buffer_size);    
                        data_offset += nested_buffer_size;
                        buffer_size += nested_buffer_size;
                    }
                    // TODO maybe add padding?
                }(), ...);
                buffer_size += calculate_amount_padding(buffer_size, Layout<Tuple<Ts...>>::final_alignment);
                /* Write buffer size */
                m_buffer.write(Layout<Tuple<Ts...>>::layout_data.buffer_size_position, buffer_size);
                m_buffer.set_size(buffer_size);
            }

            void finish_impl() {
                // Build header and dynamic buffer
                finish_iterative_impl(std::make_index_sequence<sizeof...(Ts)>{});
            }


            template<size_t... Is>
            void clear_iterative_impl(std::index_sequence<Is...>) {
                ([&] {
                    constexpr bool is_trivial = IsTriviallyCopyable<std::tuple_element_t<Is, std::tuple<Ts...>>>;
                    if constexpr (!is_trivial) {
                        auto& builder = std::get<Is>(m_data);
                        builder.clear();
                    }
                }(), ...);
            }


            void clear_impl() {
                // Clear all nested builders.
                clear_iterative_impl(std::make_index_sequence<sizeof...(Ts)>{});
            }


            auto& get_buffer_impl() { return m_buffer; }
            const auto& get_buffer_impl() const { return m_buffer; }

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
    class View<Tuple<Ts...>> 
    {
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
                assert(test_correct_alignment<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
                return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position);
            } else {
                return element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
            }
        }


        /**
         * Capacity
        */
        [[nodiscard]] size_t buffer_size() const { 
            assert(m_buf);
            assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position));
            return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position); 
        }
    };


    /**
     * View
    */
    template<IsTriviallyCopyableOrCustom... Ts>
    class ConstView<Tuple<Ts...>> 
    {
    private:
        template<size_t I>
        using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
        template<size_t I>
        using element_view_type = View<std::tuple_element_t<I, std::tuple<Ts...>>>;

        const uint8_t* m_buf;

        /**
         * Default constructor to make view a trivial data type and serializable
        */
        ConstView() = default;

        template<typename>
        friend class Builder;

    public:
        /**
         * Constructor to interpret raw data created by its corresponding builder
        */
        ConstView(const uint8_t* data) : m_buf(data) {
            assert(m_buf);
        }

        /**
         * Returns a View to the I-th element.
         * 
         * If the I-th type is dynamic we must add the offset to the actual data first.
        */
        template<std::size_t I>
        decltype(auto) get() const {
            assert(m_buf);
            assert(I < Layout<Tuple<Ts...>>::size);
            constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
            if constexpr (is_trivial) {
                assert(test_correct_alignment<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
                return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position);
            } else {
                return element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
            }
        }


        /**
         * Capacity
        */
        [[nodiscard]] size_t buffer_size() const { 
            assert(m_buf);
            assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position));
            return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position); 
        }
    };
}


#endif
