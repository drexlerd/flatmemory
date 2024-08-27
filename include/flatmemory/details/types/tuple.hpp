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

#ifndef FLATMEMORY_TYPES_TUPLE_HPP_
#define FLATMEMORY_TYPES_TUPLE_HPP_

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/types.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <tuple>

namespace flatmemory
{

/**
 * ID class for non-trivial Tuple type.
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
struct Tuple : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Tuple(const Tuple& other) {}
};

/**
 * Operators
 */

template<IsTuple T>
bool operator==(const T& lhs, const T& rhs);

template<IsTuple T1, IsTuple T2>
    requires HaveSameValueTypes<T1, T2>
bool operator==(const T1& lhs, const T2& rhs);

template<IsTuple T>
bool operator!=(const T& lhs, const T& rhs);

template<IsTuple T1, IsTuple T2>
    requires HaveSameValueTypes<T1, T2>
bool operator!=(const T1& lhs, const T2& rhs);

/**
 * Layout
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class Layout<Tuple<Ts...>>
{
private:
    template<size_t... Is>
    static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_data_positions(std::index_sequence<Is...> index_sequence, size_t first_pos);

public:
    static constexpr size_t size = sizeof...(Ts);

    static constexpr size_t buffer_size_position = 0;
    static constexpr std::array<size_t, sizeof...(Ts) + 1> data_positions =
        calculate_data_positions(std::make_index_sequence<sizeof...(Ts)> {}, sizeof(BufferSizeType));

    constexpr void print() const;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>>
{
public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_builder_type = typename maybe_builder<element_type<I>>::type;

    /**
     * Constructors
     */

    Builder(Ts&&... args);

    /// @brief Default constructor enabled only if all Ts are default-constructible.
    Builder()
        requires(std::default_initializable<typename maybe_builder<Ts>::type> && ...);

    /**
     * Lookup
     */

    template<std::size_t I>
    auto& get();

    template<std::size_t I>
    const auto& get() const;

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    template<size_t... Is>
    size_t finish_iterative_impl(std::index_sequence<Is...>, size_t pos, ByteBuffer& out);

    void finish_impl();
    size_t finish_impl(size_t pos, ByteBuffer& out);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

private:
    std::tuple<typename maybe_builder<Ts>::type...> m_data;
    ByteBuffer m_buffer;
};

/**
 * View
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class View<Tuple<Ts...>>
{
public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_view_type = View<std::tuple_element_t<I, std::tuple<Ts...>>>;
    template<size_t I>
    using const_element_view_type = ConstView<std::tuple_element_t<I, std::tuple<Ts...>>>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder.
    /// @param data
    View(uint8_t* data);

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    auto get();

    template<std::size_t I>
    auto get() const;

    template<std::size_t I>
    void mutate(element_type<I> value)
        requires(IsTriviallyCopyable<element_type<I>>);

    uint8_t* buffer();
    const uint8_t* buffer() const;

    BufferSizeType buffer_size() const;

    /**
     * Capacity
     */
    size_t size() const;

private:
    uint8_t* m_buf;
};

/**
 * ConstView
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
class ConstView<Tuple<Ts...>>
{
public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using const_element_view_type = ConstView<std::tuple_element_t<I, std::tuple<Ts...>>>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder.
    /// @param data
    ConstView(const uint8_t* data);

    /**
     * Conversion constructor
     */

    ConstView(const View<Tuple<Ts...>>& view);

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    auto get() const;

    BufferSizeType buffer_size() const;

    const uint8_t* buffer() const;

    /**
     * Capacity
     */

    size_t size() const;

private:
    const uint8_t* m_buf;
};

/**
 * Definitions
 */

/**
 * Operators
 */

template<IsTuple T1, IsTuple T2, std::size_t... Is>
static bool compare_tuples(std::index_sequence<Is...>, const T1& lhs, const T2& rhs)
{
    return (... && (lhs.template get<Is>() == rhs.template get<Is>()));
}

template<IsTuple T>
bool operator==(const T& lhs, const T& rhs)
{
    if (&lhs != &rhs)
    {
        return compare_tuples(std::make_index_sequence<std::tuple_size_v<typename T::ValueTypes>> {}, lhs, rhs);
    }
    return true;
}

template<IsTuple T1, IsTuple T2>
    requires HaveSameValueTypes<T1, T2>
bool operator==(const T1& lhs, const T2& rhs)
{
    return compare_tuples(std::make_index_sequence<std::tuple_size_v<typename T1::ValueTypes>> {}, lhs, rhs);
}

template<IsTuple T>
bool operator!=(const T& lhs, const T& rhs)
{
    return !(lhs == rhs);
}

template<IsTuple T1, IsTuple T2>
    requires HaveSameValueTypes<T1, T2>
bool operator!=(const T1& lhs, const T2& rhs)
{
    return !(lhs == rhs);
}

/**
 * Layout
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
consteval std::array<size_t, sizeof...(Ts) + 1> Layout<Tuple<Ts...>>::calculate_data_positions(std::index_sequence<Is...> index_sequence, size_t first_pos)
{
    std::array<size_t, sizeof...(Ts) + 1> data_positions {};
    (
        [&]
        {
            data_positions[Is] = first_pos;

            using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
            if constexpr (IsTriviallyCopyable<T>)
            {
                first_pos += sizeof(T);
            }
            else
            {
                first_pos += sizeof(OffsetType);
            }
        }(),
        ...);

    data_positions[sizeof...(Ts)] = first_pos;

    return data_positions;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
constexpr void Layout<Tuple<Ts...>>::print() const
{
    std::cout << "buffer_size_position: " << buffer_size_position << "\n"
              << "data_positions: [";
    for (const auto& pos : data_positions)
    {
        std::cout << pos << ", ";
    }
    std::cout << "]" << std::endl;
}

// Builder

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
size_t Builder<Tuple<Ts...>>::finish_iterative_impl(std::index_sequence<Is...>, size_t pos, ByteBuffer& out)
{
    size_t data_pos = Layout<Tuple<Ts...>>::data_positions.back();

    (
        [&]
        {
            using T = element_type<Is>;
            constexpr bool is_trivial = IsTriviallyCopyable<T>;

            if constexpr (is_trivial)
            {
                /* Write the data inline. */
                out.write(pos + Layout<Tuple<Ts...>>::data_positions[Is], std::get<Is>(m_data));
            }
            else
            {
                /* Write the distance between written data pos and offset pos at the offset pos. */
                out.write(pos + Layout<Tuple<Ts...>>::data_positions[Is], static_cast<OffsetType>(data_pos - Layout<Tuple<Ts...>>::data_positions[Is]));

                /* Write the data at offset */
                auto& nested_builder = std::get<Is>(m_data);
                data_pos += nested_builder.finish(pos + data_pos, out);
            }
        }(),
        ...);

    /* Write size of the buffer to the beginning. */
    out.write(pos + Layout<Tuple<Ts...>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));

    return data_pos;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Builder<Tuple<Ts...>>::finish_impl()
{
    m_buffer.set_size(this->finish(0, m_buffer));
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t Builder<Tuple<Ts...>>::finish_impl(size_t pos, ByteBuffer& out)
{
    return finish_iterative_impl(std::make_index_sequence<sizeof...(Ts)> {}, pos, out);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
auto& Builder<Tuple<Ts...>>::get_buffer_impl()
{
    return m_buffer;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
const auto& Builder<Tuple<Ts...>>::get_buffer_impl() const
{
    return m_buffer;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
Builder<Tuple<Ts...>>::Builder(Ts&&... args) : m_data(std::forward<Ts>(args)...), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
Builder<Tuple<Ts...>>::Builder()
    requires(std::default_initializable<typename maybe_builder<Ts>::type> && ...)
    : m_data(), m_buffer()
{
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
auto& Builder<Tuple<Ts...>>::get()
{
    static_assert(I < sizeof...(Ts));
    return std::get<I>(m_data);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
const auto& Builder<Tuple<Ts...>>::get() const
{
    static_assert(I < sizeof...(Ts));
    return std::get<I>(m_data);
}

// View

template<IsTriviallyCopyableOrNonTrivialType... Ts>
View<Tuple<Ts...>>::View(uint8_t* data) : m_buf(data)
{
    assert(m_buf);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
auto View<Tuple<Ts...>>::get()
{
    static_assert(I < sizeof...(Ts));
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Tuple<Ts...>>::data_positions[I];
        return element_view_type<I>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
auto View<Tuple<Ts...>>::get() const
{
    static_assert(I < sizeof...(Ts));
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Tuple<Ts...>>::data_positions[I];
        return const_element_view_type<I>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
void View<Tuple<Ts...>>::mutate(View<Tuple<Ts...>>::element_type<I> value)
    requires(IsTriviallyCopyable<View<Tuple<Ts...>>::element_type<I>>)
{
    return write_value<View<Tuple<Ts...>>::element_type<I>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I], value);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
uint8_t* View<Tuple<Ts...>>::buffer()
{
    return m_buf;
}
template<IsTriviallyCopyableOrNonTrivialType... Ts>
const uint8_t* View<Tuple<Ts...>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
BufferSizeType View<Tuple<Ts...>>::buffer_size() const
{
    assert(m_buf);
    return read_value<BufferSizeType>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t View<Tuple<Ts...>>::size() const
{
    return Layout<Tuple<Ts...>>::size;
}

// ConstView

template<IsTriviallyCopyableOrNonTrivialType... Ts>
ConstView<Tuple<Ts...>>::ConstView(const uint8_t* data) : m_buf(data)
{
    assert(m_buf);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
ConstView<Tuple<Ts...>>::ConstView(const View<Tuple<Ts...>>& view) : m_buf(view.buffer())
{
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
auto ConstView<Tuple<Ts...>>::get() const
{
    static_assert(I < sizeof...(Ts));
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }
    else
    {
        const auto offset_pos = m_buf + Layout<Tuple<Ts...>>::data_positions[I];
        return const_element_view_type<I>(offset_pos + read_value<OffsetType>(offset_pos));
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
BufferSizeType ConstView<Tuple<Ts...>>::buffer_size() const
{
    assert(m_buf);
    return read_value<BufferSizeType>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
const uint8_t* ConstView<Tuple<Ts...>>::buffer() const
{
    return m_buf;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t ConstView<Tuple<Ts...>>::size() const
{
    return Layout<Tuple<Ts...>>::size;
}

/**
 * Pretty printing
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
std::ostream& operator<<(std::ostream& out, ConstView<Tuple<Ts...>> element)
{
    auto formatter = Formatter(0, 4);
    formatter.write(element, out);
    return out;
}

}

template<typename... Ts>
struct std::hash<flatmemory::Builder<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::Builder<flatmemory::Tuple<Ts...>>& tuple) const
    {
        std::size_t seed = flatmemory::Layout<flatmemory::Tuple<Ts...>>::size;

        [&]<std::size_t... Is>(std::index_sequence<Is...>)
        { (flatmemory::hash_combine(seed, tuple.template get<Is>()), ...); }(std::make_index_sequence<sizeof...(Ts)> {});

        return seed;
    }
};

template<typename... Ts>
struct std::hash<flatmemory::View<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::View<flatmemory::Tuple<Ts...>>& tuple) const
    {
        size_t seed = flatmemory::Layout<flatmemory::Tuple<Ts...>>::size;
        int64_t hash[2];
        flatmemory::MurmurHash3_x64_128(tuple.buffer(), tuple.buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

template<typename... Ts>
struct std::hash<flatmemory::ConstView<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::ConstView<flatmemory::Tuple<Ts...>>& tuple) const
    {
        size_t seed = flatmemory::Layout<flatmemory::Tuple<Ts...>>::size;
        int64_t hash[2];
        flatmemory::MurmurHash3_x64_128(tuple.buffer(), tuple.buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

#endif
