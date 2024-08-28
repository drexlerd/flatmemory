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
#include <random>
#include <string>

namespace flatmemory::tests
{

/**
 * Constructors
 */

/**
 * Operators
 */

TEST(FlatmemoryTests, TypesTupleEqualToAndHashTest)
{
    using BitsetVectorLayout = Vector<Bitset<uint64_t>>;
    using BitsetTupleLayout = Tuple<BitsetVectorLayout, BitsetVectorLayout>;

    auto builder1 = Builder<BitsetTupleLayout>();
    auto& first = builder1.get<0>();
    auto& second = builder1.get<1>();
    first.resize(2);
    first[0].set(4);
    first[1].set(64);
    second.resize(3);
    second[0].set(4);
    second[1].set(100);
    second[2].set(63);
    builder1.finish();

    auto builder2 = Builder<BitsetTupleLayout>();
    auto& first_2 = builder2.get<0>();
    auto& second_2 = builder2.get<1>();
    first_2.resize(2);
    first_2[0].set(4);
    first_2[1].set(63);
    second_2.resize(3);
    second_2[0].set(4);
    second_2[1].set(100);
    second_2[2].set(63);
    builder2.finish();

    auto builder3 = Builder<BitsetTupleLayout>();
    auto& first_3 = builder3.get<0>();
    auto& second_3 = builder3.get<1>();
    first_3.resize(2);
    first_3[0].set(4);
    first_3[1].set(64);
    second_3.resize(3);
    second_3[0].set(4);
    second_3[1].set(100);
    second_3[2].set(63);
    builder3.finish();

    // Test builder
    EXPECT_EQ(builder1, builder3);
    EXPECT_EQ(std::hash<Builder<BitsetTupleLayout>>()(builder1), std::hash<Builder<BitsetTupleLayout>>()(builder3));
    EXPECT_NE(builder1, builder2);
    EXPECT_NE(std::hash<Builder<BitsetTupleLayout>>()(builder1), std::hash<Builder<BitsetTupleLayout>>()(builder2));

    // Test View
    auto view1 = View<BitsetTupleLayout>(builder1.get_buffer().data());
    auto view2 = View<BitsetTupleLayout>(builder2.get_buffer().data());
    auto view3 = View<BitsetTupleLayout>(builder3.get_buffer().data());
    EXPECT_EQ(view1, view3);
    EXPECT_EQ(std::hash<View<BitsetTupleLayout>>()(view1), std::hash<View<BitsetTupleLayout>>()(view3));
    EXPECT_NE(view1, view2);
    EXPECT_NE(std::hash<View<BitsetTupleLayout>>()(view1), std::hash<View<BitsetTupleLayout>>()(view2));

    // Test ConstView
    auto const_view1 = ConstView<BitsetTupleLayout>(builder1.get_buffer().data());
    auto const_view2 = ConstView<BitsetTupleLayout>(builder2.get_buffer().data());
    auto const_view3 = ConstView<BitsetTupleLayout>(builder3.get_buffer().data());
    EXPECT_EQ(const_view1, const_view3);
    EXPECT_EQ(std::hash<ConstView<BitsetTupleLayout>>()(const_view1), std::hash<ConstView<BitsetTupleLayout>>()(const_view3));
    EXPECT_NE(const_view1, const_view2);
    EXPECT_NE(std::hash<ConstView<BitsetTupleLayout>>()(const_view1), std::hash<ConstView<BitsetTupleLayout>>()(const_view2));

    // Test Builder and View
    EXPECT_EQ(builder1, view1);
    EXPECT_EQ(builder2, view2);
    EXPECT_EQ(builder3, view3);
    EXPECT_NE(builder1, view2);
    EXPECT_EQ(builder1, view3);
    // Test View and Builder
    EXPECT_EQ(view1, builder1);
    EXPECT_EQ(view2, builder2);
    EXPECT_EQ(view3, builder3);
    EXPECT_NE(view1, builder2);
    EXPECT_EQ(view1, builder3);

    // Test Builder and ConstView
    EXPECT_EQ(builder1, const_view1);
    EXPECT_EQ(builder2, const_view2);
    EXPECT_EQ(builder3, const_view3);
    EXPECT_NE(builder1, const_view2);
    EXPECT_EQ(builder1, const_view3);
    // Test ConstView and Builder
    EXPECT_EQ(const_view1, builder1);
    EXPECT_EQ(const_view2, builder2);
    EXPECT_EQ(const_view3, builder3);
    EXPECT_NE(const_view1, builder2);
    EXPECT_EQ(const_view1, builder3);

    // Test View and ConstView
    EXPECT_EQ(view1, const_view1);
    EXPECT_EQ(view2, const_view2);
    EXPECT_EQ(view3, const_view3);
    EXPECT_NE(view1, const_view2);
    EXPECT_EQ(view1, const_view3);
    // Test ConstView and View
    EXPECT_EQ(const_view1, view1);
    EXPECT_EQ(const_view2, view2);
    EXPECT_EQ(const_view3, view3);
    EXPECT_NE(const_view1, view2);
    EXPECT_EQ(const_view1, view3);
}

TEST(FlatmemoryTests, TypesTupleSerializeViewsTest)
{
    using BitsetVectorLayout = Vector<Bitset<uint64_t>>;

    auto builder1 = Builder<BitsetVectorLayout>();
    builder1.resize(2);
    builder1[0].set(4);
    builder1[1].set(64);
    builder1.finish();

    using BitsetTupleLayout = Tuple<View<BitsetVectorLayout>, ConstView<BitsetVectorLayout>>;

    auto builder2 =
        Builder<BitsetTupleLayout>(View<BitsetVectorLayout>(builder1.get_buffer().data()), ConstView<BitsetVectorLayout>(builder1.get_buffer().data()));
    builder2.finish();

    EXPECT_EQ(builder2.get<0>(), builder2.get<1>());
}

TEST(FlatmemoryTests, TypesTupleViewMutateTest)
{
    auto builder = Builder<Tuple<uint16_t, int32_t>>();
    builder.finish();

    auto view = View<Tuple<uint16_t, int32_t>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>(), 0);
    EXPECT_EQ(view.get<1>(), 0);

    view.mutate<0>(4);
    view.mutate<1>(-7);
    EXPECT_EQ(view.get<0>(), 4);
    EXPECT_EQ(view.get<1>(), -7);
}

/**
 * TODO: Others
 */
TEST(FlatmemoryTests, TypesTupleEmptyTest)
{
    // Test empty tuple
    EXPECT_EQ(IsTriviallyCopyable<View<Tuple<>>>, true);
    EXPECT_EQ(IsTriviallyCopyable<Tuple<>>, false);

    auto builder = Builder<Tuple<>>();
    builder.finish();

    EXPECT_NE(builder.get_buffer().data(), nullptr);
    EXPECT_EQ(builder.get_buffer().size(), 4);
}

TEST(FlatmemoryTests, TypesTupleTest)
{
    // Test without any padding.
    //  ______________________
    // ||  |  ||  |  ||  |  ||
    // ||  5  ||  6  ||  7  ||
    // ||__|__||__|__||__|__||
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<uint16_t, uint16_t, uint16_t>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<uint16_t, uint16_t, uint16_t>>), false);

    auto builder = Builder<Tuple<int16_t, uint16_t, uint16_t>>();
    builder.get<0>() = 5;
    builder.get<1>() = 6;
    builder.get<2>() = 7;
    builder.finish();
    EXPECT_NE(builder.get_buffer().data(), nullptr);
    EXPECT_EQ(builder.get_buffer().size(), 10);

    auto view = View<Tuple<int16_t, uint16_t, uint16_t>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>(), 5);
    EXPECT_EQ(view.get<1>(), 6);
    EXPECT_EQ(view.get<2>(), 7);
}

TEST(FlatmemoryTests, TypesTuplePaddingTest)
{
    // Test with padding in between.
    //  __________________________________________
    // ||  |  ||  |  ||  |  |  |  ||  |  ||  |  ||
    // ||  5  ||  P  ||     6     ||  7  ||  P  ||
    // ||__|__||__|__||__|__|__|__||__|__||__|__||
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<int16_t, int32_t, uint16_t>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<int16_t, int32_t, uint16_t>>), false);

    auto builder = Builder<Tuple<int16_t, int32_t, uint16_t>>();
    builder.get<0>() = 5;
    builder.get<1>() = 6;
    builder.get<2>() = 7;
    builder.finish();
    EXPECT_NE(builder.get_buffer().data(), nullptr);
    EXPECT_EQ(builder.get_buffer().size(), 12);

    auto view = View<Tuple<int16_t, int32_t, uint16_t>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>(), 5);
    EXPECT_EQ(view.get<1>(), 6);
    EXPECT_EQ(view.get<2>(), 7);
}

TEST(FlatmemoryTests, TypesTupleVectorTest)
{
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<uint64_t>>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<uint64_t>>>), false);

    auto builder = Builder<Tuple<Vector<uint64_t>>>();
    builder.get<0>().resize(3);
    builder.finish();
    EXPECT_NE(builder.get_buffer().data(), nullptr);
    EXPECT_EQ(builder.get_buffer().size(), 40);

    auto view = View<Tuple<Vector<uint64_t>>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>().size(), 3);
}

TEST(FlatmemoryTests, TypesTupleVector2Test)
{
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<uint64_t>, Vector<uint16_t>>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<uint64_t>, Vector<uint16_t>>>), false);

    auto builder = Builder<Tuple<Vector<uint64_t>, Vector<uint16_t>>>();
    builder.get<0>().resize(3);
    builder.get<1>().resize(4);
    builder.finish();
    EXPECT_NE(builder.get_buffer().data(), nullptr);
    EXPECT_EQ(builder.get_buffer().size(), 60);

    auto view = View<Tuple<Vector<uint64_t>, Vector<uint16_t>>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>().size(), 3);
    EXPECT_EQ(view.get<1>().size(), 4);
}

TEST(FlatmemoryTests, TypesTupleVectorVectorTest)
{
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<Vector<uint8_t>>>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<Vector<uint8_t>>>>), false);

    auto builder = Builder<Tuple<Vector<Vector<uint8_t>>>>();
    builder.get<0>().resize(3);
    builder.get<0>()[0].resize(2);
    builder.get<0>()[1].resize(3);
    builder.get<0>()[2].resize(4);
    builder.finish();

    auto view = View<Tuple<Vector<Vector<uint8_t>>>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>().size(), 3);
    EXPECT_EQ(view.get<0>()[0].size(), 2);
    EXPECT_EQ(view.get<0>()[1].size(), 3);
    EXPECT_EQ(view.get<0>()[2].size(), 4);
}

struct StructTest
{
    uint32_t x;
    uint64_t y;
};

static_assert(sizeof(StructTest) == 16);

TEST(FlatmemoryTests, TypesTupleStructTest)
{
    EXPECT_EQ((IsTriviallyCopyable<View<Tuple<Vector<uint32_t>, StructTest>>>), true);
    EXPECT_EQ((IsTriviallyCopyable<Tuple<Vector<uint32_t>, StructTest>>), false);

    auto builder = Builder<Tuple<Vector<uint32_t>, StructTest>>();
    builder.get<0>().resize(1);
    builder.get<1>().x = 5;
    builder.get<1>().y = 10;
    builder.finish();
    EXPECT_EQ(builder.get_buffer().size(), 36);

    auto view = View<Tuple<Vector<uint32_t>, StructTest>>(builder.get_buffer().data());
    EXPECT_EQ(view.get<0>().size(), 1);
    EXPECT_EQ(view.get<0>().at(0), 0);
    EXPECT_EQ(view.get<1>().x, 5);
    EXPECT_EQ(view.get<1>().y, 10);
    EXPECT_EQ(view.get_buffer_size(), 36);
}

/*
struct FlatSimpleEffect
{
    bool is_negated;
    size_t atom_id;
};  // __attribute__((packed));  // Pack the struct to avoid padding

static_assert(sizeof(FlatSimpleEffect) == 16);

TEST(FlatmemoryTests, TypesTupleConditionalEffectTest)
{
    uint8_t buffer[16] = { 00, 00, 00, 00, 00, 00, 00, 00, 04, 00, 00, 00, 00, 00, 00, 00 };
    auto effect = read_value<FlatSimpleEffect>(buffer);
    EXPECT_FALSE(effect.is_negated);
    EXPECT_EQ(effect.atom_id, 4);

    using FlatIndexListLayout = flatmemory::Vector<uint32_t>;

    using FlatConditionalEffectLayout = flatmemory::Tuple<FlatIndexListLayout,  // Positive static atom indices
                                                          FlatIndexListLayout,  // Negative static atom indices
                                                          FlatIndexListLayout,  // Positive fluent atom indices
                                                          FlatIndexListLayout,  // Negative fluent atom indices
                                                          FlatIndexListLayout,  // Positive derived atom indices
                                                          FlatIndexListLayout,  // Negative derived atom indices
                                                          FlatSimpleEffect>;    // simple add or delete effect

    Layout<FlatConditionalEffectLayout>().print();

    auto builder = Builder<FlatConditionalEffectLayout>();
    builder.get<0>().push_back(4);
    builder.get<0>().push_back(10);
    builder.get<3>().push_back(1);
    builder.get<6>().is_negated = false;
    builder.get<6>().atom_id = 4;

    builder.finish();

    auto view = View<FlatConditionalEffectLayout>(builder.get_buffer().data());
    print(builder.get_buffer().data(), builder.get_buffer().size());

    EXPECT_FALSE(view.get<6>().is_negated);
    EXPECT_EQ(view.get<6>().atom_id, 4);
}
*/

}
