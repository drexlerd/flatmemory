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

namespace flatmemory::tests
{
/**
 * Constructors
 */

TEST(FlatmemoryTests, TypesOptionalDefaultConstructorTest)
{
    {
        auto builder = Builder<Optional<uint16_t>>();
        builder.finish();

        EXPECT_TRUE(builder.has_value());
        EXPECT_EQ(builder.value(), 0);
        EXPECT_EQ(builder.buffer().size(), 4);
    }
    {
        auto builder = Builder<Optional<uint64_t>>();
        builder.finish();

        EXPECT_TRUE(builder.has_value());
        EXPECT_EQ(builder.value(), 0);
        // The final alignment is 8 bytes. We need this to store optionals in a vector.
        EXPECT_EQ(builder.buffer().size(), 8);
    }
}

}