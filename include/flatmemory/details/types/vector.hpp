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

    constexpr void print() const
    {
        std::cout << "buffer_size_position: " << buffer_size_position << "\n"
                  << "vector_size_position: " << vector_size_position << "\n"
                  << "vector_data_position: " << vector_data_position << std::endl;
    }
};

/**
 * Builder
 */

template<IsTriviallyCopyable T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
public:
    /**
     * Type declarations
     */

    using ValueType = T;

    using Iterator = typename std::vector<T>::iterator;
    using ConstIterator = typename std::vector<T>::const_iterator;

    /**
     * Constructors
     */

    Builder() : m_data(), m_buffer() {}
    explicit Builder(size_t count) : m_data(count), m_buffer() {}
    explicit Builder(size_t count, const T& value) : m_data(count, value), m_buffer() {}

    /**
     * Element access
     */

    T& operator[](size_t pos)
    {
        assert(pos < size());
        return m_data[pos];
    }
    const T& operator[](size_t pos) const
    {
        assert(pos < size());
        return m_data[pos];
    }
    T& at(size_t pos) { return m_data.at(pos); }
    const T& at(size_t pos) const { return m_data.at(pos); }
    T* data() { return m_data.data(); }
    const T* data() const { return m_data.data(); }

    /**
     * Iterators
     */

    Iterator begin() { return m_data.begin(); }
    ConstIterator begin() const { return m_data.begin(); }
    Iterator end() { return m_data.end(); }
    ConstIterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    constexpr bool empty() const { return m_data.empty(); }
    constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */
    void push_back(T&& element) { m_data.push_back(std::move(element)); }
    void push_back(const T& element) { m_data.push_back(element); }

    /// @brief Resize without default value argument enabled only if T_ is default constructible.
    /// @param count
    void resize(size_t count)
        requires(std::default_initializable<T>)
    {
        m_data.resize(count, T());
    }
    void resize(size_t count, const T& value) { m_data.resize(count, value); }
    void clear() { m_data.clear(); }

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { m_buffer.set_size(this->finish(0, m_buffer)); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        /* Write the vector size */
        out.write(pos + Layout<Vector<T>>::vector_size_position, m_data.size());

        size_t data_pos = Layout<Vector<T>>::vector_data_position;

        /* Write the data of the trivial type inline. */
        data_pos += out.write(pos + data_pos, reinterpret_cast<const uint8_t*>(m_data.data()), sizeof(T) * m_data.size());

        /* Write the size of the buffer to the beginning. */
        out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));

        return data_pos;
    }

    ByteBuffer& get_buffer_impl() { return m_buffer; }
    const ByteBuffer& get_buffer_impl() const { return m_buffer; }

private:
    std::vector<T> m_data;
    ByteBuffer m_buffer;
};

template<IsNonTrivialType T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
public:
    /**
     * Type declarations
     */

    using ValueType = T;

    using Iterator = typename std::vector<Builder<T>>::iterator;
    using ConstIterator = typename std::vector<Builder<T>>::const_iterator;

    /**
     * Constructors
     */

    Builder() : m_data(), m_buffer() {}
    explicit Builder(size_t count) : m_data(count), m_buffer() {}
    explicit Builder(size_t count, const Builder<T>& value) : m_data(count, value), m_buffer() {}

    /**
     * Element access
     */

    Builder<T>& operator[](size_t pos)
    {
        assert(pos < size());
        return m_data[pos];
    }
    const Builder<T>& operator[](size_t pos) const
    {
        assert(pos < size());
        return m_data[pos];
    }
    Builder<T>& at(size_t pos) { return m_data.at(pos); }
    const Builder<T>& at(size_t pos) const { return m_data.at(pos); }

    /**
     * Iterators
     */

    Iterator begin() { return m_data.begin(); }
    ConstIterator begin() const { return m_data.begin(); }
    Iterator end() { return m_data.end(); }
    ConstIterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    constexpr bool empty() const { return m_data.empty(); }
    constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */
    void push_back(Builder<T>&& element) { m_data.push_back(std::move(element)); }
    void push_back(const Builder<T>& element) { m_data.push_back(element); }

    /// @brief Resize without default value argument enabled only if Builder<T> is default constructible.
    /// @param count
    void resize(size_t count)
        requires(std::default_initializable<Builder<T>>)
    {
        m_data.resize(count, Builder<T>());
    }
    void resize(size_t count, const Builder<T>& value) { m_data.resize(count, value); }
    void clear() { m_data.clear(); }

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { m_buffer.set_size(this->finish(0, m_buffer)); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        /* Write the vector size */
        out.write(pos + Layout<Vector<T>>::vector_size_position, m_data.size());

        size_t data_pos = Layout<Vector<T>>::vector_data_position;

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

        /* Write the size of the buffer to the beginning. */
        out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));

        return data_pos;
    }

    ByteBuffer& get_buffer_impl() { return m_buffer; }
    const ByteBuffer& get_buffer_impl() const { return m_buffer; }

private:
    std::vector<Builder<T>> m_data;
    ByteBuffer m_buffer;
};

/**
 * View
 */

template<IsTriviallyCopyable T>
class View<Vector<T>> : public IView<View<Vector<T>>>
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
    View(uint8_t* buf) : m_buf(buf) { assert(m_buf); }

    /**
     * Element access.
     */

    T operator[](size_t pos)
    {
        assert(pos < size());
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    T operator[](size_t pos) const
    {
        assert(pos < size());
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    T at(size_t pos)
    {
        range_check(pos);
        return (*this)[pos];
    }
    T at(size_t pos) const
    {
        range_check(pos);
        return (*this)[pos];
    }
    T* data()
        requires(IsTriviallyCopyable<T>)
    {
        return reinterpret_cast<T*>(m_buf + Layout<Vector<T>>::vector_data_position);
    }
    const T* data() const
        requires(IsTriviallyCopyable<T>)
    {
        return reinterpret_cast<const T*>(m_buf + Layout<Vector<T>>::vector_data_position);
    }

    /**
     * Mutate
     */

    void mutate(size_t pos, ValueType value)
        requires(IsTriviallyCopyable<ValueType>)
    {
        write_value<View<Vector<T>>::ValueType>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T), value);
    }

    /**
     * Iterators
     */

    class Iterator
    {
    private:
        uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;

        Iterator() : m_buf(nullptr) {}
        Iterator(uint8_t* buf) : m_buf(buf) {}

        value_type operator*() const { return read_value<T>(m_buf); }
        Iterator& operator++()
        {
            m_buf += sizeof(T);
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const Iterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    Iterator begin() { return Iterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    Iterator end() { return Iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size()); }

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = const value_type*;
        using reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator() : m_buf(nullptr) {}
        ConstIterator(const uint8_t* buf) : m_buf(buf) {}

        value_type operator*() const { return read_value<T>(m_buf); }
        ConstIterator& operator++()
        {
            m_buf += sizeof(T);
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const ConstIterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const ConstIterator& other) const { return !(*this == other); }
    };

    ConstIterator begin() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    ConstIterator end() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size()); }

    /**
     * Capacity
     */

    bool empty() const { return size() == 0; }
    size_t size() const { return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position); }

private:
    void range_check(size_t pos) const
    {
        if (pos >= size())
        {
            throw std::out_of_range("View<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                    + std::to_string(size()) + ")");
        }
    }

    /* Implement IView interface. */
    friend class IView<View<Vector<T>>>;

    uint8_t* get_buffer_impl() { return m_buf; }
    const uint8_t* get_buffer_impl() const { return m_buf; }

    BufferSizeType get_buffer_size_impl() const { return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position); }

private:
    uint8_t* m_buf;
};

template<IsNonTrivialType T>
class View<Vector<T>> : public IView<View<Vector<T>>>
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
    View(uint8_t* buf) : m_buf(buf) { assert(m_buf); }

    /**
     * Element access.
     */

    View<T> operator[](size_t pos)
    {
        assert(pos < size());
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return View<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
    ConstView<T> operator[](size_t pos) const
    {
        assert(pos < size());
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return ConstView<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
    View<T> at(size_t pos)
    {
        range_check(pos);
        return (*this)[pos];
    }
    ConstView<T> at(size_t pos) const
    {
        range_check(pos);
        return (*this)[pos];
    }

    /**
     * Iterators
     */

    class Iterator
    {
    private:
        uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = View<T>;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;

        Iterator() : m_buf(nullptr) {}
        Iterator(uint8_t* buf) : m_buf(buf) {}

        value_type operator*() const { return View<T>(m_buf + read_value<OffsetType>(m_buf)); }
        Iterator& operator++()
        {
            m_buf += sizeof(OffsetType);
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const Iterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    Iterator begin() { return Iterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    Iterator end() { return Iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size()); }

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = ConstView<T>;
        using pointer = const value_type*;
        using reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator() : m_buf(nullptr) {}
        ConstIterator(const uint8_t* buf) : m_buf(buf) {}

        value_type operator*() const { return ConstView<T>(m_buf + read_value<OffsetType>(m_buf)); }
        ConstIterator& operator++()
        {
            m_buf += sizeof(OffsetType);
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const ConstIterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const ConstIterator& other) const { return !(*this == other); }
    };

    ConstIterator begin() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    ConstIterator end() const { return View<Vector<T>>::ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size()); }

    /**
     * Capacity
     */

    bool empty() const { return size() == 0; }
    size_t size() const { return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position); }

private:
    void range_check(size_t pos) const
    {
        if (pos >= size())
        {
            throw std::out_of_range("View<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                    + std::to_string(size()) + ")");
        }
    }

    /* Implement IView interface. */
    friend class IView<View<Vector<T>>>;

    uint8_t* get_buffer_impl() { return m_buf; }
    const uint8_t* get_buffer_impl() const { return m_buf; }

    BufferSizeType get_buffer_size_impl() const { return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position); }

private:
    uint8_t* m_buf;
};

/**
 * ConstView
 */

template<IsTriviallyCopyable T>
class ConstView<Vector<T>> : public IConstView<ConstView<Vector<T>>>
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
    ConstView(const uint8_t* buf) : m_buf(buf) { assert(m_buf); }

    /**
     * Conversion constructors
     */

    ConstView(const View<Vector<T>>& view) : m_buf(view.buffer()) { assert(m_buf); }

    /**
     * Conversion assigments
     */

    ConstView& operator=(const View<Vector<T>>& view)
    {
        m_buf = view.buffer();
        assert(m_buf);
        return *this;
    }

    /**
     * Element access
     */

    T operator[](size_t pos) const
    {
        assert(pos < size());
        return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
    }
    T at(size_t pos) const
    {
        range_check(pos);
        return (*this)[pos];
    }
    const T* data() const { return reinterpret_cast<const T*>(m_buf + Layout<Vector<T>>::vector_data_position); }

    /**
     * Iterators
     */

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = const value_type*;
        using reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator() : m_buf(nullptr) {}
        ConstIterator(const uint8_t* buf) : m_buf(buf) {}

        value_type operator*() const { return read_value<T>(m_buf); }
        ConstIterator& operator++()
        {
            m_buf += sizeof(T);
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const ConstIterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const ConstIterator& other) const { return !(*this == other); }
    };

    ConstIterator begin() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    ConstIterator end() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size()); }

    /**
     * Capacity
     */

    bool empty() const { return size() == 0; }
    size_t size() const { return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position); }

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */

private:
    void range_check(size_t pos) const
    {
        if (pos >= size())
        {
            throw std::out_of_range("ConstView<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                    + std::to_string(size()) + ")");
        }
    }

    /* Implement IConstView interface. */
    friend class IConstView<ConstView<Vector<T>>>;

    const uint8_t* get_buffer_impl() const { return m_buf; }

    BufferSizeType get_buffer_size_impl() const { return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position); }

private:
    const uint8_t* m_buf;
};

template<IsNonTrivialType T>
class ConstView<Vector<T>> : public IConstView<ConstView<Vector<T>>>
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
    ConstView(const uint8_t* buf) : m_buf(buf) { assert(m_buf); }

    /**
     * Conversion constructors
     */

    ConstView(const View<Vector<T>>& view) : m_buf(view.buffer()) { assert(m_buf); }

    /**
     * Conversion assigments
     */

    ConstView& operator=(const View<Vector<T>>& view)
    {
        m_buf = view.buffer();
        assert(m_buf);
        return *this;
    }

    /**
     * Element access
     */

    ConstView<T> operator[](size_t pos) const
    {
        assert(pos < size());
        const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(OffsetType);
        return ConstView<T>(offset_pos + read_value<OffsetType>(offset_pos));
    }
    ConstView<T> at(size_t pos) const
    {
        range_check(pos);
        return (*this)[pos];
    }

    /**
     * Iterators
     */

    class ConstIterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = ConstView<T>;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator() : m_buf(nullptr) {}
        ConstIterator(const uint8_t* buf) : m_buf(buf) {}

        ConstView<T> operator*() const { return ConstView<T>(m_buf + read_value<OffsetType>(m_buf)); }
        ConstIterator& operator++()
        {
            m_buf += sizeof(OffsetType);
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const ConstIterator& other) const { return m_buf == other.m_buf; }
        bool operator!=(const ConstIterator& other) const { return !(*this == other); }
    };

    ConstIterator begin() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position); }
    ConstIterator end() const { return ConstIterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(OffsetType) * size()); }

    /**
     * Capacity
     */

    bool empty() const { return size() == 0; }
    size_t size() const { return read_value<VectorSizeType>(m_buf + Layout<Vector<T>>::vector_size_position); }

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */

private:
    void range_check(size_t pos) const
    {
        if (pos >= size())
        {
            throw std::out_of_range("ConstView<Vector<T>>::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                    + std::to_string(size()) + ")");
        }
    }

    /* Implement IConstView interface. */
    friend class IConstView<ConstView<Vector<T>>>;

    uint8_t* get_buffer_impl() { return m_buf; }
    const uint8_t* get_buffer_impl() const { return m_buf; }

    BufferSizeType get_buffer_size_impl() const { return read_value<BufferSizeType>(m_buf + Layout<Vector<T>>::buffer_size_position); }

private:
    const uint8_t* m_buf;
};

/**
 * Free function operators
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
bool operator!=(const V1& lhs, const V2& rhs)
{
    return !(lhs == rhs);
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
        flatmemory::MurmurHash3_x64_128(vector.get_buffer(), vector.get_buffer_size(), seed, hash);
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
        flatmemory::MurmurHash3_x64_128(vector.get_buffer(), vector.get_buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

#endif
