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

#ifndef FLATMEMORY_BYTE_STREAM_UTILS_HPP_
#define FLATMEMORY_BYTE_STREAM_UTILS_HPP_

#include <cstdint>
#include <cstddef>
#include <type_traits>
#include <iostream>
#include <iomanip>


namespace flatmemory
{

/**
 * Ensures that we only serialize types that are trivially copieable.
 * Trivially copieable types are int float double ..
 * Untrivially copieable types are std::vector, std::unordered_set, ...
 * For untrivially copieable types we will provide our own logic.
*/
template<typename T>
concept TriviallyCopyable = std::is_trivially_copyable_v<T>;


/**
 * Read values from raw data.
*/

template<TriviallyCopyable T>
T& read_value(uint8_t* data) {
    return *reinterpret_cast<T*>(data);
}

template<TriviallyCopyable T>
const T& read_value(const uint8_t* data) {
    return *reinterpret_cast<const T*>(data);
}

template<TriviallyCopyable T>
T* read_pointer(uint8_t* data) {
    return reinterpret_cast<T*>(*reinterpret_cast<uintptr_t*>(data));
}

template<TriviallyCopyable T>
const T* read_pointer(const uint8_t* data) {
    return reinterpret_cast<const T*>(*reinterpret_cast<const uintptr_t*>(data));
}


/**
 * Convert between raw data and pointers
*/

template<typename T>
uint64_t pointer_to_uint64_t(const T* ptr) {
    uintptr_t address = reinterpret_cast<uintptr_t>(ptr);
    return static_cast<uint64_t>(address);
}

template<typename T>
T* uint64_t_to_pointer(uint64_t address) {
    uintptr_t ptrAddress = static_cast<uintptr_t>(address);
    return reinterpret_cast<T*>(ptrAddress);
}


inline void print(const uint8_t* data, size_t num_bytes) {
    for (size_t i = 0; i < num_bytes; ++i) {
        // Print each byte in hexadecimal format with leading zeros
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl; // Reset to decimal output
}





}

#endif
