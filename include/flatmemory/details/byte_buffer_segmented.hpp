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

#include "flatmemory/details/types.hpp"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

namespace flatmemory
{

/**
 * Declarations
 */

class ByteBufferSegmented
{
private:
    NumBytes m_num_bytes_per_segment;
    std::vector<uint8_t*> m_segments;

    size_t m_cur_segment_id;
    size_t m_cur_segment_pos;

    size_t m_size;
    size_t m_capacity;

    size_t m_last_written;

    /// @brief Allocate a block of size N and update tracking variables.
    void increase_capacity();

public:
    explicit ByteBufferSegmented(NumBytes n = 1000000);
    ~ByteBufferSegmented();
    ByteBufferSegmented(const ByteBufferSegmented& other) = delete;
    ByteBufferSegmented& operator=(const ByteBufferSegmented& other) = delete;
    ByteBufferSegmented(ByteBufferSegmented&& other) = default;
    ByteBufferSegmented& operator=(ByteBufferSegmented&& other) = default;

    /// @brief Write the data starting from the m_cur_segment_pos
    ///        in the segment with m_cur_segment_id, if it fits,
    ///        and otherwise, push_back a new segment first.
    uint8_t* write(const uint8_t* data, size_t amount);

    /// @brief Undo the last write operation.
    void undo_last_write();

    /// @brief Set the write head to the beginning.
    void clear();

    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;
};

}

#endif
