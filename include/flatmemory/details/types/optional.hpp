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
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/operator.hpp"
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
 * If the size prefix = sizeof(buffer_size_type), then the optional does not hold a value.
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
    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, T>();

    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
    static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_data_alignment<T>());
    static constexpr size_t data_position = buffer_size_end + buffer_size_padding;

    constexpr void print() const;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class Builder<Optional<T>> : public IBuilder<Builder<Optional<T>>>
{
public:
    using T_ = typename maybe_builder<T>::type;

private:
    std::optional<T_> m_data;
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
     * Constructors and assignments
     */

    Builder() requires(std::default_initializable<typename maybe_builder<T>::type>);
    Builder(std::nullopt_t);
    Builder(const Builder& other);
    Builder(Builder&& other);
    Builder(const View<Optional<T>>& other);
    Builder(View<Optional<T>>&& other);
    Builder(const ConstView<Optional<T>>& other);
    Builder(ConstView<Optional<T>>&& other);

    Builder& operator=(std::nullopt_t);
    Builder& operator=(const Builder& other);
    Builder& operator=(Builder&& other);
    Builder& operator=(const View<Optional<T>>& other);
    Builder& operator=(View<Optional<T>>&& other);
    Builder& operator=(const ConstView<Optional<T>>& other);
    Builder& operator=(ConstView<Optional<T>>&& other);

    /**
     * Observers
     */

    T_* operator->();
    const T_* operator->() const;

    T_& operator*() &;
    const T_& operator*() const&;

    T_&& operator*() &&;
    const T_&& operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    T_& value() &;
    const T_& value() const&;

    T_&& value() &&;
    const T_&& value() const&&;
};

/**
 * Builder operators
 */

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator==(const Builder<Optional<T>>& lhs, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator==(const Builder<Optional<T>>& lhs, std::nullopt_t);

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator==(std::nullopt_t, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator!=(const Builder<Optional<T>>& lhs, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator!=(const Builder<Optional<T>>& lhs, std::nullopt_t);

template<IsTriviallyCopyableOrNonTrivialType T>
bool operator!=(std::nullopt_t, const Builder<Optional<T>>& rhs);

/**
 * View
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class View<Optional<T>>
{
public:
    using T_ = typename maybe_builder<T>::type;

private:
    uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    View() = default;

    template<typename>
    friend class Builder;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder
    View(const uint8_t* buf);

    /**
     * Observers
     */

    T_* operator->();
    const T_* operator->() const;

    T_& operator*() &;
    const T_& operator*() const&;

    T_&& operator*() &&;
    const T_&& operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    T_& value() &;
    const T_& value() const&;

    T_&& value() &&;
    const T_&& value() const&&;
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrNonTrivialType T>
class ConstView<Optional<T>>
{
public:
    using T_ = typename maybe_builder<T>::type;

private:
    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf);

    /**
     * Observers
     */

    const T_* operator->() const;

    const T_& operator*() const&;

    const T_&& operator*() const&&;

    explicit operator bool() const;
    bool has_value() const;

    const T_& value() const&;

    const T_&& value() const&&;
};

/**
 * Implementations
 */

/**
 * IBuilder interface
 */

template<IsTriviallyCopyableOrNonTrivialType T>
void Builder<Optional<T>>::finish_impl()
{
    finish_impl(0, m_buffer);
}

template<IsTriviallyCopyableOrNonTrivialType T>
size_t Builder<Optional<T>>::finish_impl(size_t pos, ByteBuffer& out)
{
    size_t data_pos = Layout<Optional<T>>::data_position;

    if (m_data)
    {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            /* Write the trivial data inline. */
            m_buffer.write(pos + data_pos, m_data);
        }
        else
        {
            /* Write the buffer inline. */
            m_data.finish(pos + data_pos, m_buffer);
        }
    }

    /* Write the size of the buffer to the beginning. */
    out.write(pos + Layout<Vector<T>>::buffer_size_position, static_cast<buffer_size_type>(data_pos));
    out.set_size(data_pos);

    return data_pos;
}

template<IsTriviallyCopyableOrNonTrivialType T>
auto& Builder<Optional<T>>::get_buffer_impl()
{
    return m_buffer;
}

template<IsTriviallyCopyableOrNonTrivialType T>
const auto& Builder<Optional<T>>::get_buffer_impl() const
{
    return m_buffer;
}

/**
 * Constructors and assignments
 */

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder() requires(std::default_initializable<typename Builder<Optional<T>>::T_>) : m_data(Builder<Optional<T>>::T_()), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(std::nullopt_t) : m_data(std::nullopt), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(const Builder& other) : m_data(other.m_data), m_buffer(other.m_buffer)
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(Builder&& other) : m_data(std::move(other.m_data)), m_buffer(std::move(other.m_data))
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(const View<Optional<T>>& other) : m_data(other.value()), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(View<Optional<T>>&& other) : m_data(other.value()), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(const ConstView<Optional<T>>& other) : m_data(other.value()), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::Builder(ConstView<Optional<T>>&& other) : m_data(other.value()), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(std::nullopt_t)
{
    m_data = std::nullopt;
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(const Builder& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(Builder&& other)
{
    if (this != &other)
    {
        m_data = std::move(other.m_data);
        m_buffer = std::move(other.m_buffer);
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(const View<Optional<T>>& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(View<Optional<T>>&& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(const ConstView<Optional<T>>& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>& Builder<Optional<T>>::operator=(ConstView<Optional<T>>&& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

/**
 * Observers
 */

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::T_* Builder<Optional<T>>::operator->()
{
    return m_data.operator->();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Optional<T>>::T_* Builder<Optional<T>>::operator->() const
{
    return m_data.operator->();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::T_& Builder<Optional<T>>::operator*() &
{
    return *m_data;
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Optional<T>>::T_& Builder<Optional<T>>::operator*() const&
{
    return *m_data;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::T_&& Builder<Optional<T>>::operator*() &&
{
    return *m_data;
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Optional<T>>::T_&& Builder<Optional<T>>::operator*() const&&
{
    return *m_data;
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::operator bool() const
{
    return m_data.operator bool();
}

template<IsTriviallyCopyableOrNonTrivialType T>
bool Builder<Optional<T>>::has_value() const
{
    return m_data.has_value();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::T_& Builder<Optional<T>>::value() &
{
    return m_data.value();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Optional<T>>::T_& Builder<Optional<T>>::value() const&
{
    return m_data.value();
}

template<IsTriviallyCopyableOrNonTrivialType T>
Builder<Optional<T>>::T_&& Builder<Optional<T>>::value() &&
{
    return m_data.value();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const Builder<Optional<T>>::T_&& Builder<Optional<T>>::value() const&&
{
    return m_data.value();
}

}

#endif
