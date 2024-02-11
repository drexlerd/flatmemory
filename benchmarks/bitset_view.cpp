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
    static auto create_views(
        const size_t num_bitsets,
        const size_t bitset_size) {
        // Create num_bitset many views
        VariableSizedTypeVector<Bitset<uint64_t>> views;
        auto builder = Builder<Bitset<uint64_t>>();
        builder.get_blocks().resize(bitset_size);
        for (size_t i = 0; i < num_bitsets; ++i) {
            builder.finish();
            views.push_back(builder);
        }
        return views;
    }

    static void BM_BitsetViewCreate(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        for (auto _ : state) {
            auto views = create_views(num_bitsets, bitset_size);

            benchmark::DoNotOptimize(views);
        }
    }

    static void BM_BitsetViewAccess(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        auto views = create_views(num_bitsets, bitset_size);

        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 eng(rd()); // Seed the generator

        for (auto _ : state) {
            std::vector<int> indices(views.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::shuffle(indices.begin(), indices.end(), eng);

            for (int index : indices) {
                auto view = views[index];

                auto& default_bit_value = view.get_default_bit_value();
                benchmark::DoNotOptimize(default_bit_value);
                
                for (auto block : view.get_blocks()) {
                    benchmark::DoNotOptimize(block);
                }
            }
        }
    }
}


BENCHMARK(flatmemory::benchmarks::BM_BitsetViewCreate)->Args({1000000, 1});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewCreate)->Args({1000000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewCreate)->Args({1000000, 100});

BENCHMARK(flatmemory::benchmarks::BM_BitsetViewAccess)->Args({1000000, 1});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewAccess)->Args({1000000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewAccess)->Args({1000000, 100});

BENCHMARK_MAIN();
