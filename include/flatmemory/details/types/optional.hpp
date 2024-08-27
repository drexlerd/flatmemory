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

/**
 * UNDER CONSTRUCTION
 */

namespace flatmemory
{
/**
 * ID class for non-trivial Optional type.
 *
 * The idea is to encode in the prefix size whether the optional holds a value of type T as follows:
 * If the size prefix = sizeof(BufferSizeType), then the optional does not hold a value.
 * This works because hashing or equality will be correct
 */

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
    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t data_position = buffer_size_position + sizeof(BufferSizeType);

    constexpr void print() const;
};

/**
 * Free function operators
 */

template<IsOptional O>
bool operator==(const O& lhs, const O& rhs);

template<IsOptional O>
bool operator==(const O& lhs, std::nullopt_t);

template<IsOptional O>
bool operator==(std::nullopt_t, const O& rhs);

template<IsOptional O1, IsOptional O2>
    requires HaveSameValueType<O1, O2>
bool operator==(const O1& lhs, const O2& rhs);

template<IsOptional O>
bool operator==(std::nullopt_t, const O& rhs);

template<IsOptional O>
bool operator==(const O& lhs, std::nullopt_t);

template<IsOptional O>
bool operator!=(const O& lhs, const O& rhs);

template<IsOptional O>
bool operator!=(const O& lhs, std::nullopt_t);

template<IsOptional O>
bool operator!=(std::nullopt_t, const O& rhs);

template<IsOptional O>
bool operator!=(const O& lhs, std::nullopt_t);

template<IsOptional O>
bool operator!=(std::nullopt_t, const O& rhs);

/**
 * Builder
 */
// Specialization for trivially copyable types
template<IsTriviallyCopyable T>
class Builder<Optional<T>> : public IBuilder<Builder<Optional<T>>>
{
public:
    using ValueType = T;

    // Constructors and assignments (inline definitions)
    Builder() : m_data(), m_buffer() {}
    Builder(std::nullopt_t) : m_data(std::nullopt), m_buffer() {}
    Builder(const T& value) : m_data(value), m_buffer() {}
    Builder(T&& value) : m_data(std::move(value)), m_buffer() {}

    Builder(const Builder& other) : m_data(other.m_data), m_buffer(other.m_buffer) {}
    Builder(Builder&& other) : m_data(std::move(other.m_data)), m_buffer(std::move(other.m_data)) {}

    Builder& operator=(std::nullopt_t)
    {
        m_data = std::nullopt;
        return *this;
    }

    Builder& operator=(const T& value)
    {
        m_data = value;
        return *this;
    }

    Builder& operator=(T&& value)
    {
        m_data = std::move(value);
        return *this;
    }

    Builder& operator=(const Builder& other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
        }
        return *this;
    }

    Builder& operator=(Builder&& other)
    {
        if (this != &other)
        {
            m_data = std::move(other.m_data);
            m_buffer = std::move(other.m_buffer);
        }
        return *this;
    }

    // Observers (inline definitions)
    T* operator->() { return m_data.operator->(); }
    const T* operator->() const { return m_data.operator->(); }

    T& operator*() & { return *m_data; }
    const T& operator*() const& { return *m_data; }

    T&& operator*() && { return *m_data; }
    const T&& operator*() const&& { return *m_data; }

    explicit operator bool() const { return m_data.operator bool(); }
    bool has_value() const { return m_data.has_value(); }

    T& value() & { return m_data.value(); }
    const T& value() const& { return m_data.value(); }
    T&& value() && { return m_data.value(); }
    const T&& value() const&& { return m_data.value(); }

private:
    std::optional<T> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { finish_impl(0, m_buffer); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        size_t data_pos = Layout<Optional<T>>::data_position;

        if (m_data)
        {
            /* Write the trivial data inline. */
            m_buffer.write(pos + data_pos, m_data);
        }

        /* Write the size of the buffer to the beginning. */
        out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));
        out.set_size(data_pos);

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
    Builder() : m_data(), m_buffer() {}
    Builder(std::nullopt_t) : m_data(std::nullopt), m_buffer() {}
    Builder(const Builder<T>& value) : m_data(value), m_buffer() {}
    Builder(Builder<T>&& value) : m_data(std::move(value)), m_buffer() {}

    Builder(const Builder& other) : m_data(other.m_data), m_buffer(other.m_buffer) {}
    Builder(Builder&& other) : m_data(std::move(other.m_data)), m_buffer(std::move(other.m_data)) {}

    Builder& operator=(std::nullopt_t)
    {
        m_data = std::nullopt;
        return *this;
    }

    Builder& operator=(const Builder<T>& value)
    {
        m_data = value;
        return *this;
    }

    Builder& operator=(Builder<T>&& value)
    {
        m_data = std::move(value);
        return *this;
    }

    Builder& operator=(const Builder& other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
        }
        return *this;
    }

    Builder& operator=(Builder&& other)
    {
        if (this != &other)
        {
            m_data = std::move(other.m_data);
            m_buffer = std::move(other.m_buffer);
        }
        return *this;
    }

    // Observers (inline definitions)
    Builder<T>* operator->() { return m_data.operator->(); }
    const Builder<T>* operator->() const { return m_data.operator->(); }

    Builder<T>& operator*() & { return *m_data; }
    const Builder<T>& operator*() const& { return *m_data; }

    Builder<T>&& operator*() && { return *m_data; }
    const Builder<T>&& operator*() const&& { return *m_data; }

    explicit operator bool() const { return m_data.operator bool(); }
    bool has_value() const { return m_data.has_value(); }

    Builder<T>& value() & { return m_data.value(); }
    const Builder<T>& value() const& { return m_data.value(); }
    Builder<T>&& value() && { return m_data.value(); }
    const Builder<T>&& value() const&& { return m_data.value(); }

private:
    std::optional<Builder<T>> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl() { finish_impl(0, m_buffer); }
    size_t finish_impl(size_t pos, ByteBuffer& out)
    {
        size_t data_pos = Layout<Optional<T>>::data_position;

        if (m_data)
        {
            /* Write the buffer inline. */
            m_data.finish(pos + data_pos, m_buffer);
        }

        /* Write the size of the buffer to the beginning. */
        out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));
        out.set_size(data_pos);

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
    View(const uint8_t* buf);

    /**
     * Observers
     */

    T operator->();
    T operator->() const;

    T operator*() &;
    T operator*() const&;

    T operator*() &&;
    T operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    T value() &;
    T value() const&;

    T value() &&;
    T value() const&&;

    void mutate(T value);
    void mutate(const T& value);
    void mutate(T&& value);

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
    View(const uint8_t* buf);

    /**
     * Observers
     */

    View<T> operator->();
    ConstView<T> operator->() const;

    View<T> operator*() &;
    ConstView<T> operator*() const&;

    View<T> operator*() &&;
    ConstView<T> operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    View<T> value() &;
    ConstView<T> value() const&;

    View<T> value() &&;
    ConstView<T> value() const&&;

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
    ConstView(const uint8_t* buf);

    /**
     * Observers
     */

    T operator->() const;

    T operator*() const&;

    T operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    T value() const&;

    T value() const&&;

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
    ConstView(const uint8_t* buf);

    /**
     * Observers
     */

    ConstView<T> operator->() const;

    ConstView<T> operator*() const&;

    ConstView<T> operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    ConstView<T> value() const&;

    ConstView<T> value() const&&;

private:
    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;
};

}

#endif
