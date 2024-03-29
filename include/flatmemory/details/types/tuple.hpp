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
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/type_traits.hpp"
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
 * Dispatcher for Tuple.
 */
template<IsTriviallyCopyableOrCustom... Ts>
struct Tuple : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Tuple(const Tuple& other) {}
};

/**
 * Layout
 */
template<IsTriviallyCopyableOrCustom... Ts>
class Layout<Tuple<Ts...>>
{
private:
    /**
     * Helper function to calculate an array that contains header alignment requirements
     * with additional max overall alignment requirement at the end.
     */
    template<size_t... Is>
    static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_header_alignments(std::index_sequence<Is...>)
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

    /**
     * Helper function to calculate an array that contains data alignment requirements
     * with additional max overall alignment requirement at the end.
     */
    template<size_t... Is>
    static consteval std::array<size_t, sizeof...(Ts) + 1> calculate_data_alignments(std::index_sequence<Is...>)
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

    template<typename T>
    static consteval size_t calculate_header_offset_type_size()
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

    struct ElementData
    {
        size_t position;
        size_t end;
        size_t padding;
        size_t next_data_alignment;

        void print() const { std::cout << "position: " << position << " end: " << end << " padding: " << padding << std::endl; }
    };

    struct LayoutData
    {
        size_t buffer_size_position;
        size_t buffer_size_end;
        size_t buffer_size_padding;

        size_t element_datas_position;
        std::array<ElementData, sizeof...(Ts)> element_datas;

        void print() const
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
    };

    template<size_t... Is>
    static consteval LayoutData calculate_layout_data(std::index_sequence<Is...> index_sequence)
    {
        std::array<size_t, sizeof...(Ts) + 1> header_alignments = calculate_header_alignments(index_sequence);
        std::array<size_t, sizeof...(Ts) + 1> data_alignments = calculate_data_alignments(index_sequence);

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

public:
    static constexpr size_t size = sizeof...(Ts);

    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, Ts...>();

    static constexpr LayoutData layout_data = calculate_layout_data(std::make_index_sequence<sizeof...(Ts)> {});

    void print() const
    {
        layout_data.print();
        std::cout << "final_alignment: " << final_alignment << std::endl;
    }
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrCustom... Ts>
class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>>
{
private:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_builder_type = typename maybe_builder<element_type<I>>::type;

    std::tuple<typename maybe_builder<Ts>::type...> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    template<size_t... Is>
    void finish_iterative_impl(std::index_sequence<Is...>)
    {
        offset_type buffer_size = Layout<Tuple<Ts...>>::layout_data.element_datas_position;
        (
            [&]
            {
                using T = element_type<Is>;
                constexpr auto& element_data = Layout<Tuple<Ts...>>::layout_data.element_datas[Is];
                constexpr bool is_trivial = IsTriviallyCopyable<T>;
                if constexpr (is_trivial)
                {
                    auto& value = std::get<Is>(m_data);
                    m_buffer.write(element_data.position, value);
                    m_buffer.write_padding(element_data.end, element_data.padding);
                }
                else
                {
                    // write offset
                    m_buffer.write(element_data.position, buffer_size);
                    m_buffer.write_padding(element_data.end, element_data.padding);

                    // write data
                    auto& nested_builder = std::get<Is>(m_data);
                    nested_builder.finish();
                    buffer_size_type nested_buffer_size = nested_builder.buffer().size();
                    m_buffer.write(buffer_size, nested_builder.buffer().data(), nested_buffer_size);
                    buffer_size += nested_buffer_size;
                    buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, element_data.next_data_alignment));
                }
            }(),
            ...);
        // No need to write padding because if size=0 then no padding is needed and otherwise, if size>0 then the loop adds final padding.
        /* Write buffer size */
        m_buffer.write(Layout<Tuple<Ts...>>::layout_data.buffer_size_position, static_cast<buffer_size_type>(buffer_size));
        m_buffer.set_size(buffer_size);
    }

    void finish_impl()
    {
        // Build header and dynamic buffer
        finish_iterative_impl(std::make_index_sequence<sizeof...(Ts)> {});
    }

    auto& get_buffer_impl() { return m_buffer; }
    const auto& get_buffer_impl() const { return m_buffer; }

public:
    /**
     * Operators
     */
    [[nodiscard]] bool operator==(const Builder& other) const
    {
        if (this != &other)
        {
            return m_data == other.m_data;
        }
        return true;
    }

    [[nodiscard]] bool operator!=(const Builder& other) const { return !(*this == other); }

    /**
     * Lookup
     */

    template<std::size_t I>
    auto& get()
    {
        return std::get<I>(m_data);
    }

    template<std::size_t I>
    const auto& get() const
    {
        return std::get<I>(m_data);
    }

    template<size_t... Is>
    [[nodiscard]] size_t hash_helper(std::index_sequence<Is...>) const
    {
        size_t seed = Layout<Tuple<Ts...>>::size;
        (
            [&]
            {
                constexpr bool is_trivial = IsTriviallyCopyable<element_type<Is>>;
                if constexpr (is_trivial)
                {
                    hash_combine(seed, std::hash<element_type<Is>>()(get<Is>()));
                }
                else
                {
                    hash_combine(seed, get<Is>().hash());
                }
            }(),
            ...);
        return seed;
    }

    [[nodiscard]] size_t hash() const { return hash_helper(std::make_index_sequence<sizeof...(Ts)> {}); }
};

/**
 * View
 */
template<IsTriviallyCopyableOrCustom... Ts>
class View<Tuple<Ts...>>
{
private:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_view_type = View<std::tuple_element_t<I, std::tuple<Ts...>>>;

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
    View(uint8_t* data) : m_buf(data) { assert(m_buf); }

    /**
     * Operators
     */
    [[nodiscard]] bool operator==(const View& other) const
    {
        if (this != &other)
        {
            if (buffer_size() != other.buffer_size())
                return false;
            return std::memcmp(m_buf, other.m_buf, buffer_size()) == 0;
        }
        return true;
    }

    [[nodiscard]] bool operator!=(const View& other) const { return !(*this == other); }

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    decltype(auto) get()
    {
        assert(m_buf);
        assert(I < Layout<Tuple<Ts...>>::size);
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

    template<std::size_t I>
    decltype(auto) get() const
    {
        assert(m_buf);
        assert(I < Layout<Tuple<Ts...>>::size);
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

    [[nodiscard]] uint8_t* buffer() { return m_buf; }
    [[nodiscard]] const uint8_t* buffer() const { return m_buf; }

    [[nodiscard]] size_t buffer_size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position));
        return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position);
    }

    /**
     * Capacity
     */
    [[nodiscard]] size_t size() const { return Layout<Tuple<Ts...>>::size; }

    /**
     * Hashing
     */

    [[nodiscard]] size_t hash() const
    {
        size_t seed = Layout<Tuple<Ts...>>::size;
        int64_t hash[2];
        MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrCustom... Ts>
class ConstView<Tuple<Ts...>>
{
private:
    template<size_t I>
    using element_type = std::tuple_element_t<I, std::tuple<Ts...>>;
    template<size_t I>
    using element_view_type = ConstView<std::tuple_element_t<I, std::tuple<Ts...>>>;

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
    ConstView(const uint8_t* data) : m_buf(data) { assert(m_buf); }

    /**
     * Conversion constructor
     */
    ConstView(const View<Tuple<Ts...>>& view) : m_buf(view.buffer()) {}

    /**
     * Operators
     */

    [[nodiscard]] bool operator==(const ConstView& other) const
    {
        if (this != &other)
        {
            if (m_buf != other.m_buf)
            {
                if (buffer_size() != other.buffer_size())
                    return false;
                return std::memcmp(m_buf, other.m_buf, buffer_size()) == 0;
            }
        }
        return true;
    }

    [[nodiscard]] bool operator!=(const ConstView& other) const { return !(*this == other); }

    /**
     * Lookup
     */

    /// @brief Returns a View to the I-th element.
    ///
    /// If the I-th type is dynamic we must add the offset to the actual data first.
    template<std::size_t I>
    decltype(auto) get() const
    {
        assert(m_buf);
        assert(I < Layout<Tuple<Ts...>>::size);
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

    [[nodiscard]] size_t buffer_size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position));
        return read_value<buffer_size_type>(m_buf + Layout<Tuple<Ts...>>::layout_data.buffer_size_position);
    }

    [[nodiscard]] const uint8_t* buffer() const { return m_buf; }

    /**
     * Capacity
     */

    [[nodiscard]] size_t size() const { return Layout<Tuple<Ts...>>::size; }

    /**
     * Hashing
     */

    [[nodiscard]] size_t hash() const
    {
        size_t seed = Layout<Tuple<Ts...>>::size;
        int64_t hash[2];
        MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }
};
}

#endif
