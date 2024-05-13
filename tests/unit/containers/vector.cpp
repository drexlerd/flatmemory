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

#include <flatmemory/flatmemory.hpp>
#include <gtest/gtest.h>
#include <string>

namespace flatmemory::tests
{

TEST(FlatmemoryTests, ContainersVariableSizedTypeVectorTest)
{
    VariableSizedTypeVector<Bitset<uint64_t>> views;
    auto builder = Builder<Bitset<uint64_t>>();
    builder.get_blocks().resize(5);
    builder.finish();
    for (size_t i = 0; i < 5; ++i)
    {
        views.push_back(builder);
    }
}

TEST(FlatmemoryTests, ContainersFixedSizedTypeVectorConstructor1Test)
{
    FixedSizedTypeVector<Tuple<uint16_t, uint32_t>> vector;
    vector.resize(5);
}

TEST(FlatmemoryTests, ContainersFixedSizedTypeVectorTest)
{
    auto builder = Builder<Tuple<uint16_t, uint32_t>>();
    builder.finish();
    FixedSizedTypeVector<Tuple<uint16_t, uint32_t>> vector(std::move(builder));
    vector.resize(5);
}
}
