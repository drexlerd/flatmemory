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

#include <flatmemory/types/uint32.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{

TEST(FlatmemoryTests, TypesUint32Test) {
    EXPECT_EQ((Layout<Uint32>::alignment), 4);

    auto builder = Builder<Uint32>();
    builder.get_value() = 5;
    builder.finish();
    EXPECT_NE(builder.get_data(), nullptr);
    EXPECT_EQ(builder.get_size(), 4);

    auto view = View<Uint32>(builder.get_data());
    EXPECT_EQ(view.get_value(), 5);
}




}
