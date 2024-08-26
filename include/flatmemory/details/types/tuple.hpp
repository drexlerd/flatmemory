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
#include "flatmemory/details/algorithms/murmurhash3.hpp"
#include "flatmemory/details/flexbuffer_utils.hpp"
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
struct Tuple : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Tuple(const Tuple& other) {}
};

template<IsTrivialFlexbufferOrNonTrivialType... Ts>
class Builder<Tuple<Ts...>> : public IBuilder<Builder<Tuple<Ts...>>>
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
        void finish(flexbuffers::Builder& out) const { serialize_scalar_value(m_value, out); }

        T& get() { return m_value; }
        const T& get() const { return m_value; }

    private:
        T m_value;
    };

    template<IsNonTrivialType T>
    class TupleEntry<T>
    {
    public:
        void finish(flexbuffers::Builder& out) const { m_builder.finish(out); }

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

    Builder(Ts&&... args) : m_data(std::make_tuple(std::forward<Ts>(args)...)), m_fbb() {}
    Builder() : m_data(), m_fbb() {}

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
    void finish_impl()
    {
        m_fbb.Clear();
        this->finish(m_fbb);
        m_fbb.Finish();
    }

    void finish_impl(flexbuffers::Builder& out) const
    {
        // Note that we do not enforce bitwidth in a tuple.
        // Users are encouraged to initialize trivial types
        // to large values to enforce sufficiently large bitwidths for mutability.

        out.Vector([&]() { std::apply([this, &out](const auto&... entry) { (..., entry.finish(out)); }, m_data); });
    }

    const std::vector<uint8_t>& get_buffer_impl() const { return m_fbb.GetBuffer(); }

    friend class IBuilder<Builder<Tuple<Ts...>>>;

private:
    // nested elements
    std::tuple<TupleEntry<Ts>...> m_data;

    // buffer
    flexbuffers::Builder m_fbb;
};

/**
 * View
 */

template<IsTrivialFlexbufferOrNonTrivialType... Ts>
class View<Tuple<Ts...>>
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
            return retrieve_scalar_value<ElementType<I>>(m_data[I]);
        }
        else
        {
            return View<ElementType<I>>(m_data[I]);
        }
    }

    template<size_t I>
    decltype(auto) get() const
    {
        static_assert(I < sizeof...(Ts));
        if constexpr (IsTrivialFlexbufferType<ElementType<I>>)
        {
            return retrieve_scalar_value<ElementType<I>>(m_data[I]);
        }
        else
        {
            return ConstView<ElementType<I>>(m_data[I]);
        }
    }

private:
    flexbuffers::Vector m_data;
};

/**
 * ConstView
 */

template<IsTrivialFlexbufferOrNonTrivialType... Ts>
class ConstView<Tuple<Ts...>>
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