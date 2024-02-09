/*
 * Copyright (C) 2023 Dominik Drexler and Simon Stahlberg
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

#include <benchmark/benchmark.h>

#include <iostream>
#include <random>


namespace flatmemory::benchmarks 
{
    static void BM_BitsetBuilder(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        for (auto _ : state) {
            // Create num_bitset many bitsets
            std::vector<Builder<Bitset<uint64_t>>> builders;
            builders.reserve(num_bitsets);
            for (size_t i = 0; i < num_bitsets; ++i) {
                auto builder = Builder<Bitset<uint64_t>>();
                builder.get_blocks().resize(bitset_size);
                builders.push_back(std::move(builder));
            }

            benchmark::DoNotOptimize(builders);
        }
    }


    static void BM_BitsetView(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        for (auto _ : state) {
            // Create num_bitset many views
            VariableSizedTypeVector<Bitset<uint64_t>> views;
            auto builder = Builder<Bitset<uint64_t>>();
            builder.get_blocks().resize(bitset_size);
            builder.finish();
            for (size_t i = 0; i < num_bitsets; ++i) {
                views.push_back(builder);
            }

            benchmark::DoNotOptimize(views);
        }
    }
}


BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilder)->Args({100000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetView)->Args({100000, 10});

BENCHMARK_MAIN();
