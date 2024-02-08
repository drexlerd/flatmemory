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
    struct TrivialType {
        bool x;
        uint64_t y;
    };

    TEST(FlatmemoryTests, TypesTrivialTest) {
        EXPECT_EQ((Layout<Trivial<TrivialType>>::final_alignment), 16);
        EXPECT_EQ(IsTrivial<View<Trivial<TrivialType>>>, true);

        auto builder = Builder<Trivial<TrivialType>>();
        builder->x = true;
        builder->y = 4;
        builder.finish();

        EXPECT_EQ(builder.buffer().size(), 16);

        auto view = View<Trivial<TrivialType>>(builder.buffer().data());
        EXPECT_EQ(view->x, true);
        EXPECT_EQ(view->y, 4);
    }
}
