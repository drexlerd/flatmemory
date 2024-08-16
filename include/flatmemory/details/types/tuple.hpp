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
#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

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
    /**
     * Helper function to calculate an array that contains header alignment requirements
     * with additional max overall alignment requirement at the end.
     */
    template<size_t... Is>
    static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_header_alignments(std::index_sequence<Is...>);

    /**
     * Helper function to calculate an array that contains data alignment requirements
     * with additional max overall alignment requirement at the end.
     */
    template<size_t... Is>
    static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_data_alignments(std::index_sequence<Is...>);

    template<typename T>
    static consteval size_t calculate_header_offset_type_size();

    struct ElementData
    {
        size_t position;
        size_t end;
        size_t padding;
        size_t next_data_alignment;

        void print() const;
    };

    struct LayoutData
    {
        size_t buffer_size_position;
        size_t buffer_size_end;
        size_t buffer_size_padding;

        size_t element_datas_position;
        std::array<ElementData, sizeof...(Ts)> element_datas;

        void print() const;
    };

    template<size_t... Is>
    static consteval LayoutData calculate_layout_data(std::index_sequence<Is...> index_sequence);

public:
    static constexpr size_t size = sizeof...(Ts);

    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, Ts...>();

    static constexpr LayoutData layout_data = calculate_layout_data(std::make_index_sequence<sizeof...(Ts)> {});

    void print() const;
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>>
{
public:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_builder_type = typename maybe_builder<element_type<I>>::type;

private:
    std::tuple<typename maybe_builder<Ts>::type...> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    template<size_t... Is>
    size_t finish_iterative_impl(std::index_sequence<Is...>, ByteBuffer& out, size_t pos);

    void finish_impl();
    size_t finish_impl(ByteBuffer& out, size_t pos);

    auto& get_buffer_impl();
    const auto& get_buffer_impl() const;

public:
    /**
     * Constructors
     */

    /**
     * Operators
     */

    template<std::size_t... Is>
    bool compare_tuples(std::index_sequence<Is...>, const ConstView<Tuple<Ts...>>& other) const;

    template<std::size_t... Is>
    bool compare_tuples(std::index_sequence<Is...>, const View<Tuple<Ts...>>& other) const;

    bool operator==(const Builder& other) const;
    bool operator==(const ConstView<Tuple<Ts...>> other) const;
    bool operator==(const View<Tuple<Ts...>> other) const;
    bool operator!=(const Builder& other) const;
    bool operator!=(const View<Tuple<Ts...>>& other) const;
    bool operator!=(const ConstView<Tuple<Ts...>>& other) const;

    /**
     * Lookup
     */

    template<std::size_t I>
    auto& get();

    template<std::size_t I>
    const auto& get() const;

    template<size_t... Is>
    size_t hash_helper(std::index_sequence<Is...>) const;

    size_t hash() const;
};

/**
 * View
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class View<Tuple<Ts...>>
{
public:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_view_type = View<std::tuple_element_t<I, std::tuple<Ts...>>>;
    template<size_t I>
    using const_element_view_type = ConstView<std::tuple_element_t<I, std::tuple<Ts...>>>;

private:
    uint8_t* m_buf;

    /**
     * Default constructor to make view a trivial data type and serializable
     */
    View() = default;

    template<typename>
    friend class Builder;

public:
    /**
     * Constructor to interpret raw data created by its corresponding builder
     */
    View(uint8_t* data);

    /**
     * Operators
     */

    template<std::size_t... Is>
    bool compare_tuples(std::index_sequence<Is...>, const Builder<Tuple<Ts...>>& other) const;

    bool operator==(const Builder<Tuple<Ts...>> other) const;
    bool operator==(const View& other) const;
    bool operator==(const ConstView<Tuple<Ts...>> other) const;
    bool operator!=(const Builder<Tuple<Ts...>>& other) const;
    bool operator!=(const View<Tuple<Ts...>>& other) const;
    bool operator!=(const ConstView<Tuple<Ts...>>& other) const;

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    decltype(auto) get();

    template<std::size_t I>
    decltype(auto) get() const;

    uint8_t* buffer();
    const uint8_t* buffer() const;

    buffer_size_type buffer_size() const;

    /**
     * Capacity
     */
    size_t size() const;

    /**
     * Hashing
     */

    size_t hash() const;
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrNonTrivialType... Ts>
class ConstView<Tuple<Ts...>>
{
public:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using const_element_view_type = ConstView<std::tuple_element_t<I, std::tuple<Ts...>>>;

private:
    const uint8_t* m_buf;

    /**
     * Default constructor to make view a trivial data type and serializable
     */
    ConstView() = default;

    template<typename>
    friend class Builder;

public:
    /**
     * Constructor to interpret raw data created by its corresponding builder
     */

    ConstView(const uint8_t* data);

    /**
     * Conversion constructor
     */

    ConstView(const View<Tuple<Ts...>>& view);

    /**
     * Operators
     */

    template<std::size_t... Is>
    bool compare_tuples(std::index_sequence<Is...>, const Builder<Tuple<Ts...>>& other) const;

    bool operator==(const Builder<Tuple<Ts...>> other) const;
    bool operator==(const View<Tuple<Ts...>>& other) const;
    bool operator==(const ConstView<Tuple<Ts...>> other) const;
    bool operator!=(const Builder<Tuple<Ts...>>& other) const;
    bool operator!=(const View<Tuple<Ts...>>& other) const;
    bool operator!=(const ConstView<Tuple<Ts...>>& other) const;

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    decltype(auto) get() const;

    buffer_size_type buffer_size() const;

    const uint8_t* buffer() const;

    /**
     * Capacity
     */

    size_t size() const;

    /**
     * Hashing
     */

    size_t hash() const;
};

/**
 * Definitions
 */

// Layout

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
consteval std::array<size_t, sizeof...(Ts) + 1> Layout<Tuple<Ts...>>::calculate_header_alignments(std::index_sequence<Is...>)
{
    std::array<size_t, sizeof...(Ts) + 1> alignments {};
    (
        [&]
        {
            using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
            alignments[Is] = calculate_header_alignment<T>();
        }(),
        ...);
    alignments[sizeof...(Ts)] = final_alignment;
    return alignments;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
consteval std::array<size_t, sizeof...(Ts) + 1> Layout<Tuple<Ts...>>::calculate_data_alignments(std::index_sequence<Is...>)
{
    std::array<size_t, sizeof...(Ts) + 1> alignments {};
    (
        [&]
        {
            using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
            alignments[Is] = calculate_data_alignment<T>();
        }(),
        ...);
    alignments[sizeof...(Ts)] = final_alignment;
    return alignments;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<typename T>
consteval size_t Layout<Tuple<Ts...>>::calculate_header_offset_type_size()
{
    constexpr bool is_trivial = IsTriviallyCopyable<T>;
    if constexpr (is_trivial)
    {
        return sizeof(T);
    }
    else
    {
        return sizeof(offset_type);
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Layout<Tuple<Ts...>>::ElementData::print() const
{
    std::cout << "position: " << position << " end: " << end << " padding: " << padding << std::endl;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Layout<Tuple<Ts...>>::LayoutData::print() const
{
    std::cout << "buffer_size_position: " << buffer_size_position << "\n"
              << "buffer_size_end: " << buffer_size_end << "\n"
              << "buffer_size_padding: " << buffer_size_padding << "\n"
              << "element_datas_position: " << element_datas_position << std::endl;
    for (const auto& element_data : element_datas)
    {
        element_data.print();
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
consteval Layout<Tuple<Ts...>>::LayoutData Layout<Tuple<Ts...>>::calculate_layout_data(std::index_sequence<Is...> index_sequence)
{
    std::array<size_t, sizeof...(Ts) + 1> header_alignments = calculate_header_alignments(index_sequence);
    [[maybe_unused]] std::array<size_t, sizeof...(Ts) + 1> data_alignments = calculate_data_alignments(index_sequence);

    size_t buffer_size_position = 0;
    size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
    size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, header_alignments[0]);

    size_t current_position = buffer_size_end + buffer_size_padding;

    std::array<ElementData, sizeof...(Ts)> element_datas {};
    (
        [&]
        {
            using T = std::tuple_element_t<Is, std::tuple<Ts...>>;
            size_t position = current_position;
            size_t end = position + calculate_header_offset_type_size<T>();
            size_t padding = calculate_amount_padding(end, header_alignments[Is + 1]);
            size_t next_data_alignment = data_alignments[Is + 1];
            element_datas[Is] = ElementData { position, end, padding, next_data_alignment };
            current_position = end + padding;
        }(),
        ...);

    size_t element_datas_position = current_position;

    return LayoutData { buffer_size_position, buffer_size_end, buffer_size_padding, element_datas_position, element_datas };
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Layout<Tuple<Ts...>>::print() const
{
    layout_data.print();
    std::cout << "final_alignment: " << final_alignment << std::endl;
}

// Builder

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
size_t Builder<Tuple<Ts...>>::finish_iterative_impl(std::index_sequence<Is...>, ByteBuffer& out, size_t pos)
{
    size_t data_pos = Layout<Tuple<Ts...>>::layout_data.element_datas_position;
    (
        [&]
        {
            using T = element_type<Is>;
            constexpr auto& element_data = Layout<Tuple<Ts...>>::layout_data.element_datas[Is];
            constexpr bool is_trivial = IsTriviallyCopyable<T>;

            if constexpr (is_trivial)
            {
                /* Write the data inline. */
                auto& value = std::get<Is>(m_data);
                out.write(pos + element_data.position, value);
                out.write_padding(pos + element_data.end, element_data.padding);
            }
            else
            {
                /* Write the data pos at the offset pos. */
                out.write(pos + element_data.position, static_cast<offset_type>(data_pos));
                out.write_padding(pos + element_data.end, element_data.padding);

                /* Write the data at offset */
                auto& nested_builder = std::get<Is>(m_data);
                data_pos += nested_builder.finish(out, pos + data_pos);
                data_pos += out.write_padding(pos + data_pos, calculate_amount_padding(data_pos, element_data.next_data_alignment));
            }
        }(),
        ...);

    // There is no need to write padding here because if size=0 then no padding is needed and otherwise, if size>0 then the loop adds final padding.

    /* Write size of the buffer to the beginning. */
    out.write(pos + Layout<Tuple<Ts...>>::layout_data.buffer_size_position, static_cast<buffer_size_type>(data_pos));
    out.set_size(data_pos);

    return data_pos;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
void Builder<Tuple<Ts...>>::finish_impl()
{
    this->finish(m_buffer, 0);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t Builder<Tuple<Ts...>>::finish_impl(ByteBuffer& out, size_t pos)
{
    return finish_iterative_impl(std::make_index_sequence<sizeof...(Ts)> {}, out, pos);
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
bool Builder<Tuple<Ts...>>::operator==(const Builder& other) const
{
    if (this != &other)
    {
        return m_data == other.m_data;
    }
    return true;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t... Is>
bool Builder<Tuple<Ts...>>::compare_tuples(std::index_sequence<Is...>, const ConstView<Tuple<Ts...>>& other) const
{
    return (... && (std::get<Is>(m_data) == other.template get<Is>()));
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool Builder<Tuple<Ts...>>::operator==(const ConstView<Tuple<Ts...>> other) const
{  //
    return compare_tuples(std::index_sequence_for<Ts...> {}, other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t... Is>
bool Builder<Tuple<Ts...>>::compare_tuples(std::index_sequence<Is...>, const View<Tuple<Ts...>>& other) const
{
    return (... && (std::get<Is>(m_data) == other.template get<Is>()));
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool Builder<Tuple<Ts...>>::operator==(const View<Tuple<Ts...>> other) const
{  //
    return compare_tuples(std::index_sequence_for<Ts...> {}, other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool Builder<Tuple<Ts...>>::operator!=(const Builder& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool Builder<Tuple<Ts...>>::operator!=(const View<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool Builder<Tuple<Ts...>>::operator!=(const ConstView<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
auto& Builder<Tuple<Ts...>>::get()
{
    return std::get<I>(m_data);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
const auto& Builder<Tuple<Ts...>>::get() const
{
    return std::get<I>(m_data);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<size_t... Is>
size_t Builder<Tuple<Ts...>>::hash_helper(std::index_sequence<Is...>) const
{
    size_t seed = Layout<Tuple<Ts...>>::size;
    ([&] { flatmemory::hash_combine(seed, get<Is>()); }(), ...);
    return seed;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t Builder<Tuple<Ts...>>::hash() const
{
    return hash_helper(std::make_index_sequence<sizeof...(Ts)> {});
}

// View

template<IsTriviallyCopyableOrNonTrivialType... Ts>
View<Tuple<Ts...>>::View(uint8_t* data) : m_buf(data)
{
    assert(m_buf);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t... Is>
bool View<Tuple<Ts...>>::compare_tuples(std::index_sequence<Is...>, const Builder<Tuple<Ts...>>& other) const
{
    return (... && (get<Is>() == other.template get<Is>()));
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator==(const Builder<Tuple<Ts...>> other) const
{  //
    return compare_tuples(std::index_sequence_for<Ts...> {}, other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator==(const View& other) const
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

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator==(const ConstView<Tuple<Ts...>> other) const
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

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator!=(const Builder<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator!=(const View<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool View<Tuple<Ts...>>::operator!=(const ConstView<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
decltype(auto) View<Tuple<Ts...>>::get()
{
    static_assert(I < Layout<Tuple<Ts...>>::size);
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position);
    }
    else
    {
        return element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
decltype(auto) View<Tuple<Ts...>>::get() const
{
    static_assert(I < Layout<Tuple<Ts...>>::size);
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position);
    }
    else
    {
        return const_element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
    }
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
buffer_size_type View<Tuple<Ts...>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t View<Tuple<Ts...>>::size() const
{
    return Layout<Tuple<Ts...>>::size;
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t View<Tuple<Ts...>>::hash() const
{
    size_t seed = Layout<Tuple<Ts...>>::size;
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
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
template<std::size_t... Is>
bool ConstView<Tuple<Ts...>>::compare_tuples(std::index_sequence<Is...>, const Builder<Tuple<Ts...>>& other) const
{
    return (... && (get<Is>() == other.template get<Is>()));
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator==(const Builder<Tuple<Ts...>> other) const
{  //
    return compare_tuples(std::index_sequence_for<Ts...> {}, other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator==(const View<Tuple<Ts...>>& other) const
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

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator==(const ConstView<Tuple<Ts...>> other) const
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

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator!=(const Builder<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator!=(const View<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
bool ConstView<Tuple<Ts...>>::operator!=(const ConstView<Tuple<Ts...>>& other) const
{
    return !(*this == other);
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
template<std::size_t I>
decltype(auto) ConstView<Tuple<Ts...>>::get() const
{
    static_assert(I < Layout<Tuple<Ts...>>::size);
    assert(m_buf);
    constexpr bool is_trivial = IsTriviallyCopyable<element_type<I>>;
    if constexpr (is_trivial)
    {
        assert(test_correct_alignment<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
        return read_value<element_type<I>>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position);
    }
    else
    {
        return const_element_view_type<I>(m_buf + read_value<offset_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.element_datas[I].position));
    }
}

template<IsTriviallyCopyableOrNonTrivialType... Ts>
buffer_size_type ConstView<Tuple<Ts...>>::buffer_size() const
{
    assert(m_buf);
    assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position));
    return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position);
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

template<IsTriviallyCopyableOrNonTrivialType... Ts>
size_t ConstView<Tuple<Ts...>>::hash() const
{
    size_t seed = Layout<Tuple<Ts...>>::size;
    int64_t hash[2];
    MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
    return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
}

}

template<typename... Ts>
struct std::hash<flatmemory::Builder<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::Builder<flatmemory::Tuple<Ts...>>& tuple) const { return tuple.hash(); }
};

template<typename... Ts>
struct std::hash<flatmemory::View<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::View<flatmemory::Tuple<Ts...>>& tuple) const { return tuple.hash(); }
};

template<typename... Ts>
struct std::hash<flatmemory::ConstView<flatmemory::Tuple<Ts...>>>
{
    size_t operator()(const flatmemory::ConstView<flatmemory::Tuple<Ts...>>& tuple) const { return tuple.hash(); }
};

#endif
