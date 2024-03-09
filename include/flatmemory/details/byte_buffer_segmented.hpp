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

#ifndef FLATMEMORY_BYTE_BUFFER_SEGMENTED_HPP_
#define FLATMEMORY_BYTE_BUFFER_SEGMENTED_HPP_

#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/type_traits.hpp"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

namespace flatmemory
{
class ByteBufferSegmented
{
private:
    NumBytes m_num_bytes_per_segment;
    std::vector<uint8_t*> m_segments;

    size_t cur_segment_id;
    size_t cur_segment_pos;

    size_t m_size;
    size_t m_capacity;

    size_t last_written;

    /// @brief Allocate a block of size N and update tracking variables.
    void increase_capacity()
    {
        if (cur_segment_id == (m_segments.size() - 1))
        {
            m_segments.push_back(new uint8_t[m_num_bytes_per_segment]);
            cur_segment_pos = 0;
            m_capacity += m_num_bytes_per_segment;
        }
        ++cur_segment_id;
        assert(cur_segment_id < m_segments.size());
    }

public:
    explicit ByteBufferSegmented(NumBytes n = 1000000) :
        m_num_bytes_per_segment(n),
        cur_segment_id(-1),
        cur_segment_pos(0),
        m_size(0),
        m_capacity(0),
        last_written(0)
    {
        // allocate first block of memory
        increase_capacity();
        assert(cur_segment_pos == 0);
        assert(cur_segment_id == 0);
    }
    ~ByteBufferSegmented()
    {
        for (uint8_t* ptr : m_segments)
        {
            delete[] ptr;
        }
    }
    ByteBufferSegmented(const ByteBufferSegmented& other) = delete;
    ByteBufferSegmented& operator=(const ByteBufferSegmented& other) = delete;
    ByteBufferSegmented(ByteBufferSegmented&& other) = default;
    ByteBufferSegmented& operator=(ByteBufferSegmented&& other) = default;

    /// @brief Write the data starting from the cur_segment_pos
    ///        in the segment with cur_segment_id, if it fits,
    ///        and otherwise, push_back a new segment first.
    uint8_t* write(const uint8_t* data, size_t amount)
    {
        assert(data);
        assert(amount <= m_num_bytes_per_segment);
        if (amount > (m_num_bytes_per_segment - cur_segment_pos))
        {
            increase_capacity();
        }
        uint8_t* result_data = &m_segments[cur_segment_id][cur_segment_pos];
        memcpy(result_data, data, amount);
        cur_segment_pos += amount;
        m_size += amount;
        last_written = amount;
        return result_data;
    }

    /// @brief Undo the last write operation.
    void undo_last_write()
    {
        cur_segment_pos -= last_written;
        last_written = 0;
    }

    /// @brief Set the write head to the beginning.
    void clear()
    {
        cur_segment_id = 0;
        cur_segment_pos = 0;
        m_size = 0;
        last_written = 0;
    }

    [[nodiscard]] size_t size() const { return m_size; }
    [[nodiscard]] size_t capacity() const { return m_capacity; }
};
}

#endif
