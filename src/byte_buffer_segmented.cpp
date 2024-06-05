#include "flatmemory/details/byte_buffer_segmented.hpp"

namespace flatmemory
{

void ByteBufferSegmented::increase_capacity()
{
    if (m_cur_segment_id == (m_segments.size() - 1))
    {
        m_segments.push_back(new uint8_t[m_num_bytes_per_segment]());
        m_cur_segment_pos = 0;
        m_capacity += m_num_bytes_per_segment;
    }
    ++m_cur_segment_id;
    assert(m_cur_segment_id < m_segments.size());
}

ByteBufferSegmented::ByteBufferSegmented(NumBytes n) :
    m_num_bytes_per_segment(n),
    m_cur_segment_id(-1),
    m_cur_segment_pos(0),
    m_size(0),
    m_capacity(0),
    m_last_written(0)
{
    // allocate first block of memory
    increase_capacity();
    assert(m_cur_segment_pos == 0);
    assert(m_cur_segment_id == 0);
}

ByteBufferSegmented::~ByteBufferSegmented()
{
    for (uint8_t* ptr : m_segments)
    {
        delete[] ptr;
    }
}

uint8_t* ByteBufferSegmented::write(const uint8_t* data, size_t amount)
{
    assert(data);
    assert(amount <= m_num_bytes_per_segment);
    if (amount > (m_num_bytes_per_segment - m_cur_segment_pos))
    {
        increase_capacity();
    }
    uint8_t* result_data = &m_segments[m_cur_segment_id][m_cur_segment_pos];
    memcpy(result_data, data, amount);
    m_cur_segment_pos += amount;
    m_size += amount;
    m_last_written = amount;
    return result_data;
}

void ByteBufferSegmented::undo_last_write()
{
    m_cur_segment_pos -= m_last_written;
    m_last_written = 0;
}

void ByteBufferSegmented::clear()
{
    m_cur_segment_id = 0;
    m_cur_segment_pos = 0;
    m_size = 0;
    m_last_written = 0;
}

size_t ByteBufferSegmented::size() const { return m_size; }

size_t ByteBufferSegmented::capacity() const { return m_capacity; }
}
