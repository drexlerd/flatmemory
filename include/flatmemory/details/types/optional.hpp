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
#include <ranges>
#include <vector>

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

    void print() const;
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
    size_t finish_impl(ByteBuffer& out, size_t pos);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

public:
    /**
     * Member functions
     */

    constexpr Builder();
    constexpr Builder(std::nullopt_t);
    constexpr Builder(const Builder& other);
    constexpr Builder(Builder&& other);

    constexpr Builder& operator=(std::nullopt_t);
    constexpr Builder& operator=(const Builder& other);
    constexpr Builder& operator=(Builder&& other);

    /**
     * Observers
     */

    constexpr const T_* operator->() const noexcept;
    constexpr T_* operator->() noexcept;

    constexpr const T_& operator*() const& noexcept;
    constexpr T_& operator*() & noexcept;

    constexpr const T_&& operator*() const&& noexcept;
    constexpr T_&& operator*() && noexcept;

    constexpr explicit operator bool() const noexcept;
    constexpr bool has_value() const noexcept;

    constexpr T_& value() &;
    constexpr const T_& value() const&;

    constexpr T_&& value() &&;
    constexpr const T_&& value() const&&;

    template<typename U>
    constexpr T_ value_or(U&& default_value) const&;

    template<typename U>
    constexpr T_ value_or(U&& default_value) &&;
};

/**
 * Builder operators
 */

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator==(const Builder<Optional<T>>& lhs, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator==(const Builder<Optional<T>>& lhs, std::nullopt_t);

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator==(std::nullopt_t, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator!=(const Builder<Optional<T>>& lhs, const Builder<Optional<T>>& rhs);

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator!=(const Builder<Optional<T>>& lhs, std::nullopt_t);

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr bool operator!=(std::nullopt_t, const Builder<Optional<T>>& rhs);

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

    void range_check(size_t pos) const;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf);
};
}

#endif
