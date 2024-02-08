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

#ifndef FLATMEMORY_TYPES_VECTOR_HPP_
#define FLATMEMORY_TYPES_VECTOR_HPP_

#include "../byte_stream.hpp"
#include "../layout_utils.hpp"
#include "../layout.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>


namespace flatmemory
{
    /**
     * Dispatcher for tuple.
    */
    template<IsTrivialOrCustom T>
    struct Vector : public Custom {
        Vector() { }  // Non-trivial constructor
    };


    /**
     * Data types
    */
    using vector_size_type = uint32_t;

    /**
     * Layout
    */
    template<IsTrivialOrCustom T>
    class Layout<Vector<T>> {
        private:
            static consteval offset_type calculate_data_offset() {
                size_t cur_pos = 0;
                cur_pos += sizeof(vector_size_type);
                cur_pos += calculate_amoung_padding(cur_pos, calculate_header_alignment<T>());
                return cur_pos;
            }

        public:
            static constexpr offset_type size_offset = 0;
            static constexpr offset_type data_offset = calculate_data_offset();

            static constexpr size_t final_alignment = calculate_final_alignment<vector_size_type, T>();

            void print() const {
                std::cout << "size_offset: " << size_offset << std::endl;
                std::cout << "data_offset: " << data_offset << std::endl;
                std::cout << "final_alignment: " << final_alignment << std::endl;
            }
    };


    /**
     * Builder
    */
    template<IsTrivialOrCustom T>
    class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>> {
        private:
            using T_ = typename maybe_builder<T>::type;

            std::vector<T_> m_data;
            ByteStream m_buffer;
            ByteStream m_dynamic_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() {
                assert(m_data.size() <= std::numeric_limits<vector_size_type>::max());

                m_buffer.write<vector_size_type>(m_data.size());
                m_buffer.write_padding(Layout<Vector<T>>::data_offset - m_buffer.size());

                constexpr bool is_trivial = IsTrivial<T>;
                if constexpr (is_trivial) {
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        m_buffer.write(m_data[i]);
                    }
                } else {
                    /* For dynamic type T, we store the offsets first */
                    // offset is the first position to write the dynamic data
                    offset_type offset = m_data.size() * sizeof(offset_type);
                    offset += calculate_amoung_padding(offset, Layout<T>::final_alignment);
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        auto& nested_builder = m_data[i];
                        nested_builder.finish();

                        m_buffer.write(offset);
                        m_dynamic_buffer.write(nested_builder.buffer().data(), nested_builder.buffer().size());     
                        offset += nested_builder.buffer().size();
                    }
                }
                // Write padding after header
                m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), Layout<Vector<T>>::final_alignment));
                // Concatenate all buffers
                m_buffer.write(m_dynamic_buffer.data(), m_dynamic_buffer.size());  
                assert(calculate_amoung_padding(m_buffer.size(), Layout<Vector<T>>::final_alignment) == 0);
            }

            /* clear stl */
            void clear_impl() {
                // Clear all nested builders.
                for (auto& builder : m_data) {
                    builder.clear();
                }
                // Clear this builder.
                m_buffer.clear();
                m_dynamic_buffer.clear();
            }


            ByteStream& get_buffer_impl() { return m_buffer; }
            const ByteStream& get_buffer_impl() const { return m_buffer; }

        public:
            /* operator[] stl */
            T_& operator[](size_t pos) {
                assert(pos < m_data.size());
                return m_data[pos];
            }

            /* push back stl */
            void push_back(T_&& element) { m_data.push_back(std::move(element)) ;}
            void push_back(const T_& element) { m_data.push_back(element) ;}
 
            /* resize stl*/
            void resize(size_t count) { m_data.resize(count); }
            void resize(size_t count, const T_& value) { m_data.resize(count, value); }
    };


    /**
     * View
    */
    template<IsTrivialOrCustom T>
    class View<Vector<T>> {
    private:
        uint8_t* m_data;

    public:
        View() = default;  // trivial constructor
        View(uint8_t* data) : m_data(data) {}
        View(const View& other) = default;
        View& operator=(const View& other) = default; 
        View(View&& other) = default;
        View& operator=(View&& other) = default; 

        /* size stl */
        size_t size() const { 
            assert(m_data);
            return read_value<vector_size_type>(m_data + Layout<Vector<T>>::size_offset); 
        }

        /* operator[] stl */
        decltype(auto) operator[](size_t pos) const {
            assert(m_data);
            assert(pos < size());
            constexpr bool is_trivial = IsTrivial<T>;
            if constexpr (is_trivial) {
                return read_value<T>(m_data + Layout<Vector<T>>::data_offset + pos * sizeof(T));
            } else {
                return View<T>(m_data + Layout<Vector<T>>::data_offset + read_value<offset_type>(m_data + Layout<Vector<T>>::data_offset + pos * sizeof(offset_type)));
            }
        }
    };
}


#endif
