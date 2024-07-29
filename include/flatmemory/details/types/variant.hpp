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

#ifndef FLATMEMORY_TYPES_VARIANT_HPP_
#define FLATMEMORY_TYPES_VARIANT_HPP_

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
#include <variant>

namespace flatmemory
{
/**
 * Dispatcher for Trivial.
 */
template<IsTriviallyCopyableOrCustom... Ts>
struct Variant : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Variant(const Variant& other) {}
};

/**
 * Layout
 */
template<IsTriviallyCopyableOrCustom... Ts>
class Layout<Variant<Ts...>>
{
public:
    // TODO
    // static constexpr size_t final_alignment = ;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrCustom... Ts>
class Builder<Variant<Ts...>> : public IBuilder<Builder<Variant<Ts...>>>
{
private:
    std::variant<Ts...> m_variant;

    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl()
    {
        // TODO
    }

    auto& get_buffer_impl() { return m_buffer; }
    const auto& get_buffer_impl() const { return m_buffer; }

public:
    std::variant<Ts...>& operator*() { return m_variant; }

    std::variant<Ts...>* operator->() { return &m_variant; }
};

/**
 * View
 */
template<IsTriviallyCopyableOrCustom... Ts>
class View<Variant<Ts...>>
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
    View(uint8_t* data) : m_buf(data) { assert(m_buf); }

    buffer_size_type buffer_size() const
    {
        assert(m_buf);
        return sizeof(T);
    }

    uint8_t* buffer() { return m_buf; }
    const uint8_t* buffer() const { return m_buf; }
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrCustom... Ts>
class ConstView<Variant<Ts...>>
{
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
    ConstView(const uint8_t* data) : m_buf(data) { assert(m_buf); }

    /**
     * Conversion constructor
     */
    ConstView(const View<Variant<Ts...>>& view) : m_buf(view.buffer()) {}

    buffer_size_type buffer_size() const
    {
        assert(m_buf);
        return sizeof(T);
    }

    const uint8_t* buffer() const { return m_buf; }
};
}

#endif