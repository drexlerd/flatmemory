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

#include <flatmemory/types/vector.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{

TEST(FlatmemoryTests, TypesVectorTest) {
    EXPECT_EQ((Layout<Vector<uint16_t>>::final_alignment), 4);

    auto builder = Builder<Vector<uint16_t>>();
    builder.get_builders().resize(2);
    builder.get_builders()[0] = 5;
    builder.get_builders()[1] = 6;
    builder.finish();

    EXPECT_EQ(builder.get_size(), 8);

    auto view = View<Vector<uint16_t>>(builder.get_data());
    EXPECT_EQ(view.get_size(), 2);
    EXPECT_EQ(view[0], 5);
    EXPECT_EQ(view[1], 6);
}


TEST(FlatmemoryTests, TypesVector2Test) {
    EXPECT_EQ((Layout<Vector<uint16_t>>::final_alignment), 4);

    auto builder = Builder<Vector<uint16_t>>();
    builder.get_builders().resize(3);
    builder.finish();

    // 2 additional padding are added from 10 to 12
    EXPECT_EQ(builder.get_size(), 12);
}



}
