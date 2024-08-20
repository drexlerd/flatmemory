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

#ifndef FLATMEMORY_TYPES_DECLARATIONS_HPP_
#define FLATMEMORY_TYPES_DECLARATIONS_HPP_

#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/operator.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

namespace flatmemory
{

/**
 * Bitset
 */

template<IsUnsignedIntegral Block, typename Tag = void>
struct Bitset;

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

template<typename T>
struct is_bitset_builder_helper : std::false_type
{
};

template<typename T>
struct is_bitset_view_helper : std::false_type
{
};

template<typename T>
struct is_bitset_const_view_helper : std::false_type
{
};

template<typename Block, typename Tag>
struct is_bitset_builder_helper<Builder<Bitset<Block, Tag>>> : std::true_type
{
};

template<typename Block, typename Tag>
struct is_bitset_view_helper<View<Bitset<Block, Tag>>> : std::true_type
{
};

template<typename Block, typename Tag>
struct is_bitset_const_view_helper<ConstView<Bitset<Block, Tag>>> : std::true_type
{
};

template<typename T>
concept IsBitsetBuilder = is_bitset_builder_helper<T>::value;

template<typename T>
concept IsBitsetView = is_bitset_view_helper<T>::value;

template<typename T>
concept IsBitsetConstView = is_bitset_const_view_helper<T>::value;

template<typename T>
concept IsBitset = IsBitsetBuilder<T> || IsBitsetView<T> || IsBitsetConstView<T>;

/**
 * Tuple
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
struct Tuple;

template<typename T>
struct is_tuple_builder_helper : std::false_type
{
};

template<typename T>
struct is_tuple_view_helper : std::false_type
{
};

template<typename T>
struct is_tuple_const_view_helper : std::false_type
{
};

template<IsTriviallyCopyableOrNonTrivialType... Ts>
struct is_tuple_builder_helper<Builder<Tuple<Ts...>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType... Ts>
struct is_tuple_view_helper<View<Tuple<Ts...>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType... Ts>
struct is_tuple_const_view_helper<ConstView<Tuple<Ts...>>> : std::true_type
{
};

template<typename T>
concept IsTupleBuilder = is_tuple_builder_helper<T>::value;

template<typename T>
concept IsTupleView = is_tuple_view_helper<T>::value;

template<typename T>
concept IsTupleConstView = is_tuple_const_view_helper<T>::value;

template<typename T>
concept IsTuple = IsTupleBuilder<T> || IsTupleView<T> || IsTupleConstView<T>;

template<typename T1, typename T2>
concept HaveSameValueTypes = std::is_same_v<typename T1::ValueTypes, typename T2::ValueTypes>;

/**
 * Vector
 */

template<IsTriviallyCopyableOrNonTrivialType T>
struct Vector;

template<typename T1, typename T2>
concept HaveSameValueType = std::is_same_v<typename T1::ValueType, typename T2::ValueType>;

template<typename T>
struct is_vector_builder_helper : std::false_type
{
};

template<typename T>
struct is_vector_view_helper : std::false_type
{
};

template<typename T>
struct is_vector_const_view_helper : std::false_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_builder_helper<Builder<Vector<T>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_view_helper<View<Vector<T>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_const_view_helper<ConstView<Vector<T>>> : std::true_type
{
};

template<typename T>
concept IsVectorBuilder = is_vector_builder_helper<T>::value;

template<typename T>
concept IsVectorView = is_vector_view_helper<T>::value;

template<typename T>
concept IsVectorConstView = is_vector_const_view_helper<T>::value;

template<typename T>
concept IsVector = IsVectorBuilder<T> || IsVectorView<T> || IsVectorConstView<T>;

}

#endif
