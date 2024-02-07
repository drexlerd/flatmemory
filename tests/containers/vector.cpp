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

#include <flatmemory/containers/vector.hpp>
#include <flatmemory/types/vector.hpp>
#include <flatmemory/types/tuple.hpp>

#include <gtest/gtest.h>

#include <string>


namespace flatmemory::tests
{
    TEST(FlatmemoryTests, ContainersVariableSizedTypeVectorTest) {
        VariableSizedTypeVector<Vector<uint16_t>> vector;
    }

    TEST(FlatmemoryTests, ContainersFixedSizedTypeVectorTest) {
        FixedSizedTypeVector<Tuple<uint16_t, uint32_t>> vector(Builder<Tuple<uint16_t, uint32_t>>{});
    }
}
