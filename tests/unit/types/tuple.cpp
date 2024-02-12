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
    TEST(FlatmemoryTests, TypesTupleEmptyTest) {
        // Test empty tuple
        EXPECT_EQ((Layout<Tuple<>>::final_alignment), 4);
        EXPECT_EQ(IsTriviallyCopyable<View<Tuple<>>>, true);
        EXPECT_EQ(IsTriviallyCopyable<Tuple<>>, false);

        auto builder = Builder<Tuple<>>();
        builder.finish();

        EXPECT_NE(builder.buffer().data(), nullptr);
        EXPECT_EQ(builder.buffer().size(), 4);
    }

    TEST(FlatmemoryTests, TypesTupleTest) {
        // Test without any padding.
        //  ______________________
        // ||  |  ||  |  ||  |  ||
        // ||  5  ||  6  ||  7  ||
        // ||__|__||__|__||__|__||
        EXPECT_EQ((Layout<Tuple<uint16_t, uint16_t, uint16_t>>::final_alignment), 4);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<uint16_t, uint16_t, uint16_t>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<uint16_t, uint16_t, uint16_t>>), false);

        auto builder = Builder<Tuple<int16_t, uint16_t, uint16_t>>();
        builder.get<0>() = 5;
        builder.get<1>() = 6;
        builder.get<2>() = 7;
        builder.finish();
        EXPECT_NE(builder.buffer().data(), nullptr);
        EXPECT_EQ(builder.buffer().size(), 12);

        auto view = View<Tuple<int16_t, uint16_t, uint16_t>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>(), 5);
        EXPECT_EQ(view.get<1>(), 6);
        EXPECT_EQ(view.get<2>(), 7);
    }


    TEST(FlatmemoryTests, TypesTuplePaddingTest) {
        // Test with padding in between.
        //  __________________________________________
        // ||  |  ||  |  ||  |  |  |  ||  |  ||  |  ||
        // ||  5  ||  P  ||     6     ||  7  ||  P  ||
        // ||__|__||__|__||__|__|__|__||__|__||__|__||
        EXPECT_EQ((Layout<Tuple<int16_t, int32_t, uint16_t>>::final_alignment), 4);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<int16_t, int32_t, uint16_t>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<int16_t, int32_t, uint16_t>>), false);

        auto builder = Builder<Tuple<int16_t, int32_t, uint16_t>>();
        builder.get<0>() = 5;
        builder.get<1>() = 6;
        builder.get<2>() = 7;
        builder.finish();
        EXPECT_NE(builder.buffer().data(), nullptr);
        EXPECT_EQ(builder.buffer().size(), 16);

        auto view = View<Tuple<int16_t, int32_t, uint16_t>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>(), 5);
        EXPECT_EQ(view.get<1>(), 6);
        EXPECT_EQ(view.get<2>(), 7);
    }


    TEST(FlatmemoryTests, TypesTupleVectorTest) {
        EXPECT_EQ((Layout<Tuple<Vector<uint64_t>>>::final_alignment), 8);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<uint64_t>>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<uint64_t>>>), false);

        auto builder = Builder<Tuple<Vector<uint64_t>>>();
        builder.get<0>().resize(3);
        builder.finish();
        EXPECT_NE(builder.buffer().data(), nullptr);
        EXPECT_EQ(builder.buffer().size(), 40);

        auto view = View<Tuple<Vector<uint64_t>>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>().size(), 3);
    }


    TEST(FlatmemoryTests, TypesTupleVector2Test) {
        EXPECT_EQ((Layout<Tuple<Vector<uint64_t>, Vector<uint16_t>>>::final_alignment), 8);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<uint64_t>, Vector<uint16_t>>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<uint64_t>, Vector<uint16_t>>>), false);

        auto builder = Builder<Tuple<Vector<uint64_t>, Vector<uint16_t>>>();
        builder.get<0>().resize(3);
        builder.get<1>().resize(4);
        builder.finish();
        EXPECT_NE(builder.buffer().data(), nullptr);
        EXPECT_EQ(builder.buffer().size(), 56);

        auto view = View<Tuple<Vector<uint64_t>, Vector<uint16_t>>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>().size(), 3);
        EXPECT_EQ(view.get<1>().size(), 4);
    }


    TEST(FlatmemoryTests, TypesTupleVectorVectorTest) {
        EXPECT_EQ((Layout<Tuple<Vector<Vector<uint8_t>>>>::final_alignment), 4);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<Vector<uint8_t>>>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<Vector<uint8_t>>>>), false);

        auto builder = Builder<Tuple<Vector<Vector<uint8_t>>>>();
        builder.get<0>().resize(3);
        builder.get<0>()[0].resize(2);
        builder.get<0>()[1].resize(3);
        builder.get<0>()[2].resize(4);
        builder.finish();

        auto view = View<Tuple<Vector<Vector<uint8_t>>>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>().size(), 3);
        EXPECT_EQ(view.get<0>()[0].size(), 2);
        EXPECT_EQ(view.get<0>()[1].size(), 3);
        EXPECT_EQ(view.get<0>()[2].size(), 4);
    }


    struct StructTest {
        uint32_t x;
        uint64_t y;
    };

    TEST(FlatmemoryTests, TypesTupleStructTest) {
        EXPECT_EQ((Layout<Tuple<StructTest>>::final_alignment), 8);
        EXPECT_EQ((IsTriviallyCopyable<View<Tuple<StructTest>>>), true);
        EXPECT_EQ((IsTriviallyCopyable<Tuple<StructTest>>), false);

        auto builder = Builder<Tuple<StructTest>>();
        builder.get<0>().x = 5;
        builder.get<0>().y = 10;
        builder.finish();

        auto view = View<Tuple<StructTest>>(builder.buffer().data());
        EXPECT_EQ(view.get<0>().x, 5);
        EXPECT_EQ(view.get<0>().y, 10);
    }


    TEST(FlatmemoryTests, TypesTupleEqualityTest) {
        using TupleLayout = Tuple<uint64_t, uint32_t>;
        EXPECT_EQ((Layout<TupleLayout>::final_alignment), 8);
        EXPECT_EQ((IsTriviallyCopyable<View<TupleLayout>>), true);
        EXPECT_EQ((IsTriviallyCopyable<TupleLayout>), false);

        auto builder1 = Builder<TupleLayout>();
        builder1.get<0>() = 5;
        builder1.get<1>() = 10;
        builder1.finish();

        auto builder2 = Builder<TupleLayout>();
        builder2.get<0>() = 5;
        builder2.get<1>() = 10;
        builder2.finish();

        auto builder3 = Builder<TupleLayout>();
        builder3.get<0>() = 5;
        builder3.get<1>() = 9;
        builder3.finish();

        EXPECT_TRUE((builder1 == builder2));
        EXPECT_EQ(builder1.hash(), builder2.hash());

        EXPECT_FALSE((builder1 == builder3));
        EXPECT_NE(builder1.hash(), builder3.hash());

        EXPECT_FALSE((builder2 == builder3));
        EXPECT_NE(builder2.hash(), builder3.hash());


        auto view1 = View<TupleLayout>(builder1.buffer().data());
        auto view2 = View<TupleLayout>(builder2.buffer().data());
        auto view3 = View<TupleLayout>(builder3.buffer().data());
 
        EXPECT_TRUE((view1 == view2));
        EXPECT_EQ(view1.hash(), view2.hash());

        EXPECT_FALSE((view1 == view3));
        EXPECT_NE(view1.hash(), view3.hash());

        EXPECT_FALSE((view2 == view3));
        EXPECT_NE(view2.hash(), view3.hash());


        auto const_view1 = ConstView<TupleLayout>(builder1.buffer().data());
        auto const_view2 = ConstView<TupleLayout>(builder2.buffer().data());
        auto const_view3 = ConstView<TupleLayout>(builder3.buffer().data());

        EXPECT_TRUE((const_view1 == const_view2));
        EXPECT_EQ(const_view1.hash(), const_view2.hash());

        EXPECT_FALSE((const_view1 == const_view3));
        EXPECT_NE(const_view1.hash(), const_view3.hash());

        EXPECT_FALSE((const_view2 == const_view3));
        EXPECT_NE(const_view2.hash(), const_view3.hash());

    }
}
