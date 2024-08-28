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
using StateLayout = Tuple<uint32_t, Bitset<uint64_t>>;
using StateView = ConstView<StateLayout>;

TEST(FlatmemoryTests, ContainersUnorderedSetTest)
{
    UnorderedSet<StateLayout> unordered_set;

    Builder<StateLayout> builder;

    builder.get<0>() = 9;
    builder.get<1>().set(1);
    builder.finish();
    auto const_view1 = *unordered_set.insert(builder).first;
    builder.get<0>() = 9;
    builder.finish();
    auto const_view2 = *unordered_set.insert(builder).first;

    EXPECT_EQ(const_view1.get_buffer(), const_view2.get_buffer());

    builder.get<0>() = 9;
    builder.get<1>().unset_all();
    builder.finish();
    auto const_view3 = *unordered_set.insert(builder).first;

    EXPECT_NE(const_view1.get_buffer(), const_view3.get_buffer());
}
}
