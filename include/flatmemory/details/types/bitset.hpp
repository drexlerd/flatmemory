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
 
#include "vector.hpp"

#include "../byte_stream.hpp"
#include "../byte_stream_utils.hpp"
#include "../layout_utils.hpp"
#include "../layout.hpp"
#include "../operator.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../view_const.hpp"
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
    struct Bitset : public Custom {
        Bitset(const Bitset& other) {}  // Non-trivial copy-constructor
    };


    /**
     * Layout
    */
    template<typename Block>
    class Layout<Bitset<Block>> {
        public:
            static constexpr size_t default_bit_value_offset = 0;
            static constexpr size_t blocks_offset = calculate_header_offset<bool, Vector<Block>>(default_bit_value_offset);

            static constexpr size_t final_alignment = calculate_final_alignment<bool, Vector<Block>>();
    };


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
                m_buffer.write_padding(Layout<Bitset<Block>>::blocks_offset - m_buffer.size());
                m_blocks_builder.finish();
                m_buffer.write(m_blocks_builder.buffer().data(), m_blocks_builder.buffer().size());
                m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), Layout<Bitset<Block>>::final_alignment));
            }

            void clear_impl() {
                // Clear all nested builders.
                m_blocks_builder.clear();
                // Clear this builder.
                m_buffer.clear();
            }


            ByteStream& get_buffer_impl() { return m_buffer; }
            const ByteStream& get_buffer_impl() const { return m_buffer; }

        public:
            bool& get_default_bit_value() { return m_default_bit_value; }

            auto& get_blocks() { return m_blocks_builder; }
    };


    /**
     * View
    */
    template<typename Block>
    class View<Bitset<Block>> {
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

        bool& get_default_bit_value() {
            assert(m_buf);
            return read_value<bool>(m_buf);
        }

        View<Vector<Block>> get_blocks() {
            assert(m_buf);
            return View<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_offset);
        }
    };


    /**
     * View
    */
    template<typename Block>
    class ConstView<Bitset<Block>> {
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

        const bool& get_default_bit_value() {
            assert(m_buf);
            return read_value<bool>(m_buf);
        }

        const ConstView<Vector<Block>> get_blocks() const {
            assert(m_buf);
            return ConstView<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_offset);
        }
    };


    /**
     * Concepts 
    */
    template<typename>
    struct is_mutable_bitset : std::false_type {};

    template<typename Block>
    struct is_mutable_bitset<Builder<Bitset<Block>>> : std::true_type {};

    template<typename T>
    concept IsMutableBitset = is_mutable_bitset<T>::value;

    template<typename>
    struct is_immutable_bitset : std::false_type {};

    template<typename Block>
    struct is_immutable_bitset<View<Bitset<Block>>> : std::true_type {};

    template<typename Block>
    struct is_immutable_bitset<ConstView<Bitset<Block>>> : std::true_type {};

    template<typename T>
    concept IsImmutableBitset = is_immutable_bitset<T>::value;

    template<typename T>
    concept IsMutableOrImmutableBitset = (is_mutable_bitset<T>::value || is_immutable_bitset<T>::value);


    /**
     * Operator
    */
    template<typename Block>
    class Operator<Bitset<Block>> {
        public:
            /**
             * operator|=
            */
            template<IsMutableBitset L, IsMutableOrImmutableBitset R>
            static decltype(auto) or_equal(L& l, const R& r) {
                // I will implement this, just to illustrate the functionality
                return l;
            }

            /**
             * operator&=
            */
            template<IsMutableBitset L, IsMutableOrImmutableBitset R>
            static decltype(auto) and_equal(L& l, const R& r) {
                // I will implement this, just to illustrate the functionality
                return l;
            }

            /**
             * hash
            */
            template<IsMutableOrImmutableBitset B>
            static size_t hash(const B& b) {
                return 0;
            }
    };
}


namespace std 
{
    // Inject comparison and hash into the std namespace
}


#endif
