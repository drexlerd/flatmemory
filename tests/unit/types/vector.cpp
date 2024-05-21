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

TEST(FlatmemoryTests, TypesVectorEqualTest)
{
    // 1D
    auto builder1d = Builder<Vector<uint64_t>>(2);
    builder1d[1] = 42;
    builder1d.finish();

    auto builder1d_2 = Builder<Vector<uint64_t>>(2);
    builder1d_2[0] = 5;
    builder1d_2[1] = 42;
    builder1d_2.finish();

    auto builder1d_3 = Builder<Vector<uint64_t>>(2);
    builder1d_3[1] = 42;
    builder1d_3.finish();

    // Test Builder
    EXPECT_NE(builder1d, builder1d_2);
    EXPECT_EQ(builder1d, builder1d_3);

    // Test View
    auto view1d = View<Vector<uint64_t>>(builder1d.buffer().data());
    auto view1d_2 = View<Vector<uint64_t>>(builder1d_2.buffer().data());
    auto view1d_3 = View<Vector<uint64_t>>(builder1d_3.buffer().data());
    EXPECT_EQ(view1d, view1d_3);
    EXPECT_NE(view1d, view1d_2);

    // Test ConstView
    auto const_view1d = ConstView<Vector<uint64_t>>(builder1d.buffer().data());
    auto const_view1d_2 = ConstView<Vector<uint64_t>>(builder1d_2.buffer().data());
    auto const_view1d_3 = ConstView<Vector<uint64_t>>(builder1d_3.buffer().data());
    EXPECT_EQ(const_view1d, const_view1d_3);
    EXPECT_NE(const_view1d, const_view1d_2);

    // Test Builder and View
    EXPECT_EQ(builder1d, view1d);
    EXPECT_EQ(builder1d_2, view1d_2);
    EXPECT_EQ(builder1d_3, view1d_3);
    EXPECT_NE(builder1d, view1d_2);
    EXPECT_EQ(builder1d, view1d_3);
    // Test View and Builder
    EXPECT_EQ(view1d, builder1d);
    EXPECT_EQ(view1d_2, builder1d_2);
    EXPECT_EQ(view1d_3, builder1d_3);
    EXPECT_NE(view1d, builder1d_2);
    EXPECT_EQ(view1d, builder1d_3);

    // Test Builder and ConstView
    EXPECT_EQ(builder1d, const_view1d);
    EXPECT_EQ(builder1d_2, const_view1d_2);
    EXPECT_EQ(builder1d_3, const_view1d_3);
    EXPECT_NE(builder1d, const_view1d_2);
    EXPECT_EQ(builder1d, const_view1d_3);
    // Test ConstView and Builder
    EXPECT_EQ(const_view1d, builder1d);
    EXPECT_EQ(const_view1d_2, builder1d_2);
    EXPECT_EQ(const_view1d_3, builder1d_3);
    EXPECT_NE(const_view1d, builder1d_2);
    EXPECT_EQ(const_view1d, builder1d_3);

    // Test View and ConstView
    EXPECT_EQ(view1d, const_view1d);
    EXPECT_EQ(view1d_2, const_view1d_2);
    EXPECT_EQ(view1d_3, const_view1d_3);
    EXPECT_NE(view1d, const_view1d_2);
    EXPECT_EQ(view1d, const_view1d_3);
    // Test ConstView and View
    EXPECT_EQ(const_view1d, view1d);
    EXPECT_EQ(const_view1d_2, view1d_2);
    EXPECT_EQ(const_view1d_3, view1d_3);
    EXPECT_NE(const_view1d, view1d_2);
    EXPECT_EQ(const_view1d, view1d_3);

    /* 2D */
    auto builder2d = Builder<Vector<Vector<uint64_t>>>(2);
    builder2d[0].resize(2);
    builder2d[1].resize(3);
    builder2d[1][2] = 42;
    builder2d.finish();

    auto builder2d_2 = Builder<Vector<Vector<uint64_t>>>(2);
    builder2d_2[0].resize(2);
    builder2d_2[1].resize(3);
    builder2d_2[0][1] = 5;
    builder2d_2[1][2] = 42;
    builder2d_2.finish();

    auto builder2d_3 = Builder<Vector<Vector<uint64_t>>>(2);
    builder2d_3[0].resize(2);
    builder2d_3[1].resize(3);
    builder2d_3[1][2] = 42;
    builder2d_3.finish();

    // Test Builder
    EXPECT_NE(builder2d, builder2d_2);
    EXPECT_EQ(builder2d, builder2d_3);

    // Test View
    auto view2d = View<Vector<Vector<uint64_t>>>(builder2d.buffer().data());
    auto view2d_2 = View<Vector<Vector<uint64_t>>>(builder2d_2.buffer().data());
    auto view2d_3 = View<Vector<Vector<uint64_t>>>(builder2d_3.buffer().data());
    EXPECT_EQ(view2d, view2d_3);
    EXPECT_NE(view2d, view2d_2);

    // Test ConstView
    auto const_view2d = ConstView<Vector<Vector<uint64_t>>>(builder2d.buffer().data());
    auto const_view2d_2 = ConstView<Vector<Vector<uint64_t>>>(builder2d_2.buffer().data());
    auto const_view2d_3 = ConstView<Vector<Vector<uint64_t>>>(builder2d_3.buffer().data());
    EXPECT_EQ(const_view2d, const_view2d_3);
    EXPECT_NE(const_view2d, const_view2d_2);

    // Test Builder and View
    EXPECT_EQ(builder2d, view2d);
    EXPECT_EQ(builder2d_2, view2d_2);
    EXPECT_EQ(builder2d_3, view2d_3);
    EXPECT_NE(builder2d, view2d_2);
    EXPECT_EQ(builder2d, view2d_3);
    // Test View and Builder
    EXPECT_EQ(view2d, builder2d);
    EXPECT_EQ(view2d_2, builder2d_2);
    EXPECT_EQ(view2d_3, builder2d_3);
    EXPECT_NE(view2d, builder2d_2);
    EXPECT_EQ(view2d, builder2d_3);

    // Test Builder and ConstView
    EXPECT_EQ(builder2d, const_view2d);
    EXPECT_EQ(builder2d_2, const_view2d_2);
    EXPECT_EQ(builder2d_3, const_view2d_3);
    EXPECT_NE(builder2d, const_view2d_2);
    EXPECT_EQ(builder2d, const_view2d_3);
    // Test ConstView and Builder
    EXPECT_EQ(const_view2d, builder2d);
    EXPECT_EQ(const_view2d_2, builder2d_2);
    EXPECT_EQ(const_view2d_3, builder2d_3);
    EXPECT_NE(const_view2d, builder2d_2);
    EXPECT_EQ(const_view2d, builder2d_3);

    // Test View and ConstView
    EXPECT_EQ(view2d, const_view2d);
    EXPECT_EQ(view2d_2, const_view2d_2);
    EXPECT_EQ(view2d_3, const_view2d_3);
    EXPECT_NE(view2d, const_view2d_2);
    EXPECT_EQ(view2d, const_view2d_3);
    // Test ConstView and View
    EXPECT_EQ(const_view2d, view2d);
    EXPECT_EQ(const_view2d_2, view2d_2);
    EXPECT_EQ(const_view2d_3, view2d_3);
    EXPECT_NE(const_view2d, view2d_2);
    EXPECT_EQ(const_view2d, view2d_3);
}

/**
 * TODO: Others
 */

TEST(FlatmemoryTests, TypesVectorTest)
{
    EXPECT_EQ((Layout<Vector<uint16_t>>::final_alignment), 4);

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
    EXPECT_EQ((Layout<Vector<uint16_t>>::final_alignment), 4);

    auto builder = Builder<Vector<uint16_t>>();
    builder.resize(3);
    builder.finish();

    // 2 additional padding are added from 14 to 16
    EXPECT_EQ(builder.buffer().size(), 16);
}

TEST(FlatmemoryTests, TypesVectorVectorTest)
{
    EXPECT_EQ((Layout<Vector<Vector<uint16_t>>>::final_alignment), 4);

    auto builder = Builder<Vector<Vector<uint16_t>>>();
    builder.resize(2);
    builder[0].push_back(5);
    builder[1].push_back(6);
    builder[1].push_back(7);
    builder.finish();

    EXPECT_EQ(builder.buffer().size(), 40);

    auto view = View<Vector<Vector<uint16_t>>>(builder.buffer().data());
    EXPECT_EQ(view.buffer_size(), 40);
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
    EXPECT_EQ((Layout<Vector<View<Vector<uint16_t>>>>::final_alignment), 8);

    auto builder = Builder<Vector<View<Vector<uint16_t>>>>();
    builder.resize(3);
    builder.finish();

    // 2 additional padding are added from 10 to 12
    EXPECT_EQ(builder.buffer().size(), 32);
}

TEST(FlatmemoryTests, TypesVectorEqualityTest)
{
    using VectorLayout = Vector<uint64_t>;

    auto builder1 = Builder<VectorLayout>();
    builder1.push_back(5);
    builder1.push_back(10);
    builder1.finish();

    auto builder2 = Builder<VectorLayout>();
    builder2.push_back(5);
    builder2.push_back(10);
    builder2.finish();

    auto builder3 = Builder<VectorLayout>();
    builder3.push_back(5);
    builder3.push_back(9);
    builder3.finish();

    EXPECT_TRUE((builder1 == builder2));
    EXPECT_EQ(builder1.hash(), builder2.hash());

    EXPECT_FALSE((builder1 == builder3));
    EXPECT_NE(builder1.hash(), builder3.hash());

    EXPECT_FALSE((builder2 == builder3));
    EXPECT_NE(builder2.hash(), builder3.hash());

    auto view1 = View<VectorLayout>(builder1.buffer().data());
    auto view2 = View<VectorLayout>(builder2.buffer().data());
    auto view3 = View<VectorLayout>(builder3.buffer().data());

    EXPECT_TRUE((view1 == view2));
    EXPECT_EQ(view1.hash(), view2.hash());

    EXPECT_FALSE((view1 == view3));
    EXPECT_NE(view1.hash(), view3.hash());

    EXPECT_FALSE((view2 == view3));
    EXPECT_NE(view2.hash(), view3.hash());

    auto const_view1 = ConstView<VectorLayout>(builder1.buffer().data());
    auto const_view2 = ConstView<VectorLayout>(builder2.buffer().data());
    auto const_view3 = ConstView<VectorLayout>(builder3.buffer().data());

    EXPECT_TRUE((const_view1 == const_view2));
    EXPECT_EQ(const_view1.hash(), const_view2.hash());

    EXPECT_FALSE((const_view1 == const_view3));
    EXPECT_NE(const_view1.hash(), const_view3.hash());

    EXPECT_FALSE((const_view2 == const_view3));
    EXPECT_NE(const_view2.hash(), const_view3.hash());
}

}
