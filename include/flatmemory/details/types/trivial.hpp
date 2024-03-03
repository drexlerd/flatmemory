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
     * Dispatcher for Trivial.
    */
    template<IsTriviallyCopyable T>
    struct Trivial : public Custom {
        /// @brief Non-trivial copy-constructor
        /// @param other
        Trivial(const Trivial& other) {}
    };


    /**
     * Layout
    */
    template<IsTriviallyCopyable T>
    class Layout<Trivial<T>> {
        public:
            // we do not add size prefix since we can use sizeof for trivial types T

            static constexpr size_t final_alignment = sizeof(T);
    };


    /**
     * Builder
    */
    template<IsTriviallyCopyable T>
    class Builder<Trivial<T>> : public IBuilder<Builder<Trivial<T>>>
    {
        private:
            T m_trivial;

            ByteBuffer m_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() {
                m_buffer.write(0, m_trivial);
                m_buffer.set_size(sizeof(T));
            }

            [[nodiscard]] auto& get_buffer_impl() { return m_buffer; }
            [[nodiscard]] const auto& get_buffer_impl() const { return m_buffer; }

        public:
            [[nodiscard]] T& operator*() { return m_trivial; }

            [[nodiscard]] T* operator->() { return &m_trivial; }
    };


    /**
     * View
    */
    template<IsTriviallyCopyable T>
    class View<Trivial<T>>
    {
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

        [[nodiscard]] T& operator*() {
            assert(m_buf);
            assert(test_correct_alignment<T>(m_buf));
            return read_value<T>(m_buf);
        }

        [[nodiscard]] T* operator->() {
            assert(m_buf);
            assert(test_correct_alignment<T>(m_buf));
            return &read_value<T>(m_buf);
        }

        [[nodiscard]] size_t buffer_size() const {
            assert(m_buf);
            return sizeof(T);
        }

        [[nodiscard]] uint8_t* buffer() { return m_buf; }
        [[nodiscard]] const uint8_t* buffer() const { return m_buf; }
    };


    /**
     * ConstView
    */
    template<IsTriviallyCopyable T>
    class ConstView<Trivial<T>> {
    private:
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
         * Conversion constructor
        */
        ConstView(const View<Trivial<T>>& view) : m_buf(view.buffer()) {}


        [[nodiscard]] const T& operator*() const {
            assert(m_buf);
            assert(test_correct_alignment<T>(m_buf));
            return read_value<T>(m_buf);
        }

        [[nodiscard]] const T* operator->() const {
            assert(m_buf);
            assert(test_correct_alignment<T>(m_buf));
            return &read_value<T>(m_buf);
        }

        [[nodiscard]] size_t buffer_size() const {
            assert(m_buf);
            return sizeof(T);
        }

        [[nodiscard]] uint8_t* buffer() { return m_buf; }
    };
}


#endif
