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

TEST(FlatmemoryTests, TypesBitsetTest) {
    EXPECT_EQ((Layout<Bitset<uint64_t>>::final_alignment), 8);
    EXPECT_EQ(IsTriviallyCopyable<View<Bitset<uint64_t>>>, true);

    auto builder = Builder<Bitset<uint64_t>>();
    builder.get_default_bit_value() = true;
    builder.get_blocks().resize(5); 
    builder.finish();

    EXPECT_EQ(builder.buffer().size(), 56);

    auto view = View<Bitset<uint64_t>>(builder.buffer().data());
    EXPECT_EQ(view.get_default_bit_value(), true);
    EXPECT_EQ(view.get_blocks().size(), 5);
    for (auto block : view.get_blocks()) {
        
    }
}





}
