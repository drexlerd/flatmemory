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

#ifndef FLATMEMORY_BYTE_BUFFER_HPP_
#define FLATMEMORY_BYTE_BUFFER_HPP_

#include "byte_buffer_utils.hpp"

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <vector>
#include <iostream>


namespace flatmemory {


class ByteBuffer {
private:
    std::vector<uint8_t> m_data;
    size_t m_size;

    inline void resize_to_fit(size_t pos, size_t amount) {
        size_t final_size = pos + amount;
        if (final_size > m_data.size()) {
            m_data.resize(final_size);
        }
    }

public:
    ByteBuffer() : m_size(0) { }

    size_t write(size_t pos, const uint8_t* data, size_t amount) {
        resize_to_fit(pos, amount);
        std::memcpy(&m_data[pos], data, amount);
        return amount;
    }
    
    /// @brief Writes a value to the stream.
    template<IsTriviallyCopyable T>
    size_t write(size_t pos, const T& value) {
        write(pos, reinterpret_cast<const uint8_t*>(&value), sizeof(value));
        return sizeof(value);
    }

    /// @brief Writes a pointer to the stream
    template<typename T>
    size_t write(size_t pos, const T* pointer) {
        uintptr_t address = reinterpret_cast<uintptr_t>(pointer);
        write(pos, reinterpret_cast<const uint8_t*>(&address), sizeof(address));
        return sizeof(address);
    }

    size_t write_padding(size_t pos, size_t amount) {
        if (amount > 0) {
            // Write num_byte many zeros 0's 
            resize_to_fit(pos, amount);
            std::memset(&m_data[pos], 0, amount);
        }
        return amount;
    }

    /// @brief Set the final size of the buffer.
    /// @param count 
    void set_size(size_t count) { m_size = count; }

    [[nodiscard]] uint8_t* data() { return m_data.data(); }
    [[nodiscard]] const uint8_t* data() const { return m_data.data(); }

    [[nodiscard]] size_t size() const { return m_size; }
    [[nodiscard]] size_t capacity() const { return m_data.capacity(); }
};

} 

#endif