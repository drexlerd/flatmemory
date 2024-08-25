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

#ifndef FLATMEMORY_CONCEPTS_HPP_
#define FLATMEMORY_CONCEPTS_HPP_

#include <concepts>
#include <string>
#include <type_traits>

namespace flatmemory
{
/**
 * Base ID class for non-trivial types.
 */
struct NonTrivialType
{
};

template<typename T>
concept IsNonTrivialType = std::derived_from<T, NonTrivialType>;

template<typename T>
concept IsTriviallyCopyable = std::is_trivially_copyable_v<T>;

template<typename T>
concept IsTriviallyCopyableOrNonTrivialType = (IsTriviallyCopyable<T> || IsNonTrivialType<T>);

// Concept to check whether T is an unsigned integral
template<typename T>
concept IsUnsignedIntegral = std::is_integral_v<T> && std::is_unsigned_v<T>;

template<typename T>
concept IsTrivialFlexbufferType =
    std::same_as<int8_t, T> || std::same_as<int16_t, T> || std::same_as<int32_t, T> || std::same_as<int64_t, T> || std::same_as<uint8_t, T>
    || std::same_as<uint16_t, T> || std::same_as<uint32_t, T> || std::same_as<uint64_t, T> || std::same_as<float, T> || std::same_as<double, T>
    || std::same_as<bool, T> || std::same_as<std::string, T> || std::same_as<std::nullptr_t, T>;

template<typename T>
concept IsTrivialFlexbufferOrNonTrivialType = (IsTrivialFlexbufferType<T> || IsNonTrivialType<T>);
}

#endif
