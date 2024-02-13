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

#include "../byte_buffer.hpp"
#include "../byte_buffer_utils.hpp"
#include "../layout_utils.hpp"
#include "../layout.hpp"
#include "../operator.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../view_const.hpp"
#include "../type_traits.hpp"

#include "../algorithms/murmurhash3.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <tuple>
#include <iostream>
#include <string>


namespace flatmemory
{
    /**
     * Dispatcher for Bitset.
     */
    template <typename Block>
    struct Bitset : public Custom
    {
        /// @brief Non-trivial copy-constructor
        /// @param other
        Bitset(const Bitset &other) {}
    };


    /**
     * Layout
     */
    template <typename Block>
    class Layout<Bitset<Block>>
    {
    public:
        static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, bool, Vector<Block>>();

        static constexpr size_t buffer_size_position = 0;
        static constexpr size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type); 
        static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_header_alignment<bool>());
        static constexpr size_t default_bit_value_position = buffer_size_end + buffer_size_padding;
        static constexpr size_t default_bit_value_end = default_bit_value_position + sizeof(bool);
        static constexpr size_t default_bit_value_padding = calculate_amount_padding(default_bit_value_end, calculate_data_alignment<Vector<Block>>());
        static constexpr size_t blocks_position = default_bit_value_end + default_bit_value_padding;

        void print() const {
            std::cout << "buffer_size_position: " << buffer_size_position << "\n"
                      << "buffer_size_end: " << buffer_size_end << "\n"
                      << "buffer_size_padding: " << buffer_size_padding << "\n"
                      << "default_bit_value_position: " << default_bit_value_position << "\n"
                      << "default_bit_value_end: " << default_bit_value_end << "\n"
                      << "default_bit_value_padding: " << default_bit_value_padding << "\n"
                      << "blocks_position: " << blocks_position << "\n"
                      << "final_alignment: " << final_alignment << std::endl;
        }
    };


    /**
     * Forward declarations
    */
    template<typename Block>
    class View<Bitset<Block>>;

    template<typename Block>
    class ConstView<Bitset<Block>>;

    template<typename Block>
    class Builder<Bitset<Block>>;


    /**
     * Concepts
    */
    template <typename>
    struct is_bitset : std::false_type {};

    template <typename Block>
    struct is_bitset<Builder<Bitset<Block>>> : std::true_type {};

    template <typename Block>
    struct is_bitset<View<Bitset<Block>>> : std::true_type {};

    template <typename Block>
    struct is_bitset<ConstView<Bitset<Block>>> : std::true_type {};

    // Concept to check whether T is a Bitset
    template <typename T>
    concept IsBitset = is_bitset<T>::value;

    template<typename T>
    struct block_type_extractor;

    template<typename Block>
    struct block_type_extractor<Builder<Bitset<Block>>> {
        using type = Block;
    };

    template<typename Block>
    struct block_type_extractor<View<Bitset<Block>>> {
        using type = Block;
    };

    template<typename Block>
    struct block_type_extractor<ConstView<Bitset<Block>>> {
        using type = Block;
    };

    template<typename T>
    using block_type_extractor_t = typename block_type_extractor<T>::type;

    // Concept to check if two types have the same Block type
    template<typename T1, typename T2>
    concept SameBlockType = std::is_same_v<block_type_extractor_t<T1>, block_type_extractor_t<T2>>;


    /**
     * Operator
    */
    template<typename Block>
    class Operator<Bitset<Block>> {
        private:
            static constexpr std::size_t block_size = sizeof(Block) * 8;
            // 000...
            static constexpr Block block_zeroes = 0;
            // 111...
            static constexpr Block block_ones = Block(-1);
            // 100...
            static constexpr Block block_msb_one = Block(1) << (block_size - 1);
            // 011...
            static constexpr Block block_msb_zero = block_ones & (~block_msb_one);

        public:
            template<IsBitset L, IsBitset R>
            requires SameBlockType<L, R>
            static bool are_equal(const L& left_bitset, const R& right_bitset) {
                // Fetch data
                const auto &blocks = left_bitset.get_blocks();
                bool default_bit_value = left_bitset.get_default_bit_value();
                const auto &other_blocks = right_bitset.get_blocks();
                bool other_default_bit_value = right_bitset.get_default_bit_value();

                std::size_t common_size = std::min(blocks.size(), other_blocks.size());
                if (std::memcmp(blocks.data(), other_blocks.data(), common_size * sizeof(Block)) != 0) return false;

                std::size_t max_size = std::max(blocks.size(), other_blocks.size());

                for (std::size_t index = common_size; index < max_size; ++index)
                {
                    Block this_value = index < blocks.size() ? blocks[index] : (default_bit_value ? block_ones : block_zeroes);
                    Block other_value = index < other_blocks.size() ? other_blocks[index] : (other_default_bit_value ? block_ones : block_zeroes);

                    if (this_value != other_value)
                    {
                        return false;
                    }
                }

                return true;
            }

            template<IsBitset B>
            static size_t hash(const B& bitset) {
                // Fetch data
                const bool default_bit_value = bitset.get_default_bit_value();
                const auto &blocks = bitset.get_blocks();

                const auto default_block = default_bit_value ? block_ones : block_zeroes;
                const auto seed = static_cast<uint32_t>(default_block);

                // Find the last block that differs from the default block
                auto last_relevant_index = static_cast<int64_t>(blocks.size()) - 1;
                for (; (last_relevant_index >= 0) && (blocks[last_relevant_index] == default_block); --last_relevant_index)
                {
                }
                const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(Block);

                // Compute a hash value up to and including this block
                int64_t hash[2];
                MurmurHash3_x64_128(blocks.data(), length, seed, hash);
                return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
            }


            /**
             * Iterators
            */

            class const_iterator {
            private:
                // Underlying data
                const Block* m_blocks;
                size_t m_num_blocks;

                // The current block to be worked on
                size_t m_block_index;
                size_t m_bit_index;
                size_t m_cur_block;

                // The iterator positions
                size_t m_end_pos;
                size_t m_pos;

                void next_set_bit() 
                {
                    do {
                        /* Advance step */
                        ++m_pos;
                        ++m_bit_index;

                        /* Skip step */
                        if (m_cur_block == block_zeroes) {
                            // Skip remaining zero bits; set pos to last position in current block for advance step
                            m_pos += block_size - m_bit_index - 1;
                            // Move to next block; set bit_index to -1 for advance step
                            m_bit_index = -1;
                            ++m_block_index;
                            m_cur_block = m_blocks[m_block_index];
                            continue;
                        }

                        /* Test step */
                        if (m_cur_block & Block(1)) {
                            m_cur_block >>= 1;
                            break;
                        }
                        m_cur_block >>= 1;
                    } while (m_pos < m_end_pos);
                }
    
                size_t find_end_pos() const 
                {
                    assert(m_num_blocks > 0);
                    // Find the last block that differs from the default block
                    int32_t last_relevant_block_index = static_cast<int64_t>(m_num_blocks) - 1;
                    for (; (last_relevant_block_index >= 0) && (m_blocks[last_relevant_block_index] == block_ones); --last_relevant_block_index)
                    {
                    }
                    // Point to the last position of the next block (it must not exist)
                    return (last_relevant_block_index + 1) * block_size - 1;
                }

            public:
                using difference_type = size_t;
                using value_type = bool;
                using pointer = bool*;
                using reference = bool&;
                using iterator_category = std::forward_iterator_tag;

                const_iterator(bool default_bit_value, const Block* blocks, size_t num_blocks, bool begin)
                    : m_blocks(blocks)
                    , m_num_blocks(num_blocks)
                    , m_block_index(0)
                    , m_bit_index(-1)  // set bit_index to -1 for advance step
                    , m_cur_block(num_blocks > 0 ? blocks[m_block_index] : block_zeroes)
                    , m_end_pos(find_end_pos())
                    , m_pos(begin ? -1 : m_end_pos)  // set to -1 for advance step
                {
                    // Iteration is only well-defined on non default_bit_value
                    assert(!default_bit_value);
                    if (begin) {
                        next_set_bit();
                    } 
                }

                [[nodiscard]] size_t operator*() const {
                    // Do not allow interpreting begin or end as position.
                    assert(m_pos < m_end_pos);
                    return m_pos;
                }

                const_iterator& operator++() {
                    next_set_bit();
                    return *this;
                }

                // No postfix increment since it is too costly to copy the iterator

                [[nodiscard]] bool operator==(const const_iterator& other) const {
                    return m_pos == other.m_pos;
                }

                [[nodiscard]] bool operator!=(const const_iterator& other) const {
                    return !(*this == other);
                }
            };
    };


    /**
     * View
     */
    template <typename Block>
    class View<Bitset<Block>>
    {
    private:
        using const_iterator = Operator<Bitset<Block>>::const_iterator;

        uint8_t *m_buf;

        /**
         * Default constructor to make view a trivial data type and serializable
         */
        View() = default;

        template <typename>
        friend class Builder;

        static constexpr std::size_t block_size = sizeof(Block) * 8;
        static constexpr Block block_zeroes = 0;
        static constexpr Block block_ones = Block(-1);

    public:
        /**
         * Constructor to interpret raw data created by its corresponding builder
         */
        explicit View(uint8_t* buf) : m_buf(buf)
        {
            assert(m_buf);
        }

        
        /**
         * Operators
        */

        template <IsBitset Other>
        [[nodiscard]] bool operator==(const Other& other) const
        {
            assert(m_buf);
            return Operator<Bitset<Block>>::are_equal(*this, other);
        }

        template <IsBitset Other>
        [[nodiscard]] bool operator!=(const Other& other) const {
            return !(*this == other);
        }


        /**
         * Iterators
        */
       
        [[nodiscard]] const_iterator begin() { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true); }
        [[nodiscard]] const_iterator begin() const { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true); }
        [[nodiscard]] const_iterator end() { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false); }
        [[nodiscard]] const_iterator end() const { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false); }


        /**
         * Hashing
        */

        [[nodiscard]] size_t hash() const
        {
            assert(m_buf);
            return Operator<Bitset<Block>>::hash(*this);
        }


        /**
         * Getters
        */
        [[nodiscard]] size_t buffer_size() const
        {
            assert(m_buf);
            assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_position));
            return read_value<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_position);
        }

        [[nodiscard]] bool& get_default_bit_value()
        {
            assert(m_buf);
            assert(test_correct_alignment<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position));
            return read_value<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position);
        }

        [[nodiscard]] const bool& get_default_bit_value() const
        {
            assert(m_buf);
            assert(test_correct_alignment<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position));
            return read_value<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position);
        }

        [[nodiscard]] View<Vector<Block>> get_blocks()
        {
            assert(m_buf);
            return View<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_position);
        }

        [[nodiscard]] ConstView<Vector<Block>> get_blocks() const
        {
            assert(m_buf);
            return ConstView<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_position);
        }
    };

    /**
     * ConstView
     */
    template <typename Block>
    class ConstView<Bitset<Block>>
    {
    private:
        using const_iterator = Operator<Bitset<Block>>::const_iterator;

        const uint8_t *m_buf;

        /**
         * Default constructor to make view a trivial data type and serializable
         */
        ConstView() = default;

        template <typename>
        friend class Builder;

        static constexpr std::size_t block_size = sizeof(Block) * 8;
        static constexpr Block block_zeroes = 0;
        static constexpr Block block_ones = Block(-1);

    public:
        /**
         * Constructor to interpret raw data created by its corresponding builder
         */
        ConstView(const uint8_t *data) : m_buf(data)
        {
            assert(m_buf);
        }

        /**
         * Operators
        */

        template <IsBitset Other>
        [[nodiscard]] bool operator==(const Other& other) const
        {
            assert(m_buf);
            return Operator<Bitset<Block>>::are_equal(*this, other);
        }

        template <IsBitset Other>
        [[nodiscard]] bool operator!=(const Other& other) const {
            return !(*this == other);
        }


        /**
         * Iterators
        */
       
        [[nodiscard]] const_iterator begin() { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true); }
        [[nodiscard]] const_iterator begin() const { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true); }
        [[nodiscard]] const_iterator end() { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false); }
        [[nodiscard]] const_iterator end() const { return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false); }


        /**
         * Hashing
        */

        [[nodiscard]] size_t hash() const
        {
            assert(m_buf);
            return Operator<Bitset<Block>>::hash(*this);
        }


        /**
         * Getters
        */

        [[nodiscard]] size_t buffer_size() const
        {
            assert(m_buf);
            assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_position));
            return read_value<buffer_size_type>(m_buf + Layout<Bitset<Block>>::buffer_size_position);
        }

        [[nodiscard]] const bool& get_default_bit_value() const
        {
            assert(m_buf);
            assert(test_correct_alignment<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position));
            return read_value<bool>(m_buf + Layout<Bitset<Block>>::default_bit_value_position);
        }

        [[nodiscard]] ConstView<Vector<Block>> get_blocks() const
        {
            assert(m_buf);
            return ConstView<Vector<Block>>(m_buf + Layout<Bitset<Block>>::blocks_position);
        }
    };

    /**
     * Builder
     */
    template <typename Block>
    class Builder<Bitset<Block>> : public IBuilder<Builder<Bitset<Block>>>
    {
    private:
        using const_iterator = Operator<Bitset<Block>>::const_iterator;

        bool m_default_bit_value;
        Builder<Vector<Block>> m_blocks;

        ByteBuffer m_buffer;

        static constexpr std::size_t block_size = sizeof(Block) * 8;
        static constexpr Block block_zeroes = 0;
        static constexpr Block block_ones = Block(-1);
        static constexpr std::size_t no_position = std::size_t(-1);

        /* Implement IBuilder interface. */
        template <typename>
        friend class IBuilder;

        void finish_impl()
        {
            /* Write header info */
            // Write default_bit_value
            m_buffer.write(Layout<Bitset<Block>>::default_bit_value_position, m_default_bit_value);
            m_buffer.write_padding(Layout<Bitset<Block>>::default_bit_value_end, Layout<Bitset<Block>>::default_bit_value_padding);

            /* Write dynamic info */
            buffer_size_type buffer_size = Layout<Bitset<Block>>::blocks_position;

            // Write blocks
            m_blocks.finish();
            buffer_size += m_buffer.write(Layout<Bitset<Block>>::blocks_position, m_blocks.buffer().data(), m_blocks.buffer().size());

            // Write final padding
            buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, Layout<Bitset<Block>>::final_alignment));
            
            /* Write buffer size */
            m_buffer.write(Layout<Bitset<Block>>::buffer_size_position, buffer_size);
            m_buffer.set_size(buffer_size);
        }

        [[nodiscard]] auto& get_buffer_impl() { return m_buffer; }
        [[nodiscard]] const auto& get_buffer_impl() const { return m_buffer; }


        template <IsBitset Other>
        void resize_to_fit(const Other &other)
        {
            if (m_blocks.size() < other.get_blocks().size())
            {
                m_blocks.resize(other.get_blocks().size(), m_default_bit_value ? block_ones : block_zeroes);
            }
        }

        std::size_t get_lsb_position(Block n) const
        {
            assert(n != 0);
            const Block v = n & (-n);
            return static_cast<std::size_t>(log2(v));
        }

    public:
        Builder() : m_default_bit_value(false) {}
        // Initialize the bitset with a certain size
        Builder(std::size_t size) 
            : m_default_bit_value(false)
            , m_blocks((size / (sizeof(Block) * 8)) + 1, block_zeroes) {}

        Builder(std::size_t size, bool default_bit_value)
            : m_default_bit_value(default_bit_value)
            , m_blocks((size / (sizeof(Block) * 8)) + 1, default_bit_value ? block_ones : block_zeroes) { }

        
        /**
         * Operators
        */

        template <IsBitset Other>
        bool operator<(const Other& other) const
        {
            // Fetch data
            const auto &other_blocks = other.get_blocks();
            bool other_default_bit_value = other.get_default_bit_value();

            std::size_t common_size = std::min(m_blocks.size(), other_blocks.size());

            for (std::size_t index = 0; index < common_size; ++index)
            {
                if (m_blocks[index] < other_blocks[index])
                {
                    return true;
                }
            }

            std::size_t max_size = std::max(m_blocks.size(), other_blocks.size());

            for (std::size_t index = common_size; index < max_size; ++index)
            {
                Block this_value = index < m_blocks.size() ? m_blocks[index] : (m_default_bit_value ? block_ones : block_zeroes);
                Block other_value = index < other_blocks.size() ? other_blocks[index] : (other_default_bit_value ? block_ones : block_zeroes);

                if (this_value < other_value)
                {
                    return true;
                }
            }

            return false;
        }

        template <IsBitset Other>
        bool operator==(const Other& other) const
        {
            return Operator<Bitset<Block>>::are_equal(*this, other);
        }

        template <IsBitset Other>
        [[nodiscard]] bool operator!=(const Other& other) const {
            return !(*this == other);
        }


        /**
         * Modifiers
        */

        // Set a bit at a specific position
        void set(std::size_t position)
        {
            const std::size_t index = position / block_size;   // Find the index in the vector
            const std::size_t offset = position % block_size;  // Find the offset within the std::size_t

            if (index >= m_blocks.size())
            {
                m_blocks.resize(index + 1, m_default_bit_value ? block_ones : block_zeroes);
            }

            m_blocks[index] |= (static_cast<Block>(1) << offset);  // Set the bit at the offset
        }

        // Unset a bit at a specific position
        void unset(std::size_t position)
        {
            const std::size_t index = position / block_size;   // Find the index in the vector
            const std::size_t offset = position % block_size;  // Find the offset within the std::size_t

            if (index >= m_blocks.size())
            {
                m_blocks.resize(index + 1, m_default_bit_value ? block_ones : block_zeroes);
            }

            m_blocks[index] &= ~(static_cast<Block>(1) << offset);  // Set the bit at the offset
        }

        // Unset all bits
        void unset_all()
        {
            for (auto& value : m_blocks) {
                value = (m_default_bit_value) ? block_ones : block_zeroes;
            }
        }

        // Unset all bits for a given default_bit_value
        void unset_all(bool default_bit_value)
        {
            m_default_bit_value = default_bit_value;
            unset_all();
        }

        Builder& operator~()
        {
            m_default_bit_value = !m_default_bit_value;

            for (Block& value : m_blocks)
            {
                value = ~value;
            }

            return *this;
        }

        template <IsBitset Other>
        Builder& operator|=(const Other &other)
        {
            // Fetch data
            const auto &other_blocks = other.get_blocks();
            bool other_default_bit_value = other.get_default_bit_value();

            // Update default bit value
            m_default_bit_value |= other_default_bit_value;

            // Update blocks
            resize_to_fit(other);
            auto it = m_blocks.begin();
            auto other_it = other_blocks.begin();
            while (it != m_blocks.end())
            {
                *it |= *other_it;
                ++it;
                ++other_it;
            }

            return *this;
        }

        template <IsBitset Other>
        Builder& operator&=(const Other &other)
        {
            // Fetch data
            const auto &other_blocks = other.get_blocks();
            bool other_default_bit_value = other.get_default_bit_value();

            // Update default bit value
            m_default_bit_value &= other_default_bit_value;

            // Update blocks
            resize_to_fit(other);
            auto it = m_blocks.begin();
            auto other_it = other_blocks.begin();
            while (it != m_blocks.end())
            {
                *it &= *other_it;
                ++it;
                ++other_it;
            }

            return *this;
        }


        /**
         * Lookup
        */

        // Get the value of a bit at a specific position
        bool get(std::size_t position) const {
            {
                const std::size_t index = position / block_size;

                if (index < m_blocks.size())
                {
                    const std::size_t offset = position % block_size;
                    return (m_blocks[index] & (static_cast<Block>(1) << offset)) != 0;
                }
                else
                {
                    return m_default_bit_value;
                }
            }
        }

        // Find the next set bit, inclusive the given position
        std::size_t next_set_bit(std::size_t position) const
        {
            std::size_t index = position / block_size;
            std::size_t offset = position % block_size;

            while (index < m_blocks.size())
            {
                // Shift so that we start checking from the offset
                const Block value = m_blocks[index] >> offset;

                if (value)
                {
                    // If there are set bits in the current value
                    const auto lsb_position = get_lsb_position(value);
                    return index * block_size + offset + lsb_position;
                }

                // Reset offset for the next value
                offset = 0;
                index++;
            }

            return no_position;
        }

    
        /**
         * Iterators
        */

        [[nodiscard]] const_iterator begin() { return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), true); }
        [[nodiscard]] const_iterator begin() const { return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), true); }
        [[nodiscard]] const_iterator end() { return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), false); }
        [[nodiscard]] const_iterator end() const { return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), false); }


        /**
         * Hashing
        */

        [[nodiscard]] size_t hash() const
        {
            return Operator<Bitset<Block>>::hash(*this);
        }


        /**
         * Getters
        */

        [[nodiscard]] bool& get_default_bit_value() { return m_default_bit_value; }
        [[nodiscard]] const bool& get_default_bit_value() const { return m_default_bit_value; }

        [[nodiscard]] auto& get_blocks() { return m_blocks; }
        [[nodiscard]] const auto& get_blocks() const { return m_blocks; }
    };
}


namespace std
{
    // Inject hash into the std namespace
    template <typename Block>
    struct hash<flatmemory::View<flatmemory::Bitset<Block>>>
    {
        std::size_t operator()(const flatmemory::View<flatmemory::Bitset<Block>> &bitset) const
        {
            return bitset.hash();
        }
    };

    template <typename Block>
    struct hash<flatmemory::ConstView<flatmemory::Bitset<Block>>>
    {
        std::size_t operator()(const flatmemory::ConstView<flatmemory::Bitset<Block>> &bitset) const
        {
            return bitset.hash();
        }
    };

    template <typename Block>
    struct hash<flatmemory::Builder<flatmemory::Bitset<Block>>>
    {
        std::size_t operator()(const flatmemory::Builder<flatmemory::Bitset<Block>> &bitset) const
        {
            return bitset.hash();
        }
    };
}

#endif
