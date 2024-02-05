#include <flatmemory/types/tuple.hpp>
#include <flatmemory/types/uint16.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{

TEST(FlatmemoryTests, TypesTupleTest) {
    EXPECT_EQ((Layout<TupleTag<Uint16Tag, Uint16Tag, Uint16Tag>>::alignment), 2);

    auto builder = Builder<TupleTag<Uint16Tag, Uint16Tag, Uint16Tag>>();
    builder.get_builder<0>().get_value() = 5;
    builder.get_builder<1>().get_value() = 6;
    builder.get_builder<2>().get_value() = 7;
    builder.finish();
    EXPECT_NE(builder.get_data(), nullptr);
    EXPECT_EQ(builder.get_size(), 6);

    auto view = View<TupleTag<Uint16Tag, Uint16Tag, Uint16Tag>>(builder.get_data());
    EXPECT_EQ(view.get<0>().get_value(), 5);
    EXPECT_EQ(view.get<1>().get_value(), 6);
    EXPECT_EQ(view.get<2>().get_value(), 7);
}




}
