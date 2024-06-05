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

#ifndef FLATMEMORY_LAYOUT_UTILS_HPP_
#define FLATMEMORY_LAYOUT_UTILS_HPP_

#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace flatmemory
{
/**
 * Common data types
 */
using offset_type = uint32_t;

using buffer_size_type = uint32_t;

/**
 * Compute padding needed to store an object with given alignment factor from the given position.
 */
inline constexpr size_t calculate_amount_padding(size_t pos, size_t align_factor) { return (align_factor - (pos % align_factor)) % align_factor; }

/**
 * Compute alignment of header related information of type T
 */
template<typename T>
inline consteval size_t calculate_header_alignment()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return alignof(T);
    }
    else
    {
        return alignof(offset_type);
    }
}

/**
 * Compute alignment of data related information of type T
 */
template<typename T>
inline consteval size_t calculate_data_alignment()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return alignof(T);
    }
    else
    {
        return Layout<T>::final_alignment;
    }
}

/**
 * Compute final alignment needed for a non-trivial type T.
 */
template<typename T>
inline consteval size_t calculate_final_alignment_helper()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return alignof(T);
    }
    else
    {
        return std::max(Layout<T>::final_alignment, alignof(offset_type));
    }
}
template<typename... Ts>
inline consteval size_t calculate_final_alignment()
{
    size_t max_alignment = 0;
    ((max_alignment = std::max(max_alignment, calculate_final_alignment_helper<Ts>())), ...);
    return std::max(static_cast<size_t>(1), max_alignment);
}
}

#endif
