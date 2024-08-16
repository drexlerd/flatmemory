/*
 * Copyright (C) 2023 Dominik Drexler and Simon Stahlberg
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

#ifndef FLATMEMORY_ALGORITHMS_HASH_HPP_
#define FLATMEMORY_ALGORITHMS_HASH_HPP_

#include <cstddef>
#include <functional>
#include <set>
#include <vector>

namespace flatmemory
{

/**
 * Forward declarations
 */

template<typename T>
inline void hash_combine(size_t& seed, const T& value);

template<typename T, typename... Rest>
inline void hash_combine(size_t& seed, const Rest&... rest);

template<typename... Ts>
inline size_t hash_combine(const Ts&... rest);
}

/**
 * std::hash specializations
 */

/// @brief std::hash specialization for a forward range.
/// @tparam ForwardRange
template<std::ranges::input_range R>
struct std::hash<R>
{
    size_t operator()(const R& range) const
    {
        std::size_t aggregated_hash = 0;
        for (const auto& item : range)
        {
            flatmemory::hash_combine(aggregated_hash, item);
        }
        return aggregated_hash;
    }
};

/**
 * Definitions
 */

namespace flatmemory
{

template<typename T>
inline void hash_combine(size_t& seed, const T& value)
{
    seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T, typename... Rest>
inline void hash_combine(size_t& seed, const Rest&... rest)
{
    (flatmemory::hash_combine(seed, rest), ...);
}

template<typename... Ts>
inline size_t hash_combine(const Ts&... rest)
{
    size_t seed = 0;
    (flatmemory::hash_combine(seed, rest), ...);
    return seed;
}

}

#endif
