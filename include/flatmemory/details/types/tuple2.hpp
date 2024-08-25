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

#ifndef FLATMEMORY_TYPES_TYPED_TUPLE_HPP_
#define FLATMEMORY_TYPES_TYPED_TUPLE_HPP_

#include "flatmemory/details/algorithms/hash.hpp"
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/flexbuffer_utils.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/types/declarations.hpp"
#include "flatmemory/details/types/formatter.hpp"

#include <algorithm>
#include <cassert>
#include <flatbuffers/flexbuffers.h>
#include <iostream>
#include <ranges>
#include <vector>

namespace flatmemory
{
/**
 * ID class for non-trivial tuple type.
 */
template<IsTrivialFlexbufferOrNonTrivialType... Ts>
struct Tuple2 : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Tuple2(const Tuple2& other) {}
};

template<IsTrivialFlexbufferOrNonTrivialType... Ts>
class Builder<Tuple2<Ts...>> : public IBuilder<Builder<Tuple2<Ts...>>>
{
private:
    template<typename T>
    class TupleEntry
    {
        static_assert(std::false_type::value, "No suitable overload found for TupleEntry<T>.");
    };

    template<IsTrivialFlexbufferType T>
    class TupleEntry<T>
    {
    public:
        void finish(flexbuffers::Builder& out) { serialize_scalar_value(m_value, out); }

        T& get() { return m_value; }
        const T& get() const { return m_value; }

    private:
        T m_value;
    };

    template<IsNonTrivialType T>
    class TupleEntry<T>
    {
    public:
        void finish(flexbuffers::Builder& out) { m_builder.finish(out); }

        Builder<T>& get() { return m_builder; }
        const Builder<T>& get() const { return m_builder; }

    private:
        Builder<T> m_builder;
    };

public:
    /**
     * Type declarations
     */

    using ValueTypes = std::tuple<Ts...>;

    /**
     * Constructors
     */

    Builder(Ts&&... args);
    Builder();

    void finish()
    {
        m_fbb.Clear();
        finish(m_fbb);
        m_fbb.Finish();
    }
    void finish(flexbuffers::Builder& out)
    {
        out.Vector([&]() { std::apply([this, &out](const auto&... entry) { (..., entry.finish(out)); }, m_data); });
    }

    const std::vector<uint8_t>& get_buffer() const { return m_fbb.GetBuffer(); }

    template<size_t I>
    auto& get()
    {
        static_assert(I < sizeof...(Ts));
        return std::get<I>(m_data).get();
    }

    template<size_t I>
    const auto& get() const
    {
        static_assert(I < sizeof...(Ts));
        return std::get<I>(m_data).get();
    }

private:
    // nested elements
    std::tuple<TupleEntry<Ts>...> m_data;

    // buffer
    flexbuffers::Builder m_fbb;
};

/**
 * View
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
class View<Tuple2<Ts...>>
{
public:
    using ValueTypes = std::tuple<Ts...>;
    template<size_t I>
    using ElementType = std::tuple_element_t<I, std::tuple<Ts...>>;

    template<size_t I>
    decltype(auto) get()
    {
        static_assert(I < sizeof...(Ts));
        if constexpr (IsTrivialFlexbufferType<ElementType<I>>)
        {
            return retrieve_scalar_value<ElementType<I>>(m_reference[I]);
        }
        else
        {
            return View<ElementType<I>>(m_reference[I]);
        }
    }

    template<size_t I>
    decltype(auto) get() const
    {
        static_assert(I < sizeof...(Ts));
        if constexpr (IsTrivialFlexbufferType<ElementType<I>>)
        {
            return retrieve_scalar_value<ElementType<I>>(m_reference[I]);
        }
        else
        {
            return ConstView<ElementType<I>>(m_reference[I]);
        }
    }

private:
    flexbuffers::Vector m_reference;
};

/**
 * ConstView
 */

template<IsTriviallyCopyableOrNonTrivialType... Ts>
class ConstView<Tuple2<Ts...>>
{
public:
    using ValueTypes = std::tuple<Ts...>;
    template<size_t I>
    using ElementType = std::tuple_element_t<I, std::tuple<Ts...>>;

    template<size_t I>
    decltype(auto) get() const
    {
        static_assert(I < sizeof...(Ts));
        if constexpr (IsTrivialFlexbufferType<ElementType<I>>)
        {
            return retrieve_scalar_value<ElementType<I>>(m_reference[I]);
        }
        else
        {
            return ConstView<ElementType<I>>(m_reference[I]);
        }
    }

private:
    flexbuffers::Vector m_reference;
};

}

#endif