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

/**
 * Constructors
 */

TEST(FlatmemoryTests, TypesBitsetDefaultConstructorTest)
{
    {
        // 1D
        auto builder = Builder<Bitset<uint64_t, void>>();
        builder.finish();
        EXPECT_EQ(builder.get_buffer().size(), 9);
    }
}

TEST(FlatmemoryTests, TypesBitsetConstructorTest)
{
    {
        // 1D
        auto builder = Builder<Bitset<uint64_t, void>>(10);
        builder.finish();
        EXPECT_EQ(builder.get_buffer().size(), 96);
    }
}

}
