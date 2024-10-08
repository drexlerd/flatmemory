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

#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

namespace flatmemory
{

class ByteBuffer
{
private:
    std::vector<uint8_t> m_data;
    size_t m_size;

    inline void resize_to_fit(size_t pos, size_t amount)
    {
        size_t final_size = pos + amount;
        if (final_size > m_data.size())
        {
            m_data.resize(final_size);
        }
    }

public:
    ByteBuffer() : m_size(0) {}

    size_t write(size_t pos, const uint8_t* data, size_t amount)
    {
        resize_to_fit(pos, amount);
        std::memcpy(&m_data[pos], data, amount);
        return amount;
    }

    /// @brief Writes a value to the stream.
    template<IsTriviallyCopyable T>
    size_t write(size_t pos, const T& value)
    {
        write(pos, reinterpret_cast<const uint8_t*>(&value), sizeof(value));
        return sizeof(value);
    }

    /// @brief Set the final size of the buffer.
    /// @param count
    void set_size(size_t count) { m_size = count; }

    uint8_t* data() { return m_data.data(); }
    const uint8_t* data() const { return m_data.data(); }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_data.capacity(); }
};

}

#endif