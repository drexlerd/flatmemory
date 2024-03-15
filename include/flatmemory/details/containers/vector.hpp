
#ifndef FLATMEMORY_CONTAINERS_VECTOR_HPP_
#define FLATMEMORY_CONTAINERS_VECTOR_HPP_

#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer_segmented.hpp"
#include "flatmemory/details/type_traits.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <cassert>
#include <stdexcept>
#include <vector>

namespace flatmemory
{

/**
 * VariableSizedTypeVector can handle different sized objects
 * but does not support resize since the exact
 * amount of needed bytes is not known in advance.
 */
template<typename T>
class VariableSizedTypeVector
{
private:
    // Persistent storage
    ByteBufferSegmented m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

    using iterator = typename std::vector<View<T>>::iterator;
    using const_iterator = typename std::vector<View<T>>::const_iterator;

public:
    explicit VariableSizedTypeVector(NumBytes n = 1000000) : m_storage(ByteBufferSegmented(n)) {}
    // Move only
    VariableSizedTypeVector(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector& operator=(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector(VariableSizedTypeVector&& other) = default;
    VariableSizedTypeVector& operator=(VariableSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    [[nodiscard]] View<T> operator[](size_t pos)
    {
        assert(pos <= size());
        return m_data[pos];
    }

    [[nodiscard]] ConstView<T> operator[](size_t pos) const
    {
        assert(pos <= size());
        return m_data[pos];
    }

    [[nodiscard]] View<T> back()
    {
        assert(!m_data.empty());
        return m_data.back();
    }

    [[nodiscard]] ConstView<T> back() const
    {
        assert(!m_data.empty());
        return m_data.back();
    }

    /**
     * Iterators
     */

    [[nodiscard]] iterator begin() { return m_data.begin(); }
    [[nodiscard]] const_iterator begin() const { return m_data.begin(); }
    [[nodiscard]] iterator end() { return m_data.end(); }
    [[nodiscard]] const_iterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    [[nodiscard]] constexpr size_t empty() const { return m_data.empty(); }

    [[nodiscard]] constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */

    void push_back(const Builder<T>& builder) { m_data.push_back(View<T>(m_storage.write(builder.buffer().data(), builder.buffer().size()))); }

    void push_back(const View<T>& view) { m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size()))); }

    void push_back(const ConstView<T>& view) { m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size()))); }
};

/**
 * FixedSizedTypeVector can handle only equally sized objects
 * because it is meant to be resizeable.
 */
template<typename T>
class FixedSizedTypeVector
{
private:
    // Persistent storage
    ByteBufferSegmented m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

    const Builder<T> m_default_builder;

    using iterator = typename std::vector<View<T>>::iterator;
    using const_iterator = typename std::vector<View<T>>::const_iterator;

public:
    FixedSizedTypeVector(Builder<T>&& default_builder, NumBytes n = 1000000) : m_storage(ByteBufferSegmented(n)), m_default_builder(std::move(default_builder))
    {
        if (m_default_builder.buffer().data() == nullptr)
        {
            throw std::runtime_error("Builder is not fully initialized! Did you forget to call finish()?");
        }
    }
    // Move only
    FixedSizedTypeVector(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector& operator=(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector(FixedSizedTypeVector&& other) = default;
    FixedSizedTypeVector& operator=(FixedSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    [[nodiscard]] View<T> operator[](size_t pos)
    {
        if (pos >= size())
        {
            resize(pos);
        }
        return m_data[pos];
    }

    [[nodiscard]] ConstView<T> operator[](size_t pos) const
    {
        if (pos < size())
        {
            return m_data[pos];
        }
        throw std::runtime_error("invalid argument");
    }

    [[nodiscard]] View<T> back() { return m_data.back(); }

    [[nodiscard]] ConstView<T> back() const { return m_data.back(); }

    /**
     * Iterators
     */

    [[nodiscard]] iterator begin() { return m_data.begin(); }
    [[nodiscard]] const_iterator begin() const { return m_data.begin(); }
    [[nodiscard]] iterator end() { return m_data.end(); }
    [[nodiscard]] const_iterator end() const { return m_data.end(); }

    /**
     * Capacity
     */

    [[nodiscard]] constexpr size_t empty() const { return m_data.empty(); }

    [[nodiscard]] constexpr size_t size() const { return m_data.size(); }

    /**
     * Modifiers
     */

    void push_back(const Builder<T>& builder) { m_data.push_back(View<T>(m_storage.write(builder.get_data(), builder.size()))); }

    void push_back(const View<T>& view) { m_data.push_back(View<T>(m_storage.write(view.buffer(), view.get_buffer_size()))); }

    void push_back(const ConstView<T>& view) { m_data.push_back(View<T>(m_storage.write(view.buffer(), view.get_buffer_size()))); }

    void resize(size_t count)
    {
        const uint8_t* default_data = m_default_builder.buffer().data();
        size_t default_size = m_default_builder.buffer().size();
        while (size() <= count)
        {
            uint8_t* written_data = m_storage.write(default_data, default_size);
            m_data.push_back(View<T>(written_data));
        }
    }
};

}

#endif
