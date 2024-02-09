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


namespace flatmemory 
{
    using State = Tuple<uint32_t, Bitset<uint64_t>>;
    using StateView = View<State>;
}


namespace std 
{
    template<>
    struct hash<flatmemory::StateView>
    {
        std::size_t operator()(const flatmemory::StateView& view) const {
            return 0;
        }
    };

    template<>
    struct equal_to<flatmemory::StateView>
    {
        bool operator()(const flatmemory::StateView& view_left, const flatmemory::StateView& view_right) const {
            return true;
        }
    };
}


namespace flatmemory::tests
{
    TEST(FlatmemoryTests, ContainersUnorderedSetTest) {
        UnorderedSet<Tuple<uint32_t, Bitset<uint64_t>>> unordered_set;
    }
}
