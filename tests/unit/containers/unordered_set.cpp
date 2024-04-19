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

struct CustomHash
{
    std::size_t operator()(const StateView& view) const { return view.get<1>().hash(); }
};

struct CustomEqual
{
    bool operator()(const StateView& view_left, const StateView& view_right) const { return view_left.get<1>() == view_right.get<1>(); }
};

TEST(FlatmemoryTests, ContainersUnorderedSetTest)
{
    UnorderedSet<StateLayout, CustomHash, CustomEqual> unordered_set;

    Builder<StateLayout> builder;

    builder.get<0>() = 9;
    builder.get<1>().set(1);
    builder.finish();
    auto const_view1 = *unordered_set.insert(builder).first;
    builder.get<0>() = 8;
    builder.finish();
    auto const_view2 = *unordered_set.insert(builder).first;

    EXPECT_EQ(const_view1.buffer(), const_view2.buffer());

    builder.get<0>() = 9;
    builder.get<1>().unset_all();
    builder.finish();
    auto const_view3 = *unordered_set.insert(builder).first;

    EXPECT_NE(const_view1.buffer(), const_view3.buffer());
}
}
