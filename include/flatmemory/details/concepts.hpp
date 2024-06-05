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
#include <type_traits>

namespace flatmemory
{
/**
 * Base ID class for custom types.
 */
struct Custom
{
};

template<typename T>
concept IsCustom = std::derived_from<T, Custom>;

template<typename T>
concept IsTriviallyCopyable = std::is_trivially_copyable_v<T>;

template<typename T>
concept IsTriviallyCopyableOrCustom = (IsTriviallyCopyable<T> || IsCustom<T>);

// Concept to check whether T is integral
template<typename T>
concept IsIntegral = std::is_integral_v<T>;

// Concept to check whether T is an unsigned integral
template<typename T>
concept IsUnsignedIntegral = IsIntegral<T> && std::is_unsigned_v<T>;
}

#endif
