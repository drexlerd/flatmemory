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
    static auto create_builders(
        const size_t num_bitsets,
        const size_t bitset_size) {
        // Create num_bitset many bitsets
        std::vector<Builder<Bitset<uint64_t>>> builders;
        builders.reserve(num_bitsets);
        for (size_t i = 0; i < num_bitsets; ++i) {
            auto builder = Builder<Bitset<uint64_t>>();
            builder.get_blocks().resize(bitset_size);
            builders.push_back(std::move(builder));
        }
        return builders;
    }

    static void BM_BitsetBuilderCreate(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        for (auto _ : state) {
            auto builders = create_builders(num_bitsets, bitset_size);

            benchmark::DoNotOptimize(builders);
        }
    }

    static void BM_BitsetBuilderAccess(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        auto builders = create_builders(num_bitsets, bitset_size);

        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 eng(rd()); // Seed the generator

        for (auto _ : state) {
            std::vector<int> indices(builders.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::shuffle(indices.begin(), indices.end(), eng);

            for (int index : indices) {
                auto builder = builders[index];

                auto& default_bit_value = builder.get_default_bit_value();
                benchmark::DoNotOptimize(default_bit_value);
                
                for (auto block : builder.get_blocks()) {
                    benchmark::DoNotOptimize(block);
                }   
            }
        }
    }
}


BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderCreate)->Args({1000000, 1});
BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderCreate)->Args({1000000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderCreate)->Args({1000000, 100});

BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderAccess)->Args({1000000, 1});
BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderAccess)->Args({1000000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderAccess)->Args({1000000, 100});

BENCHMARK_MAIN();
