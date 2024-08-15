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

#ifndef FLATMEMORY_TYPES_TAGS_HPP_
#define FLATMEMORY_TYPES_TAGS_HPP_

#include "flatmemory/details/concepts.hpp"

#include <concepts>
#include <type_traits>

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

// Primary template for is_bitset_tag_helper
template<typename T>
struct is_bitset_tag_helper : std::false_type
{
};

// Specialization for Bitset<Block, Tag>
template<IsUnsignedIntegral Block, typename Tag>
struct is_bitset_tag_helper<Bitset<Block, Tag>> : std::true_type
{
};

// Concept to check if a type is a Bitset
template<typename T>
concept IsBitsetTag = is_bitset_tag_helper<T>::value;

/**
 * Dispatcher for Tuple.
 */
template<IsTriviallyCopyableOrCustom... Ts>
struct Tuple : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Tuple(const Tuple& other) {}
};

template<typename T>
struct is_tuple_tag_helper : std::false_type
{
};

template<IsTriviallyCopyableOrCustom... Ts>
struct is_tuple_tag_helper<Tuple<Ts...>> : std::true_type
{
};

template<typename T>
concept IsTupleTag = is_tuple_tag_helper<T>::value;

/**
 * Dispatcher for Vector.
 */
template<IsTriviallyCopyableOrCustom T>
struct Vector : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Vector(const Vector& other) {}
};

template<typename T>
struct is_vector_tag_helper : std::false_type
{
};

template<IsTriviallyCopyableOrCustom T>
struct is_vector_tag_helper<Vector<T>> : std::true_type
{
};

template<typename T>
concept IsVectorTag = is_vector_tag_helper<T>::value;

template<typename T>
concept IsTag = IsBitsetTag<T> || IsTupleTag<T> || IsVectorTag<T>;

}

#endif
