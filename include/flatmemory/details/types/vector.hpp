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
    template<IsTriviallyCopyableOrCustom T>
    struct Vector : public Custom {
        Vector(const Vector& other) {}  // Non-trivial copy-constructor
    };


    /**
     * Data types
    */
    using vector_size_type = uint32_t;

    /**
     * Layout
    */
    template<IsTriviallyCopyableOrCustom T>
    class Layout<Vector<T>> {
        public:
            static constexpr buffer_size_type buffer_size_offset = 0;
            static constexpr offset_type vector_size_offset = calculate_header_offset<buffer_size_type, offset_type>(buffer_size_offset);
            static constexpr offset_type vector_data_offset = calculate_header_offset<vector_size_type, T>(vector_size_offset);

            static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, vector_size_type, T>();

            void print() const {
                std::cout << "buffer_size_offset: " << buffer_size_offset << std::endl;
                std::cout << "vector_size_offset: " << vector_size_offset << std::endl;
                std::cout << "vector_data_offset: " << vector_data_offset << std::endl;
                std::cout << "final_alignment: " << final_alignment << std::endl;
            }
    };


    /**
     * Builder
    */
    template<IsTriviallyCopyableOrCustom T>
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

                size_t buffer_size = 0;

                buffer_size += m_buffer.write<buffer_size_type>(buffer_size);  // reserve 4 bytes written at the end
                buffer_size += m_buffer.write_padding(Layout<Vector<T>>::vector_size_offset - m_buffer.size());
                
                buffer_size += m_buffer.write<vector_size_type>(m_data.size());
                buffer_size += m_buffer.write_padding(Layout<Vector<T>>::vector_data_offset - m_buffer.size());

                constexpr bool is_trivial = IsTriviallyCopyable<T>;
                if constexpr (is_trivial) {
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        buffer_size += m_buffer.write(m_data[i]);
                    }
                } else {
                    /* For dynamic type T, we store the offsets first */
                    // offset is the first position to write the dynamic data
                    offset_type offset = m_data.size() * sizeof(offset_type);
                    offset += calculate_amoung_padding(offset, Layout<T>::final_alignment);
                    for (size_t i = 0; i < m_data.size(); ++i) {
                        auto& nested_builder = m_data[i];
                        nested_builder.finish();

                        buffer_size += m_buffer.write(offset);
                        m_dynamic_buffer.write(nested_builder.buffer().data(), nested_builder.buffer().size());     
                        offset += nested_builder.buffer().size();
                    }
                }
                // Write padding after header
                buffer_size += m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), calculate_overall_alignment<T>()));
                // Concatenate all buffers
                buffer_size += m_buffer.write(m_dynamic_buffer.data(), m_dynamic_buffer.size());  
                // Write final padding
                buffer_size += m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), Layout<Vector<T>>::final_alignment));
                // Modify the prefix size
                write_value<buffer_size_type>(m_buffer.data(), buffer_size);
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


            [[nodiscard]] ByteStream& get_buffer_impl() { return m_buffer; }
            [[nodiscard]] const ByteStream& get_buffer_impl() const { return m_buffer; }

        public:
            /**
             * empty
            */
            [[nodiscard]] bool empty() const {
                return m_data.empty();
            }

            /**
             * size
            */
            [[nodiscard]] size_t size() const { 
                return m_data.size(); 
            }

            /* operator[] stl */
            [[nodiscard]] T_& operator[](size_t pos) {
                assert(pos < m_data.size());
                return m_data[pos];
            }

            /* push back stl */
            void push_back(T_&& element) { m_data.push_back(std::move(element)) ;}
            void push_back(const T_& element) { m_data.push_back(element) ;}
 
            /**
             * Resize
             * 
             * Resizing a vector of views needs additional caution 
             * since the default constructed views are not meaningful.
            */
            void resize(size_t count) { m_data.resize(count, T_()); }
            void resize(size_t count, const T_& value) { m_data.resize(count, value); }

            /**
             * iterators
            */
            auto begin() { return m_data.begin(); }
            auto end() { return m_data.end(); }
    };


    /**
     * View
    */
    template<IsTriviallyCopyableOrCustom T>
    class View<Vector<T>> {
        private:
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
            View(uint8_t* buf) : m_buf(buf) {
                assert(buf);
            } 

            /**
             * operator==
            */
            [[nodiscard]] bool operator==(const View& other) const {
                if (this == &other) return true;
                if (m_buf != other.m_buf) {
                    if (buffer_size() != other.buffer_size()) return false;
                    return std::memcmp(m_buf, other.m_buf, buffer_size());
                    if (size() != other.size()) return false;
                }
                return true;
            }

            /**
             * empty
             * 
             * This operation is more costly than std::vector empty() because it is not constexpr.
            */
            [[nodiscard]] bool empty() const {
                return size() == 0;
            }


            /**
             * buffer size
            */
            [[nodiscard]] size_t buffer_size() const { 
                assert(m_buf);
                return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_offset); 
            }

            /**
             * vector size
             * 
             * This operation is more costly than std::vector size() because it is not constexpr.
            */
            [[nodiscard]] size_t size() const { 
                assert(m_buf);
                return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_offset); 
            }

            /**
             * operator[]
            */
            [[nodiscard]] decltype(auto) operator[](size_t pos) const {
                assert(m_buf);
                assert(pos < size());
                constexpr bool is_trivial = IsTriviallyCopyable<T>;
                if constexpr (is_trivial) {
                    return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_offset + pos * sizeof(T));
                } else {
                    return View<T>(m_buf + Layout<Vector<T>>::vector_data_offset + read_value<offset_type>(m_buf + Layout<Vector<T>>::vector_data_offset + pos * sizeof(offset_type)));
                }
            }

            /**
             * iterators
            */
            class iterator {
            private:
                uint8_t* buf;

            public:
                using difference_type = std::ptrdiff_t;
                using value_type = typename maybe_view<T>::type;
                using pointer = typename maybe_view<T>::type*;
                using reference = typename maybe_view<T>::type&;
                using iterator_category = std::forward_iterator_tag;

                iterator(uint8_t* buf) : buf(buf) {}

                // Dereference operator
                reference operator*() const {
                    constexpr bool is_trivial = IsTriviallyCopyable<T>;
                    if constexpr (is_trivial) {
                        return read_value<T>(buf);
                    } else {
                        return View<T>(read_value<offset_type>(m_buf));
                    }
                }

                // Pre-increment operator
                iterator& operator++() {
                    constexpr bool is_trivial = IsTriviallyCopyable<T>;
                    if constexpr (is_trivial) {
                        buf += sizeof(T);
                    } else {
                        buf += sizeof(offset_type);
                    }
                    return *this;
                }

                // Post-increment operator
                iterator operator++(int) {
                    iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }

                // Equality comparison
                bool operator==(const iterator& other) const {
                    return buf == other.buf;
                }

                // Inequality comparison
                bool operator!=(const iterator& other) const {
                    return !(*this == other);
                }
            };

            // Begin iterator
            iterator begin() {
                return iterator(m_buf + Layout<Vector<T>>::vector_data_offset);
            }

            // End iterator
            iterator end() {
                constexpr bool is_trivial = IsTriviallyCopyable<T>;
                if constexpr (is_trivial) {
                    return iterator(m_buf + Layout<Vector<T>>::vector_data_offset + sizeof(T) * size());
                } else {
                    return iterator(m_buf + Layout<Vector<T>>::vector_data_offset + sizeof(offset_type) * size());
                }
            }
    };
}


#endif
