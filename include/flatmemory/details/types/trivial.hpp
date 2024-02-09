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

#ifndef FLATMEMORY_TYPES_STRUCT_HPP_
#define FLATMEMORY_TYPES_STRUCT_HPP_

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
    template<IsTriviallyCopyable T>
    struct Trivial : public Custom {
        Trivial(const Trivial& other) {}  // Non-trivial copy-constructor
    };


    /**
     * Layout
    */
    template<IsTriviallyCopyable T>
    class Layout<Trivial<T>> {     
        public:
            static constexpr size_t final_alignment = sizeof(T);
    };


    /**
     * Builder
    */
    template<IsTriviallyCopyable T>
    class Builder<Trivial<T>> : public IBuilder<Builder<Trivial<T>>> {
        private:
            T m_trivial;

            ByteStream m_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() {
                m_buffer.write(m_trivial);
            }

            void clear_impl() {
                // Clear this builder.
                m_buffer.clear();
            }


            ByteStream& get_buffer_impl() { return m_buffer; }
            const ByteStream& get_buffer_impl() const { return m_buffer; }

        public:
            T& operator*() { return m_trivial; }
            T* operator->() { return &m_trivial; }
    };


    /**
     * View
    */
    template<IsTriviallyCopyable T>
    class View<Trivial<T>> {
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
        View(uint8_t* data) : m_buf(data) {
            assert(m_buf);
        }

        T& operator*() { 
            assert(m_buf);
            return read_value<T>(m_buf); 
        }
        T* operator->() { 
            assert(m_buf);
            return &read_value<T>(m_buf); 
        }
    };
}


#endif