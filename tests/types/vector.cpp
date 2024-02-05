#include <flatmemory/types/vector.hpp>
#include <flatmemory/types/uint16.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{

TEST(FlatmemoryTests, TypesVectorTest) {
    EXPECT_EQ((Layout<VectorTag<Uint16Tag>>::alignment), 4);

    auto builder = Builder<VectorTag<Uint16Tag>>();
    builder.get_builders().resize(2);
    builder.get_builders()[0].get_value() = 5;
    builder.get_builders()[1].get_value() = 6;
    builder.finish();

    EXPECT_EQ(builder.get_size(), 8);

    auto view = View<VectorTag<Uint16Tag>>(builder.get_data());
    EXPECT_EQ(view.get_size(), 2);
    EXPECT_EQ(view[0].get_value(), 5);
    EXPECT_EQ(view[1].get_value(), 6);
}


TEST(FlatmemoryTests, TypesVector2Test) {
    EXPECT_EQ((Layout<VectorTag<Uint16Tag>>::alignment), 4);

    auto builder = Builder<VectorTag<Uint16Tag>>();
    builder.get_builders().resize(3);
    builder.finish();

    // 2 additional padding are added from 10 to 12
    EXPECT_EQ(builder.get_size(), 12);
}



}
