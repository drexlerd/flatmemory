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

#ifndef FLATMEMORY_TYPES_VECTOR_HPP_
#define FLATMEMORY_TYPES_VECTOR_HPP_

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

/// @brief `Vector` is an id class for the non-trivial vector type.
/// @tparam T is the nested element type.
/// @tparam FixedBitwidth defines whether trivial flexbuffer types should be serialized with fixed bitwidth.
template<IsTrivialFlexbufferOrNonTrivialType T, bool FixedBitwidth>
struct Vector : public NonTrivialType
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Vector(const Vector& other) {}
};

template<IsTrivialFlexbufferType T, bool FixedBitwidth>
class Builder<Vector<T, FixedBitwidth>> : public IBuilder<Builder<Vector<T, FixedBitwidth>>>
{
public:
    using ValueType = T;

    using Iterator = std::vector<T>::iterator;
    using ConstIterator = std::vector<T>::const_iterator;

    Builder() : m_data(), m_fbb() {}
    explicit Builder(size_t count) : m_data(count), m_fbb() {}
    Builder(size_t count, const T& value) : m_data(count, value), m_fbb() {}

    /**
     * Element access
     */

    T& operator[](size_t pos) { return m_data[pos]; }
    const T& operator[](size_t pos) const { return m_data[pos]; }
    T& at(size_t pos) { return m_data.at(pos); }
    const T& at(size_t pos) const { return m_data.at(pos); }

    /**
     * Iterators
     */

    Iterator begin() { return m_data.begin(); }
    ConstIterator begin() const { return m_data.begin(); }
    Iterator end() { return m_data.end(); }
    ConstIterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    constexpr bool empty() const { return m_data.empty(); }
    constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */
    void push_back(T&& element) { m_data.push_back(std::forward<T>(element)); }
    void push_back(const T& element) { m_data.push_back(element); }

    void resize(size_t count) { m_data.resize(count); }
    void resize(size_t count, const T& value) { m_data.resize(count, value); }
    void clear() { m_data.clear(); }

private:
    /// @brief Construct the buffer in the builder.
    void finish_impl()
    {
        m_fbb.Clear();
        this->finish(m_fbb);
        m_fbb.Finish();
    }

    /// @brief Construct the buffer in the builder.
    /// @tparam FixedBitwidth defines whether trivial flexbuffer types should be serialized with fixed bitwidth.
    /// @param out is the builder that contains the final buffer.
    void finish_impl(flexbuffers::Builder& out) const
    {
        if constexpr (FixedBitwidth)
        {
            if (!m_data.empty())
            {
                set_minimum_bitwidth(ValueType(), out);
            }
        }

        out.TypedVector(
            [&]()
            {
                for (auto& element : m_data)
                {
                    serialize_scalar_value(element, out);
                }
            });

        if constexpr (FixedBitwidth)
        {
            out.ForceMinimumBitWidth(flexbuffers::BIT_WIDTH_8);
        }
    }

    const std::vector<uint8_t>& get_buffer_impl() const { return m_fbb.GetBuffer(); }

    friend class IBuilder<Builder<Vector<T, FixedBitwidth>>>;

private:
    // nested elements
    std::vector<T> m_data;

    // buffer
    flexbuffers::Builder m_fbb;
};

template<IsNonTrivialType T, bool FixedBitwidth>
class Builder<Vector<T, FixedBitwidth>> : public IBuilder<Builder<Vector<T, FixedBitwidth>>>
{
public:
    using ValueType = T;

    using Iterator = std::vector<Builder<T>>::iterator;
    using ConstIterator = std::vector<Builder<T>>::const_iterator;

    Builder() : m_data(), m_fbb() {}
    explicit Builder(size_t count) : m_data(count), m_fbb() {}
    Builder(size_t count, const Builder<T>& value) : m_data(count, value), m_fbb() {}

    /**
     * Element access
     */

    Builder<T>& operator[](size_t pos) { return m_data[pos]; }
    const Builder<T>& operator[](size_t pos) const { return m_data[pos]; }
    Builder<T>& at(size_t pos) { return m_data.at(pos); }
    const Builder<T>& at(size_t pos) const { return m_data.at(pos); }

    /**
     * Iterators
     */

    Iterator begin() { return m_data.begin(); }
    ConstIterator begin() const { return m_data.begin(); }
    Iterator end() { return m_data.end(); }
    ConstIterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    constexpr bool empty() const { return m_data.empty(); }
    constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */
    void push_back(Builder<T>&& element) { m_data.push_back(std::forward<Builder<T>>(element)); }
    void push_back(const Builder<T>& element) { m_data.push_back(element); }

    void resize(size_t count) { m_data.resize(count); }
    void resize(size_t count, const Builder<T>& value) { m_data.resize(count, value); }
    void clear() { m_data.clear(); }

private:
    void finish_impl()
    {
        m_fbb.Clear();
        this->finish(m_fbb);
        m_fbb.Finish();
    }

    void finish_impl(flexbuffers::Builder& out) const
    {
        out.Vector(
            [&]()
            {
                for (auto& element : m_data)
                {
                    element.finish(out);
                }
            });
    }

    const std::vector<uint8_t>& get_buffer_impl() const { return m_fbb.GetBuffer(); }

    friend class IBuilder<Builder<Vector<T, FixedBitwidth>>>;

private:
    // nested elements
    std::vector<Builder<T>> m_data;

    // buffer
    flexbuffers::Builder m_fbb;
};

/**
 * View
 */

template<IsTrivialFlexbufferType T, bool FixedBitwidth>
class View<Vector<T, FixedBitwidth>>
{
private:
    flexbuffers::Vector m_data;

public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    View(const uint8_t* buffer, size_t size) : View(flexbuffers::GetRoot(buffer, size)) {}
    View(flexbuffers::Reference reference) : m_data(reference.AsTypedVector()) {}

    /**
     * Element access
     */

    auto operator[](size_t pos) const { return retrieve_scalar_value<T>(m_data[pos]); }

    void mutate_scalar_value(size_t pos, T value)
        requires(FixedBitwidth == true)
    {
        bool success = flatmemory::mutate_scalar_value(m_data[pos], value);

        if (!success)
        {
            throw std::logic_error("View<Vector<T>>::mutate_scalar_value: error mutating data.");
        }
    }

    size_t size() const { return m_data.size(); }
};

template<IsNonTrivialType T, bool FixedBitwidth>
class View<Vector<T, FixedBitwidth>>
{
private:
    flexbuffers::Vector m_data;

public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    View(const uint8_t* buffer, size_t size) : View(flexbuffers::GetRoot(buffer, size)) {}
    View(flexbuffers::Reference reference) : m_data(reference.AsVector()) {}

    /**
     * Element access
     */

    View<T> operator[](size_t pos) const { return View<T>(m_data[pos]); }

    size_t size() const { return m_data.size(); }
};

/**
 * ConstView
 */
template<IsTrivialFlexbufferType T, bool FixedBitwidth>
class ConstView<Vector<T, FixedBitwidth>>
{
private:
    flexbuffers::Vector m_data;

public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buffer, size_t size) : ConstView(flexbuffers::GetRoot(buffer, size)) {}
    ConstView(flexbuffers::Reference reference) : m_data(reference.AsTypedVector()) {}

    /**
     * Element access
     */

    auto operator[](size_t pos) const { return retrieve_scalar_value<T>(m_data[pos]); }

    size_t size() const { return m_data.size(); }
};

template<IsNonTrivialType T, bool FixedBitwidth>
class ConstView<Vector<T, FixedBitwidth>>
{
private:
    flexbuffers::Vector m_data;

public:
    /**
     * Type declarations
     */

    using ValueType = T;

    /**
     * Constructors
     */

    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buffer, size_t size) : ConstView(flexbuffers::GetRoot(buffer, size)) {}
    ConstView(flexbuffers::Reference reference) : m_data(reference.AsVector()) {}

    /**
     * Element access
     */

    ConstView<T> operator[](size_t pos) const { return ConstView<T>(m_data[pos]); }

    size_t size() const { return m_data.size(); }
};
}

#endif