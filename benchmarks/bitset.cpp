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
            // Create num_bitset many bitsets
            auto builders = create_builders(num_bitsets, bitset_size);

            benchmark::DoNotOptimize(builders);
        }
    }

    static void BM_BitsetBuilderAccess(benchmark::State& state) {
        const size_t num_bitsets = state.range(0);
        const size_t bitset_size = state.range(1);

        // Create num_bitset many bitsets
        auto builders = create_builders(num_bitsets, bitset_size);

        for (auto _ : state) {
            // Access the data
            for (auto& builder : builders) {
                auto& default_bit_value = builder.get_default_bit_value();
                benchmark::DoNotOptimize(default_bit_value);
                
                auto& blocks = builder.get_blocks();
                for (size_t i = 0; i < blocks.size(); ++i) {
                    auto block = blocks[i];
                    benchmark::DoNotOptimize(block);
                }
                
            }

            benchmark::DoNotOptimize(builders);
        }
    }


    static auto create_views(
        const size_t num_bitsets,
        const size_t bitset_size) {
        // Create num_bitset many views
        VariableSizedTypeVector<Bitset<uint64_t>> views;
        auto builder = Builder<Bitset<uint64_t>>();
        builder.get_blocks().resize(bitset_size);
        builder.finish();
        for (size_t i = 0; i < num_bitsets; ++i) {
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

        for (auto _ : state) {
            // Access the data
            for (size_t i = 0; i < views.size(); ++i) {
                auto view = views[i];
                auto& default_bit_value = view.get_default_bit_value();
                benchmark::DoNotOptimize(default_bit_value);
                
                auto blocks = view.get_blocks();
                size_t size = blocks.size();
                for (size_t i = 0; i < size; ++i) {
                    auto block = blocks[i];
                    benchmark::DoNotOptimize(block);
                }
                
            }
        }
    }
}


BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderCreate)->Args({100000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetBuilderAccess)->Args({100000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewCreate)->Args({100000, 10});
BENCHMARK(flatmemory::benchmarks::BM_BitsetViewAccess)->Args({100000, 10});


BENCHMARK_MAIN();
