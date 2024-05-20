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
#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer.hpp"
#include "flatmemory/details/byte_buffer_utils.hpp"
#include "flatmemory/details/layout.hpp"
#include "flatmemory/details/layout_utils.hpp"
#include "flatmemory/details/operator.hpp"
#include "flatmemory/details/type_traits.hpp"
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
 * Dispatcher for Vector.
 */
template<IsTriviallyCopyableOrCustom T>
struct Vector : public Custom
{
    /// @brief Non-trivial copy-constructor
    /// @param other
    Vector(const Vector& other) {}
};

/**
 * Data types
 */
using vector_size_type = uint32_t;

/**
 * Layout
 */
template<IsTriviallyCopyableOrCustom T>
class Layout<Vector<T>>
{
public:
    static constexpr size_t final_alignment = calculate_final_alignment<buffer_size_type, offset_type, vector_size_type, T>();

    static constexpr size_t buffer_size_position = 0;
    static constexpr size_t buffer_size_end = buffer_size_position + sizeof(buffer_size_type);
    static constexpr size_t buffer_size_padding = calculate_amount_padding(buffer_size_end, calculate_header_alignment<vector_size_type>());
    static constexpr size_t vector_size_position = buffer_size_end + buffer_size_padding;
    static constexpr size_t vector_size_end = vector_size_position + sizeof(vector_size_type);
    static constexpr size_t vector_size_padding = calculate_amount_padding(vector_size_end, calculate_data_alignment<T>());
    static constexpr size_t vector_data_position = vector_size_end + vector_size_padding;

    void print() const
    {
        std::cout << "buffer_size_position: " << buffer_size_position << "\n"
                  << "buffer_size_end: " << buffer_size_end << "\n"
                  << "buffer_size_padding: " << buffer_size_padding << "\n"
                  << "vector_size_position: " << vector_size_position << "\n"
                  << "vector_size_end: " << vector_size_end << "\n"
                  << "vector_data_position: " << vector_data_position << "\n"
                  << "vector_size_padding: " << vector_size_padding << "\n"
                  << "final_alignment: " << final_alignment << std::endl;
    }
};

/**
 * Forward declarations
 */
template<IsTriviallyCopyableOrCustom T>
class View<Vector<T>>;

template<IsTriviallyCopyableOrCustom T>
class ConstView<Vector<T>>;

template<IsTriviallyCopyableOrCustom T>
class Builder<Vector<T>>;

/**
 * Operator
 */
template<IsTriviallyCopyableOrCustom T>
class Operator<Vector<T>>
{
private:
public:
};

/**
 * Builder
 */
template<IsTriviallyCopyableOrCustom T>
class Builder<Vector<T>> : public IBuilder<Builder<Vector<T>>>
{
private:
    using T_ = typename maybe_builder<T>::type;

    using iterator = typename std::vector<T_>::iterator;
    using const_iterator = typename std::vector<T_>::const_iterator;

    std::vector<T_> m_data;
    ByteBuffer m_buffer;

    /* Implement IBuilder interface. */
    template<typename>
    friend class IBuilder;

    void finish_impl()
    {
        /* Write header info */
        // Write vector size
        m_buffer.write(Layout<Vector<T>>::vector_size_position, m_data.size());
        m_buffer.write_padding(Layout<Vector<T>>::vector_size_end, Layout<Vector<T>>::vector_size_padding);

        /* Write dynamic info */
        offset_type buffer_size = Layout<Vector<T>>::vector_data_position;
        // Write vector data
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            /* For trivial type we can write the data without additional padding. */
            buffer_size += m_buffer.write(buffer_size, reinterpret_cast<const uint8_t*>(m_data.data()), sizeof(T_) * m_data.size());
        }
        else
        {
            /* For non-trivial type T, we store the offsets first */
            // position of offset
            offset_type offset_pos = Layout<Vector<T>>::vector_data_position;
            size_t offset_end = offset_pos + m_data.size() * sizeof(offset_type);
            size_t offset_padding = calculate_amount_padding(offset_end, Layout<T>::final_alignment);
            m_buffer.write_padding(offset_end, offset_padding);
            // We have to add padding to ensure that the data is correctly aligned
            buffer_size = offset_end + offset_padding;
            for (size_t i = 0; i < m_data.size(); ++i)
            {
                // write distance between written data position and offset position
                offset_type x = buffer_size - offset_pos;
                offset_pos += m_buffer.write(offset_pos, x);

                // write data
                auto& nested_builder = m_data[i];
                nested_builder.finish();
                buffer_size_type nested_buffer_size = nested_builder.buffer().size();
                m_buffer.write(buffer_size, nested_builder.buffer().data(), nested_buffer_size);
                buffer_size += nested_buffer_size;
                buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, Layout<Vector<T>>::final_alignment));
            }
        }
        // Write final padding to satisfy alignment requirements
        buffer_size += m_buffer.write_padding(buffer_size, calculate_amount_padding(buffer_size, Layout<Vector<T>>::final_alignment));

        /* Write buffer size */
        m_buffer.write(Layout<Vector<T>>::buffer_size_position, static_cast<buffer_size_type>(buffer_size));
        m_buffer.set_size(buffer_size);
    }

    [[nodiscard]] auto& get_buffer_impl() { return m_buffer; }
    [[nodiscard]] const auto& get_buffer_impl() const { return m_buffer; }

public:
    Builder() {}
    explicit Builder(size_t count) : m_data(count) {}
    explicit Builder(size_t count, const T_& value) : m_data(count, value) {}

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
     * Element access
     */
    [[nodiscard]] T_& operator[](size_t pos)
    {
        assert(pos < size());
        return m_data[pos];
    }

    [[nodiscard]] const T_& operator[](size_t pos) const
    {
        assert(pos < size());
        return m_data[pos];
    }

    [[nodiscard]] size_t hash() const
    {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            return hash_combine(hash_iteration(m_data.begin(), m_data.end()));
        }
        else
        {
            size_t seed = size();
            for (auto iter = m_data.begin(); iter < m_data.end(); ++iter)
            {
                seed = hash_combine(seed, iter->hash());
            }
            return seed;
        }
    }

    [[nodiscard]] T_* data() { return m_data.data(); }
    [[nodiscard]] const T_* data() const { return m_data.data(); }

    /**
     * Iterators
     */

    iterator begin() { return m_data.begin(); }
    const_iterator begin() const { return m_data.begin(); }
    iterator end() { return m_data.end(); }
    const_iterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    [[nodiscard]] constexpr bool empty() const { return m_data.empty(); }

    [[nodiscard]] constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */
    void push_back(T_&& element) { m_data.push_back(std::move(element)); }
    void push_back(const T_& element) { m_data.push_back(element); }

    /// @brief
    ///
    /// Resizing a vector of views needs additional caution
    /// since the default constructed views are not meaningful.
    /// @param count
    void resize(size_t count) { m_data.resize(count, T_()); }
    void resize(size_t count, const T_& value) { m_data.resize(count, value); }

    void clear() { m_data.clear(); }
};

/**
 * View
 */
template<IsTriviallyCopyableOrCustom T>
class View<Vector<T>>
{
private:
    using T_ = typename maybe_builder<T>::type;

    uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    View() = default;

    template<typename>
    friend class Builder;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder.
    /// @param buf
    View(uint8_t* buf) : m_buf(buf) { assert(buf); }

    /**
     * Operators
     */

    [[nodiscard]] bool operator==(const View& other) const
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

    [[nodiscard]] bool operator!=(const View& other) const { return !(*this == other); }

    /**
     * Element access.
     */

    [[nodiscard]] decltype(auto) operator[](size_t pos)
    {
        assert(m_buf);
        assert(pos < size());
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
            return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
        }
        else
        {
            const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
            return View<T>(offset_pos + read_value<offset_type>(offset_pos));
        }
    }

    [[nodiscard]] decltype(auto) operator[](size_t pos) const
    {
        assert(m_buf);
        assert(pos < size());
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
            return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
        }
        else
        {
            const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
            return View<T>(offset_pos + read_value<offset_type>(offset_pos));
        }
    }

    [[nodiscard]] size_t hash() const
    {
        size_t seed = size();
        int64_t hash[2];
        MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }

    [[nodiscard]] T_* data() { return reinterpret_cast<T_*>(m_buf + Layout<Vector<T>>::vector_data_position); }
    [[nodiscard]] const T_* data() const { return reinterpret_cast<const T_*>(m_buf + Layout<Vector<T>>::vector_data_position); }

    [[nodiscard]] uint8_t* buffer() { return m_buf; }
    [[nodiscard]] const uint8_t* buffer() const { return m_buf; }

    /**
     * Iterators
     */

    class iterator
    {
    private:
        uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_view<T>::type;
        using pointer = typename maybe_view<T>::type*;
        using reference = typename maybe_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        iterator() : m_buf(nullptr) {}
        iterator(uint8_t* buf) : m_buf(buf) {}

        [[nodiscard]] decltype(auto) operator*() const
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                assert(test_correct_alignment<T>(m_buf));
                return read_value<T>(m_buf);
            }
            else
            {
                return View<T>(m_buf + read_value<offset_type>(m_buf));
            }
        }

        iterator& operator++()
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                m_buf += sizeof(T);
            }
            else
            {
                m_buf += sizeof(offset_type);
            }
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        [[nodiscard]] bool operator==(const iterator& other) const { return m_buf == other.m_buf; }

        [[nodiscard]] bool operator!=(const iterator& other) const { return !(*this == other); }
    };

    [[nodiscard]] iterator begin()
    {
        assert(m_buf);
        return iterator(m_buf + Layout<Vector<T>>::vector_data_position);
    }

    [[nodiscard]] iterator end()
    {
        assert(m_buf);
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            return iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
        }
        else
        {
            return iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
        }
    }

    class const_iterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = typename maybe_const_view<T>::type*;
        using reference = typename maybe_const_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        const_iterator() : m_buf(nullptr) {}
        const_iterator(const uint8_t* buf) : m_buf(buf) {}

        [[nodiscard]] decltype(auto) operator*() const
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                assert(test_correct_alignment<T>(m_buf));
                return read_value<T>(m_buf);
            }
            else
            {
                return View<T>(m_buf + read_value<offset_type>(m_buf));
            }
        }

        const_iterator& operator++()
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                m_buf += sizeof(T);
            }
            else
            {
                m_buf += sizeof(offset_type);
            }
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        [[nodiscard]] bool operator==(const const_iterator& other) const { return m_buf == other.m_buf; }

        [[nodiscard]] bool operator!=(const const_iterator& other) const { return !(*this == other); }
    };

    [[nodiscard]] const_iterator begin() const
    {
        assert(m_buf);
        return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
    }

    [[nodiscard]] const_iterator end() const
    {
        assert(m_buf);
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
        }
        else
        {
            return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
        }
    }

    /**
     * Capacity
     */

    /// @brief
    ///
    /// Notes: This operation is more costly than std::vector empty() because it is not constexpr.
    /// @return
    [[nodiscard]] bool empty() const { return size() == 0; }

    [[nodiscard]] size_t buffer_size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
        return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
    }

    /// @brief
    ///
    /// Notes: This operation is more costly than std::vector size() because it is not constexpr.
    /// @return
    [[nodiscard]] size_t size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
        return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
    }

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */
};

/**
 * ConstView
 */
template<IsTriviallyCopyableOrCustom T>
class ConstView<Vector<T>>
{
private:
    using T_ = typename maybe_builder<T>::type;

    const uint8_t* m_buf;

    /// @brief Default constructor to make view a trivial data type and serializable
    ConstView() = default;

    template<typename>
    friend class Builder;

public:
    /// @brief Constructor to interpret raw data created by its corresponding builder
    ConstView(const uint8_t* buf) : m_buf(buf) { assert(buf); }

    /**
     * Conversion constructor
     */
    ConstView(const View<Vector<T>>& view) : m_buf(view.buffer()) {}

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
     * Element access
     */

    [[nodiscard]] decltype(auto) operator[](size_t pos) const
    {
        assert(m_buf);
        assert(pos < size());
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            assert(test_correct_alignment<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T)));
            return read_value<T>(m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(T));
        }
        else
        {
            const auto offset_pos = m_buf + Layout<Vector<T>>::vector_data_position + pos * sizeof(offset_type);
            return ConstView<T>(offset_pos + read_value<offset_type>(offset_pos));
        }
    }

    [[nodiscard]] size_t hash() const
    {
        size_t seed = size();
        int64_t hash[2];
        MurmurHash3_x64_128(m_buf, buffer_size(), seed, hash);
        return static_cast<std::size_t>(hash[0] + 0x9e3779b9 + (hash[1] << 6) + (hash[1] >> 2));
    }

    [[nodiscard]] const T_* data() const { return reinterpret_cast<const T_*>(m_buf + Layout<Vector<T>>::vector_data_position); }

    [[nodiscard]] const uint8_t* buffer() const { return m_buf; }

    /**
     * Iterators
     */

    class const_iterator
    {
    private:
        const uint8_t* m_buf;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename maybe_const_view<T>::type;
        using pointer = typename maybe_const_view<T>::type*;
        using reference = typename maybe_const_view<T>::type&;
        using iterator_category = std::forward_iterator_tag;

        const_iterator() : m_buf(nullptr) {}
        const_iterator(const uint8_t* buf) : m_buf(buf) {}

        [[nodiscard]] decltype(auto) operator*() const
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                assert(test_correct_alignment<T>(m_buf));
                return read_value<T>(m_buf);
            }
            else
            {
                return ConstView<T>(m_buf + read_value<offset_type>(m_buf));
            }
        }

        const_iterator& operator++()
        {
            constexpr bool is_trivial = IsTriviallyCopyable<T>;
            if constexpr (is_trivial)
            {
                m_buf += sizeof(T);
            }
            else
            {
                m_buf += sizeof(offset_type);
            }
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        [[nodiscard]] bool operator==(const const_iterator& other) const { return m_buf == other.m_buf; }

        [[nodiscard]] bool operator!=(const const_iterator& other) const { return !(*this == other); }
    };

    [[nodiscard]] const_iterator begin() const
    {
        assert(m_buf);
        return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position);
    }

    [[nodiscard]] const_iterator end() const
    {
        assert(m_buf);
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial)
        {
            return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(T) * size());
        }
        else
        {
            return const_iterator(m_buf + Layout<Vector<T>>::vector_data_position + sizeof(offset_type) * size());
        }
    }

    /**
     * Capacity
     */

    /// @brief
    ///
    /// Note: This operation is more costly than std::vector empty() because it is not constexpr.
    /// @return
    [[nodiscard]] bool empty() const { return size() == 0; }

    [[nodiscard]] size_t buffer_size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position));
        return read_value<buffer_size_type>(m_buf + Layout<Vector<T>>::buffer_size_position);
    }

    /// @brief
    ///
    /// Note: This operation is more costly than std::vector size() because it is not constexpr.
    /// @return
    [[nodiscard]] size_t size() const
    {
        assert(m_buf);
        assert(test_correct_alignment<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position));
        return read_value<vector_size_type>(m_buf + Layout<Vector<T>>::vector_size_position);
    }

    /**
     * Modifiers
     *
     * Views cannot be modified!
     */
};

/**
 * Static assertions
 */

static_assert(std::ranges::forward_range<Builder<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<View<Vector<uint64_t>>>);
static_assert(std::ranges::forward_range<ConstView<Vector<uint64_t>>>);
}

#endif
