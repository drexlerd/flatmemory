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

#ifndef FLATMEMORY_FLEX_BUFFER_UTILS_HPP_
#define FLATMEMORY_FLEX_BUFFER_UTILS_HPP_

#include <flatbuffers/flexbuffers.h>

namespace flatmemory
{

/**
 * Templated wrapper function to serialize trivial flexbuffer types.
 */

template<typename T>
void serialize_scalar_value(T value, flexbuffers::Builder& builder)
{
    static_assert(std::false_type::value, "No suitable overload found for serialize<T>.");
}

template<>
inline void serialize_scalar_value(int8_t value, flexbuffers::Builder& builder)
{
    builder.Int(value);
}

template<>
inline void serialize_scalar_value(int16_t value, flexbuffers::Builder& builder)
{
    builder.ForceMinimumBitWidth(flexbuffers::BIT_WIDTH_16);
    builder.Int(value);
    builder.ForceMinimumBitWidth(flexbuffers::BIT_WIDTH_8);
}

/**
 * Templated wrapper function to retrieve trivial flexbuffer types.
 */

template<typename T>
T retrieve_scalar_value(flexbuffers::Reference reference)
{
    static_assert(std::false_type::value, "No suitable overload found for retrieve_scalar_value<T>.");
}

template<>
inline int8_t retrieve_scalar_value<int8_t>(flexbuffers::Reference reference)
{
    return reference.AsInt8();
}

template<>
inline int16_t retrieve_scalar_value<int16_t>(flexbuffers::Reference reference)
{
    return reference.AsInt16();
}

/**
 * Templated wrapper function to mutate trivial flexbuffer types.
 */

template<typename T>
bool mutate_scalar_value(T value, flexbuffers::Reference reference)
{
    static_assert(std::false_type::value, "No suitable overload found for mutate_scalar_value<T>.");
    return false;
}

template<>
inline bool mutate_scalar_value(int8_t value, flexbuffers::Reference reference)
{
    return reference.MutateInt(value);
}

template<>
inline bool mutate_scalar_value(int16_t value, flexbuffers::Reference reference)
{
    return reference.MutateInt(value);
}

}

#endif
