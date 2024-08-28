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

#ifndef FLATMEMORY_TYPES_FORMATTER_IMPL_HPP_
#define FLATMEMORY_TYPES_FORMATTER_IMPL_HPP_

#include "flatmemory/details/types/formatter.hpp"

namespace flatmemory
{

template<IsUnsignedIntegral Block, typename Tag>
void Formatter::write(ConstView<Bitset<Block, Tag>> element, std::ostream& out)
{
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Formatter::write(ConstView<Tuple<Ts...>> element, std::ostream& out)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Formatter::write(ConstView<Vector<T>> element, std::ostream& out)
{
}
}

#endif