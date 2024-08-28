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
private:
    template<typename T>
    class TupleEntry;

    template<IsTriviallyCopyable T>
    class TupleEntry<T>
    {
    public:
        TupleEntry() : m_value() {}
        TupleEntry(const T& value) : m_value(value) {}
        TupleEntry(T&& value) : m_value(std::move(value)) {}

        T& get() { return m_value; }
        const T& get() const { return m_value; }

        size_t finish(size_t offset_pos, size_t data_pos, ByteBuffer& out)
        {
            /* Write the data inline. */
            out.write(offset_pos, m_value);

            return data_pos;
        }

    private:
        T m_value;
    };

    template<IsNonTrivialType T>
    class TupleEntry<T>
    {
    public:
        TupleEntry() : m_value() {}
        TupleEntry(const Builder<T>& value) : m_value(value) {}
        TupleEntry(Builder<T>&& value) : m_value(std::move(value)) {}

        Builder<T>& get() { return m_value; }
        const Builder<T>& get() const { return m_value; }

        size_t finish(size_t offset_pos, size_t data_pos, ByteBuffer& out)
        {
            /* Write the distance between written data pos and offset pos at the offset pos. */
            out.write(offset_pos, static_cast<OffsetType>(data_pos - offset_pos));

            /* Write the data at offset */
            data_pos += m_value.finish(data_pos, out);

            return data_pos;
        }

    private:
        Builder<T> m_value;
    };

public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;

    /**
     * Constructors
     */

    // Builder(std::conditional_t<IsTriviallyCopyable<Ts>, Ts, Builder<Ts>>&&... args)
    //     requires(sizeof...(Ts) > 0)
    //     : m_data(std::forward<std::conditional_t<IsTriviallyCopyable<Ts>, Ts, Builder<Ts>>>(args)...), m_buffer()
    //{
    // }

    Builder() : m_data(), m_buffer() {}

    /**
     * Lookup
     */

    template<std::size_t I>
    auto& get()
    {
        static_assert(I < sizeof...(Ts));
        return std::get<I>(m_data).get();
    }

    template<std::size_t I>
    const auto& get() const
    {
        static_assert(I < sizeof...(Ts));
        return std::get<I>(m_data).get();
    }

private:
    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    template<size_t... Is>
    size_t finish_iterative_impl(std::index_sequence<Is...>, size_t pos, ByteBuffer& out)
    {
        size_t data_pos = Layout<Tuple<Ts...>>::data_positions.back();

        ([&] { data_pos = std::get<Is>(m_data).finish(Layout<Tuple<Ts...>>::data_positions[Is], data_pos, out); }(), ...);

        /* Write size of the buffer to the beginning. */
        out.write(pos + Layout<Tuple<Ts...>>::buffer_size_position, static_cast<BufferSizeType>(data_pos));

        return data_pos;
    }

    void finish_impl() { m_buffer.set_size(this->finish(0, m_buffer)); }
    size_t finish_impl(size_t pos, ByteBuffer& out) { return finish_iterative_impl(std::make_index_sequence<sizeof...(Ts)> {}, pos, out); }

    auto& get_buffer_impl() { return m_buffer; }
    const auto& get_buffer_impl() const { return m_buffer; }

private:
    std::tuple<TupleEntry<Ts>...> m_data;
    ByteBuffer m_buffer;
};

/**
 * View
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class View<Tuple<Ts...>>
{
private:
    /**
     * Helper lookup functions
     */

    template<typename T>
    auto get_element(uint8_t* buf)
    {
        static_assert(std::false_type::value, "View<Tuple<Ts...>>::get_element(...): Expected usage of overload.");
    }
    template<typename T>
    auto get_element(const uint8_t* buf) const
    {
        static_assert(std::false_type::value, "View<Tuple<Ts...>>::get_element(...): Expected usage of overload.");
    }

    template<IsTriviallyCopyable T>
    T get_element(uint8_t* buf)
    {
        return read_value<T>(buf);
    }
    template<IsTriviallyCopyable T>
    T get_element(const uint8_t* buf) const
    {
        return read_value<T>(buf);
    }

    template<IsNonTrivialType T>
    View<T> get_element(uint8_t* buf)
    {
        return View<T>(buf + read_value<OffsetType>(buf));
    }
    template<IsNonTrivialType T>
    ConstView<T> get_element(const uint8_t* buf) const
    {
        return ConstView<T>(buf + read_value<OffsetType>(buf));
    }

public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder.
    /// @param data
    View(uint8_t* data) : m_buf(data) { assert(m_buf); }

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    auto get()
    {
        static_assert(I < sizeof...(Ts));
        assert(m_buf);
        return get_element<std::tuple_element_t<I, std::tuple<Ts...>>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }

    template<std::size_t I>
    auto get() const
    {
        static_assert(I < sizeof...(Ts));
        assert(m_buf);
        return get_element<std::tuple_element_t<I, std::tuple<Ts...>>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }

    template<std::size_t I>
    void mutate(std::tuple_element_t<I, std::tuple<Ts...>> value)
        requires(IsTriviallyCopyable<std::tuple_element_t<I, std::tuple<Ts...>>>)
    {
        return write_value<std::tuple_element_t<I, std::tuple<Ts...>>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I], value);
    }

    uint8_t* buffer() { return m_buf; }
    const uint8_t* buffer() const { return m_buf; }

    BufferSizeType buffer_size() const
    {
        assert(m_buf);
        return read_value<BufferSizeType>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position);
    }

    /**
     * Capacity
     */
    size_t size() const { return Layout<Tuple<Ts...>>::size; }

private:
    uint8_t* m_buf;
};

/**
 * ConstView
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
class ConstView<Tuple<Ts...>>
{
private:
    /**
     * Helper lookup functions
     */

    template<typename T>
    auto get_element(const uint8_t* buf) const
    {
        static_assert(std::false_type::value, "ConstView<Tuple<Ts...>>::get_element(...): Expected usage of overload.");
    }

    template<IsTriviallyCopyable T>
    T get_element(const uint8_t* buf) const
    {
        return read_value<T>(buf);
    }

    template<IsNonTrivialType T>
    ConstView<T> get_element(const uint8_t* buf) const
    {
        return ConstView<T>(buf + read_value<OffsetType>(buf));
    }

public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder.
    /// @param data
    ConstView(const uint8_t* data) : m_buf(data) { assert(m_buf); }

    /**
     * Conversion constructor
     */

    ConstView(const View<Tuple<Ts...>>& view) : m_buf(view.buffer()) {}

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    auto get() const
    {
        static_assert(I < sizeof...(Ts));
        assert(m_buf);
        return get_element<std::tuple_element_t<I, std::tuple<Ts...>>>(m_buf + Layout<Tuple<Ts...>>::data_positions[I]);
    }

    BufferSizeType buffer_size() const
    {
        assert(m_buf);
        return read_value<BufferSizeType>(m_buf + Layout<Tuple<Ts...>>::buffer_size_position);
    }

    const uint8_t* buffer() const { return m_buf; }

    /**
     * Capacity
     */

    size_t size() const { return Layout<Tuple<Ts...>>::size; }

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

/**
 * Pretty printing
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
std::ostream& operator<<(std::ostream& out, ConstView<Tuple<Ts...>> element)
{
    return out;
}

}

template<flatmemory::IsTriviallyCopyableOrNonTrivialType... Ts>
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

template<flatmemory::IsTriviallyCopyableOrNonTrivialType... Ts>
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

template<flatmemory::IsTriviallyCopyableOrNonTrivialType... Ts>
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
