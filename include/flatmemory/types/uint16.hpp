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

#ifndef FLATMEMORY_TYPES_UINT16_HPP_
#define FLATMEMORY_TYPES_UINT16_HPP_
 
#include "../byte_stream.hpp"

#include "../layout.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"
#include "../types.hpp"

#include <algorithm>
#include <cassert>


namespace flatmemory
{
    /**
     * Dispatcher for tuple.
    */
    struct Uint16Tag {};


    /**
     * Layout
    */
    template<>
    class Layout<Uint16Tag> {
        public:
            static constexpr offset_type size = sizeof(uint16_t); 
            static constexpr size_t alignment = alignof(uint16_t);
    };

    
    /**
     * Type traits
    */
    template<>
    struct is_dynamic_type<Uint16Tag> : std::false_type{};


    /**
     * Builder
    */
    template<>
    class Builder<Uint16Tag> : public IBuilder<Builder<Uint16Tag>> {
        private:
            uint16_t m_value;
            ByteStream m_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() { m_buffer.write<uint16_t>(m_value); }

            void clear_impl() {}

            uint8_t* get_data_impl() { return m_buffer.get_data(); }
            size_t get_size_impl() const { return m_buffer.get_size(); }

        public:
            uint16_t& get_value() { return m_value; }
    };


    /**
     * View
    */
    template<>
    class View<Uint16Tag> {
    private:
        uint8_t* m_data;

    public:
        View(uint8_t* data) : m_data(data) {}

        uint16_t& get_value() const { return read_value<uint16_t>(m_data); }
    };
}


#endif
