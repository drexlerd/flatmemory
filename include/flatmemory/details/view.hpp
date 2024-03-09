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

#ifndef FLATMEMORY_VIEW_HPP_
#define FLATMEMORY_VIEW_HPP_

#include <type_traits>

namespace flatmemory
{
/**
 * Implementation class.
 *
 * Provide overload with your Tag.
 *
 * Define operations to access the underlying raw data.
 */
template<typename Tag>
class View
{
};

/**
 * Concepts
 */
template<IsTriviallyCopyableOrCustom T, bool = IsTriviallyCopyable<T>>
struct maybe_view
{
    using type = T;
};

template<IsTriviallyCopyableOrCustom T>
struct maybe_view<T, false>
{
    using type = View<T>;
};
}

#endif
