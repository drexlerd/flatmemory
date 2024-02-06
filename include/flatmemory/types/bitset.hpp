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

#ifndef FLATMEMORY_TYPES_BITSET_HPP_
#define FLATMEMORY_TYPES_BITSET_HPP_
 
#include "utils.hpp"
#include "vector.hpp"

#include "../byte_stream.hpp"
#include "../byte_stream_utils.hpp"

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
    template<typename Block>
    struct Bitset {
        Bitset() { }  // Non-trivial constructor
        ~Bitset() { } // Non-trivial destructor
    };


    /**
     * Layout
    */
    template<typename Block>
    class Layout<Bitset<Block>> {
        private:
            static constexpr offset_type calculate_blocks_offset() {
                size_t cur_pos = 0;
                cur_pos += sizeof(bool);
                cur_pos += compute_amount_padding(cur_pos, calculate_header_alignment<Vector<Block>>());
                return cur_pos;
            }
            
        public:
            static constexpr size_t blocks_offset = calculate_blocks_offset();

            static constexpr size_t final_alignment = calculate_final_alignment<bool, Vector<Block>>();
    };

    
    /**
     * Type traits
     * 
     * A bitset is dynamic because vector is dynamic
    */
    template<typename Block>
    struct is_dynamic_type<Bitset<Block>> : std::true_type{};


    /**
     * Builder
    */
    template<typename Block>
    class Builder<Bitset<Block>> : public IBuilder<Builder<Bitset<Block>>> {
        private:
            bool m_default_bit_value;
            Builder<Vector<Block>> m_blocks_builder;

            ByteStream m_buffer;

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() {
                m_buffer.write(m_default_bit_value);
                m_buffer.write_padding(Layout<Bitset<Block>>::blocks_offset - m_buffer.get_size());
                m_blocks_builder.finish();
                m_buffer.write(m_blocks_builder.get_data(), m_blocks_builder.get_size());
                m_buffer.write_padding(compute_amount_padding(m_buffer.get_size(), Layout<Bitset<Block>>::final_alignment));
            }

            void clear_impl() {
                // Clear all nested builders.
                m_blocks_builder.clear();
                // Clear this builder.
                m_buffer.clear();
            }

            uint8_t* get_data_impl() { return m_buffer.get_data(); }
            size_t get_size_impl() const { return m_buffer.get_size(); }

        public:
            bool& get_default_bit_value() { return m_default_bit_value; }

            auto& get_blocks_builer() { return m_blocks_builder; }
    };


    /**
     * View
    */
    template<typename Block>
    class View<Bitset<Block>> {
    private:
        uint8_t* m_data;

    public:
        View(uint8_t* data) : m_data(data) {}

        /**
         * Returns a View to the I-th element.
         * 
         * If the I-th type is dynamic we must add the offset to the actual data first.
        */
        bool& get_default_bit_value() {
            return read_value<bool>(m_data);
        }

        View<Vector<Block>> get_blocks() {
            return View<Vector<Block>>(m_data + Layout<Bitset<Block>>::blocks_offset);
        }
    };
}


#endif
