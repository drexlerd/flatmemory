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

#ifndef FLATMEMORY_TYPES_OPTIONAL_HPP_
#define FLATMEMORY_TYPES_OPTIONAL_HPP_

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/types.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>

namespace flatmemory
{
/**
 * ID class
 */

/// @brief `Optional` implements an optional where a boolean encodes whether it holds a value of type T or not.
/// There is no additional buffer size prefix because taking the buffer size of T + 1 suffices.
/// @tparam T
template<IsTriviallyCopyableOrNonTrivialType T>
struct Optional : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Optional(const Optional& other) {}
};

/**
 * Layout
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class Layout<Optional<T>>
{
public:
    static constexpr size_t bool_position = 0;
    static constexpr size_t data_position = bool_position + sizeof(bool);

    constexpr void print() const;
};

/**
 * Builder
 */

template<IsTriviallyCopyable T>
class Builder<Optional<T>> : public IBuilder<Builder<Optional<T>>>
{
public:
    using ValueType = T;

    // Constructors and assignments (inline definitions)
    Builder() : m_has_value(false), m_value(), m_buffer() {}
    Builder(std::nullopt_t) : m_has_value(false), m_value(), m_buffer() {}
    Builder(const T& value) : m_has_value(true), m_value(value), m_buffer() {}
    Builder(T&& value) : m_has_value(true), m_value(std::move(value)), m_buffer() {}

    Builder(const Builder& other) : m_has_value(other.m_has_value), m_value(other.m_value), m_buffer(other.m_buffer) {}
    Builder(Builder&& other) : m_has_value(other.m_has_value), m_value(std::move(other.m_value)), m_buffer(std::move(other.m_buffer)) {}

    Builder& operator=(std::nullopt_t)
    {
        m_has_value = false;
        return *this;
    }

    Builder& operator=(const T& value)
    {
        m_has_value = true;
        m_value = value;
        return *this;
    }

    Builder& operator=(T&& value)
    {
        m_has_value = true;
        m_value = std::move(value);
        return *this;
    }

    Builder& operator=(const Builder& other)
    {
        if (this != &other)
        {
            m_has_value = other.m_has_value;
            m_value = other.m_value;
            m_buffer = other.m_buffer;
        }
        return *this;
    }

    Builder& operator=(Builder&& other)
    {
        if (this != &other)
        {
            m_has_value = other.m_has_value;
            m_value = std::move(other.m_value);
            m_buffer = std::move(other.m_buffer);
        }
        return *this;
    }

    // Observers (inline definitions)
    T* operator->() { return &m_value; }
    const T* operator->() const { return &m_value; }

    T& operator*() & { return m_value; }
    const T& operator*() const& { return m_value; }

    T&& operator*() && { return std::move(m_value); }
    const T&& operator*() const&& { return std::move(m_value); }

    explicit operator bool() const { return m_has_value; }
    bool has_value() const { return m_has_value; }

    T& value() &
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return m_value;
    }
    const T& value() const&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return m_value;
    }
    T&& value() &&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return std::move(m_value);
    }
    const T&& value() const&&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return std::move(m_value);
    }

private:
    bool m_has_value;
    T m_value;

    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { m_buffer.set_size(finish_impl(0, m_buffer)); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        /* Write whether the optional has a value. */
        out.write(pos + Layout<Optional<T>>::bool_position, m_has_value);

        size_t data_pos = Layout<Optional<T>>::data_position;

        if (m_has_value)
        {
            /* Write the value inline. */
            data_pos += out.write(pos + data_pos, m_value);
        }

        return data_pos;
    }

    auto& get_buffer_impl() { return m_buffer; }
    const auto& get_buffer_impl() const { return m_buffer; }
};

template<IsNonTrivialType T>
class Builder<Optional<T>> : public IBuilder<Builder<Optional<T>>>
{
public:
    using ValueType = T;

    // Constructors and assignments (inline definitions)
    Builder() : m_has_value(false), m_value(), m_buffer() {}
    Builder(std::nullopt_t) : m_has_value(false), m_value(), m_buffer() {}
    Builder(const Builder<T>& value) : m_has_value(true), m_value(value), m_buffer() {}
    Builder(Builder<T>&& value) : m_has_value(true), m_value(std::move(value)), m_buffer() {}

    Builder(const Builder& other) : m_has_value(other.m_has_value), m_value(other.m_value), m_buffer(other.m_buffer) {}
    Builder(Builder&& other) : m_has_value(other.m_has_value), m_value(std::move(other.m_value)), m_buffer(std::move(other.m_data)) {}

    Builder& operator=(std::nullopt_t)
    {
        m_has_value = false;
        return *this;
    }

    Builder& operator=(const Builder<T>& value)
    {
        m_has_value = true;
        m_value = value;
        return *this;
    }

    Builder& operator=(Builder<T>&& value)
    {
        m_has_value = true;
        m_value = value;
        return *this;
    }

    Builder& operator=(const Builder& other)
    {
        if (this != &other)
        {
            m_has_value = other.m_has_value;
            m_value = other.m_value;
            m_buffer = other.m_buffer;
        }
        return *this;
    }

    Builder& operator=(Builder&& other)
    {
        if (this != &other)
        {
            m_has_value = std::move(other.m_has_value);
            m_value = std::move(other.m_buffer);
            m_buffer = std::move(other.m_buffer);
        }
        return *this;
    }

    Builder<T>* operator->() { return &m_value; }
    const Builder<T>* operator->() const { return &m_value; }

    Builder<T>& operator*() & { return m_value; }
    const Builder<T>& operator*() const& { return m_value; }

    Builder<T>&& operator*() && { return std::move(m_value); }
    const Builder<T>&& operator*() const&& { return std::move(m_value); }

    explicit operator bool() const { return m_has_value; }
    bool has_value() const { return m_has_value; }

    Builder<T>& value() &
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return m_value;
    }
    const Builder<T>& value() const&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return m_value;
    }
    Builder<T>&& value() &&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return std::move(m_value);
    }
    const Builder<T>&& value() const&&
    {
        if (!m_has_value)
        {
            throw std::runtime_error("Optional<T>::value(): Tried to access non existing value.");
        }
        return std::move(m_value);
    }

private:
    bool m_has_value;
    Builder<T> m_value;

    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { m_buffer.set_size(finish_impl(0, m_buffer)); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        /* Write whether the optional has a value. */
        out.write(pos + Layout<Optional<T>>::bool_position, m_has_value);

        size_t data_pos = Layout<Optional<T>>::data_position;

        if (m_has_value)
        {
            /* Write the value inline. */
            data_pos += m_value.finish(pos + data_pos, out);
        }

        return data_pos;
    }

    auto& get_buffer_impl() { return m_buffer; }
    const auto& get_buffer_impl() const { return m_buffer; }
};

/**
 * View
 */
template<IsTriviallyCopyable T>
class View<Optional<T>>
{
public:
    using ValueType = T;

    /// @brief Constructor to interpret raw data created by its corresponding builder
    View(uint8_t* buf) : m_buf(buf) {}

    /**
     * Observers
     */

    T operator->() { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }
    T operator->() const { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T operator*() & { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }
    T operator*() const& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T operator*() && { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }
    T operator*() const&& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    explicit operator bool() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }
    bool has_value() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }

    T value() & { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }
    T value() const& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T value() && { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }
    T value() const&& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    void mutate(T value) { write_value(m_buf + Layout<Optional<T>>::data_position, value); }
    void mutate(const T& value) { write_value(m_buf + Layout<Optional<T>>::data_position, value); }
    void mutate(T&& value) { write_value(m_buf + Layout<Optional<T>>::data_position, std::move(value)); }

    uint8_t* buffer() { return m_buf; }
    const uint8_t* buffer() const { return m_buf; }

    BufferSizeType buffer_size() const
    {
        if (!has_value())
        {
            return Layout<Optional<T>>::data_position;
        }
        return Layout<Optional<T>>::data_position + sizeof(T);
    }

private:
    uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    View() = default;

    template<typename>
    friend class Builder;
};

template<IsNonTrivialType T>
class View<Optional<T>>
{
public:
    using ValueType = T;

    /// @brief Constructor to interpret raw data created by its corresponding builder
    View(uint8_t* buf) : m_buf(buf) {}

    /**
     * Observers
     */

    View<T> operator->() { return View<T>(m_buf + Layout<Optional<T>>::data_position); }
    ConstView<T> operator->() const { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    View<T> operator*() & { return View<T>(m_buf + Layout<Optional<T>>::data_position); }
    ConstView<T> operator*() const& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    View<T> operator*() && { return View<T>(m_buf + Layout<Optional<T>>::data_position); }
    ConstView<T> operator*() const&& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    explicit operator bool() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }
    bool has_value() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }

    View<T> value() & { return View<T>(m_buf + Layout<Optional<T>>::data_position); }
    ConstView<T> value() const& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    View<T> value() && { return View<T>(m_buf + Layout<Optional<T>>::data_position); }
    ConstView<T> value() const&& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    uint8_t* buffer() { return m_buf; }
    const uint8_t* buffer() const { return m_buf; }

    BufferSizeType buffer_size() const
    {
        if (!has_value())
        {
            return Layout<Optional<T>>::data_position;
        }
        return Layout<Optional<T>>::data_position + sizeof(T);
    }

private:
    uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    View() = default;

    template<typename>
    friend class Builder;
};

/**
 * ConstView
 */

template<IsTriviallyCopyable T>
class ConstView<Optional<T>>
{
public:
    using ValueType = T;

    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf) : m_buf(buf) {}

    /**
     * Observers
     */

    T operator->() const { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T operator*() const& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T operator*() const&& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    explicit operator bool() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }
    bool has_value() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }

    T value() const& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    T value() const&& { return read_value<T>(m_buf + Layout<Optional<T>>::data_position); }

    const uint8_t* buffer() const { return m_buf; }

    BufferSizeType buffer_size() const
    {
        if (!has_value())
        {
            return Layout<Optional<T>>::data_position;
        }
        return Layout<Optional<T>>::data_position + sizeof(T);
    }

private:
    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;
};

template<IsNonTrivialType T>
class ConstView<Optional<T>>
{
public:
    using ValueType = T;

    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf) : m_buf(buf) {}

    /**
     * Observers
     */

    ConstView<T> operator->() const { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    ConstView<T> operator*() const& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    ConstView<T> operator*() const&& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    explicit operator bool() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }
    bool has_value() const { return read_value<bool>(m_buf + Layout<Optional<T>>::bool_position); }

    ConstView<T> value() const& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    ConstView<T> value() const&& { return ConstView<T>(m_buf + Layout<Optional<T>>::data_position); }

    const uint8_t* buffer() const { return m_buf; }

    BufferSizeType buffer_size() const
    {
        if (!has_value())
        {
            return Layout<Optional<T>>::data_position;
        }
        return Layout<Optional<T>>::data_position + sizeof(T);
    }

private:
    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;
};

/**
 * Free function operators
 */

template<IsOptional O>
bool operator==(const O& lhs, const O& rhs)
{
    if (&lhs != &rhs)
    {
        if (lhs.has_value() != rhs.has_value())
        {
            // One has value, the other doesn't.
            return false;
        }
        if (!lhs.has_value())
        {
            // Both are empty.
            return true;
        }
        assert(lhs.has_value() && rhs.has_value());
        // Both have values.
        return lhs.value() == rhs.value();
    }
    return true;
}

template<IsOptional O>
bool operator==(const O& lhs, std::nullopt_t)
{
    return (!lhs.has_value());
}

template<IsOptional O>
bool operator==(std::nullopt_t, const O& rhs)
{
    return (!rhs.has_value());
}

template<IsOptional O1, IsOptional O2>
    requires HaveSameValueType<O1, O2>
bool operator==(const O1& lhs, const O2& rhs)
{
    if (lhs.has_value() != rhs.has_value())
    {
        // One has value, the other doesn't.
        return false;
    }
    if (!lhs.has_value())
    {
        // Both are empty.
        return true;
    }
    assert(lhs.has_value() && rhs.has_value());
    // Both have values.
    return lhs.value() == rhs.value();
}

template<IsOptional O>
bool operator!=(const O& lhs, const O& rhs)
{
    return !(lhs == rhs);
}

template<IsOptional O>
bool operator!=(const O& lhs, std::nullopt_t)
{
    return !(lhs == std::nullopt);
}

template<IsOptional O>
bool operator!=(std::nullopt_t, const O& rhs)
{
    return !(std::nullopt == rhs);
}

template<IsOptional O1, IsOptional O2>
    requires HaveSameValueType<O1, O2>
bool operator!=(const O1& lhs, const O2& rhs)
{
    return !(lhs == rhs);
}

}

template<flatmemory::IsOptional O>
struct std::hash<O>
{
    size_t operator()(const O& optional) const
    {
        if (!optional.has_value())
        {
            return 1;
        }
        return flatmemory::hash_combine(optional.value());
    }
};

#endif
