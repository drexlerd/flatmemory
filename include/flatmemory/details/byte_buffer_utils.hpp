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

#include "type_traits.hpp"

#include <cassert>
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <iomanip>


namespace flatmemory
{

/**
 * Assertion logic
*/

template<typename T>
bool test_correct_alignment(const uint8_t* buf) {
    return (reinterpret_cast<uintptr_t>(buf) % alignof(T)) == 0;
}


/**
 * Read values from raw data.
*/

template<IsTriviallyCopyable T>
T& read_value(uint8_t* buf) {
    assert(test_correct_alignment<T>(buf));
    return *reinterpret_cast<T*>(buf);
}

template<IsTriviallyCopyable T>
const T& read_value(const uint8_t* buf) {
    assert(test_correct_alignment<T>(buf));
    return *reinterpret_cast<const T*>(buf);
}


/**
 * Write values to raw data.
*/

template<IsTriviallyCopyable T>
void write_value(uint8_t* buf, const T& value) {
    *reinterpret_cast<T*>(buf) = value;
}


/**
 * Pretty printing
*/
inline void print(const uint8_t* data, size_t num_bytes) {
    for (size_t i = 0; i < num_bytes; ++i) {
        // Print each byte in hexadecimal format with leading zeros
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl; // Reset to decimal output
}





}

#endif
