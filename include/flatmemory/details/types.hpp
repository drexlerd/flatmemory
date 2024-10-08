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

#ifndef FLATMEMORY_TYPES_HPP_
#define FLATMEMORY_TYPES_HPP_

#include <concepts>
#include <cstddef>

namespace flatmemory
{

using NumBytes = size_t;

using OffsetType = uint32_t;

using BufferSizeType = uint32_t;

// It does not make sense the other way around, since potentially many offsets are stored within a single buffer.
static_assert(sizeof(BufferSizeType) >= sizeof(OffsetType));
}

#endif
