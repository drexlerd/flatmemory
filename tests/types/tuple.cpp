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

#include <flatmemory/types/tuple.hpp>
#include <flatmemory/types/uint16.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{

TEST(FlatmemoryTests, TypesTupleTest) {
    EXPECT_EQ((Layout<Tuple<Uint16, Uint16, Uint16>>::alignment), 2);
    static_assert(!is_trivial_and_standard_layout_v<Tuple<Uint16, Uint16, Uint16>>, "Tuple<Ts...> must not have standard layout.");

    auto builder = Builder<Tuple<int16_t, int32_t, uint16_t>>();
    builder.get_builder<0>() = 5;
    builder.get_builder<1>() = 6;
    builder.get_builder<2>() = 7;
    builder.finish();
    EXPECT_NE(builder.get_data(), nullptr);
    EXPECT_EQ(builder.get_size(), 6);

    auto view = View<Tuple<int16_t, int32_t, uint16_t>>(builder.get_data());
    EXPECT_EQ(view.get<0>(), 5);
    EXPECT_EQ(view.get<1>(), 6);
    EXPECT_EQ(view.get<2>(), 7);
}




}
