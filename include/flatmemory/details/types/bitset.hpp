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

#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"
#include "flatmemory/details/types/vector.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <iostream>
#include <ranges>

namespace flatmemory
{
/**
 * ID class for non-trivial Bitset type.
 * The optional tag can be used to disallow operations with bitsets with other non-default tags.
 */

template<IsUnsignedIntegral Block, typename Tag>
struct Bitset : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Bitset(const Bitset& other) {}
};

/**
 * Layout
 */

template<IsUnsignedIntegral Block, typename Tag>
class Layout<Bitset<Block, Tag>>
{
public:
    static constexpr size_t final_alignment = calculate_final_alignment<BufferSizeType, bool, Vector<Block>>();

    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t buffer_size_end = buffer_size_position + sizeof(BufferSizeType);
    static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_header_alignment<bool>());
    static constexpr size_t default_bit_value_position = buffer_size_end + buffer_size_padding;
    static constexpr size_t default_bit_value_end = default_bit_value_position + sizeof(bool);
    static constexpr size_t default_bit_value_padding = calculate_amount_padding(default_bit_value_end, calculate_data_alignment<Vector<Block>>());
    static constexpr size_t blocks_position = default_bit_value_end + default_bit_value_padding;

    constexpr void print() const;
};

/**
 * BitsetUtils
 */

class BitsetUtils
{
public:
    template<IsUnsignedIntegral Block>
    static constexpr std::size_t block_size = sizeof(Block) * 8;
    // 000...
    template<IsUnsignedIntegral Block>
    static constexpr Block block_zeroes = 0;
    // 111...
    template<IsUnsignedIntegral Block>
    static constexpr Block block_ones = Block(-1);
    // 100...
    template<IsUnsignedIntegral Block>
    static constexpr Block block_msb_one = Block(1) << (block_size<Block> - 1);
    // 011...
    template<IsUnsignedIntegral Block>
    static constexpr Block block_msb_zero = block_ones<Block> & (~block_msb_one<Block>);
    // 111...
    static constexpr std::size_t no_position = std::size_t(-1);

    /**
     * Operators
     */

    template<IsBitset B1, IsBitset B2>
        requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
    static bool is_superseteq(const B1& lhs, const B2& rhs);

    template<IsBitset B1, IsBitset B2>
        requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
    static bool are_disjoint(const B1& lhs, const B2& rhs);

    /**
     * Lookup
     */

    template<IsBitset B>
    static bool get(const B& bitset, std::size_t position);

    /// @brief Return the number of set bits.
    template<IsBitset B>
    static size_t count(const B& bitset);

    template<IsUnsignedIntegral Block>
    static int64_t find_last_relevant_block(const std::vector<Block>& blocks, bool default_bit_value);

    /**
     * Iterators
     */

    template<IsUnsignedIntegral Block>
    class ConstIterator
    {
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

        void next_set_bit();

    public:
        using difference_type = int;
        using value_type = size_t;
        using pointer = size_t*;
        using reference = size_t&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator();
        ConstIterator(bool default_bit_value, const Block* blocks, size_t num_blocks, bool begin);
        size_t operator*() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };

    /**
     * Math
     */

    template<IsUnsignedIntegral Block>
    static size_t get_lsb_position(Block n) noexcept;

    template<IsUnsignedIntegral Block>
    static size_t get_index(size_t position) noexcept;

    template<IsUnsignedIntegral Block>
    static size_t get_offset(size_t position) noexcept;
};

/**
 * Free function operators
 */

template<IsBitset B>
bool operator==(const B& lhs, const B& rhs);

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool operator==(const B1& lhs, const B2& rhs);

template<IsBitset B>
bool operator!=(const B& lhs, const B& rhs);

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool operator!=(const B1& lhs, const B2& rhs);

template<IsBitset B>
Builder<Bitset<typename B::BlockType, typename B::TagType>> operator~(const B& element);

/**
 * Builder
 */

template<IsUnsignedIntegral Block, typename Tag>
class Builder<Bitset<Block, Tag>> : public IBuilder<Builder<Bitset<Block, Tag>>>
{
public:
    /**
     * Type declarations
     */

    using BlockType = Block;
    using TagType = Tag;

    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using ConstIterator = typename BitsetUtils::ConstIterator<Block>;

    /**
     * Constructors
     */

    Builder();
    Builder(std::size_t size);
    Builder(std::size_t size, bool default_bit_value);
    Builder(const Builder& other) = default;
    Builder& operator=(const Builder& other) = default;
    Builder(Builder&& other) noexcept = default;
    Builder& operator=(Builder&& other) noexcept = default;

    /**
     * Conversion constructors
     */

    Builder(const BitsetView& other);
    Builder(const BitsetConstView& other);

    /**
     * Conversion assignments
     */

    Builder& operator=(const BitsetView& other);
    Builder& operator=(const BitsetConstView& other);

    /**
     * Modifiers
     */

    /// @brief Shrink the bitset to minimum number of blocks (at least 1) to represent its bits.
    void shrink_to_fit();

    /// @brief Set a bit at a specific position
    /// @param position
    void set(std::size_t position);

    /// @brief Unset a bit at a specific position
    /// @param position
    void unset(std::size_t position);

    /// @brief Unset all bits and shrink its size to represent the bits
    void unset_all();

    Builder& operator~();

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder operator|(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder& operator|=(const Other& other);

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder operator&(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder& operator&=(const Other& other);

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder operator-(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    Builder& operator-=(const Other& other);

    /**
     * Operators
     */

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool is_superseteq(const B& other) const;

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool are_disjoint(const B& other) const;

    /**
     * Lookup
     */

    /// @brief Get the value of a bit at a specific position
    /// @param position
    /// @return
    bool get(std::size_t position) const;

    /// @brief Count the number of set bits.
    /// @return
    size_t count() const;

    /// @brief Find the next set bit, inclusive the given position
    /// @param position
    /// @return
    std::size_t next_set_bit(std::size_t position) const;

    /**
     * Iterators
     */

    ConstIterator begin() const;
    ConstIterator end() const;

    /**
     * Getters
     */

    bool& get_default_bit_value();
    bool get_default_bit_value() const;

    auto& get_blocks();
    const auto& get_blocks() const;

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl();
    size_t finish_impl(size_t pos, ByteBuffer& out);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    void resize_to_fit(const Other& other);

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    void init_from_view(const Other& other);

private:
    bool m_default_bit_value;
    Builder<Vector<Block>> m_blocks;

    ByteBuffer m_buffer;
};

/**
 * View
 */

template<IsUnsignedIntegral Block, typename Tag>
class View<Bitset<Block, Tag>>
{
public:
    /**
     * Type declarations
     */

    using BlockType = Block;
    using TagType = Tag;

    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using ConstIterator = typename BitsetUtils::ConstIterator<Block>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    /// @param buf
    explicit View(uint8_t* buf);

    /**
     * Operators
     */

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool is_superseteq(const B& other) const;

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool are_disjoint(const B& other) const;

    /**
     * Lookup
     */

    bool get(std::size_t position) const;

    size_t count() const;

    /**
     * Iterators
     */

    ConstIterator begin();
    ConstIterator begin() const;
    ConstIterator end();
    ConstIterator end() const;

    /**
     * Getters
     */

    uint8_t* buffer();
    const uint8_t* buffer() const;
    BufferSizeType buffer_size() const;

    bool& get_default_bit_value();
    bool get_default_bit_value() const;

    View<Vector<Block>> get_blocks();
    ConstView<Vector<Block>> get_blocks() const;

private:
    uint8_t* m_buf;
};

/**
 * ConstView
 */

template<IsUnsignedIntegral Block, typename Tag>
class ConstView<Bitset<Block, Tag>>
{
public:
    /**
     * Type declarations
     */

    using BlockType = Block;
    using TagType = Tag;

    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using ConstIterator = typename BitsetUtils::ConstIterator<Block>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    /// @param data
    ConstView(const uint8_t* data);

    /**
     * Conversion constructors
     */

    ConstView(const BitsetView& view);

    /**
     * Operators
     */

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool is_superseteq(const B& other) const;

    template<IsBitset B>
        requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
    bool are_disjoint(const B& other) const;

    /**
     * Lookup
     */

    bool get(std::size_t position) const;

    size_t count() const;

    /**
     * Iterators
     */

    ConstIterator begin();
    ConstIterator begin() const;
    ConstIterator end();
    ConstIterator end() const;

    /**
     * Getters
     */

    const uint8_t* buffer() const;

    BufferSizeType buffer_size() const;

    bool get_default_bit_value();

    bool get_default_bit_value() const;

    ConstView<Vector<Block>> get_blocks();

    ConstView<Vector<Block>> get_blocks() const;

private:
    const uint8_t* m_buf;
};

/**
 * Definitions
 */

/* Layout */

template<IsUnsignedIntegral Block, typename Tag>
constexpr void Layout<Bitset<Block, Tag>>::print() const
{
    std::cout << "buffer_size_position: " << buffer_size_position << "\n"
              << "buffer_size_end: " << buffer_size_end << "\n"
              << "buffer_size_padding: " << buffer_size_padding << "\n"
              << "default_bit_value_position: " << default_bit_value_position << "\n"
              << "default_bit_value_end: " << default_bit_value_end << "\n"
              << "default_bit_value_padding: " << default_bit_value_padding << "\n"
              << "blocks_position: " << blocks_position << "\n"
              << "final_alignment: " << final_alignment << std::endl;
}

/* Operator */

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool BitsetUtils::is_superseteq(const B1& lhs, const B2& rhs)
{
    // Fetch data
    const auto& blocks = lhs.get_blocks();
    bool default_bit_value = lhs.get_default_bit_value();
    const auto& other_blocks = rhs.get_blocks();
    bool other_default_bit_value = rhs.get_default_bit_value();

    if (other_default_bit_value && !default_bit_value)
    {
        // blocks has finitely many and other blocks has infinitely many set bits.
        // Hence blocks cannot be a superseteq of other_blocks.
        return false;
    }

    std::size_t common_size = std::min(blocks.size(), other_blocks.size());

    for (std::size_t index = 0; index < common_size; ++index)
    {
        if ((blocks[index] & other_blocks[index]) != other_blocks[index])
        {
            // There exists a set bit in other block that is not set in block.
            return false;
        }
    }

    if (other_blocks.size() <= blocks.size())
    {
        // blocks can only contain additional set bits
        return true;
    }

    if (default_bit_value)
    {
        return true;
    }

    for (std::size_t index = common_size; index < other_blocks.size(); ++index)
    {
        if (other_blocks[index])
        {
            // other_block contains additional set bits
            return false;
        }
    }

    return true;
}

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool BitsetUtils::are_disjoint(const B1& lhs, const B2& rhs)
{
    // Fetch data
    const auto& blocks = lhs.get_blocks();
    bool default_bit_value = lhs.get_default_bit_value();
    const auto& other_blocks = rhs.get_blocks();
    bool other_default_bit_value = rhs.get_default_bit_value();

    if (default_bit_value && other_default_bit_value)
    {
        // blocks and other blocks have infinitely many set bits after finite sized explicit bitsets.
        // Hence blocks and other_blocks cannot be disjoint.
        return false;
    }

    std::size_t common_size = std::min(blocks.size(), other_blocks.size());

    for (std::size_t index = 0; index < common_size; ++index)
    {
        if ((blocks[index] & other_blocks[index]) > 0)
        {
            // block and other_block have set bits in common
            return false;
        }
    }

    if (default_bit_value && !other_default_bit_value)
    {
        for (std::size_t index = common_size; index < other_blocks.size(); ++index)
        {
            if (other_blocks[index] > 0)
            {
                // other_blocks has a set bit in common with blocks in the infinite part.
                return false;
            }
        }
    }

    if (!default_bit_value && other_default_bit_value)
    {
        for (std::size_t index = common_size; index < blocks.size(); ++index)
        {
            if (blocks[index] > 0)
            {
                // blocks has a set bit in common with other_blocks in the infinite part.
                return false;
            }
        }
    }

    return true;
}

template<IsUnsignedIntegral Block>
int64_t BitsetUtils::find_last_relevant_block(const std::vector<Block>& blocks, bool default_bit_value)
{
    int64_t last_relevant_block_index = static_cast<int64_t>(blocks.size()) - 1;
    for (; (last_relevant_block_index >= 0) && (blocks[last_relevant_block_index] == (default_bit_value ? block_ones<Block> : block_zeroes<Block>) );
         --last_relevant_block_index)
    {
    }
    return last_relevant_block_index;
}

template<IsBitset B>
bool BitsetUtils::get(const B& bitset, std::size_t position)
{
    {
        const std::size_t index = get_index<typename B::BlockType>(position);

        const auto& blocks = bitset.get_blocks();
        if (index < blocks.size())
        {
            const std::size_t offset = get_offset<typename B::BlockType>(position);
            return (blocks[index] & (static_cast<B::BlockType>(1) << offset)) != 0;
        }
        else
        {
            return bitset.get_default_bit_value();
        }
    }
}

template<IsBitset B>
size_t BitsetUtils::count(const B& bitset)
{
    auto count = (size_t) 0;
    for (auto it = bitset.begin(); it != bitset.end(); ++it)
    {
        ++count;
    }
    return count;
}

template<IsUnsignedIntegral Block>
void BitsetUtils::ConstIterator<Block>::next_set_bit()
{
    assert(m_pos != m_end_pos);
    do
    {
        // Advance position
        ++m_pos;
        ++m_bit_index;
        if (m_bit_index == block_size<Block>)
        {
            ++m_block_index;
            if (m_block_index == m_num_blocks)
            {
                // Reached end of blocks, set m_pos to end
                m_pos += block_size<Block> - 1;
                break;
            }
            m_bit_index = 0;
            m_cur_block = m_blocks[m_block_index];
        }

        if (m_cur_block)
        {
            // If there are set bits in the current value
            const auto lsb_position = get_lsb_position<Block>(m_cur_block);
            m_bit_index += lsb_position;
            m_pos += lsb_position;
            // shift by + 1 to advance further
            m_cur_block >>= lsb_position + 1;
            break;
        }
        else
        {
            // Skip the remaining bits, point to last position in the current block
            m_pos += block_size<Block> - m_bit_index - 1;
            ++m_block_index;
            m_bit_index = -1;
            // Fetch next data block or zeroes
            m_cur_block = m_block_index < m_num_blocks ? m_blocks[m_block_index] : block_zeroes<Block>;
        }
    } while (m_pos < m_end_pos);
}

template<IsUnsignedIntegral Block>
BitsetUtils::ConstIterator<Block>::ConstIterator() : m_blocks(nullptr), m_num_blocks(0), m_block_index(0), m_bit_index(-1)
{
}

template<IsUnsignedIntegral Block>
BitsetUtils::ConstIterator<Block>::ConstIterator(bool default_bit_value, const Block* blocks, size_t num_blocks, bool begin) :
    m_blocks(blocks),
    m_num_blocks(num_blocks),
    m_block_index(0),
    m_bit_index(-1),
    m_cur_block(num_blocks > 0 ? m_blocks[m_block_index] : block_zeroes<Block>),
    m_end_pos((num_blocks + 1) * block_size<Block> - 1),
    m_pos(begin ? -1 : m_end_pos)
{
    if (default_bit_value)
    {
        throw std::runtime_error("Cannot iterate over infinite set.");
    }
    if (begin && m_pos != m_end_pos)
    {
        // Operator::block_msb_one
        if ((num_blocks > 0) && ((m_blocks[0] & 1) == 0))
        {
            // The first bit is not set, so we need to find it
            next_set_bit();
        }
        else if (num_blocks == 0)
        {
            m_pos = m_end_pos;
        }
        else
        {
            // The first bit is set, advance by 1 manually
            m_pos = 0;
            m_bit_index = 0;
            m_cur_block >>= 1;
        }
    }
}

template<IsUnsignedIntegral Block>
size_t BitsetUtils::ConstIterator<Block>::ConstIterator::operator*() const
{
    // Do not allow interpreting end as position.
    assert(m_pos < m_end_pos);
    return m_pos;
}

template<IsUnsignedIntegral Block>
BitsetUtils::ConstIterator<Block>& BitsetUtils::ConstIterator<Block>::operator++()
{
    next_set_bit();
    return *this;
}

template<IsUnsignedIntegral Block>
BitsetUtils::ConstIterator<Block> BitsetUtils::ConstIterator<Block>::operator++(int)
{
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsUnsignedIntegral Block>
bool BitsetUtils::ConstIterator<Block>::ConstIterator::operator==(const ConstIterator& other) const
{
    return m_pos == other.m_pos;
}

template<IsUnsignedIntegral Block>
bool BitsetUtils::ConstIterator<Block>::ConstIterator::operator!=(const ConstIterator& other) const
{
    return !(*this == other);
}

template<IsUnsignedIntegral Block>
size_t BitsetUtils::get_lsb_position(Block n) noexcept
{
    assert(n != 0);
    const Block v = n & (-n);
    return std::bit_width(v) - 1;  // bit_width uses more efficient specialized cpu instructions
}

template<IsUnsignedIntegral Block>
size_t BitsetUtils::get_index(size_t position) noexcept
{
    return position / block_size<Block>;
}

template<IsUnsignedIntegral Block>
size_t BitsetUtils::get_offset(size_t position) noexcept
{
    return position % block_size<Block>;
}

/* Builder */

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::finish_impl()
{
    this->finish(0, m_buffer);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Builder<Bitset<Block, Tag>>::finish_impl(size_t pos, ByteBuffer& out)
{
    /* Write the default_bit_value. */
    out.write(pos + BitsetLayout::default_bit_value_position, m_default_bit_value);
    out.write_padding(pos + BitsetLayout::default_bit_value_end, BitsetLayout::default_bit_value_padding);

    size_t data_pos = BitsetLayout::blocks_position;

    /* Write the blocks inline because there is no other data. */
    data_pos += m_blocks.finish(pos + data_pos, out);

    /* Write the final padding. */
    data_pos += m_buffer.write_padding(pos + data_pos, calculate_amount_padding(data_pos, BitsetLayout::final_alignment));

    /* Write the size of the buffer to the beginning. */
    out.write(pos + BitsetLayout::buffer_size_position, static_cast<BufferSizeType>(data_pos));
    out.set_size(data_pos);

    return data_pos;
}

template<IsUnsignedIntegral Block, typename Tag>
auto& Builder<Bitset<Block, Tag>>::get_buffer_impl()
{
    return m_buffer;
}
template<IsUnsignedIntegral Block, typename Tag>
const auto& Builder<Bitset<Block, Tag>>::get_buffer_impl() const
{
    return m_buffer;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
void Builder<Bitset<Block, Tag>>::resize_to_fit(const Other& other)
{
    if (m_blocks.size() < other.get_blocks().size())
    {
        m_blocks.resize(other.get_blocks().size(), m_default_bit_value ? BitsetUtils::block_ones<Block> : BitsetUtils::block_zeroes<Block>);
    }
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
void Builder<Bitset<Block, Tag>>::init_from_view(const Other& other)
{
    m_default_bit_value = other.get_default_bit_value();
    const auto& other_blocks = other.get_blocks();
    m_blocks.resize(other_blocks.size());
    for (size_t i = 0; i < other_blocks.size(); ++i)
    {
        m_blocks[i] = other_blocks[i];
    }
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder() : Builder(0)
{
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder(std::size_t size) :
    m_default_bit_value(false),
    m_blocks((size + BitsetUtils::block_size<Block> - 1) / (BitsetUtils::block_size<Block>), BitsetUtils::block_zeroes<Block>)
{
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder(std::size_t size, bool default_bit_value) :
    m_default_bit_value(default_bit_value),
    m_blocks((size + BitsetUtils::block_size<Block> - 1) / (BitsetUtils::block_size<Block>),
             default_bit_value ? BitsetUtils::block_ones<Block> : BitsetUtils::block_zeroes<Block>)
{
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder(const BitsetView& other)
{
    init_from_view(other);
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder(const BitsetConstView& other)
{
    init_from_view(other);
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator=(const BitsetView& other)
{
    init_from_view(other);
    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator=(const BitsetConstView& other)
{
    init_from_view(other);
    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::shrink_to_fit()
{
    int32_t last_non_default_block_index = m_blocks.size() - 1;

    const Block default_block = m_default_bit_value ? BitsetUtils::block_ones<Block> : BitsetUtils::block_zeroes<Block>;

    for (; last_non_default_block_index >= 0; --last_non_default_block_index)
    {
        if (m_blocks[last_non_default_block_index] != default_block)
        {
            break;
        }
    }

    m_blocks.resize(last_non_default_block_index + 1);
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::set(std::size_t position)
{
    const std::size_t index = BitsetUtils::get_index<Block>(position);
    const std::size_t offset = BitsetUtils::get_offset<Block>(position);

    if (index >= m_blocks.size())
    {
        m_blocks.resize(index + 1, m_default_bit_value ? BitsetUtils::block_ones<Block> : BitsetUtils::block_zeroes<Block>);
    }

    m_blocks[index] |= (static_cast<Block>(1) << offset);  // Set the bit at the offset
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::unset(std::size_t position)
{
    const std::size_t index = BitsetUtils::get_index<Block>(position);
    const std::size_t offset = BitsetUtils::get_offset<Block>(position);

    if (index >= m_blocks.size())
    {
        m_blocks.resize(index + 1, m_default_bit_value ? BitsetUtils::block_ones<Block> : BitsetUtils::block_zeroes<Block>);
    }

    m_blocks[index] &= ~(static_cast<Block>(1) << offset);  // Set the bit at the offset
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::unset_all()
{
    m_blocks.clear();
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator~()
{
    m_default_bit_value = !m_default_bit_value;

    for (Block& value : m_blocks)
    {
        value = ~value;
    }

    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>> Builder<Bitset<Block, Tag>>::operator|(const Other& other) const
{
    auto result = Builder<Bitset<Block, Tag>>(*this);
    result |= other;

    return result;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator|=(const Other& other)
{
    // Fetch data
    const auto& other_blocks = other.get_blocks();
    bool other_default_bit_value = other.get_default_bit_value();

    // Update default bit value
    m_default_bit_value |= other_default_bit_value;

    // Update blocks
    resize_to_fit(other);
    // Other blocks might still be smaller which is fine
    assert(other_blocks.size() <= m_blocks.size());

    // Since other is potentially smaller, it acts as termination conditions
    auto it = m_blocks.begin();
    auto other_it = other_blocks.begin();
    for (; other_it != other_blocks.end(); ++it, ++other_it)
    {
        *it |= *other_it;
    }

    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>> Builder<Bitset<Block, Tag>>::operator&(const Other& other) const
{
    auto result = Builder<Bitset<Block, Tag>>(*this);
    result &= other;

    return result;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator&=(const Other& other)
{
    // Fetch data
    const auto& other_blocks = other.get_blocks();
    bool other_default_bit_value = other.get_default_bit_value();

    // Update default bit value
    m_default_bit_value &= other_default_bit_value;

    // Update blocks
    resize_to_fit(other);
    // Other blocks might still be smaller which is fine
    assert(other_blocks.size() <= m_blocks.size());

    auto it = m_blocks.begin();
    auto other_it = other_blocks.begin();
    for (; other_it != other_blocks.end(); ++it, ++other_it)
    {
        *it &= *other_it;
    }
    // Shrink to size of other since those bits should become default valued
    m_blocks.resize(other_blocks.size());

    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>> Builder<Bitset<Block, Tag>>::operator-(const Other& other) const
{
    auto result = Builder<Bitset<Block, Tag>>(*this);
    result -= other;

    return result;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
Builder<Bitset<Block, Tag>>& Builder<Bitset<Block, Tag>>::operator-=(const Other& other)
{
    // Fetch data
    const auto& other_blocks = other.get_blocks();
    bool other_default_bit_value = other.get_default_bit_value();

    // Update default bit value
    m_default_bit_value &= !other_default_bit_value;

    // Update blocks
    resize_to_fit(other);
    // Other blocks might still be smaller which is fine
    assert(other_blocks.size() <= m_blocks.size());

    auto it = m_blocks.begin();
    auto other_it = other_blocks.begin();
    for (; other_it != other_blocks.end(); ++it, ++other_it)
    {
        *it &= ~(*other_it);
    }
    // The remaining blocks stay the same.

    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool Builder<Bitset<Block, Tag>>::is_superseteq(const B& other) const
{
    return BitsetUtils::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool Builder<Bitset<Block, Tag>>::are_disjoint(const B& other) const
{
    return BitsetUtils::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
bool Builder<Bitset<Block, Tag>>::get(std::size_t position) const
{
    const std::size_t index = BitsetUtils::get_index<Block>(position);

    if (index < m_blocks.size())
    {
        const std::size_t offset = BitsetUtils::get_offset<Block>(position);
        return (m_blocks[index] & (static_cast<Block>(1) << offset)) != 0;
    }
    else
    {
        return m_default_bit_value;
    }
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Builder<Bitset<Block, Tag>>::count() const
{
    return BitsetUtils::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
std::size_t Builder<Bitset<Block, Tag>>::next_set_bit(std::size_t position) const
{
    std::size_t index = BitsetUtils::get_index<Block>(position);
    std::size_t offset = BitsetUtils::get_offset<Block>(position);

    for (auto iter = m_blocks.begin() + index; iter < m_blocks.end(); ++iter)
    {
        // Shift so that we start checking from the offset
        const Block value = *iter >> offset;

        if (value)
        {
            // If there are set bits in the current value
            const auto lsb_position = BitsetUtils::get_lsb_position<Block>(value);
            return index * BitsetUtils::block_size<Block> + offset + lsb_position;
        }

        // Reset offset for the next value
        offset = 0;
    }

    return BitsetUtils::no_position;
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::ConstIterator Builder<Bitset<Block, Tag>>::begin() const
{
    return ConstIterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::ConstIterator Builder<Bitset<Block, Tag>>::end() const
{
    return ConstIterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
bool& Builder<Bitset<Block, Tag>>::get_default_bit_value()
{
    return m_default_bit_value;
}

template<IsUnsignedIntegral Block, typename Tag>
bool Builder<Bitset<Block, Tag>>::get_default_bit_value() const
{
    return m_default_bit_value;
}

template<IsUnsignedIntegral Block, typename Tag>
auto& Builder<Bitset<Block, Tag>>::get_blocks()
{
    return m_blocks;
}

template<IsUnsignedIntegral Block, typename Tag>
const auto& Builder<Bitset<Block, Tag>>::get_blocks() const
{
    return m_blocks;
}

/* View */

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::View(uint8_t* buf) : m_buf(buf)
{
    assert(m_buf);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool View<Bitset<Block, Tag>>::is_superseteq(const B& other) const
{
    return BitsetUtils::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool View<Bitset<Block, Tag>>::are_disjoint(const B& other) const
{
    return BitsetUtils::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
bool View<Bitset<Block, Tag>>::get(std::size_t position) const
{
    assert(m_buf);
    return BitsetUtils::get(*this, position);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t View<Bitset<Block, Tag>>::count() const
{
    assert(m_buf);
    return BitsetUtils::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::ConstIterator View<Bitset<Block, Tag>>::begin()
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::ConstIterator View<Bitset<Block, Tag>>::begin() const
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::ConstIterator View<Bitset<Block, Tag>>::end()
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::ConstIterator View<Bitset<Block, Tag>>::end() const
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
uint8_t* View<Bitset<Block, Tag>>::buffer()
{
    return m_buf;
}

template<IsUnsignedIntegral Block, typename Tag>
const uint8_t* View<Bitset<Block, Tag>>::buffer() const
{
    return m_buf;
}

template<IsUnsignedIntegral Block, typename Tag>
BufferSizeType View<Bitset<Block, Tag>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<BufferSizeType>(m_buf + BitsetLayout::buffer_size_position));
    return read_value<BufferSizeType>(m_buf + BitsetLayout::buffer_size_position);
}

template<IsUnsignedIntegral Block, typename Tag>
bool& View<Bitset<Block, Tag>>::get_default_bit_value()
{
    assert(m_buf);
    assert(test_correct_alignment<bool>(m_buf + BitsetLayout::default_bit_value_position));
    return read_value<bool>(m_buf + BitsetLayout::default_bit_value_position);
}

template<IsUnsignedIntegral Block, typename Tag>
bool View<Bitset<Block, Tag>>::get_default_bit_value() const
{
    assert(m_buf);
    assert(test_correct_alignment<bool>(m_buf + BitsetLayout::default_bit_value_position));
    return read_value<bool>(m_buf + BitsetLayout::default_bit_value_position);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Vector<Block>> View<Bitset<Block, Tag>>::get_blocks()
{
    assert(m_buf);
    return View<Vector<Block>>(m_buf + BitsetLayout::blocks_position);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Vector<Block>> View<Bitset<Block, Tag>>::get_blocks() const
{
    assert(m_buf);
    return ConstView<Vector<Block>>(m_buf + BitsetLayout::blocks_position);
}

/* ConstView */

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstView(const uint8_t* data) : m_buf(data)
{
    assert(m_buf);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstView(const BitsetView& view) : m_buf(view.buffer())
{
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool ConstView<Bitset<Block, Tag>>::is_superseteq(const B& other) const
{
    return BitsetUtils::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
    requires HasBlockType<B, Block> && HasCompatibleTagType<B, Tag>
bool ConstView<Bitset<Block, Tag>>::are_disjoint(const B& other) const
{
    return BitsetUtils::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
bool ConstView<Bitset<Block, Tag>>::get(std::size_t position) const
{
    assert(m_buf);
    return BitsetUtils::get(*this, position);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t ConstView<Bitset<Block, Tag>>::count() const
{
    assert(m_buf);
    return BitsetUtils::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstIterator ConstView<Bitset<Block, Tag>>::begin()
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstIterator ConstView<Bitset<Block, Tag>>::begin() const
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstIterator ConstView<Bitset<Block, Tag>>::end()
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::ConstIterator ConstView<Bitset<Block, Tag>>::end() const
{
    return ConstIterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
const uint8_t* ConstView<Bitset<Block, Tag>>::buffer() const
{
    return m_buf;
}

template<IsUnsignedIntegral Block, typename Tag>
BufferSizeType ConstView<Bitset<Block, Tag>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<BufferSizeType>(m_buf + BitsetLayout::buffer_size_position));
    return read_value<BufferSizeType>(m_buf + BitsetLayout::buffer_size_position);
}

template<IsUnsignedIntegral Block, typename Tag>
bool ConstView<Bitset<Block, Tag>>::get_default_bit_value()
{
    assert(m_buf);
    assert(test_correct_alignment<bool>(m_buf + BitsetLayout::default_bit_value_position));
    return read_value<bool>(m_buf + BitsetLayout::default_bit_value_position);
}

template<IsUnsignedIntegral Block, typename Tag>
bool ConstView<Bitset<Block, Tag>>::get_default_bit_value() const
{
    assert(m_buf);
    assert(test_correct_alignment<bool>(m_buf + BitsetLayout::default_bit_value_position));
    return read_value<bool>(m_buf + BitsetLayout::default_bit_value_position);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Vector<Block>> ConstView<Bitset<Block, Tag>>::get_blocks()
{
    assert(m_buf);
    return ConstView<Vector<Block>>(m_buf + BitsetLayout::blocks_position);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Vector<Block>> ConstView<Bitset<Block, Tag>>::get_blocks() const
{
    assert(m_buf);
    return ConstView<Vector<Block>>(m_buf + BitsetLayout::blocks_position);
}

/* Free function operators */

template<IsBitset B>
bool operator==(const B& lhs, const B& rhs)
{
    if (&lhs != &rhs)
    {
        // Fetch data
        const auto& blocks = lhs.get_blocks();
        bool default_bit_value = lhs.get_default_bit_value();
        const auto& other_blocks = rhs.get_blocks();
        bool other_default_bit_value = rhs.get_default_bit_value();

        std::size_t common_size = std::min(blocks.size(), other_blocks.size());
        if (std::memcmp(blocks.data(), other_blocks.data(), common_size * sizeof(typename B::BlockType)) != 0)
            return false;

        std::size_t max_size = std::max(blocks.size(), other_blocks.size());

        for (std::size_t index = common_size; index < max_size; ++index)
        {
            auto this_value = index < blocks.size() ?
                                  blocks[index] :
                                  (default_bit_value ? BitsetUtils::block_ones<typename B::BlockType> : BitsetUtils::block_zeroes<typename B::BlockType>);
            auto other_value = index < other_blocks.size() ? other_blocks[index] :
                                                             (other_default_bit_value ? BitsetUtils::block_ones<typename B::BlockType> :
                                                                                        BitsetUtils::block_zeroes<typename B::BlockType>);

            if (this_value != other_value)
            {
                return false;
            }
        }

        return true;
    }

    return true;
}

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool operator==(const B1& lhs, const B2& rhs)
{
    // Fetch data
    const auto& blocks = lhs.get_blocks();
    bool default_bit_value = lhs.get_default_bit_value();
    const auto& other_blocks = rhs.get_blocks();
    bool other_default_bit_value = rhs.get_default_bit_value();

    std::size_t common_size = std::min(blocks.size(), other_blocks.size());
    if (std::memcmp(blocks.data(), other_blocks.data(), common_size * sizeof(typename B1::BlockType)) != 0)
        return false;

    std::size_t max_size = std::max(blocks.size(), other_blocks.size());

    for (std::size_t index = common_size; index < max_size; ++index)
    {
        auto this_value = index < blocks.size() ?
                              blocks[index] :
                              (default_bit_value ? BitsetUtils::block_ones<typename B1::BlockType> : BitsetUtils::block_zeroes<typename B1::BlockType>);
        auto other_value = index < other_blocks.size() ?
                               other_blocks[index] :
                               (other_default_bit_value ? BitsetUtils::block_ones<typename B1::BlockType> : BitsetUtils::block_zeroes<typename B1::BlockType>);

        if (this_value != other_value)
        {
            return false;
        }
    }

    return true;
}

template<IsBitset B>
bool operator!=(const B& lhs, const B& rhs)
{
    return !(lhs == rhs);
}

template<IsBitset B1, IsBitset B2>
    requires HaveSameBlockType<B1, B2> && HaveCompatibleTagType<B1, B2>
bool operator!=(const B1& lhs, const B2& rhs)
{
    return !(lhs == rhs);
}

template<IsBitset B>
Builder<Bitset<typename B::BlockType, typename B::TagType>> operator~(const B& element)
{
    Builder<Bitset<typename B::BlockType, typename B::TagType>> result(element);
    ~result;
    return result;
}

/**
 * Static assertions
 */

static_assert(std::ranges::forward_range<Builder<Bitset<uint64_t>>>);
static_assert(std::ranges::forward_range<View<Bitset<uint64_t>>>);
static_assert(std::ranges::forward_range<ConstView<Bitset<uint64_t>>>);

static_assert(HaveSameBlockType<Builder<Bitset<uint64_t>>, Builder<Bitset<uint64_t>>>);
static_assert(!HaveSameBlockType<Builder<Bitset<uint64_t>>, Builder<Bitset<uint32_t>>>);

static_assert(HaveSameBlockType<Builder<Bitset<uint64_t>>, View<Bitset<uint64_t>>>);
static_assert(!HaveSameBlockType<Builder<Bitset<uint64_t>>, View<Bitset<uint32_t>>>);

struct Tag1
{
};
struct Tag2
{
};
static_assert(HaveCompatibleTagType<Builder<Bitset<uint64_t, Tag1>>, Builder<Bitset<uint64_t, Tag1>>>);
static_assert(!HaveCompatibleTagType<Builder<Bitset<uint64_t, Tag1>>, Builder<Bitset<uint64_t, Tag2>>>);

static_assert(HaveCompatibleTagType<Builder<Bitset<uint64_t, Tag1>>, View<Bitset<uint64_t, Tag1>>>);
static_assert(!HaveCompatibleTagType<Builder<Bitset<uint64_t, Tag1>>, View<Bitset<uint64_t, Tag2>>>);

/**
 * Pretty printing
 */

template<flatmemory::IsUnsignedIntegral Block, typename Tag>
std::ostream& operator<<(std::ostream& out, ConstView<Bitset<Block, Tag>> element)
{
    auto formatter = Formatter(0, 4);
    formatter.write(element, out);
    return out;
}
}

/**
 * Hashing
 */

template<flatmemory::IsBitset B>
struct std::hash<B>
{
    size_t operator()(const B& bitset) const
    {
        // Fetch data
        const bool default_bit_value = bitset.get_default_bit_value();
        const auto& blocks = bitset.get_blocks();

        const auto default_block =
            default_bit_value ? flatmemory::BitsetUtils::block_ones<typename B::BlockType> : flatmemory::BitsetUtils::block_zeroes<typename B::BlockType>;
        const auto seed = static_cast<uint32_t>(default_block);

        // Find the last block that differs from the default block
        auto last_relevant_index = static_cast<int64_t>(blocks.size()) - 1;
        for (; (last_relevant_index >= 0) && (blocks[last_relevant_index] == default_block); --last_relevant_index) {}
        const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(typename B::BlockType);

        // Compute a hash value up to and including this block
        int64_t hash[2] = { 0, 0 };
        flatmemory::MurmurHash3_x64_128(blocks.data(), length, seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

#endif
