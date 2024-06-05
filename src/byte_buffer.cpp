#include "flatmemory/details/byte_buffer.hpp"

namespace flatmemory
{

void ByteBuffer::resize_to_fit(size_t pos, size_t amount)
{
    size_t final_size = pos + amount;
    if (final_size > m_data.size())
    {
        m_data.resize(final_size);
    }
}

ByteBuffer::ByteBuffer() : m_size(0) {}

size_t ByteBuffer::write(size_t pos, const uint8_t* data, size_t amount)
{
    resize_to_fit(pos, amount);
    std::memcpy(&m_data[pos], data, amount);
    return amount;
}

size_t ByteBuffer::write_padding(size_t pos, size_t amount)
{
    if (amount > 0)
    {
        // Write num_byte many zeros 0's
        resize_to_fit(pos, amount);
        std::memset(&m_data[pos], 0, amount);
    }
    return amount;
}

void ByteBuffer::set_size(size_t count) { m_size = count; }

uint8_t* ByteBuffer::data() { return m_data.data(); }
const uint8_t* ByteBuffer::data() const { return m_data.data(); }

size_t ByteBuffer::size() const { return m_size; }
size_t ByteBuffer::capacity() const { return m_data.capacity(); }
}
