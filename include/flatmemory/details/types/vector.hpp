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

#ifndef FLATMEMORY_TYPES_VECTOR_HPP_
#define FLATMEMORY_TYPES_VECTOR_HPP_

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/operator.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

namespace flatmemory
{
/**
 * Dispatcher for Vector.
 */
template<IsTriviallyCopyableOrCustom T>
struct Vector : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Vector(const Vector& other) {}
};

/**
 * Data types
 */
using vector_size_type = uint32_t;

/**
 * Forward declarations
 */
template<IsTriviallyCopyableOrCustom T>
class View<Vector<T>>;

template<IsTriviallyCopyableOrCustom T>
class ConstView<Vector<T>>;

template<IsTriviallyCopyableOrCustom T>
class Builder<Vector<T>>;

/**
 * Operator
 */
template<IsTriviallyCopyableOrCustom T>
class Operator<Vector<T>>
{
private:
public:
};

/**
 * Layout
 */
template<IsTriviallyCopyableOrCustom T>
class Layout<Vector<T>>
{
public:
    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, vector_size_type, T>();

    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
    static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_header_alignment<vector_size_type>());
    static constexpr size_t vector_size_position = buffer_size_end + buffer_size_padding;
    static constexpr size_t vector_size_end = vector_size_position + sizeof(vector_size_type);
    static constexpr size_t vector_size_padding = calculate_amount_padding(vector_size_end, calculate_data_alignment<T>());
    static constexpr size_t vector_data_position = vector_size_end + vector_size_padding;

    void print() const;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrCustom T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
public:
    using T_ = typename maybe_builder<T>::type;

    using iterator = typename std::vector<T_>::iterator;
    using const_iterator = typename std::vector<T_>::const_iterator;

private:
    std::vector<T_> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl();

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

public:
    /**
     * Constructors
     */

    Builder();
    explicit Builder(size_t count);
    explicit Builder(size_t count, const T_& value);

    /**
     * Operators
     */

    bool operator==(const Builder& other) const;
    bool operator==(const ConstView<Vector<T>> other) const;
    bool operator==(const View<Vector<T>> other) const;
    bool operator!=(const Builder& other) const;

    /**
     * Element access
     */

    T_& operator[](size_t pos);
    const T_& operator[](size_t pos) const;
    T_& at(size_t pos);
    const T_& at(size_t pos) const;
    size_t hash() const;
    T_* data();
    const T_* data() const;

    /**
     * Iterators
     */

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    /**
     * Capacity
     */

    constexpr bool empty() const;
    constexpr size_t size() const;

    /**
     * Modifiers
     */
    void push_back(T_&& element);
    void push_back(const T_& element);

    void resize(size_t count);
    void resize(size_t count, const T_& value);
    void clear();
};

/**
 * View
 */
template<IsTriviallyCopyableOrCustom T>
class View<Vector<T>>
{
public:
    using T_ = typename maybe_builder<T>::type;

private:
    uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    View() = default;

    template<typename>
    friend class Builder;

    void range_check(size_t pos) const;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder.
    View(uint8_t* buf);

    /**
     * Operators
     */

    bool operator==(const Builder<Vector<T>>& other) const;
    bool operator==(const View<Vector<T>>& other) const;
    bool operator==(const ConstView<Vector<T>>& other) const;
    bool operator!=(const Builder<Vector<T>>& other) const;
    bool operator!=(const View<Vector<T>>& other) const;
    bool operator!=(const ConstView<Vector<T>>& other) const;

    /**
     * Element access.
     */

    decltype(auto) operator[](size_t pos);
    decltype(auto) operator[](size_t pos) const;
    decltype(auto) at(size_t pos);
    decltype(auto) at(size_t pos) const;
    size_t hash() const;
    T_* data();
    const T_* data() const;
    uint8_t* buffer();
    const uint8_t* buffer() const;

    /**
     * Iterators
     */

    class iterator
    {
    private:
        uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_view<T>::type;
        using pointer = typename maybe_view<T>::type*;
        using reference = typename maybe_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        iterator();
        iterator(uint8_t* buf);

        decltype(auto) operator*() const;
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };

    iterator begin();
    iterator end();

    class const_iterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = typename maybe_const_view<T>::type*;
        using reference = typename maybe_const_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        const_iterator();
        const_iterator(const uint8_t* buf);

        decltype(auto) operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };

    const_iterator begin() const;
    const_iterator end() const;

    /**
     * Capacity
     */

    bool empty() const;
    buffer_size_type buffer_size() const;
    size_t size() const;
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrCustom T>
class ConstView<Vector<T>>
{
public:
    using T_ = typename maybe_builder<T>::type;

private:
    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;

    void range_check(size_t pos) const;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf);

    /**
     * Conversion constructor
     */

    ConstView(const View<Vector<T>>& view);

    /**
     * Operators
     */
    bool operator==(const Builder<Vector<T>>& other) const;
    bool operator==(const ConstView<Vector<T>>& other) const;
    bool operator==(const View<Vector<T>>& other) const;
    bool operator!=(const Builder<Vector<T>>& other) const;
    bool operator!=(const ConstView<Vector<T>>& other) const;
    bool operator!=(const View<Vector<T>>& other) const;

    /**
     * Element access
     */

    decltype(auto) operator[](size_t pos) const;
    decltype(auto) at(size_t pos) const;
    size_t hash() const;
    const T_* data() const;
    const uint8_t* buffer() const;

    /**
     * Iterators
     */

    class const_iterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = typename maybe_const_view<T>::type*;
        using reference = typename maybe_const_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        const_iterator();
        const_iterator(const uint8_t* buf);

        decltype(auto) operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };

    const_iterator begin() const;
    const_iterator end() const;

    /**
     * Capacity
     */

    bool empty() const;
    buffer_size_type buffer_size() const;
    size_t size() const;

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */
};

/**
 * Definitions
 */

// Layout

template<IsTriviallyCopyableOrCustom T>
void Layout<Vector<T>>::print() const
{
    std::cout << "buffer_size_position: " << buffer_size_position << "\n"
              << "buffer_size_end: " << buffer_size_end << "\n"
              << "buffer_size_padding: " << buffer_size_padding << "\n"
              << "vector_size_position: " << vector_size_position << "\n"
              << "vector_size_end: " << vector_size_end << "\n"
              << "vector_data_position: " << vector_data_position << "\n"
              << "vector_size_padding: " << vector_size_padding << "\n"
              << "final_alignment: " << final_alignment << std::endl;
}

// Builder

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::finish_impl()
{
    /* Write header info */
    // Write vector size
    m_buffer.write(Layout<Vector<T>>::vector_size_position, m_data.size());
    m_buffer.write_padding(Layout<Vector<T>>::vector_size_end, Layout<Vector<T>>::vector_size_padding);

    /* Write dynamic info */
    offset_type buffer_size = Layout<Vector<T>>::vector_data_position;
    // Write vector data
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        /* For trivial type we can write the data without additional padding. */
        buffer_size += m_buffer.write(buffer_size, reinterpret_cast<const uint8_t*>(m_data.data()), sizeof(T_) * m_data.size());
    }
    else
    {
        /* For non-trivial type T, we store the offsets first */
        // position of offset
        offset_type offset_pos = Layout<Vector<T>>::vector_data_position;
        size_t offset_end = offset_pos + m_data.size() * sizeof(offset_type);
        size_t offset_padding = calculate_amount_padding(offset_end, Layout<T>::final_alignment);
        m_buffer.write_padding(offset_end, offset_padding);
        // We have to add padding to ensure that the data is correctly aligned
        buffer_size = offset_end + offset_padding;
        for (size_t i = 0; i < m_data.size(); ++i)
        {
            // write distance between written data position and offset position
            offset_type distance = buffer_size - offset_pos;
            offset_pos += m_buffer.write(offset_pos, distance);

            // write data
            auto& nested_builder = m_data[i];
            nested_builder.finish();
            buffer_size_type nested_buffer_size = nested_builder.buffer().size();
            m_buffer.write(buffer_size, nested_builder.buffer().data(), nested_buffer_size);
            buffer_size += nested_buffer_size;
            buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, Layout<Vector<T>>::final_alignment));
        }
    }
    // Write final padding to satisfy alignment requirements
    buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, Layout<Vector<T>>::final_alignment));

    /* Write buffer size */
    m_buffer.write(Layout<Vector<T>>::buffer_size_position, static_cast<buffer_size_type>(buffer_size));
    m_buffer.set_size(buffer_size);
}

template<IsTriviallyCopyableOrCustom T>
auto& Builder<Vector<T>>::get_buffer_impl()
{
    return m_buffer;
}

template<IsTriviallyCopyableOrCustom T>
const auto& Builder<Vector<T>>::get_buffer_impl() const
{
    return m_buffer;
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::Builder()
{
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::Builder(size_t count) : m_data(count)
{
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::Builder(size_t count, const T_& value) : m_data(count, value)
{
}

template<IsTriviallyCopyableOrCustom T>
bool Builder<Vector<T>>::operator==(const Builder& other) const
{
    if (this != &other)
    {
        return m_data == other.m_data;
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool Builder<Vector<T>>::operator==(const ConstView<Vector<T>> other) const
{
    if (size() != other.size())
    {
        return false;
    }

    for (size_t i = 0; i < size(); ++i)
    {
        // Requires comparison between nested builder and constview/view types
        if ((*this)[i] != other[i])
        {
            return false;
        }
    }

    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool Builder<Vector<T>>::operator==(const View<Vector<T>> other) const
{
    if (size() != other.size())
    {
        return false;
    }

    for (size_t i = 0; i < size(); ++i)
    {
        // Requires comparison between nested builder and constview/view types
        if ((*this)[i] != other[i])
        {
            return false;
        }
    }

    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool Builder<Vector<T>>::operator!=(const Builder& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::T_& Builder<Vector<T>>::operator[](size_t pos)
{
    assert(pos < size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrCustom T>
const Builder<Vector<T>>::T_& Builder<Vector<T>>::operator[](size_t pos) const
{
    assert(pos < size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::T_& Builder<Vector<T>>::at(size_t pos)
{
    return m_data.at(pos);
}

template<IsTriviallyCopyableOrCustom T>
const Builder<Vector<T>>::T_& Builder<Vector<T>>::at(size_t pos) const
{
    return m_data.at(pos);
}

template<IsTriviallyCopyableOrCustom T>
size_t Builder<Vector<T>>::hash() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return hash_combine(hash_iteration(m_data.begin(), m_data.end()));
    }
    else
    {
        size_t seed = size();
        for (auto iter = m_data.begin(); iter < m_data.end(); ++iter)
        {
            seed = hash_combine(seed, iter->hash());
        }
        return seed;
    }
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::T_* Builder<Vector<T>>::data()
{
    return m_data.data();
}

template<IsTriviallyCopyableOrCustom T>
const Builder<Vector<T>>::T_* Builder<Vector<T>>::data() const
{
    return m_data.data();
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::iterator Builder<Vector<T>>::begin()
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::const_iterator Builder<Vector<T>>::begin() const
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::iterator Builder<Vector<T>>::end()
{
    return m_data.end();
}

template<IsTriviallyCopyableOrCustom T>
Builder<Vector<T>>::const_iterator Builder<Vector<T>>::end() const
{
    return m_data.end();
}

template<IsTriviallyCopyableOrCustom T>
constexpr bool Builder<Vector<T>>::empty() const
{
    return m_data.empty();
}

template<IsTriviallyCopyableOrCustom T>
constexpr size_t Builder<Vector<T>>::size() const
{
    return m_data.size();
}

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::push_back(T_&& element)
{
    m_data.push_back(std::move(element));
}

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::push_back(const T_& element)
{
    m_data.push_back(element);
}

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::resize(size_t count)
{
    m_data.resize(count, T_());
}

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::resize(size_t count, const T_& value)
{
    m_data.resize(count, value);
}

template<IsTriviallyCopyableOrCustom T>
void Builder<Vector<T>>::clear()
{
    m_data.clear();
}

// View

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::View(uint8_t* buf) : m_buf(buf)
{
    assert(m_buf);
}

template<IsTriviallyCopyableOrCustom T>
void View<Vector<T>>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("View<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is " + std::to_string(size())
                                + ")");
    }
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator==(const Builder<Vector<T>>& other) const
{
    if (size() != other.size())
    {
        return false;
    }
    for (size_t i = 0; i < size(); ++i)
    {
        if ((*this)[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator==(const View<Vector<T>>& other) const
{
    if (m_buf != other.buffer())
    {
        if (buffer_size() != other.buffer_size())
        {
            return false;
        }
        return std::memcmp(m_buf, other.buffer(), buffer_size()) == 0;
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator==(const ConstView<Vector<T>>& other) const
{
    if (m_buf != other.buffer())
    {
        if (buffer_size() != other.buffer_size())
        {
            return false;
        }
        return std::memcmp(m_buf, other.buffer(), buffer_size()) == 0;
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator!=(const Builder<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator!=(const View<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::operator!=(const ConstView<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::operator[](size_t pos)
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
        return View<T>(offset_pos + read_value<offset_type>(offset_pos));
    }
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::operator[](size_t pos) const
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
        return View<T>(offset_pos + read_value<offset_type>(offset_pos));
    }
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::at(size_t pos)
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrCustom T>
size_t View<Vector<T>>::hash() const
{
    size_t seed = size();
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::T_* View<Vector<T>>::data()
{
    return reinterpret_cast<View<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
const View<Vector<T>>::T_* View<Vector<T>>::data() const
{
    return reinterpret_cast<const View<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
uint8_t* View<Vector<T>>::buffer()
{
    return m_buf;
}

template<IsTriviallyCopyableOrCustom T>
const uint8_t* View<Vector<T>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator::iterator() : m_buf(nullptr)
{
}
template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator::iterator(uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::iterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf));
        return read_value<T>(m_buf);
    }
    else
    {
        return View<T>(m_buf + read_value<offset_type>(m_buf));
    }
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator& View<Vector<T>>::iterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(offset_type);
    }
    return *this;
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator View<Vector<T>>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::iterator::operator==(const View<Vector<T>>::iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::iterator::operator!=(const View<Vector<T>>::iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator View<Vector<T>>::begin()
{
    assert(m_buf);
    return View<Vector<T>>::iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::iterator View<Vector<T>>::end()
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return View<Vector<T>>::iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return View<Vector<T>>::iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
    }
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator::const_iterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator::const_iterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) View<Vector<T>>::const_iterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf));
        return read_value<T>(m_buf);
    }
    else
    {
        return ConstView<T>(m_buf + read_value<offset_type>(m_buf));
    }
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator& View<Vector<T>>::const_iterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(offset_type);
    }
    return *this;
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator View<Vector<T>>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::const_iterator::operator==(const View<Vector<T>>::const_iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::const_iterator::operator!=(const View<Vector<T>>::const_iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator View<Vector<T>>::begin() const
{
    assert(m_buf);
    return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
View<Vector<T>>::const_iterator View<Vector<T>>::end() const
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return View<Vector<T>>::const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return View<Vector<T>>::const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
    }
}

template<IsTriviallyCopyableOrCustom T>
bool View<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrCustom T>
buffer_size_type View<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrCustom T>
size_t View<Vector<T>>::size() const
{
    assert(m_buf);
    assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
    return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
}

// ConstView

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::ConstView(const uint8_t* buf) : m_buf(buf)
{
    assert(buf);
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::ConstView(const View<Vector<T>>& view) : m_buf(view.buffer())
{
}

template<IsTriviallyCopyableOrCustom T>
void ConstView<Vector<T>>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("ConstView<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator==(const Builder<Vector<T>>& other) const
{
    if (size() != other.size())
    {
        return false;
    }
    for (size_t i = 0; i < size(); ++i)
    {
        if ((*this)[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator==(const ConstView<Vector<T>>& other) const
{
    if (m_buf != other.buffer())
    {
        if (buffer_size() != other.buffer_size())
        {
            return false;
        }
        return std::memcmp(m_buf, other.buffer(), buffer_size()) == 0;
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator==(const View<Vector<T>>& other) const
{
    if (m_buf != other.buffer())
    {
        if (buffer_size() != other.buffer_size())
        {
            return false;
        }
        return std::memcmp(m_buf, other.buffer(), buffer_size()) == 0;
    }
    return true;
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator!=(const Builder<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator!=(const ConstView<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::operator!=(const View<Vector<T>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) ConstView<Vector<T>>::operator[](size_t pos) const
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
        return ConstView<T>(offset_pos + read_value<offset_type>(offset_pos));
    }
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) ConstView<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrCustom T>
size_t ConstView<Vector<T>>::hash() const
{
    size_t seed = size();
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

template<IsTriviallyCopyableOrCustom T>
const ConstView<Vector<T>>::T_* ConstView<Vector<T>>::data() const
{
    return reinterpret_cast<const ConstView<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
const uint8_t* ConstView<Vector<T>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator::const_iterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator::const_iterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrCustom T>
decltype(auto) ConstView<Vector<T>>::const_iterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<T>(m_buf));
        return read_value<T>(m_buf);
    }
    else
    {
        return ConstView<T>(m_buf + read_value<offset_type>(m_buf));
    }
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator& ConstView<Vector<T>>::const_iterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(offset_type);
    }
    return *this;
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator ConstView<Vector<T>>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::const_iterator::operator==(const ConstView<Vector<T>>::const_iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::const_iterator::operator!=(const ConstView<Vector<T>>::const_iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator ConstView<Vector<T>>::begin() const
{
    assert(m_buf);
    return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrCustom T>
ConstView<Vector<T>>::const_iterator ConstView<Vector<T>>::end() const
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
    }
}

template<IsTriviallyCopyableOrCustom T>
bool ConstView<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrCustom T>
buffer_size_type ConstView<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrCustom T>
size_t ConstView<Vector<T>>::size() const
{
    assert(m_buf);
    assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
    return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
}

/**
 * Static assertions
 */

static_assert(std::ranges::forward_range<Builder<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<View<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<ConstView<Vector<uint64_t>>>);
}

#endif
