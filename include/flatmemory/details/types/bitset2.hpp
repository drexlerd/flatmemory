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

#ifndef FLATMEMORY_TYPES_BITSET2_HPP_
#define FLATMEMORY_TYPES_BITSET2_HPP_

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/flexbuffer_utils.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"
#include "flatmemory/details/types/vector2.hpp"

#include <algorithm>
#include <cassert>
#include <flatbuffers/flexbuffers.h>
#include <iostream>
#include <ranges>
#include <vector>

namespace flatmemory
{
/**
 * ID class for non-trivial tuple type.
 */
template<IsUnsignedIntegral Block, typename Tag>
struct Bitset2 : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Bitset2(const Bitset2& other) {}
};

template<IsUnsignedIntegral Block, typename Tag>
class Builder<Bitset2<Block, Tag>> : public IBuilder<Builder<Bitset<Block, Tag>>>
{
public:
    /**
     * Constructors
     */

    Builder() : m_default_bit_value(false), m_blocks(), m_fbb() {}
    Builder(std::size_t size) : m_default_bit_value(false), m_blocks(size), m_fbb() {}
    Builder(std::size_t size, bool default_bit_value) : m_default_bit_value(default_bit_value), m_blocks(size), m_fbb() {}
    Builder(const Builder& other) = default;
    Builder& operator=(const Builder& other) = default;
    Builder(Builder&& other) noexcept = default;
    Builder& operator=(Builder&& other) noexcept = default;

    void finish()
    {
        m_fbb.Clear();
        finish(m_fbb);
        m_fbb.Finish();
    }
    void finish(flexbuffers::Builder& out)
    {
        out.Vector(
            [this, &out]()
            {
                serialize_scalar_value(m_default_bit_value, out);

                m_blocks.finish(out);
            });
    }

    const std::vector<uint8_t>& get_buffer() const { return m_fbb.GetBuffer(); }

private:
    // nested elements
    bool m_default_bit_value;
    Builder<Vector2<Block, true>> m_blocks;

    // buffer
    flexbuffers::Builder m_fbb;
};

/**
 * View
 */

template<IsUnsignedIntegral Block, typename Tag>
class View<Bitset2<Block, Tag>>
{
public:
private:
    flexbuffers::Vector m_reference;
};

/**
 * ConstView
 */

template<IsUnsignedIntegral Block, typename Tag>
class ConstView<Bitset2<Block, Tag>>
{
public:
private:
    flexbuffers::Vector m_reference;
};

}

#endif