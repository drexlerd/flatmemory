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
#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/operator.hpp"
#include "flatmemory/details/types/vector.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <iostream>
#include <ranges>

namespace flatmemory
{
/**
 * Dispatcher for Bitset.
 * The optional tag can be used to disallow operations between bitsets have similar tag.
 */

template<IsUnsignedIntegral Block, typename Tag = void>
struct Bitset : public Custom
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
    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, bool, Vector<Block>>();

    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
    static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_header_alignment<bool>());
    static constexpr size_t default_bit_value_position = buffer_size_end + buffer_size_padding;
    static constexpr size_t default_bit_value_end = default_bit_value_position + sizeof(bool);
    static constexpr size_t default_bit_value_padding = calculate_amount_padding(default_bit_value_end, calculate_data_alignment<Vector<Block>>());
    static constexpr size_t blocks_position = default_bit_value_end + default_bit_value_padding;

    void print() const;
};

/**
 * Forward declarations
 */

template<IsUnsignedIntegral Block, typename Tag>
class View<Bitset<Block, Tag>>;

template<IsUnsignedIntegral Block, typename Tag>
class ConstView<Bitset<Block, Tag>>;

template<IsUnsignedIntegral Block, typename Tag>
class Builder<Bitset<Block, Tag>>;

/**
 * Concepts
 */

/// @brief Concept to check if two types `T1` and `T2` have the same Block type.
template<typename T1, typename T2>
concept HaveSameBlockType = std::is_same_v<typename T1::BlockType, typename T2::BlockType>;

/// @brief Concept to check if two types have a compatible `Tag`,
/// i.e., either one is void or both are the same.
template<typename T1, typename T2>
concept HaveCompatibleTagType =
    std::is_same_v<typename T1::TagType, typename T2::TagType> || std::is_same_v<typename T1::TagType, void> || std::is_same_v<typename T2::TagType, void>;

/// @brief Concept to check the `Block` type of another bitset
/// is compatible with the block type of the bitset of type `T`, i.e.,
/// the block types are the same.
template<typename T, typename Block>
concept HasBlockType = std::is_same_v<typename T::BlockType, Block>;

/// @brief Concept to check whether the `Tag` type of another bitset
/// is compatible with the tag type of the bitset of type `T`,
/// i.e., either one is void or both are the same.
template<typename T, typename Tag>
concept HasCompatibleTagType = std::is_same_v<typename T::TagType, Tag> || std::is_same_v<Tag, void> || std::is_same_v<typename T::TagType, void>;

/// @brief Concept for user define bitsets based on the STL
template<typename T>
concept IsUserDefinedBitset = requires(T a, const T b) {
    /* Common */

    requires IsIntegral<typename T::BlockType>;

    /* Non const version*/

    {
        a.get_default_bit_value()
    } -> std::same_as<bool&>;
    {
        a.get_blocks()
    } -> std::same_as<std::vector<typename T::BlockType>&>;

    /* Const version */

    {
        b.get_default_bit_value()
    } -> std::same_as<bool>;
    {
        b.get_blocks()
    } -> std::same_as<const std::vector<typename T::BlockType>&>;
};

/// @brief Concept for Builder
template<typename T>
concept IsBitsetBuilder = requires(T a, const T b) {
    /* Common */

    requires IsIntegral<typename T::BlockType>;
    typename T::TagType;

    /* Non const version*/

    {
        a.get_default_bit_value()
    } -> std::same_as<bool&>;
    {
        a.get_blocks()
    } -> std::same_as<Builder<Vector<typename T::BlockType>>&>;

    /* Const version */

    {
        b.get_default_bit_value()
    } -> std::same_as<bool>;
    {
        b.get_blocks()
    } -> std::same_as<const Builder<Vector<typename T::BlockType>>&>;
};

/// @brief Concept for View
template<typename T>
concept IsBitsetView = requires(T a, const T b) {
    /* Common */

    requires IsIntegral<typename T::BlockType>;
    typename T::TagType;

    /* Non const version*/

    {
        a.get_default_bit_value()
    } -> std::same_as<bool&>;
    {
        a.get_blocks()
    } -> std::same_as<View<Vector<typename T::BlockType>>>;

    /* Const version */

    {
        b.get_default_bit_value()
    } -> std::same_as<bool>;
    {
        b.get_blocks()
    } -> std::same_as<ConstView<Vector<typename T::BlockType>>>;
};

/// @brief Concept for ConstView
template<typename T>
concept IsBitsetConstView = requires(T a, const T b) {
    /* Common */

    requires IsIntegral<typename T::BlockType>;
    typename T::TagType;

    /* Non const version*/

    {
        a.get_default_bit_value()
    } -> std::same_as<bool>;
    {
        a.get_blocks()
    } -> std::same_as<ConstView<Vector<typename T::BlockType>>>;

    /* Const version */

    {
        b.get_default_bit_value()
    } -> std::same_as<bool>;
    {
        b.get_blocks()
    } -> std::same_as<ConstView<Vector<typename T::BlockType>>>;
};

/// @brief Concept for Bitset
template<typename T>
concept IsBitset = IsUserDefinedBitset<T> || IsBitsetBuilder<T> || IsBitsetView<T> || IsBitsetConstView<T>;

/**
 * Operator
 */
template<IsUnsignedIntegral Block, typename Tag>
class Operator<Bitset<Block, Tag>>
{
public:
    static constexpr std::size_t block_size = sizeof(Block) * 8;
    // 000...
    static constexpr Block block_zeroes = 0;
    // 111...
    static constexpr Block block_ones = Block(-1);
    // 100...
    static constexpr Block block_msb_one = Block(1) << (block_size - 1);
    // 011...
    static constexpr Block block_msb_zero = block_ones & (~block_msb_one);
    // 111...
    static constexpr std::size_t no_position = std::size_t(-1);

    /**
     * Operators
     */
    template<IsBitset L, IsBitset R>
        requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
    static bool are_equal(const L& left_bitset, const R& right_bitset);

    template<IsBitset L, IsBitset R>
        requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
    static bool less(const L& left_bitset, const R& right_bitset);

    template<IsBitset L, IsBitset R>
        requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
    static bool is_superseteq(const L& left_bitset, const R& right_bitset);

    template<IsBitset L, IsBitset R>
        requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
    static bool are_disjoint(const L& left_bitset, const R& right_bitset);

    /**
     * Helpers
     */

    static int64_t find_last_relevant_block(const std::vector<Block>& blocks, bool default_bit_value);

    /**
     * Hashing
     */

    template<IsBitset B>
    static size_t hash(const B& bitset);

    /**
     * Lookup
     */

    template<IsBitset B>
    static bool get(const B& bitset, std::size_t position);

    /// @brief Return the number of set bits.
    template<IsBitset B>
    static size_t count(const B& bitset);

    /**
     * Iterators
     */

    class const_iterator
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

        const_iterator();
        const_iterator(bool default_bit_value, const Block* blocks, size_t num_blocks, bool begin);
        size_t operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };

    /**
     * Math
     */

    static size_t get_lsb_position(Block n) noexcept;

    static size_t get_index(size_t position) noexcept;

    static size_t get_offset(size_t position) noexcept;
};

/**
 * View
 */
template<IsUnsignedIntegral Block, typename Tag>
class View<Bitset<Block, Tag>>
{
public:
    using BlockType = Block;
    using TagType = Tag;

    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetOperator = Operator<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using const_iterator = typename BitsetOperator::const_iterator;

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
    explicit View(uint8_t* buf);

    /**
     * Operators
     */

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator==(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator!=(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool is_superseteq(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool are_disjoint(const Other& other) const;

    /**
     * Lookup
     */

    bool get(std::size_t position) const;

    size_t count() const;

    /**
     * Iterators
     */

    const_iterator begin();
    const_iterator begin() const;
    const_iterator end();
    const_iterator end() const;

    /**
     * Hashing
     */

    size_t hash() const;

    /**
     * Getters
     */
    uint8_t* buffer();
    const uint8_t* buffer() const;
    buffer_size_type buffer_size() const;

    bool& get_default_bit_value();
    bool get_default_bit_value() const;

    View<Vector<Block>> get_blocks();
    ConstView<Vector<Block>> get_blocks() const;
};

/**
 * ConstView
 */
template<IsUnsignedIntegral Block, typename Tag>
class ConstView<Bitset<Block, Tag>>
{
public:
    using BlockType = Block;
    using TagType = Tag;

    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetOperator = Operator<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using const_iterator = typename BitsetOperator::const_iterator;

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
    ConstView(const uint8_t* data);

    /**
     * Conversion constructor
     */
    ConstView(const BitsetView& view);

    /**
     * Operators
     */

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator==(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator!=(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool is_superseteq(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool are_disjoint(const Other& other) const;

    /**
     * Lookup
     */

    bool get(std::size_t position) const;

    size_t count() const;

    /**
     * Iterators
     */

    const_iterator begin();
    const_iterator begin() const;
    const_iterator end();
    const_iterator end() const;

    /**
     * Hashing
     */

    size_t hash() const;

    /**
     * Getters
     */

    const uint8_t* buffer() const;

    buffer_size_type buffer_size() const;

    bool get_default_bit_value();

    bool get_default_bit_value() const;

    ConstView<Vector<Block>> get_blocks();

    ConstView<Vector<Block>> get_blocks() const;
};

/**
 * Builder
 */
template<IsUnsignedIntegral Block, typename Tag>
class Builder<Bitset<Block, Tag>> : public IBuilder<Builder<Bitset<Block, Tag>>>
{
public:
    using BlockType = Block;
    using TagType = Tag;

    using BitsetOperator = Operator<Bitset<Block, Tag>>;
    using BitsetLayout = Layout<Bitset<Block, Tag>>;
    using BitsetView = View<Bitset<Block, Tag>>;
    using BitsetConstView = ConstView<Bitset<Block, Tag>>;
    using const_iterator = typename BitsetOperator::const_iterator;

private:
    bool m_default_bit_value;
    Builder<Vector<Block>> m_blocks;

    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl();
    size_t finish_impl(ByteBuffer& out, size_t pos);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    void resize_to_fit(const Other& other);

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    void init_from_view(const Other& other);

public:
    /**
     * Constructors
     */

    Builder();
    // Initialize the bitset with a certain size
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
     * Operators
     */

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator<(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator==(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool operator!=(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool is_superseteq(const Other& other) const;

    template<IsBitset Other>
        requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
    bool are_disjoint(const Other& other) const;

    /**
     * Modifiers
     */

    /// @brief Shrink the bitset to minimum number of blocks (at least 1) to represent its bits.
    void shrink_to_fit();

    // Set a bit at a specific position
    void set(std::size_t position);

    // Unset a bit at a specific position
    void unset(std::size_t position);

    // Unset all bits and shrink its size to represent the bits
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
     * Lookup
     */

    // Get the value of a bit at a specific position
    bool get(std::size_t position) const;

    size_t count() const;

    // Find the next set bit, inclusive the given position
    std::size_t next_set_bit(std::size_t position) const;

    /**
     * Iterators
     */

    const_iterator begin() const;
    const_iterator end() const;

    /**
     * Hashing
     */

    size_t hash() const;

    /**
     * Getters
     */

    bool& get_default_bit_value();
    bool get_default_bit_value() const;

    auto& get_blocks();
    const auto& get_blocks() const;
};

/**
 * Definitions
 */

// Layout

template<IsUnsignedIntegral Block, typename Tag>
void Layout<Bitset<Block, Tag>>::print() const
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

// Operator

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset L, IsBitset R>
    requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
bool Operator<Bitset<Block, Tag>>::are_equal(const L& left_bitset, const R& right_bitset)
{
    // Fetch data
    const auto& blocks = left_bitset.get_blocks();
    bool default_bit_value = left_bitset.get_default_bit_value();
    const auto& other_blocks = right_bitset.get_blocks();
    bool other_default_bit_value = right_bitset.get_default_bit_value();

    std::size_t common_size = std::min(blocks.size(), other_blocks.size());
    if (std::memcmp(blocks.data(), other_blocks.data(), common_size * sizeof(Block)) != 0)
        return false;

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

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset L, IsBitset R>
    requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
bool Operator<Bitset<Block, Tag>>::less(const L& left_bitset, const R& right_bitset)
{
    // Fetch data
    const auto& blocks = left_bitset.get_blocks();
    bool default_bit_value = left_bitset.get_default_bit_value();
    const auto& other_blocks = right_bitset.get_blocks();
    bool other_default_bit_value = right_bitset.get_default_bit_value();

    std::size_t common_size = std::min(blocks.size(), other_blocks.size());

    for (std::size_t index = 0; index < common_size; ++index)
    {
        if (blocks[index] < other_blocks[index])
        {
            return true;
        }
    }

    std::size_t max_size = std::max(blocks.size(), other_blocks.size());

    for (std::size_t index = common_size; index < max_size; ++index)
    {
        Block this_value = index < blocks.size() ? blocks[index] : (default_bit_value ? block_ones : block_zeroes);
        Block other_value = index < other_blocks.size() ? other_blocks[index] : (other_default_bit_value ? block_ones : block_zeroes);

        if (this_value < other_value)
        {
            return true;
        }
    }

    return false;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset L, IsBitset R>
    requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
bool Operator<Bitset<Block, Tag>>::is_superseteq(const L& left_bitset, const R& right_bitset)
{
    // Fetch data
    const auto& blocks = left_bitset.get_blocks();
    bool default_bit_value = left_bitset.get_default_bit_value();
    const auto& other_blocks = right_bitset.get_blocks();
    bool other_default_bit_value = right_bitset.get_default_bit_value();

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

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset L, IsBitset R>
    requires HaveSameBlockType<L, R> && HaveCompatibleTagType<L, R>
bool Operator<Bitset<Block, Tag>>::are_disjoint(const L& left_bitset, const R& right_bitset)
{
    // Fetch data
    const auto& blocks = left_bitset.get_blocks();
    bool default_bit_value = left_bitset.get_default_bit_value();
    const auto& other_blocks = right_bitset.get_blocks();
    bool other_default_bit_value = right_bitset.get_default_bit_value();

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

template<IsUnsignedIntegral Block, typename Tag>
int64_t Operator<Bitset<Block, Tag>>::find_last_relevant_block(const std::vector<Block>& blocks, bool default_bit_value)
{
    int64_t last_relevant_block_index = static_cast<int64_t>(blocks.size()) - 1;
    for (; (last_relevant_block_index >= 0) && (blocks[last_relevant_block_index] == (default_bit_value ? block_ones : block_zeroes));
         --last_relevant_block_index)
    {
    }
    return last_relevant_block_index;
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
size_t Operator<Bitset<Block, Tag>>::hash(const B& bitset)
{
    // Fetch data
    const bool default_bit_value = bitset.get_default_bit_value();
    const auto& blocks = bitset.get_blocks();

    const auto default_block = default_bit_value ? block_ones : block_zeroes;
    const auto seed = static_cast<uint32_t>(default_block);

    // Find the last block that differs from the default block
    auto last_relevant_index = static_cast<int64_t>(blocks.size()) - 1;
    for (; (last_relevant_index >= 0) && (blocks[last_relevant_index] == default_block); --last_relevant_index) {}
    const auto length = static_cast<std::size_t>(last_relevant_index + 1) * sizeof(Block);

    // Compute a hash value up to and including this block
    int64_t hash[2] = { 0, 0 };
    MurmurHash3_x64_128(blocks.data(), length, seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
bool Operator<Bitset<Block, Tag>>::get(const B& bitset, std::size_t position)
{
    {
        const std::size_t index = get_index(position);

        const auto& blocks = bitset.get_blocks();
        if (index < blocks.size())
        {
            const std::size_t offset = get_offset(position);
            return (blocks[index] & (static_cast<Block>(1) << offset)) != 0;
        }
        else
        {
            return bitset.get_default_bit_value();
        }
    }
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset B>
size_t Operator<Bitset<Block, Tag>>::count(const B& bitset)
{
    auto count = (size_t) 0;
    for (auto it = bitset.begin(); it != bitset.end(); ++it)
    {
        ++count;
    }
    return count;
}

template<IsUnsignedIntegral Block, typename Tag>
void Operator<Bitset<Block, Tag>>::const_iterator::next_set_bit()
{
    assert(m_pos != m_end_pos);
    do
    {
        // Advance position
        ++m_pos;
        ++m_bit_index;
        if (m_bit_index == Operator::block_size)
        {
            ++m_block_index;
            if (m_block_index == m_num_blocks)
            {
                // Reached end of blocks, set m_pos to end
                m_pos += Operator::block_size - 1;
                break;
            }
            m_bit_index = 0;
            m_cur_block = m_blocks[m_block_index];
        }

        if (m_cur_block)
        {
            // If there are set bits in the current value
            const auto lsb_position = get_lsb_position(m_cur_block);
            m_bit_index += lsb_position;
            m_pos += lsb_position;
            // shift by + 1 to advance further
            m_cur_block >>= lsb_position + 1;
            break;
        }
        else
        {
            // Skip the remaining bits, point to last position in the current block
            m_pos += Operator::block_size - m_bit_index - 1;
            ++m_block_index;
            m_bit_index = -1;
            // Fetch next data block or zeroes
            m_cur_block = m_block_index < m_num_blocks ? m_blocks[m_block_index] : Operator::block_zeroes;
        }
    } while (m_pos < m_end_pos);
}

template<IsUnsignedIntegral Block, typename Tag>
Operator<Bitset<Block, Tag>>::const_iterator::const_iterator() : m_blocks(nullptr), m_num_blocks(0), m_block_index(0), m_bit_index(-1)
{
}

template<IsUnsignedIntegral Block, typename Tag>
Operator<Bitset<Block, Tag>>::const_iterator::const_iterator(bool default_bit_value, const Block* blocks, size_t num_blocks, bool begin) :
    m_blocks(blocks),
    m_num_blocks(num_blocks),
    m_block_index(0),
    m_bit_index(-1),
    m_cur_block(num_blocks > 0 ? m_blocks[m_block_index] : Operator::block_zeroes),
    m_end_pos((m_num_blocks + 1) * Operator::block_size - 1),
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
        else
        {
            // The first bit is set, advance by 1 manually
            m_pos = 0;
            m_bit_index = 0;
            m_cur_block >>= 1;
        }
    }
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Operator<Bitset<Block, Tag>>::const_iterator::operator*() const
{
    // Do not allow interpreting end as position.
    assert(m_pos < m_end_pos);
    return m_pos;
}

template<IsUnsignedIntegral Block, typename Tag>
Operator<Bitset<Block, Tag>>::const_iterator& Operator<Bitset<Block, Tag>>::const_iterator::operator++()
{
    next_set_bit();
    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
Operator<Bitset<Block, Tag>>::const_iterator Operator<Bitset<Block, Tag>>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsUnsignedIntegral Block, typename Tag>
bool Operator<Bitset<Block, Tag>>::const_iterator::operator==(const const_iterator& other) const
{
    return m_pos == other.m_pos;
}

template<IsUnsignedIntegral Block, typename Tag>
bool Operator<Bitset<Block, Tag>>::const_iterator::operator!=(const const_iterator& other) const
{
    return !(*this == other);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Operator<Bitset<Block, Tag>>::get_lsb_position(Block n) noexcept
{
    assert(n != 0);
    const Block v = n & (-n);
    return std::bit_width(v) - 1;  // bit_width uses more efficient specialized cpu instructions
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Operator<Bitset<Block, Tag>>::get_index(size_t position) noexcept
{
    return position / block_size;
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Operator<Bitset<Block, Tag>>::get_offset(size_t position) noexcept
{
    return position % block_size;
}

// View

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::View(uint8_t* buf) : m_buf(buf)
{
    assert(m_buf);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool View<Bitset<Block, Tag>>::operator==(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::are_equal(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool View<Bitset<Block, Tag>>::operator!=(const Other& other) const
{
    return !(*this == other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool View<Bitset<Block, Tag>>::is_superseteq(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool View<Bitset<Block, Tag>>::are_disjoint(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
bool View<Bitset<Block, Tag>>::get(std::size_t position) const
{
    assert(m_buf);
    return BitsetOperator::get(*this, position);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t View<Bitset<Block, Tag>>::count() const
{
    assert(m_buf);
    return BitsetOperator::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::const_iterator View<Bitset<Block, Tag>>::begin()
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::const_iterator View<Bitset<Block, Tag>>::begin() const
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::const_iterator View<Bitset<Block, Tag>>::end()
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
View<Bitset<Block, Tag>>::const_iterator View<Bitset<Block, Tag>>::end() const
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t View<Bitset<Block, Tag>>::hash() const
{
    assert(m_buf);
    return BitsetOperator::hash(*this);
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
buffer_size_type View<Bitset<Block, Tag>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + BitsetLayout::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + BitsetLayout::buffer_size_position);
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

// ConstView

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
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool ConstView<Bitset<Block, Tag>>::operator==(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::are_equal(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool ConstView<Bitset<Block, Tag>>::operator!=(const Other& other) const
{
    return !(*this == other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool ConstView<Bitset<Block, Tag>>::is_superseteq(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool ConstView<Bitset<Block, Tag>>::are_disjoint(const Other& other) const
{
    assert(m_buf);
    return BitsetOperator::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
bool ConstView<Bitset<Block, Tag>>::get(std::size_t position) const
{
    assert(m_buf);
    return BitsetOperator::get(*this, position);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t ConstView<Bitset<Block, Tag>>::count() const
{
    assert(m_buf);
    return BitsetOperator::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::const_iterator ConstView<Bitset<Block, Tag>>::begin()
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::const_iterator ConstView<Bitset<Block, Tag>>::begin() const
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::const_iterator ConstView<Bitset<Block, Tag>>::end()
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
ConstView<Bitset<Block, Tag>>::const_iterator ConstView<Bitset<Block, Tag>>::end() const
{
    return const_iterator(get_default_bit_value(), get_blocks().data(), get_blocks().size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t ConstView<Bitset<Block, Tag>>::hash() const
{
    assert(m_buf);
    return BitsetOperator::hash(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
const uint8_t* ConstView<Bitset<Block, Tag>>::buffer() const
{
    return m_buf;
}

template<IsUnsignedIntegral Block, typename Tag>
buffer_size_type ConstView<Bitset<Block, Tag>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + BitsetLayout::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + BitsetLayout::buffer_size_position);
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

// Builder

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::finish_impl()
{
    this->finish(m_buffer, 0);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Builder<Bitset<Block, Tag>>::finish_impl(ByteBuffer& out, size_t pos)
{
    /* Write header info */
    // Write default_bit_value
    out.write(pos + BitsetLayout::default_bit_value_position, m_default_bit_value);
    out.write_padding(pos + BitsetLayout::default_bit_value_end, BitsetLayout::default_bit_value_padding);

    /* Write dynamic info */
    buffer_size_type buffer_size = BitsetLayout::blocks_position;

    // Write blocks
    buffer_size += m_blocks.finish(out, pos + buffer_size);
    // Write final padding
    buffer_size += m_buffer.write_padding(pos + buffer_size, calculate_amount_padding(buffer_size, BitsetLayout::final_alignment));

    /* Write buffer size */
    out.write(pos + BitsetLayout::buffer_size_position, buffer_size);
    out.set_size(buffer_size);

    return buffer_size;
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
        m_blocks.resize(other.get_blocks().size(), m_default_bit_value ? BitsetOperator::block_ones : BitsetOperator::block_zeroes);
    }

    assert(m_blocks.size() > 0);
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
    m_blocks((size / BitsetOperator::block_size) + 1, BitsetOperator::block_zeroes)
{
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::Builder(std::size_t size, bool default_bit_value) :
    m_default_bit_value(default_bit_value),
    m_blocks((size / BitsetOperator::block_size) + 1, default_bit_value ? BitsetOperator::block_ones : BitsetOperator::block_zeroes)
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
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool Builder<Bitset<Block, Tag>>::operator<(const Other& other) const
{
    return BitsetOperator::less(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool Builder<Bitset<Block, Tag>>::operator==(const Other& other) const
{
    return BitsetOperator::are_equal(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool Builder<Bitset<Block, Tag>>::operator!=(const Other& other) const
{
    return !(*this == other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool Builder<Bitset<Block, Tag>>::is_superseteq(const Other& other) const
{
    return BitsetOperator::is_superseteq(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
template<IsBitset Other>
    requires HasBlockType<Other, Block> && HasCompatibleTagType<Other, Tag>
bool Builder<Bitset<Block, Tag>>::are_disjoint(const Other& other) const
{
    return BitsetOperator::are_disjoint(*this, other);
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::shrink_to_fit()
{
    int32_t last_non_default_block_index = m_blocks.size() - 1;

    const Block default_block = m_default_bit_value ? BitsetOperator::block_ones : BitsetOperator::block_zeroes;

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
    const std::size_t index = BitsetOperator::get_index(position);
    const std::size_t offset = BitsetOperator::get_offset(position);

    if (index >= m_blocks.size())
    {
        m_blocks.resize(index + 1, m_default_bit_value ? BitsetOperator::block_ones : BitsetOperator::block_zeroes);
    }

    m_blocks[index] |= (static_cast<Block>(1) << offset);  // Set the bit at the offset
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::unset(std::size_t position)
{
    const std::size_t index = BitsetOperator::get_index(position);
    const std::size_t offset = BitsetOperator::get_offset(position);

    if (index >= m_blocks.size())
    {
        m_blocks.resize(index + 1, m_default_bit_value ? BitsetOperator::block_ones : BitsetOperator::block_zeroes);
    }

    m_blocks[index] &= ~(static_cast<Block>(1) << offset);  // Set the bit at the offset
}

template<IsUnsignedIntegral Block, typename Tag>
void Builder<Bitset<Block, Tag>>::unset_all()
{
    assert(m_blocks.size() > 0);

    m_blocks[0] = (m_default_bit_value) ? BitsetOperator::block_ones : BitsetOperator::block_zeroes;

    m_blocks.resize(1);
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

    auto it = m_blocks.begin();
    auto other_it = other_blocks.begin();
    // Since other is potentially smaller, it acts as termination conditions
    while (other_it != other_blocks.end())
    {
        *it |= *other_it;
        ++it;
        ++other_it;
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
    while (other_it != other_blocks.end())
    {
        *it &= *other_it;
        ++it;
        ++other_it;
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
    while (other_it != other_blocks.end())
    {
        *it &= ~(*other_it);
        ++it;
        ++other_it;
    }
    // The remaining blocks stay the same.

    return *this;
}

template<IsUnsignedIntegral Block, typename Tag>
bool Builder<Bitset<Block, Tag>>::get(std::size_t position) const
{
    const std::size_t index = BitsetOperator::get_index(position);

    if (index < m_blocks.size())
    {
        const std::size_t offset = BitsetOperator::get_offset(position);
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
    return BitsetOperator::count(*this);
}

template<IsUnsignedIntegral Block, typename Tag>
std::size_t Builder<Bitset<Block, Tag>>::next_set_bit(std::size_t position) const
{
    std::size_t index = BitsetOperator::get_index(position);
    std::size_t offset = BitsetOperator::get_offset(position);

    for (auto iter = m_blocks.begin() + index; iter < m_blocks.end(); ++iter)
    {
        // Shift so that we start checking from the offset
        const Block value = *iter >> offset;

        if (value)
        {
            // If there are set bits in the current value
            const auto lsb_position = BitsetOperator::get_lsb_position(value);
            return index * BitsetOperator::block_size + offset + lsb_position;
        }

        // Reset offset for the next value
        offset = 0;
    }

    return BitsetOperator::no_position;
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::const_iterator Builder<Bitset<Block, Tag>>::begin() const
{
    return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), true);
}

template<IsUnsignedIntegral Block, typename Tag>
Builder<Bitset<Block, Tag>>::const_iterator Builder<Bitset<Block, Tag>>::end() const
{
    return const_iterator(m_default_bit_value, m_blocks.data(), m_blocks.size(), false);
}

template<IsUnsignedIntegral Block, typename Tag>
size_t Builder<Bitset<Block, Tag>>::hash() const
{
    return BitsetOperator::hash(*this);
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
}

template<flatmemory::IsUnsignedIntegral Block, typename Tag>
struct std::hash<flatmemory::Builder<flatmemory::Bitset<Block, Tag>>>
{
    size_t operator()(const flatmemory::Builder<flatmemory::Bitset<Block, Tag>>& bitset) const { return bitset.hash(); }
};

template<flatmemory::IsUnsignedIntegral Block, typename Tag>
struct std::hash<flatmemory::View<flatmemory::Bitset<Block, Tag>>>
{
    size_t operator()(const flatmemory::View<flatmemory::Bitset<Block, Tag>>& bitset) const { return bitset.hash(); }
};

template<flatmemory::IsUnsignedIntegral Block, typename Tag>
struct std::hash<flatmemory::ConstView<flatmemory::Bitset<Block, Tag>>>
{
    size_t operator()(const flatmemory::ConstView<flatmemory::Bitset<Block, Tag>>& bitset) const { return bitset.hash(); }
};

#endif
