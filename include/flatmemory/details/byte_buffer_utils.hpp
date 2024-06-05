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

#ifndef FLATMEMORY_BYTE_BUFFER_UTILS_HPP_
#define FLATMEMORY_BYTE_BUFFER_UTILS_HPP_

#include "flatmemory/details/concepts.hpp"

#include <bitset>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>

namespace flatmemory
{

/**
 * Assertion logic
 */

template<typename T>
bool test_correct_alignment(const uint8_t* buf)
{
    return (reinterpret_cast<uintptr_t>(buf) % alignof(T)) == 0;
}

inline bool test_correct_alignment(const uint8_t* buf, size_t alignment) { return ((reinterpret_cast<uintptr_t>(buf) % alignment) == 0); }

/**
 * Read values from raw data.
 */

template<IsTriviallyCopyable T>
T& read_value(uint8_t* buf)
{
    assert(test_correct_alignment<T>(buf));
    return *reinterpret_cast<T*>(buf);
}

template<IsTriviallyCopyable T>
const T& read_value(const uint8_t* buf)
{
    assert(test_correct_alignment<T>(buf));
    return *reinterpret_cast<const T*>(buf);
}

/**
 * Write values to raw data.
 */

template<IsTriviallyCopyable T>
void write_value(uint8_t* buf, const T& value)
{
    *reinterpret_cast<T*>(buf) = value;
}

/**
 * Pretty printing
 */

/// @brief Print alignment many bytes as hexadecimal in a row with
///        additional byte numbers above.
inline size_t print_row(const uint8_t* data, size_t num_bytes, size_t alignment, size_t row_number)
{
    // 0 1 2 3
    const auto first_pos = reinterpret_cast<uintptr_t>(data) % alignment;
    const auto amount = alignment - first_pos;

    for (size_t i = 0 + row_number * alignment; i < alignment + row_number * alignment; ++i)
    {
        if (i < first_pos)
        {
            continue;
        }
        std::cout << std::setw(4) << std::setfill(' ') << std::left << i;
    }
    std::cout << std::endl;

    for (size_t i = 0; i < alignment; ++i)
    {
        if (i < first_pos)
        {
            continue;
        }
        std::cout << std::left << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<int>(data[i - first_pos]) << "  ";
    }
    std::cout << std::dec << std::endl << std::endl;

    return amount;
}

inline void print(const uint8_t* data, size_t num_bytes, size_t alignment)
{
    auto row_number = size_t(0);
    while (num_bytes > 0)
    {
        num_bytes -= print_row(data, num_bytes, alignment, row_number++);
        data += num_bytes;
    }
}

inline void print(const uint8_t* data, size_t num_bytes)
{
    for (size_t i = 0; i < num_bytes; ++i)
    {
        // Print each byte in hexadecimal format with leading zeros
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl;  // Reset to decimal output
}

inline void printBits(const uint8_t* data, size_t num_bytes)
{
    for (size_t i = 0; i < num_bytes; ++i)
    {
        // Print each byte as a series of bits
        std::cout << std::bitset<8>(data[i]) << " ";
    }
    std::cout << std::endl;  // New line at the end
}

}

#endif
