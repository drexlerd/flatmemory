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
#include <vector>
#include <iostream>


namespace flatmemory {


class ByteBuffer {
private:
    std::vector<uint8_t> m_data;

public:
    size_t write(const uint8_t* data, size_t amount) {
        m_data.insert(m_data.end(), data, data + amount);
        return amount;
    }
    
    /// @brief Writes a value to the stream.
    template<IsTriviallyCopyable T>
    size_t write(const T& value) {
        assert(test_correct_alignment<T>(m_data.data()));
        write(reinterpret_cast<const uint8_t*>(&value), sizeof(value));
        return sizeof(T);
    }

    /// @brief Writes a value to the stream to a specific position
    ///        Assumes that the value fits into the buffer.
    template<IsTriviallyCopyable T>
    size_t write(size_t pos, const T& value) {
        assert(test_correct_alignment<T*>(m_data.data() + pos));
        assert(pos + sizeof(T) <= m_data.size());
        write_value(m_data.data() + pos, value);
        return sizeof(T);
    }

    /// @brief Writes padding to the stream
    size_t write_padding(size_t num_bytes) {
        m_data.insert(m_data.end(), num_bytes, 0);
        return num_bytes;
    }

    void clear() { m_data.clear(); }

    [[nodiscard]] uint8_t* data() { return m_data.data(); }
    [[nodiscard]] const uint8_t* data() const { return m_data.data(); }

    [[nodiscard]] size_t size() const { return m_data.size(); }
    [[nodiscard]] size_t capacity() const { return m_data.capacity(); }
};

} 

#endif