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

TEST(FlatmemoryTests, TypesVectorDefaultConstructorTest)
{
    // 1D
    auto builder1d = Builder<Vector<uint64_t>>();
    builder1d.finish();
    EXPECT_EQ(builder1d.size(), 0);

    // 2D
    auto builder2d = Builder<Vector<Vector<uint64_t>>>();
    builder2d.finish();
    EXPECT_EQ(builder2d.size(), 0);
}

TEST(FlatmemoryTests, TypesVectorDefaultConstructorSizeTest)
{
    // 1D
    auto builder1d = Builder<Vector<uint64_t>>(2);
    builder1d[1] = 42;
    builder1d.finish();
    EXPECT_EQ(builder1d.size(), 2);

    // 2D
    auto builder2d = Builder<Vector<Vector<uint64_t>>>(2);
    builder2d[1].resize(3);
    builder2d.finish();
    EXPECT_EQ(builder2d.size(), 2);
    EXPECT_EQ(builder2d[0].size(), 0);
    EXPECT_EQ(builder2d[1].size(), 3);
}

TEST(FlatmemoryTests, TypesVectorDefaultConstructorSizeValueTest)
{
    // TODO
}

/**
 * Operators
 */

TEST(FlatmemoryTests, TypesVectorEqualToAndHashTest)
{
    // 1D
    using Vector1DLayout = Vector<uint64_t>;
    auto builder1d_1 = Builder<Vector1DLayout>(2);
    builder1d_1[1] = 42;
    builder1d_1.finish();

    auto builder1d_2 = Builder<Vector1DLayout>(2);
    builder1d_2[0] = 5;
    builder1d_2[1] = 42;
    builder1d_2.finish();

    auto builder1d_3 = Builder<Vector1DLayout>(2);
    builder1d_3[1] = 42;
    builder1d_3.finish();

    // Test Builder
    EXPECT_NE(builder1d_1, builder1d_2);
    EXPECT_EQ(std::hash<Builder<Vector1DLayout>>()(builder1d_1), std::hash<Builder<Vector1DLayout>>()(builder1d_3));
    EXPECT_EQ(builder1d_1, builder1d_3);
    EXPECT_NE(std::hash<Builder<Vector1DLayout>>()(builder1d_1), std::hash<Builder<Vector1DLayout>>()(builder1d_2));

    // Test View
    auto view1d_1 = View<Vector1DLayout>(builder1d_1.buffer().data());
    auto view1d_2 = View<Vector1DLayout>(builder1d_2.buffer().data());
    auto view1d_3 = View<Vector1DLayout>(builder1d_3.buffer().data());
    EXPECT_EQ(view1d_1, view1d_3);
    EXPECT_EQ(std::hash<View<Vector1DLayout>>()(view1d_1), std::hash<View<Vector1DLayout>>()(view1d_3));
    EXPECT_NE(view1d_1, view1d_2);
    EXPECT_NE(std::hash<View<Vector1DLayout>>()(view1d_1), std::hash<View<Vector1DLayout>>()(view1d_2));

    // Test ConstView
    auto const_view1d_1 = ConstView<Vector1DLayout>(builder1d_1.buffer().data());
    auto const_view1d_2 = ConstView<Vector1DLayout>(builder1d_2.buffer().data());
    auto const_view1d_3 = ConstView<Vector1DLayout>(builder1d_3.buffer().data());
    EXPECT_EQ(const_view1d_1, const_view1d_3);
    EXPECT_EQ(std::hash<ConstView<Vector1DLayout>>()(const_view1d_1), std::hash<ConstView<Vector1DLayout>>()(const_view1d_3));
    EXPECT_NE(const_view1d_1, const_view1d_2);
    EXPECT_NE(std::hash<ConstView<Vector1DLayout>>()(const_view1d_1), std::hash<ConstView<Vector1DLayout>>()(const_view1d_2));

    // Test Builder and View
    EXPECT_EQ(builder1d_1, view1d_1);
    EXPECT_EQ(builder1d_2, view1d_2);
    EXPECT_EQ(builder1d_3, view1d_3);
    EXPECT_NE(builder1d_1, view1d_2);
    EXPECT_EQ(builder1d_1, view1d_3);
    // Test View and Builder
    EXPECT_EQ(view1d_1, builder1d_1);
    EXPECT_EQ(view1d_2, builder1d_2);
    EXPECT_EQ(view1d_3, builder1d_3);
    EXPECT_NE(view1d_1, builder1d_2);
    EXPECT_EQ(view1d_1, builder1d_3);

    // Test Builder and ConstView
    EXPECT_EQ(builder1d_1, const_view1d_1);
    EXPECT_EQ(builder1d_2, const_view1d_2);
    EXPECT_EQ(builder1d_3, const_view1d_3);
    EXPECT_NE(builder1d_1, const_view1d_2);
    EXPECT_EQ(builder1d_1, const_view1d_3);
    // Test ConstView and Builder
    EXPECT_EQ(const_view1d_1, builder1d_1);
    EXPECT_EQ(const_view1d_2, builder1d_2);
    EXPECT_EQ(const_view1d_3, builder1d_3);
    EXPECT_NE(const_view1d_1, builder1d_2);
    EXPECT_EQ(const_view1d_1, builder1d_3);

    // Test View and ConstView
    EXPECT_EQ(view1d_1, const_view1d_1);
    EXPECT_EQ(view1d_2, const_view1d_2);
    EXPECT_EQ(view1d_3, const_view1d_3);
    EXPECT_NE(view1d_1, const_view1d_2);
    EXPECT_EQ(view1d_1, const_view1d_3);
    // Test ConstView and View
    EXPECT_EQ(const_view1d_1, view1d_1);
    EXPECT_EQ(const_view1d_2, view1d_2);
    EXPECT_EQ(const_view1d_3, view1d_3);
    EXPECT_NE(const_view1d_1, view1d_2);
    EXPECT_EQ(const_view1d_1, view1d_3);

    /* 2D */
    using Vector2DLayout = Vector<Vector<uint64_t>>;
    auto builder2d_1 = Builder<Vector2DLayout>(2);
    builder2d_1[0].resize(2);
    builder2d_1[1].resize(3);
    builder2d_1[1][2] = 42;
    builder2d_1.finish();

    auto builder2d_2 = Builder<Vector2DLayout>(2);
    builder2d_2[0].resize(2);
    builder2d_2[1].resize(3);
    builder2d_2[0][1] = 5;
    builder2d_2[1][2] = 42;
    builder2d_2.finish();

    auto builder2d_3 = Builder<Vector2DLayout>(2);
    builder2d_3[0].resize(2);
    builder2d_3[1].resize(3);
    builder2d_3[1][2] = 42;
    builder2d_3.finish();

    // Test Builder
    EXPECT_NE(builder2d_1, builder2d_2);
    EXPECT_EQ(std::hash<Builder<Vector2DLayout>>()(builder2d_1), std::hash<Builder<Vector2DLayout>>()(builder2d_3));
    EXPECT_EQ(builder2d_1, builder2d_3);
    EXPECT_NE(std::hash<Builder<Vector2DLayout>>()(builder2d_1), std::hash<Builder<Vector2DLayout>>()(builder2d_2));

    // Test View
    auto view2d_1 = View<Vector2DLayout>(builder2d_1.buffer().data());
    auto view2d_2 = View<Vector2DLayout>(builder2d_2.buffer().data());
    auto view2d_3 = View<Vector2DLayout>(builder2d_3.buffer().data());
    EXPECT_EQ(view2d_1, view2d_3);
    EXPECT_EQ(std::hash<View<Vector2DLayout>>()(view2d_1), std::hash<View<Vector2DLayout>>()(view2d_3));
    EXPECT_NE(view2d_1, view2d_2);
    EXPECT_NE(std::hash<View<Vector2DLayout>>()(view2d_1), std::hash<View<Vector2DLayout>>()(view2d_2));

    // Test ConstView
    auto const_view2d_1 = ConstView<Vector2DLayout>(builder2d_1.buffer().data());
    auto const_view2d_2 = ConstView<Vector2DLayout>(builder2d_2.buffer().data());
    auto const_view2d_3 = ConstView<Vector2DLayout>(builder2d_3.buffer().data());
    EXPECT_EQ(const_view2d_1, const_view2d_3);
    EXPECT_EQ(std::hash<ConstView<Vector2DLayout>>()(const_view2d_1), std::hash<ConstView<Vector2DLayout>>()(const_view2d_3));
    EXPECT_NE(const_view2d_1, const_view2d_2);
    EXPECT_NE(std::hash<ConstView<Vector2DLayout>>()(const_view2d_1), std::hash<ConstView<Vector2DLayout>>()(const_view2d_2));

    // Test Builder and View
    EXPECT_EQ(builder2d_1, view2d_1);
    EXPECT_EQ(builder2d_2, view2d_2);
    EXPECT_EQ(builder2d_3, view2d_3);
    EXPECT_NE(builder2d_1, view2d_2);
    EXPECT_EQ(builder2d_1, view2d_3);
    // Test View and Builder
    EXPECT_EQ(view2d_1, builder2d_1);
    EXPECT_EQ(view2d_2, builder2d_2);
    EXPECT_EQ(view2d_3, builder2d_3);
    EXPECT_NE(view2d_1, builder2d_2);
    EXPECT_EQ(view2d_1, builder2d_3);

    // Test Builder and ConstView
    EXPECT_EQ(builder2d_1, const_view2d_1);
    EXPECT_EQ(builder2d_2, const_view2d_2);
    EXPECT_EQ(builder2d_3, const_view2d_3);
    EXPECT_NE(builder2d_1, const_view2d_2);
    EXPECT_EQ(builder2d_1, const_view2d_3);
    // Test ConstView and Builder
    EXPECT_EQ(const_view2d_1, builder2d_1);
    EXPECT_EQ(const_view2d_2, builder2d_2);
    EXPECT_EQ(const_view2d_3, builder2d_3);
    EXPECT_NE(const_view2d_1, builder2d_2);
    EXPECT_EQ(const_view2d_1, builder2d_3);

    // Test View and ConstView
    EXPECT_EQ(view2d_1, const_view2d_1);
    EXPECT_EQ(view2d_2, const_view2d_2);
    EXPECT_EQ(view2d_3, const_view2d_3);
    EXPECT_NE(view2d_1, const_view2d_2);
    EXPECT_EQ(view2d_1, const_view2d_3);
    // Test ConstView and View
    EXPECT_EQ(const_view2d_1, view2d_1);
    EXPECT_EQ(const_view2d_2, view2d_2);
    EXPECT_EQ(const_view2d_3, view2d_3);
    EXPECT_NE(const_view2d_1, view2d_2);
    EXPECT_EQ(const_view2d_1, view2d_3);
}

/**
 * TODO: Others
 */

TEST(FlatmemoryTests, TypesVectorTest)
{
    auto builder = Builder<Vector<uint16_t>>();
    builder.resize(2);
    builder[0] = 5;
    builder[1] = 6;
    builder.finish();

    EXPECT_EQ(builder.buffer().size(), 12);

    auto view = View<Vector<uint16_t>>(builder.buffer().data());
    EXPECT_EQ(view.size(), 2);
    EXPECT_EQ(view[0], 5);
    EXPECT_EQ(view[1], 6);
}

TEST(FlatmemoryTests, TypesVector2Test)
{
    auto builder = Builder<Vector<uint16_t>>();
    builder.resize(3);
    builder.finish();

    EXPECT_EQ(builder.buffer().size(), 14);
}

TEST(FlatmemoryTests, TypesVectorVectorTest)
{
    auto builder = Builder<Vector<Vector<uint16_t>>>();
    builder.resize(2);
    builder[0].push_back(5);
    builder[1].push_back(6);
    builder[1].push_back(7);
    builder.finish();

    EXPECT_EQ(builder.buffer().size(), 38);

    auto view = View<Vector<Vector<uint16_t>>>(builder.buffer().data());
    EXPECT_EQ(view.buffer_size(), 38);
    EXPECT_EQ(view.size(), 2);
    EXPECT_EQ(view[0][0], 5);
    EXPECT_EQ(view[1][0], 6);
    EXPECT_EQ(view[1][1], 7);
}

TEST(FlatmemoryTests, TypesVectorViewIteratorTest)
{
    using VectorVectorUint32Layout = Vector<Vector<uint32_t>>;
    using VectorVectorUint32Builder = Builder<VectorVectorUint32Layout>;
    using VectorVectorUint32 = View<VectorVectorUint32Layout>;
    using ConstVectorVectorUint32 = ConstView<VectorVectorUint32Layout>;

    auto builder = VectorVectorUint32Builder();
    builder.resize(3);
    builder[0].resize(3);
    builder[1].resize(4);
    builder[2].resize(5);
    builder.finish();

    auto view = VectorVectorUint32(builder.buffer().data());
    for (const auto element : view)
    {
        EXPECT_GT(element.size(), 0);
    }

    auto const_view = ConstVectorVectorUint32(builder.buffer().data());
    for (const auto element : const_view)
    {
        EXPECT_GT(element.size(), 0);
    }
}

TEST(FlatmemoryTests, TypesVectorViewTest)
{
    auto builder1 = Builder<Vector<uint16_t>>();
    builder1.finish();

    auto builder2 = Builder<Vector<View<Vector<uint16_t>>>>();
    builder2.resize(3, View<Vector<uint16_t>>(builder1.buffer().data()));
    builder2.finish();

    // 2 additional padding are added from 10 to 12
    EXPECT_EQ(builder2.buffer().size(), 32);
}

}
