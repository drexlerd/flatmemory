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
#include "../builder.hpp"
#include "../view.hpp"
#include "../view_const.hpp"
#include "../type_traits.hpp"

#include "../algorithms/murmurhash3.hpp"

#include <algorithm>
#include <cassert>
#include <tuple>
#include <iostream>
#include <string>


namespace flatmemory
{
    /**
     * Dispatcher for Bitset.
    */
    template<typename Block>
    struct Bitset : public Custom {
        /// @brief Non-trivial copy-constructor
        /// @param other 
        Bitset(const Bitset& other) {}
    };


    /**
     * Layout
    */
    template<typename Block>
    class Layout<Bitset<Block>> {
        public:
            static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, bool, Vector<Block>>();

            static constexpr size_t buffer_size_offset = 0;
            static constexpr size_t default_bit_value_offset = calculate_header_offset<buffer_size_type, bool>(buffer_size_offset);
            static constexpr size_t blocks_offset = calculate_header_offset<bool, Vector<Block>>(default_bit_value_offset);
    
            void print() const {
                std::cout << "buffer_size_offset: " << buffer_size_offset << std::endl;
                std::cout << "default_bit_value_offset: " << default_bit_value_offset << std::endl;
                std::cout << "blocks_offset: " << blocks_offset << std::endl;
                std::cout << "final_alignment: " << final_alignment << std::endl;
            }
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

        static constexpr std::size_t block_size = sizeof(Block) * 8;
        static constexpr Block block_zeroes = 0;
        static constexpr Block block_ones = Block(-1);

    public:        
        /**
         * Constructor to interpret raw data created by its corresponding builder
        */
        View(uint8_t* data) : m_buf(data) {
            assert(m_buf);
        }

        [[nodiscard]] size_t buffer_size() const { 
            assert(m_buf);
            return read_value<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_offset); 
        }

        [[nodiscard]] bool& get_default_bit_value() {
            assert(m_buf);
            return read_value<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_offset);
        }

        [[nodiscard]] View<Vector<Block>> get_blocks() {
            assert(m_buf);
            return View<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_offset);
        }

        [[nodiscard]] size_t hash() const {
            const bool default_bit_value = get_default_bit_value();
            const auto& blocks = get_blocks();

            const auto default_block = default_bit_value ? block_ones : block_zeroes;
            const auto seed = static_cast<uint32_t>(default_block);

            // TODO (dominik): use reverse iterator
            // Find the last block that differs from the default block
            auto last_relevant_index = static_cast<int64_t>(blocks.size()) - 1;
            for (; (last_relevant_index >= 0) && (blocks[last_relevant_index] == default_block); --last_relevant_index) {}
            const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(Block);

            // Compute a hash value up to and including this block
            int64_t hash[2];
            MurmurHash3_x64_128(m_buf, length, seed, hash);
            return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
        }
    };


    /**
     * ConstView
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

        static constexpr std::size_t block_size = sizeof(Block) * 8;
        static constexpr Block block_zeroes = 0;
        static constexpr Block block_ones = Block(-1);

    public:        
        /**
         * Constructor to interpret raw data created by its corresponding builder
        */
        ConstView(const uint8_t* data) : m_buf(data) {
            assert(m_buf);
        }

        [[nodiscard]] size_t buffer_size() const { 
            assert(m_buf);
            return read_value<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_offset); 
        }

        [[nodiscard]] const bool& get_default_bit_value() const {
            assert(m_buf);
            return read_value<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_offset);
        }

        [[nodiscard]] ConstView<Vector<Block>> get_blocks() const {
            assert(m_buf);
            return ConstView<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_offset);
        }

        [[nodiscard]] size_t hash() const {
            const bool default_bit_value = get_default_bit_value();
            const auto& blocks = get_blocks();

            const auto default_block = default_bit_value ? block_ones : block_zeroes;
            const auto seed = static_cast<uint32_t>(default_block);

            // TODO (dominik): use reverse iterator
            // Find the last block that differs from the default block
            auto last_relevant_index = static_cast<int64_t>(blocks.size()) - 1;
            for (; (last_relevant_index >= 0) && (blocks[last_relevant_index] == default_block); --last_relevant_index) {}
            const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(Block);

            // Compute a hash value up to and including this block
            int64_t hash[2];
            MurmurHash3_x64_128(m_buf, length, seed, hash);
            return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
        }
    };


    /**
     * Concepts 
    */
    template<typename>
    struct is_bitset : std::false_type {};

    template<typename Block>
    struct is_bitset<Builder<Bitset<Block>>> : std::true_type {};

    template<typename Block>
    struct is_bitset<View<Bitset<Block>>> : std::true_type {};

    template<typename Block>
    struct is_bitset<ConstView<Bitset<Block>>> : std::true_type {};

    template<typename T>
    concept IsBitset = is_bitset<T>::value;


    /**
     * Builder
    */
    template<typename Block>
    class Builder<Bitset<Block>> : public IBuilder<Builder<Bitset<Block>>> {
        private:
            bool m_default_bit_value;
            Builder<Vector<Block>> m_blocks;

            ByteStream m_buffer;

            static constexpr std::size_t block_size = sizeof(Block) * 8;
            static constexpr Block block_zeroes = 0;
            static constexpr Block block_ones = Block(-1);

            /* Implement IBuilder interface. */
            template<typename>
            friend class IBuilder;

            void finish_impl() 
            {
                size_t buffer_size = 0;
                // Reserve 4 bytes written at the end
                buffer_size += m_buffer.write<buffer_size_type>(buffer_size);
                buffer_size += m_buffer.write_padding(Layout<Bitset<Block>>::default_bit_value_offset - m_buffer.size());
                // Write default_bit_value
                buffer_size += m_buffer.write(m_default_bit_value);
                buffer_size += m_buffer.write_padding(Layout<Bitset<Block>>::blocks_offset - m_buffer.size());
                m_blocks.finish();
                // Write blocks
                buffer_size += m_buffer.write(m_blocks.buffer().data(), m_blocks.buffer().size());
                // Write final padding
                buffer_size += m_buffer.write_padding(calculate_amoung_padding(m_buffer.size(), Layout<Bitset<Block>>::final_alignment));
                // Modify the prefix size
                write_value<buffer_size_type>(m_buffer.data(), buffer_size);
            }

            void clear_impl() 
            {
                // Clear all nested builders.
                m_blocks.clear();
                // Clear this builder.
                m_buffer.clear();
            }


            [[nodiscard]] ByteStream& get_buffer_impl() { return m_buffer; }
            [[nodiscard]] const ByteStream& get_buffer_impl() const { return m_buffer; }

            template<IsBitset Other>
            void resize_to_fit(const Other& other) 
            {
                if (m_blocks.size() < other.get_blocks().size()) 
                {
                    m_blocks.resize(other.get_blocks().size(), m_default_bit_value ? block_ones : block_zeroes);
                }
            }

        public:
            [[nodiscard]] bool& get_default_bit_value() { return m_default_bit_value; }

            [[nodiscard]] auto& get_blocks() { return m_blocks; }

            template<IsBitset Other>
            [[nodiscard]] Builder& operator|=(const Other& other) {
                // Fetch data
                const auto& other_blocks = other.get_blocks();
                bool other_default_bit_value = other.get_default_bit_value();
                
                // Update default bit value
                m_default_bit_value |= other_default_bit_value;

                // Update blocks
                resize_to_fit(other);
                auto it = m_blocks.begin();
                auto other_it = other_blocks.begin();
                while (it != m_blocks.end()) {
                    *it |= *other_it;
                    ++it;
                    ++other_it;
                }

                return *this;
            }

            template<IsBitset Other>
            [[nodiscard]] Builder& operator&=(const Other& other) {
                // Fetch data
                const auto& other_blocks = other.get_blocks();
                bool other_default_bit_value = other.get_default_bit_value();
                
                // Update default bit value
                m_default_bit_value &= other_default_bit_value;

                // Update blocks
                resize_to_fit(other);
                auto it = m_blocks.begin();
                auto other_it = other_blocks.begin();
                while (it != m_blocks.end()) {
                    *it &= *other_it;
                    ++it;
                    ++other_it;
                }

                return *this;
            }

            [[nodiscard]] size_t hash() const {
                const auto default_block = m_default_bit_value ? block_ones : block_zeroes;
                const auto seed = static_cast<uint32_t>(default_block);

                // TODO (dominik): use reverse iterator
                // Find the last block that differs from the default block
                auto last_relevant_index = static_cast<int64_t>(m_blocks.size()) - 1;
                for (; (last_relevant_index >= 0) && (m_blocks[last_relevant_index] == default_block); --last_relevant_index) {}
                const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(Block);

                // Compute a hash value up to and including this block
                int64_t hash[2];
                MurmurHash3_x64_128(&m_blocks[0], length, seed, hash);
                return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
            }
    };
}


namespace std 
{
    // Inject hash into the std namespace
    template<typename Block>
    struct hash<flatmemory::View<flatmemory::Bitset<Block>>> {
        std::size_t operator()(const flatmemory::View<flatmemory::Bitset<Block>>& bitset) const
        {
            return bitset.hash();
        }
    };

    template<typename Block>
    struct hash<flatmemory::ConstView<flatmemory::Bitset<Block>>> {
        std::size_t operator()(const flatmemory::ConstView<flatmemory::Bitset<Block>>& bitset) const
        {
            return bitset.hash();
        }
    };

    template<typename Block>
    struct hash<flatmemory::Builder<flatmemory::Bitset<Block>>> {
        std::size_t operator()(const flatmemory::Builder<flatmemory::Bitset<Block>>& bitset) const
        {
            return bitset.hash();
        }
    };
}


#endif
