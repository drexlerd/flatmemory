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

#ifndef FLATMEMORY_BUILDER_HPP_
#define FLATMEMORY_BUILDER_HPP_

#include "flatmemory/details/concepts.hpp"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace flatmemory
{
/**
 * Forward declarations
 */
class ByteBuffer;

/**
 * Interface class.
 */
template<typename Derived>
class IBuilder
{
private:
    /// @brief Helper to cast to Derived.
    constexpr const auto& self() const { return static_cast<const Derived&>(*this); }
    constexpr auto& self() { return static_cast<Derived&>(*this); }

public:
    /// @brief Serialize data to size prefixed byte sequence into the internal buffer.
    void finish() { self().finish_impl(); }

    /// @brief Serialize data to size prefixed byte sequence into the given buffer.
    /// @param out the buffer to write the data.
    /// @param pos the next free position in the out buffer.
    /// @return the number of bytest written to out.
    size_t finish(ByteBuffer& out, size_t pos) { return self().finish_impl(out, pos); }

    /// @brief Access the serialized buffer
    auto& buffer() { return self().get_buffer_impl(); }
    const auto& buffer() const { return self().get_buffer_impl(); }
};

/**
 * Implementation class.
 *
 * Provide overload with your Tag.
 *
 * Define operations to feed data for serialization.
 */
template<typename Tag>
class Builder : IBuilder<Builder<Tag>>
{
};

/**
 * Concepts
 */
template<IsTriviallyCopyableOrCustom T, bool = IsTriviallyCopyable<T>>
struct maybe_builder
{
    using type = T;
};

template<IsTriviallyCopyableOrCustom T>
struct maybe_builder<T, false>
{
    using type = Builder<T>;
};
}

#endif
