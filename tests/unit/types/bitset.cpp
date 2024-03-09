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
TEST(FlatmemoryTests, TypesBitsetTest)
{
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
    for (auto block : view.get_blocks()) {}
}

TEST(FlatmemoryTests, TypesBitsetDefaultConstructorTest)
{
    // Test default constructor bitset
    auto bitset = Builder<Bitset<uint64_t>>();
    EXPECT_FALSE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 1);
}

TEST(FlatmemoryTests, TypesBitsetConstructorSizeTest)
{
    // Test size constructor
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits);
    EXPECT_FALSE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 1);
    for (size_t i = 0; i < num_bits; ++i)
        EXPECT_FALSE(bitset.get(i));
    EXPECT_FALSE(bitset.get(num_bits));
}

TEST(FlatmemoryTests, TypesBitsetConstructorSizeValueTest)
{
    // Test size constructor
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits, true);
    EXPECT_TRUE(bitset.get_default_bit_value());
    EXPECT_EQ(bitset.get_blocks().size(), 1);
    for (size_t i = 0; i < num_bits; ++i)
        EXPECT_TRUE(bitset.get(i));
    EXPECT_TRUE(bitset.get(num_bits));
}

TEST(FlatmemoryTests, TypesBitsetResizeTest)
{
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

TEST(FlatmemoryTests, TypesBitsetNextSetBitTest)
{
    size_t num_bits = 10;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits);

    // Test next_set_bit
    bitset.set(5);
    EXPECT_EQ(bitset.next_set_bit(0), 5);
}

TEST(FlatmemoryTests, TypesBitsetOrEqualTest)
{
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

TEST(FlatmemoryTests, TypesBitsetAndEqualTest)
{
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

TEST(FlatmemoryTests, TypesBitsetNotTest)
{
    size_t num_bits = 3;
    auto bitset = Builder<Bitset<uint64_t>>(num_bits, false);
    bitset.set(1);

    ~bitset;

    EXPECT_TRUE(bitset.get_default_bit_value());
    EXPECT_TRUE(bitset.get(0));
    EXPECT_FALSE(bitset.get(1));
    EXPECT_TRUE(bitset.get(2));
}

TEST(FlatmemoryTests, TypesBitsetEqualityTest)
{
    using BitsetLayout = Bitset<uint64_t>;

    auto builder1 = Builder<BitsetLayout>(3);
    builder1.get_default_bit_value() = false;
    builder1.set(1);
    builder1.finish();

    auto builder2 = Builder<BitsetLayout>(3);
    builder2.get_default_bit_value() = false;
    builder2.set(1);
    builder2.finish();

    auto builder3 = Builder<BitsetLayout>(3);
    builder3.get_default_bit_value() = false;
    builder3.finish();

    EXPECT_TRUE((builder1 == builder2));
    EXPECT_EQ(builder1.hash(), builder2.hash());

    EXPECT_FALSE((builder1 == builder3));
    EXPECT_NE(builder1.hash(), builder3.hash());

    EXPECT_FALSE((builder2 == builder3));
    EXPECT_NE(builder2.hash(), builder3.hash());

    auto view1 = View<BitsetLayout>(builder1.buffer().data());
    auto view2 = View<BitsetLayout>(builder2.buffer().data());
    auto view3 = View<BitsetLayout>(builder3.buffer().data());

    EXPECT_TRUE((view1 == view2));
    EXPECT_EQ(view1.hash(), view2.hash());

    EXPECT_FALSE((view1 == view3));
    EXPECT_NE(view1.hash(), view3.hash());

    EXPECT_FALSE((view2 == view3));
    EXPECT_NE(view2.hash(), view3.hash());

    auto const_view1 = ConstView<BitsetLayout>(builder1.buffer().data());
    auto const_view2 = ConstView<BitsetLayout>(builder2.buffer().data());
    auto const_view3 = ConstView<BitsetLayout>(builder3.buffer().data());

    EXPECT_TRUE((const_view1 == const_view2));
    EXPECT_EQ(const_view1.hash(), const_view2.hash());

    EXPECT_FALSE((const_view1 == const_view3));
    EXPECT_NE(const_view1.hash(), const_view3.hash());

    EXPECT_FALSE((const_view2 == const_view3));
    EXPECT_NE(const_view2.hash(), const_view3.hash());
}

TEST(FlatmemoryTests, TypesBitsetIteratorTest)
{
    size_t num_bits = 200;
    auto builder = Builder<Bitset<uint64_t>>(num_bits, false);
    builder.set(0);
    builder.set(2);
    builder.set(4);
    builder.set(99);

    auto it = builder.begin();
    auto end = builder.end();
    EXPECT_EQ(*it, 0);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 99);
    ++it;
    EXPECT_EQ(it, end);

    builder.finish();

    auto view = View<Bitset<uint64_t>>(builder.buffer().data());
    it = view.begin();
    end = view.end();
    EXPECT_EQ(*it, 0);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 99);
    ++it;
    EXPECT_EQ(it, end);

    auto const_view = ConstView<Bitset<uint64_t>>(builder.buffer().data());
    it = const_view.begin();
    end = const_view.end();
    EXPECT_EQ(*it, 0);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 99);
    ++it;
    EXPECT_EQ(it, end);
}

TEST(FlatmemoryTests, TypesBitsetIterator2Test)
{
    size_t num_bits = 0;
    auto builder = Builder<Bitset<uint64_t>>(num_bits, false);

    auto it = builder.begin();
    auto end = builder.end();
    EXPECT_EQ(it, end);
}

}
