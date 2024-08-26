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

#ifndef FLATMEMORY_TYPES_FORMATTER_HPP_
#define FLATMEMORY_TYPES_FORMATTER_HPP_

#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/view_const.hpp"

#include <cstddef>
#include <ostream>

namespace flatmemory
{

class Formatter
{
private:
    size_t m_indent;
    size_t m_add_indent;

public:
    Formatter(size_t indent = 0, size_t add_indent = 0) : m_indent(indent), m_add_indent(add_indent) {}

    template<IsUnsignedIntegral Block, typename Tag>
    void write(ConstView<Bitset<Block, Tag>> element, std::ostream& out);

    template<IsTrivialFlexbufferOrNonTrivialType... Ts>
    void write(ConstView<Tuple<Ts...>> element, std::ostream& out);

    template<IsTrivialFlexbufferOrNonTrivialType T>
    void write(ConstView<Vector<T>> element, std::ostream& out);
};

}

#endif
