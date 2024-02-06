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

#include "../layout.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"
#include "../types.hpp"

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>


namespace flatmemory
{
    /**
     * Dispatcher for tuple.
    */
    template<typename T>
    struct Vector {};


    /**
     * Data types
    */
    using vector_size_type = uint32_t;

    /**
     * Layout
    */
    template<typename T>
    class Layout<Vector<T>> {
        static constexpr offset_type calculate_data_offset() {
            size_t cur_pos = 0;
            cur_pos += sizeof(vector_size_type);
            if constexpr (is_dynamic_type<T>::value) {
                cur_pos += compute_amount_padding(cur_pos, Layout<T>::alignment);
            } else {
                cur_pos += compute_amount_padding(cur_pos, sizeof(offset_type));
            }
            return cur_pos;
        }

        public:
            static constexpr offset_type size_offset = 0;
            static constexpr offset_type data_offset = calculate_data_offset();

            static constexpr size_t alignment = std::max({alignof(offset_type), alignof(vector_size_type), Layout<T>::alignment});
    };

    
    /**
     * Type traits
    */
    template<typename T>
    struct is_dynamic_type<Vector<T>> : std::true_type{};


    /**
     * Builder
    */
    template<typename T>
    class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>> {
        private:
            std::vector<Builder<T>> m_data;
            ByteStream m_buffer;
            ByteStream m_dynamic_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() {
                assert(m_data.size() <= std::numeric_limits<vector_size_type>::max());

                m_buffer.write<vector_size_type>(m_data.size());
                m_buffer.write_padding(Layout<Vector<T>>::data_offset - m_buffer.get_size());

                if constexpr (is_dynamic_type<T>::value) {
                    /* For dynamic type T, we store the offsets first */
                    // offset is the first position to write the dynamic data
                    offset_type offset = Layout<Vector<T>>::data_offset;
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        auto& nested_builder = m_data[i];
                        nested_builder.finish();

                        m_buffer.write(offset);
                        m_dynamic_buffer.write(nested_builder.get_data(), nested_builder.get_size());     
                        offset += sizeof(offset_type) + nested_builder.get_size();
                    }
                } else {
                    /* For static type T, we can store the data directly */
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        auto& nested_builder = m_data[i];
                        nested_builder.finish();
                        
                        assert(nested_builder.get_size() == Layout<T>::size);  
                        m_buffer.write(nested_builder.get_data(), nested_builder.get_size()); 
                    }  
                }
                // Concatenate all buffers
                m_buffer.write(m_dynamic_buffer.get_data(), m_dynamic_buffer.get_size());  
                // Write alignment padding
                m_buffer.write_padding(compute_amount_padding(m_buffer.get_size(), Layout<Vector<T>>::alignment));
            }

            void clear_impl() {
                // Clear all nested builders.
                for (auto& builder : m_data) {
                    builder.clear();
                }
                // Clear this builder.
                m_buffer.clear();
                m_dynamic_buffer.clear();
            }

            uint8_t* get_data_impl() { return m_buffer.get_data(); }
            size_t get_size_impl() const { return m_buffer.get_size(); }

        public:
            std::vector<Builder<T>>& get_builders() { return m_data; }
    };


    /**
     * View
    */
    template<typename T>
    class View<Vector<T>> {
    private:
        uint8_t* m_data;

    public:
        View(uint8_t* data) : m_data(data) {}

        size_t get_size() const { return read_value<vector_size_type>(m_data + Layout<Vector<T>>::size_offset); }

        View<T> operator[](size_t pos) const {
            if constexpr (is_dynamic_type<T>::value) {
                return View<T>(m_data + read_value<offset_type>(m_data + Layout<Vector<T>>::data_offset + pos * sizeof(offset_type)));
            } else {
                return View<T>(m_data + Layout<Vector<T>>::data_offset + pos * Layout<T>::size);
            }
        }
    };
}


#endif
