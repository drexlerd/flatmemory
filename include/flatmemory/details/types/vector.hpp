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
#include "flatmemory/details/types/formatter.hpp"
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
 * ID class for non-trivial Vector type.
 */
template<IsTriviallyCopyableOrNonTrivialType T>
struct Vector : public NonTrivialType
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

template<IsTriviallyCopyableOrNonTrivialType T>
class View<Vector<T>>;

template<IsTriviallyCopyableOrNonTrivialType T>
class ConstView<Vector<T>>;

template<IsTriviallyCopyableOrNonTrivialType T>
class Builder<Vector<T>>;

/**
 * Concepts
 */

template<typename T1, typename T2>
concept HaveSameValueType = std::is_same_v<typename T1::ValueType, typename T2::ValueType>;

template<typename T>
struct is_vector_builder_helper : std::false_type
{
};

template<typename T>
struct is_vector_nonconst_view_helper : std::false_type
{
};

template<typename T>
struct is_vector_const_view_helper : std::false_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_builder_helper<Builder<Vector<T>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_nonconst_view_helper<View<Vector<T>>> : std::true_type
{
};

template<IsTriviallyCopyableOrNonTrivialType T>
struct is_vector_const_view_helper<ConstView<Vector<T>>> : std::true_type
{
};

template<typename T>
concept IsVectorBuilder = is_vector_builder_helper<T>::value;

template<typename T>
concept IsVectorView = is_vector_nonconst_view_helper<T>::value;

template<typename T>
concept IsVectorConstView = is_vector_const_view_helper<T>::value;

template<typename T>
concept IsVector = IsVectorBuilder<T> || IsVectorView<T> || IsVectorConstView<T>;

/**
 * Operator
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class Operator<Vector<T>>
{
private:
public:
};

/**
 * Layout
 */
template<IsTriviallyCopyableOrNonTrivialType T>
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

    constexpr void print() const;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
public:
    using ValueType = T;
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
    size_t finish_impl(size_t pos, ByteBuffer& out);

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
template<IsTriviallyCopyableOrNonTrivialType T>
class View<Vector<T>>
{
public:
    using ValueType = T;
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
        using pointer = value_type*;
        using reference = value_type&;
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
        using pointer = const value_type*;
        using reference = const value_type&;
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
template<IsTriviallyCopyableOrNonTrivialType T>
class ConstView<Vector<T>>
{
public:
    using ValueType = T;
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
 * Operators
 */

template<IsVector V>
bool operator==(const V& lhs, const V& rhs);

template<IsVector V1, IsVector V2>
requires HaveSameValueType<V1, V2>
bool operator==(const V1& lhs, const V2& rhs);

template<IsVector V>
bool operator!=(const V& lhs, const V& rhs);

template<IsVector V1, IsVector V2>
requires HaveSameValueType<V1, V2>
bool operator!=(const V1& lhs, const V2& rhs);

/**
 * Definitions
 */

// Layout

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr void Layout<Vector<T>>::print() const
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

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::finish_impl()
{
    this->finish(0, m_buffer);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t Builder<Vector<T>>::finish_impl(size_t pos, ByteBuffer& out)
{
    /* Write the vector size */
    out.write(pos + Layout<Vector<T>>::vector_size_position, m_data.size());
    out.write_padding(pos + Layout<Vector<T>>::vector_size_end, Layout<Vector<T>>::vector_size_padding);

    size_t data_pos = Layout<Vector<T>>::vector_data_position;

    /* Write vector data */
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        /* Write the data of the trivial type inline. */
        data_pos += out.write(pos + data_pos, reinterpret_cast<const uint8_t*>(m_data.data()), sizeof(T_) * m_data.size());
    }
    else
    {
        /* Write the offset inline and data at offset. */
        size_t offset_pos = Layout<Vector<T>>::vector_data_position;
        /* Write sufficiently much padding before the data. */
        size_t offset_end = offset_pos + m_data.size() * sizeof(offset_type);
        size_t offset_padding = calculate_amount_padding(offset_end, Layout<T>::final_alignment);
        out.write_padding(pos + offset_end, offset_padding);

        /* Set data pos after the offset locations. */
        data_pos = offset_end + offset_padding;
        for (size_t i = 0; i < m_data.size(); ++i)
        {
            /* Write the distance between written data pos and offset pos at the offset pos.
               This allows for more efficient iterator logic.
            */
            offset_pos += out.write(pos + offset_pos, static_cast<offset_type>(data_pos - offset_pos));

            /* Write the data at offset. */
            data_pos += m_data[i].finish(pos + data_pos, out);
            data_pos += out.write_padding(pos + data_pos, calculate_amount_padding(data_pos, Layout<Vector<T>>::final_alignment));
        }
    }
    /* Write the final padding. */
    data_pos += out.write_padding(pos + data_pos, calculate_amount_padding(data_pos, Layout<Vector<T>>::final_alignment));

    /* Write the size of the buffer to the beginning. */
    out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<buffer_size_type>(data_pos));
    out.set_size(data_pos);

    return data_pos;
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto& Builder<Vector<T>>::get_buffer_impl()
{
    return m_buffer;
}

template<IsTriviallyCopyableOrNonTrivialType T>
const auto& Builder<Vector<T>>::get_buffer_impl() const
{
    return m_buffer;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::Builder()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::Builder(size_t count) : m_data(count)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::Builder(size_t count, const T_& value) : m_data(count, value)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::T_& Builder<Vector<T>>::operator[](size_t pos)
{
    assert(pos < size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Vector<T>>::T_& Builder<Vector<T>>::operator[](size_t pos) const
{
    assert(pos < size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::T_& Builder<Vector<T>>::at(size_t pos)
{
    return m_data.at(pos);
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Vector<T>>::T_& Builder<Vector<T>>::at(size_t pos) const
{
    return m_data.at(pos);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t Builder<Vector<T>>::hash() const
{
    return flatmemory::hash_combine(m_data);
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::T_* Builder<Vector<T>>::data()
{
    return m_data.data();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Vector<T>>::T_* Builder<Vector<T>>::data() const
{
    return m_data.data();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::iterator Builder<Vector<T>>::begin()
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::const_iterator Builder<Vector<T>>::begin() const
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::iterator Builder<Vector<T>>::end()
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::const_iterator Builder<Vector<T>>::end() const
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool Builder<Vector<T>>::empty() const
{
    return m_data.empty();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr size_t Builder<Vector<T>>::size() const
{
    return m_data.size();
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::push_back(T_&& element)
{
    m_data.push_back(std::move(element));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::push_back(const T_& element)
{
    m_data.push_back(element);
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::resize(size_t count)
{
    m_data.resize(count, T_());
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::resize(size_t count, const T_& value)
{
    m_data.resize(count, value);
}

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::clear()
{
    m_data.clear();
}

// View

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::View(uint8_t* buf) : m_buf(buf)
{
    assert(m_buf);
}

template<IsTriviallyCopyableOrNonTrivialType T>
void View<Vector<T>>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("View<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is " + std::to_string(size())
                                + ")");
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
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
        return ConstView<T>(offset_pos + read_value<offset_type>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
decltype(auto) View<Vector<T>>::at(size_t pos)
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
decltype(auto) View<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t View<Vector<T>>::hash() const
{
    size_t seed = size();
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::T_* View<Vector<T>>::data()
{
    return reinterpret_cast<View<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
const View<Vector<T>>::T_* View<Vector<T>>::data() const
{
    return reinterpret_cast<const View<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
uint8_t* View<Vector<T>>::buffer()
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
const uint8_t* View<Vector<T>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::iterator::iterator() : m_buf(nullptr)
{
}
template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::iterator::iterator(uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::iterator View<Vector<T>>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::iterator::operator==(const View<Vector<T>>::iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::iterator::operator!=(const View<Vector<T>>::iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::iterator View<Vector<T>>::begin()
{
    assert(m_buf);
    return View<Vector<T>>::iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::const_iterator::const_iterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::const_iterator::const_iterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::const_iterator View<Vector<T>>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::const_iterator::operator==(const View<Vector<T>>::const_iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::const_iterator::operator!=(const View<Vector<T>>::const_iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::const_iterator View<Vector<T>>::begin() const
{
    assert(m_buf);
    return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrNonTrivialType T>
buffer_size_type View<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t View<Vector<T>>::size() const
{
    assert(m_buf);
    assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
    return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
}

// ConstView

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstView(const uint8_t* buf) : m_buf(buf)
{
    assert(buf);
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstView(const View<Vector<T>>& view) : m_buf(view.buffer())
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
void ConstView<Vector<T>>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("ConstView<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
decltype(auto) ConstView<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t ConstView<Vector<T>>::hash() const
{
    size_t seed = size();
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

template<IsTriviallyCopyableOrNonTrivialType T>
const ConstView<Vector<T>>::T_* ConstView<Vector<T>>::data() const
{
    return reinterpret_cast<const ConstView<Vector<T>>::T_*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
const uint8_t* ConstView<Vector<T>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::const_iterator::const_iterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::const_iterator::const_iterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::const_iterator ConstView<Vector<T>>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::const_iterator::operator==(const ConstView<Vector<T>>::const_iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::const_iterator::operator!=(const ConstView<Vector<T>>::const_iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::const_iterator ConstView<Vector<T>>::begin() const
{
    assert(m_buf);
    return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
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

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrNonTrivialType T>
buffer_size_type ConstView<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t ConstView<Vector<T>>::size() const
{
    assert(m_buf);
    assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
    return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
}

/**
 * Operators
 */

template<IsVector V>
bool operator==(const V& lhs, const V& rhs)
{
    if (&lhs != &rhs)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }
        for (size_t i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i] != rhs[i])
            {
                return false;
            }
        }
    }
    return true;
}

template<IsVector V1, IsVector V2>
requires HaveSameValueType<V1, V2>
bool operator==(const V1& lhs, const V2& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}

template<IsVector V>
bool operator!=(const V& lhs, const V& rhs)
{
    return !(lhs == rhs);
}

template<IsVector V1, IsVector V2>
requires HaveSameValueType<V1, V2>
bool operator!=(const V1& lhs, const V2& rhs) { return !(lhs == rhs); }

/**
 * Static assertions
 */

static_assert(std::ranges::forward_range<Builder<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<View<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<ConstView<Vector<uint64_t>>>);

/**
 * Pretty printing
 */

template<IsTriviallyCopyableOrNonTrivialType T>
std::ostream& operator<<(std::ostream& out, ConstView<Vector<T>> element)
{
    auto formatter = Formatter(0, 4);
    formatter.write(element, out);
    return out;
}
}

template<flatmemory::IsTriviallyCopyableOrNonTrivialType T>
struct std::hash<flatmemory::Vector<T>>
{
    size_t operator()(const flatmemory::Builder<flatmemory::Vector<T>>& vector) const { return vector.hash(); }
};

template<flatmemory::IsTriviallyCopyableOrNonTrivialType T>
struct std::hash<flatmemory::View<flatmemory::Vector<T>>>
{
    size_t operator()(const flatmemory::View<flatmemory::Vector<T>>& vector) const { return vector.hash(); }
};

template<flatmemory::IsTriviallyCopyableOrNonTrivialType T>
struct std::hash<flatmemory::ConstView<flatmemory::Vector<T>>>
{
    size_t operator()(const flatmemory::ConstView<flatmemory::Vector<T>>& vector) const { return vector.hash(); }
};

#endif
