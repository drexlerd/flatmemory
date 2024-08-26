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

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/flexbuffer_utils.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"
#include "flatmemory/details/types/vector.hpp"

#include <algorithm>
#include <cassert>
#include <flatbuffers/flexbuffers.h>
#include <iostream>
#include <ranges>
#include <vector>

namespace flatmemory
{
/**
 * ID class for non-trivial bitset type.
 */
template<IsUnsignedIntegral Block, typename Tag>
struct Bitset : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Bitset(const Bitset& other) {}
};

template<IsUnsignedIntegral Block, typename Tag>
class Builder<Bitset<Block, Tag>> : public IBuilder<Builder<Bitset<Block, Tag>>>
{
public:
    using BlockType = Block;
    using TagType = Tag;

    /**
     * Constructors
     */

    Builder() : m_default_bit_value(false), m_blocks(), m_fbb() {}
    Builder(std::size_t size) : m_default_bit_value(false), m_blocks(size), m_fbb() {}
    Builder(std::size_t size, bool default_bit_value) : m_default_bit_value(default_bit_value), m_blocks(size), m_fbb() {}
    Builder(const Builder& other) = delete;
    Builder& operator=(const Builder& other) = delete;
    Builder(Builder&& other) noexcept = default;
    Builder& operator=(Builder&& other) noexcept = default;

    /**
     * Getters
     */

    Builder<Vector<Block, true>>& get_blocks() { return m_blocks; }
    const Builder<Vector<Block, true>>& get_blocks() const { return m_blocks; }

    bool& get_default_bit_value() { return m_default_bit_value; }
    bool get_default_bit_value() const { return m_default_bit_value; }

private:
    void finish_impl()
    {
        m_fbb.Clear();
        this->finish(m_fbb);
        m_fbb.Finish();
    }
    void finish_impl(flexbuffers::Builder& out) const
    {
        out.Vector(
            [this, &out]()
            {
                serialize_scalar_value(m_default_bit_value, out);

                m_blocks.finish(out);
            });
    }

    const std::vector<uint8_t>& get_buffer_impl() const { return m_fbb.GetBuffer(); }

    friend class IBuilder<Builder<Bitset<Block, Tag>>>;

private:
    // nested elements
    bool m_default_bit_value;
    Builder<Vector<Block, true>> m_blocks;

    // buffer
    flexbuffers::Builder m_fbb;
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

    /**
     * Constructors
     */

    View(const uint8_t* buffer, size_t size) : View(flexbuffers::GetRoot(buffer, size)) {}
    View(flexbuffers::Reference reference) : m_data(reference.AsVector()) {}

    /**
     * Getters
     */

    View<Vector<Block, true>> get_blocks() { return View<Vector<Block, true>>(m_data[1]); }
    ConstView<Vector<Block, true>> get_blocks() const { return ConstView<Vector<Block, true>>(m_data[1]); }

    bool get_default_bit_value() const { return retrieve_scalar_value<bool>(m_data[0]); }

    /**
     * Mutations
     */

    void set_default_bit_value(bool default_bit_value) { mutate_scalar_value(default_bit_value, m_data[0]); }

private:
    flexbuffers::Vector m_data;
};

static_assert(sizeof(ConstView<Bitset<uint64_t, void>>) == 24);

/**
 * ConstView
 */

template<IsUnsignedIntegral Block, typename Tag>
class ConstView<Bitset<Block, Tag>>
{
public:
    using BlockType = Block;
    using TagType = Tag;

    /**
     * Constructors
     */

    ConstView(const uint8_t* buffer, size_t size) : ConstView(flexbuffers::GetRoot(buffer, size)) {}
    ConstView(flexbuffers::Reference reference) : m_data(reference.AsVector()) {}

    /**
     * Getters
     */

    View<Vector<Block, true>> get_blocks();
    ConstView<Vector<Block, true>> get_blocks() const;

    bool get_default_bit_value() const;

private:
    flexbuffers::Vector m_data;
};

}

#endif