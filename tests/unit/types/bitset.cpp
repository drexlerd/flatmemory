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


TEST(FlatmemoryTests, TypesBitsetDefaultConstructorTest) {
    // Test default constructor bitset
    auto bitset = Builder<Bitset<uint64_t>>();
    EXPECT_FALSE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 0);
}


TEST(FlatmemoryTests, TypesBitsetConstructorSizeTest) {
    // Test size constructor
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits);
    EXPECT_FALSE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 1);
    for (size_t i = 0; i < num_bits; ++i) EXPECT_FALSE(bitset.get(i));
    EXPECT_FALSE(bitset.get(num_bits));
}


TEST(FlatmemoryTests, TypesBitsetConstructorSizeValueTest) {
    // Test size constructor
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits, true);
    EXPECT_TRUE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 1);
    for (size_t i = 0; i < num_bits; ++i) EXPECT_TRUE(bitset.get(i));
    EXPECT_TRUE(bitset.get(num_bits));
}


TEST(FlatmemoryTests, TypesBitsetResizeTest) {
    auto bitset = Builder<Bitset<uint64_t>>();

    // Test resize
    bitset.set(100);
    EXPECT_EQ(bitset.get_blocks().size(), 2);
    EXPECT_TRUE(bitset.get(100));
    EXPECT_FALSE(bitset.get(0));
    EXPECT_FALSE(bitset.get(101));

    // Test no resize out of bounds
    EXPECT_FALSE(bitset.get(1000));
    EXPECT_EQ(bitset.get_blocks().size(), 2);
}


TEST(FlatmemoryTests, TypesBitsetNextSetBitTest) {
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits);

    // Test next_set_bit
    bitset.set(5);
    EXPECT_EQ(bitset.next_set_bit(0), 5);
}


TEST(FlatmemoryTests, TypesBitsetOrEqualTest) {
    // Test operator|=
    // 1. Test with same default_bit_value=false
    size_t num_bits_1 = 4;
    auto bitset_1 = Builder<Bitset<uint64_t>>(num_bits_1, false);
    bitset_1.set(1);
    bitset_1.set(3);

    size_t num_bits_2 = 4;
    auto bitset_2 = Builder<Bitset<uint64_t>>(num_bits_2, false);
    bitset_2.set(2);
    bitset_2.set(3);

    bitset_1 |= bitset_2;
    EXPECT_EQ(bitset_1.get_blocks().size(), 1);
    EXPECT_FALSE(bitset_1.get_default_bit_value());
    EXPECT_FALSE(bitset_1.get(0));
    EXPECT_TRUE(bitset_1.get(1));
    EXPECT_TRUE(bitset_1.get(2));
    EXPECT_TRUE(bitset_1.get(3));
    EXPECT_FALSE(bitset_1.get(4));
}


TEST(FlatmemoryTests, TypesBitsetAndEqualTest) {
    // Test operator&=
    // 1. Test with same default_bit_value=false
    size_t num_bits_1 = 4;
    auto bitset_1 = Builder<Bitset<uint64_t>>(num_bits_1, false);
    bitset_1.set(1);
    bitset_1.set(3);

    size_t num_bits_2 = 4;
    auto bitset_2 = Builder<Bitset<uint64_t>>(num_bits_2, false);
    bitset_2.set(2);
    bitset_2.set(3);

    bitset_1 &= bitset_2;
    EXPECT_EQ(bitset_1.get_blocks().size(), 1);
    EXPECT_FALSE(bitset_1.get_default_bit_value());
    EXPECT_FALSE(bitset_1.get(0));
    EXPECT_FALSE(bitset_1.get(1));
    EXPECT_FALSE(bitset_1.get(2));
    EXPECT_TRUE(bitset_1.get(3));
    EXPECT_FALSE(bitset_1.get(4));
}


TEST(FlatmemoryTests, TypesBitsetNotTest) {
    size_t num_bits = 3;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits, false);
    bitset.set(1);

    ~bitset;

    EXPECT_TRUE(bitset.get_default_bit_value());
    EXPECT_TRUE(bitset.get(0));
    EXPECT_FALSE(bitset.get(1));
    EXPECT_TRUE(bitset.get(2));
}



}
