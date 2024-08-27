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
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/types.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"

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
using VectorSizeType = uint32_t;

/**
 * Layout
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class Layout<Vector<T>>
{
public:
    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t vector_size_position = buffer_size_position + sizeof(BufferSizeType);
    static constexpr size_t vector_data_position = vector_size_position + sizeof(VectorSizeType);

    constexpr void print() const;
};

/**
 * Free function operators
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
 * Builder
 */

template<IsTriviallyCopyableOrNonTrivialType T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
public:
    /**
     * Type declarations
     */

    using ValueType = T;
    using T_ = typename maybe_builder<T>::type;

    using Iterator = typename std::vector<T_>::iterator;
    using ConstIterator = typename std::vector<T_>::const_iterator;

    /**
     * Constructors
     */

    /// @brief Default constructor only enabled if T is default constructible
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
    T* data()
        requires(IsTriviallyCopyable<T>);
    const T* data() const
        requires(IsTriviallyCopyable<T>);

    /**
     * Iterators
     */

    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;

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

    /// @brief Resize without default value argument enabled only if T_ is default constructible.
    /// @param count
    void resize(size_t count)
        requires(std::default_initializable<T_>);
    void resize(size_t count, const T_& value);
    void clear();

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl();
    size_t finish_impl(size_t pos, ByteBuffer& out);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

private:
    std::vector<T_> m_data;
    ByteBuffer m_buffer;
};

/**
 * View
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class View<Vector<T>>
{
public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder.
    View(uint8_t* buf);

    /**
     * Element access.
     */

    auto operator[](size_t pos);
    auto operator[](size_t pos) const;
    auto at(size_t pos);
    auto at(size_t pos) const;
    T* data()
        requires(IsTriviallyCopyable<T>);
    const T* data() const
        requires(IsTriviallyCopyable<T>);
    uint8_t* buffer();
    const uint8_t* buffer() const;

    /**
     * Mutate
     */

    void mutate(size_t pos, ValueType value)
        requires(IsTriviallyCopyable<ValueType>);

    /**
     * Iterators
     */

    class Iterator
    {
    private:
        uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_view<T>::type;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;

        Iterator();
        Iterator(uint8_t* buf);

        auto operator*() const;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = const value_type*;
        using reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator();
        ConstIterator(const uint8_t* buf);

        auto operator*() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };

    ConstIterator begin() const;
    ConstIterator end() const;

    /**
     * Capacity
     */

    bool empty() const;
    BufferSizeType buffer_size() const;
    size_t size() const;

private:
    void range_check(size_t pos) const;

private:
    uint8_t* m_buf;
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class ConstView<Vector<T>>
{
public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf);

    /**
     * Conversion constructors
     */

    ConstView(const View<Vector<T>>& view);

    /**
     * Conversion assigments
     */

    ConstView& operator=(const View<Vector<T>>& view);

    /**
     * Element access
     */

    auto operator[](size_t pos) const;
    auto at(size_t pos) const;
    const T* data() const
        requires(IsTriviallyCopyable<T>);
    const uint8_t* buffer() const;

    /**
     * Iterators
     */

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = typename maybe_const_view<T>::type*;
        using reference = typename maybe_const_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator();
        ConstIterator(const uint8_t* buf);

        auto operator*() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };

    ConstIterator begin() const;
    ConstIterator end() const;

    /**
     * Capacity
     */

    bool empty() const;
    BufferSizeType buffer_size() const;
    size_t size() const;

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */

private:
    void range_check(size_t pos) const;

private:
    const uint8_t* m_buf;
};

/**
 * Definitions
 */

/* Layout */

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr void Layout<Vector<T>>::print() const
{
    std::cout << "buffer_size_position: " << buffer_size_position << "\n"
              << "vector_size_position: " << vector_size_position << "\n"
              << "vector_data_position: " << vector_data_position << std::endl;
}

/* Operators */

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
bool operator!=(const V1& lhs, const V2& rhs)
{
    return !(lhs == rhs);
}

/* Builder */

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Vector<T>>::finish_impl()
{
    m_buffer.set_size(this->finish(0, m_buffer));
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t Builder<Vector<T>>::finish_impl(size_t pos, ByteBuffer& out)
{
    /* Write the vector size */
    out.write(pos + Layout<Vector<T>>::vector_size_position, m_data.size());

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
        size_t offset_pos = data_pos;
        /* Write sufficiently much padding before the data. */
        data_pos = offset_pos + m_data.size() * sizeof(OffsetType);

        /* Set data pos after the offset locations. */
        for (size_t i = 0; i < m_data.size(); ++i)
        {
            /* Write the distance between written data pos and offset pos at the offset pos.
               This allows for more efficient iterator logic.
            */
            offset_pos += out.write(pos + offset_pos, static_cast<OffsetType>(data_pos - offset_pos));

            /* Write the data at offset. */
            data_pos += m_data[i].finish(pos + data_pos, out);
        }
    }

    /* Write the size of the buffer to the beginning. */
    out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));

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
T* Builder<Vector<T>>::data()
    requires(IsTriviallyCopyable<T>)
{
    return m_data.data();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const T* Builder<Vector<T>>::data() const
    requires(IsTriviallyCopyable<T>)
{
    return m_data.data();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::Iterator Builder<Vector<T>>::begin()
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::ConstIterator Builder<Vector<T>>::begin() const
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::Iterator Builder<Vector<T>>::end()
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Vector<T>>::ConstIterator Builder<Vector<T>>::end() const
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
    requires(std::default_initializable<typename maybe_builder<T>::type>)
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

/* View */

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
auto View<Vector<T>>::operator[](size_t pos)
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return View<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto View<Vector<T>>::operator[](size_t pos) const
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return ConstView<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto View<Vector<T>>::at(size_t pos)
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto View<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
T* View<Vector<T>>::data()
    requires(IsTriviallyCopyable<T>)
{
    return reinterpret_cast<T*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
const T* View<Vector<T>>::data() const
    requires(IsTriviallyCopyable<T>)
{
    return reinterpret_cast<const T*>(m_buf + Layout<Vector<T>>::vector_data_position);
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
void View<Vector<T>>::mutate(size_t pos, View<Vector<T>>::ValueType value)
    requires(IsTriviallyCopyable<View<Vector<T>>::ValueType>)
{
    write_value<View<Vector<T>>::ValueType>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T), value);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator::Iterator() : m_buf(nullptr)
{
}
template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator::Iterator(uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto View<Vector<T>>::Iterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf);
    }
    else
    {
        return View<T>(m_buf + read_value<OffsetType>(m_buf));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator& View<Vector<T>>::Iterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(OffsetType);
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator View<Vector<T>>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::Iterator::operator==(const View<Vector<T>>::Iterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::Iterator::operator!=(const View<Vector<T>>::Iterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator View<Vector<T>>::begin()
{
    assert(m_buf);
    return View<Vector<T>>::Iterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::Iterator View<Vector<T>>::end()
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return View<Vector<T>>::Iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return View<Vector<T>>::Iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size());
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator::ConstIterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator::ConstIterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto View<Vector<T>>::ConstIterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf);
    }
    else
    {
        return ConstView<T>(m_buf + read_value<OffsetType>(m_buf));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator& View<Vector<T>>::ConstIterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(OffsetType);
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator View<Vector<T>>::ConstIterator::operator++(int)
{
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::ConstIterator::operator==(const View<Vector<T>>::ConstIterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::ConstIterator::operator!=(const View<Vector<T>>::ConstIterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator View<Vector<T>>::begin() const
{
    assert(m_buf);
    return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<Vector<T>>::ConstIterator View<Vector<T>>::end() const
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return View<Vector<T>>::ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return View<Vector<T>>::ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size());
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool View<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrNonTrivialType T>
BufferSizeType View<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t View<Vector<T>>::size() const
{
    assert(m_buf);
    return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position);
}

/* ConstView */

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
ConstView<Vector<T>>& ConstView<Vector<T>>::operator=(const View<Vector<T>>& view)
{
    m_buf = view.buffer();
    return *this;
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
auto ConstView<Vector<T>>::operator[](size_t pos) const
{
    assert(m_buf);
    assert(pos < size());
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return ConstView<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto ConstView<Vector<T>>::at(size_t pos) const
{
    range_check(pos);
    return (*this)[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
const T* ConstView<Vector<T>>::data() const
    requires(IsTriviallyCopyable<T>)
{
    return reinterpret_cast<const T*>(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
const uint8_t* ConstView<Vector<T>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator::ConstIterator() : m_buf(nullptr)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator::ConstIterator(const uint8_t* buf) : m_buf(buf)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto ConstView<Vector<T>>::ConstIterator::operator*() const
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return read_value<T>(m_buf);
    }
    else
    {
        return ConstView<T>(m_buf + read_value<OffsetType>(m_buf));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator& ConstView<Vector<T>>::ConstIterator::operator++()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        m_buf += sizeof(T);
    }
    else
    {
        m_buf += sizeof(OffsetType);
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator ConstView<Vector<T>>::ConstIterator::operator++(int)
{
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::ConstIterator::operator==(const ConstView<Vector<T>>::ConstIterator& other) const
{
    return m_buf == other.m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::ConstIterator::operator!=(const ConstView<Vector<T>>::ConstIterator& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator ConstView<Vector<T>>::begin() const
{
    assert(m_buf);
    return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<Vector<T>>::ConstIterator ConstView<Vector<T>>::end() const
{
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
    }
    else
    {
        return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size());
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool ConstView<Vector<T>>::empty() const
{
    return size() == 0;
}

template<IsTriviallyCopyableOrNonTrivialType T>
BufferSizeType ConstView<Vector<T>>::buffer_size() const
{
    assert(m_buf);
    return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t ConstView<Vector<T>>::size() const
{
    assert(m_buf);
    return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position);
}

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
struct std::hash<flatmemory::Builder<flatmemory::Vector<T>>>
{
    size_t operator()(const flatmemory::Builder<flatmemory::Vector<T>>& vector) const
    {
        size_t seed = vector.size();
        for (const auto& element : vector)
        {
            flatmemory::hash_combine(seed, element);
        }
        return seed;
    }
};

template<flatmemory::IsTriviallyCopyableOrNonTrivialType T>
struct std::hash<flatmemory::View<flatmemory::Vector<T>>>
{
    size_t operator()(const flatmemory::View<flatmemory::Vector<T>>& vector) const
    {
        size_t seed = vector.size();
        int64_t hash[2];
        flatmemory::MurmurHash3_x64_128(vector.buffer(), vector.buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

template<flatmemory::IsTriviallyCopyableOrNonTrivialType T>
struct std::hash<flatmemory::ConstView<flatmemory::Vector<T>>>
{
    size_t operator()(const flatmemory::ConstView<flatmemory::Vector<T>>& vector) const
    {
        size_t seed = vector.size();
        int64_t hash[2];
        flatmemory::MurmurHash3_x64_128(vector.buffer(), vector.buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

#endif
