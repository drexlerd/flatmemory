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

        EXPECT_FALSE(builder.has_value());
        EXPECT_ANY_THROW(builder.value());
        EXPECT_EQ(builder.buffer().size(), 1);
    }
}

TEST(FlatmemoryTests, TypesOptionalConstructorTest)
{
    {
        auto builder = Builder<Optional<uint64_t>>(42);
        builder.finish();

        EXPECT_TRUE(builder.has_value());
        EXPECT_EQ(builder.value(), 42);
        EXPECT_EQ(builder.buffer().size(), 9);
    }

    {
        auto builder = Builder<Optional<Vector<uint64_t>>>(Builder<Vector<uint64_t>>(10));
        builder.value()[5] = 42;
        builder.value()[7] = 19;
        builder.finish();

        EXPECT_TRUE(builder.has_value());
        EXPECT_EQ(builder.value().size(), 10);
        EXPECT_EQ(builder.value()[5], 42);
        EXPECT_EQ(builder.value()[7], 19);
        EXPECT_EQ(builder.buffer().size(), 89);
    }
}

TEST(FlatmemoryTests, TypesOptionalEqualToAndHashTest)
{
    using VectorLayout = Vector<uint64_t>;
    using OptionalLayout = Optional<VectorLayout>;

    auto builder1 = Builder<OptionalLayout>(Builder<VectorLayout>());
    builder1.value().resize(3);
    builder1.value()[0] = 42;
    builder1.value()[2] = 19;
    builder1.finish();

    auto builder2 = Builder<OptionalLayout>(Builder<VectorLayout>());
    builder2.value().resize(2);
    builder2.value()[0] = 42;
    builder2.finish();

    auto builder3 = Builder<OptionalLayout>(Builder<VectorLayout>());
    builder3.value().resize(3);
    builder3.value()[0] = 42;
    builder3.value()[2] = 19;
    builder3.finish();

    // Test builder
    EXPECT_EQ(builder1, builder3);
    EXPECT_EQ(std::hash<Builder<OptionalLayout>>()(builder1), std::hash<Builder<OptionalLayout>>()(builder3));
    EXPECT_NE(builder1, builder2);
    EXPECT_NE(std::hash<Builder<OptionalLayout>>()(builder1), std::hash<Builder<OptionalLayout>>()(builder2));

    // Test View
    auto view1 = View<OptionalLayout>(builder1.buffer().data());
    auto view2 = View<OptionalLayout>(builder2.buffer().data());
    auto view3 = View<OptionalLayout>(builder3.buffer().data());
    EXPECT_EQ(view1, view3);
    EXPECT_EQ(std::hash<View<OptionalLayout>>()(view1), std::hash<View<OptionalLayout>>()(view3));
    EXPECT_NE(view1, view2);
    EXPECT_NE(std::hash<View<OptionalLayout>>()(view1), std::hash<View<OptionalLayout>>()(view2));

    // Test ConstView
    auto const_view1 = ConstView<OptionalLayout>(builder1.buffer().data());
    auto const_view2 = ConstView<OptionalLayout>(builder2.buffer().data());
    auto const_view3 = ConstView<OptionalLayout>(builder3.buffer().data());
    EXPECT_EQ(const_view1, const_view3);
    EXPECT_EQ(std::hash<ConstView<OptionalLayout>>()(const_view1), std::hash<ConstView<OptionalLayout>>()(const_view3));
    EXPECT_NE(const_view1, const_view2);
    EXPECT_NE(std::hash<ConstView<OptionalLayout>>()(const_view1), std::hash<ConstView<OptionalLayout>>()(const_view2));

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

}