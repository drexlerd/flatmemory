
#ifndef FLATMEMORY_CONTAINERS_VECTOR_HPP_
#define FLATMEMORY_CONTAINERS_VECTOR_HPP_

#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer_segmented.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <cassert>
#include <stdexcept>
#include <vector>

namespace flatmemory
{

/**
 * Declarations
 */

/// @brief VariableSizedTypeVector can handle different sized objects
/// but does not support resize since the exact
/// amount of needed bytes is not known in advance.
/// @tparam T
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

    void range_check(size_t pos) const;

public:
    explicit VariableSizedTypeVector(NumBytes n = 1000000);
    // Move only
    VariableSizedTypeVector(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector& operator=(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector(VariableSizedTypeVector&& other) = default;
    VariableSizedTypeVector& operator=(VariableSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    [[nodiscard]] View<T> operator[](size_t pos);
    [[nodiscard]] ConstView<T> operator[](size_t pos) const;

    [[nodiscard]] View<T> at(size_t pos);
    [[nodiscard]] ConstView<T> at(size_t pos) const;

    [[nodiscard]] View<T> back();
    [[nodiscard]] ConstView<T> back() const;

    /**
     * Iterators
     */

    [[nodiscard]] iterator begin();
    [[nodiscard]] const_iterator begin() const;
    [[nodiscard]] iterator end();
    [[nodiscard]] const_iterator end() const;

    /**
     * Capacity
     */

    [[nodiscard]] constexpr size_t empty() const;
    [[nodiscard]] constexpr size_t size() const;

    /**
     * Modifiers
     */

    void push_back(const Builder<T>& builder);
    void push_back(const View<T>& view);
    void push_back(const ConstView<T>& view);
    void clear();
};

/// @brief FixedSizedTypeVector can handle only equally sized objects
/// because it is meant to be resizeable.
/// @tparam T
template<typename T>
class FixedSizedTypeVector
{
private:
    // Persistent storage
    ByteBufferSegmented m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

    Builder<T> m_default_builder;

    using iterator = typename std::vector<View<T>>::iterator;
    using const_iterator = typename std::vector<View<T>>::const_iterator;

    void range_check(size_t pos) const;

public:
    /// @brief Constructor that uses empty default constructed elements when resizing.
    explicit FixedSizedTypeVector(NumBytes n = 1000000);
    /// @brief Constructor that ensure that a resize yields non trivially initialized objects.
    FixedSizedTypeVector(Builder<T>&& default_builder, NumBytes n = 1000000);
    // Move only
    FixedSizedTypeVector(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector& operator=(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector(FixedSizedTypeVector&& other) = default;
    FixedSizedTypeVector& operator=(FixedSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    [[nodiscard]] View<T> operator[](size_t pos);
    [[nodiscard]] ConstView<T> operator[](size_t pos) const;

    [[nodiscard]] View<T> at(size_t pos);
    [[nodiscard]] ConstView<T> at(size_t pos) const;

    [[nodiscard]] View<T> back();
    [[nodiscard]] ConstView<T> back() const;

    /**
     * Iterators
     */

    [[nodiscard]] iterator begin();
    [[nodiscard]] const_iterator begin() const;
    [[nodiscard]] iterator end();
    [[nodiscard]] const_iterator end() const;

    /**
     * Capacity
     */

    [[nodiscard]] constexpr size_t empty() const;
    [[nodiscard]] constexpr size_t size() const;

    /**
     * Modifiers
     */

    void push_back(const Builder<T>& builder);
    void push_back(const View<T>& view);
    void push_back(const ConstView<T>& view);
    void resize(size_t count);
    void clear();
};

/**
 * Definitions
 */

// VariableSizedTypeVector

template<typename T>
VariableSizedTypeVector<T>::VariableSizedTypeVector(NumBytes n) : m_storage(ByteBufferSegmented(n))
{
}

template<typename T>
void VariableSizedTypeVector<T>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("VariableSizedTypeVector::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<typename T>
View<T> VariableSizedTypeVector<T>::operator[](size_t pos)
{
    assert(pos <= size());
    return m_data[pos];
}

template<typename T>
ConstView<T> VariableSizedTypeVector<T>::operator[](size_t pos) const
{
    assert(pos <= size());
    return m_data[pos];
}

template<typename T>
View<T> VariableSizedTypeVector<T>::at(size_t pos)
{
    range_check(pos);
    return m_data[pos];
}

template<typename T>
ConstView<T> VariableSizedTypeVector<T>::at(size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<typename T>
View<T> VariableSizedTypeVector<T>::back()
{
    assert(!m_data.empty());
    return m_data.back();
}

template<typename T>
ConstView<T> VariableSizedTypeVector<T>::back() const
{
    assert(!m_data.empty());
    return m_data.back();
}

template<typename T>
VariableSizedTypeVector<T>::iterator VariableSizedTypeVector<T>::begin()
{
    return m_data.begin();
}

template<typename T>
VariableSizedTypeVector<T>::const_iterator VariableSizedTypeVector<T>::begin() const
{
    return m_data.begin();
}

template<typename T>
VariableSizedTypeVector<T>::iterator VariableSizedTypeVector<T>::end()
{
    return m_data.end();
}

template<typename T>
VariableSizedTypeVector<T>::const_iterator VariableSizedTypeVector<T>::end() const
{
    return m_data.end();
}

template<typename T>
constexpr size_t VariableSizedTypeVector<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
constexpr size_t VariableSizedTypeVector<T>::size() const
{
    return m_data.size();
}

template<typename T>
void VariableSizedTypeVector<T>::push_back(const Builder<T>& builder)
{
    m_data.push_back(View<T>(m_storage.write(builder.buffer().data(), builder.buffer().size())));
}

template<typename T>
void VariableSizedTypeVector<T>::push_back(const View<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size())));
}

template<typename T>
void VariableSizedTypeVector<T>::push_back(const ConstView<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size())));
}

template<typename T>
void VariableSizedTypeVector<T>::clear()
{
    m_data.clear();
    m_storage.clear();
}

// FixedSizedTypeVector

template<typename T>
FixedSizedTypeVector<T>::FixedSizedTypeVector(NumBytes n) : m_storage(ByteBufferSegmented(n))
{  //
    m_default_builder.finish();
}

template<typename T>
FixedSizedTypeVector<T>::FixedSizedTypeVector(Builder<T>&& default_builder, NumBytes n) :
    m_storage(ByteBufferSegmented(n)),
    m_default_builder(std::move(default_builder))
{
    if (m_default_builder.buffer().data() == nullptr)
    {
        throw std::runtime_error("Builder is not fully initialized! Did you forget to call finish()?");
    }
}

template<typename T>
void FixedSizedTypeVector<T>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("FixedSizedTypeVector::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<typename T>
View<T> FixedSizedTypeVector<T>::operator[](size_t pos)
{
    if (pos >= size())
    {
        resize(pos);
    }
    return m_data[pos];
}

template<typename T>
ConstView<T> FixedSizedTypeVector<T>::operator[](size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<typename T>
View<T> FixedSizedTypeVector<T>::at(size_t pos)
{
    if (pos >= size())
    {
        resize(pos);
    }
    return m_data[pos];
}

template<typename T>
ConstView<T> FixedSizedTypeVector<T>::at(size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<typename T>
View<T> FixedSizedTypeVector<T>::back()
{
    return m_data.back();
}

template<typename T>
ConstView<T> FixedSizedTypeVector<T>::back() const
{
    return m_data.back();
}

template<typename T>
FixedSizedTypeVector<T>::iterator FixedSizedTypeVector<T>::begin()
{
    return m_data.begin();
}

template<typename T>
FixedSizedTypeVector<T>::const_iterator FixedSizedTypeVector<T>::begin() const
{
    return m_data.begin();
}

template<typename T>
FixedSizedTypeVector<T>::iterator FixedSizedTypeVector<T>::end()
{
    return m_data.end();
}

template<typename T>
FixedSizedTypeVector<T>::const_iterator FixedSizedTypeVector<T>::end() const
{
    return m_data.end();
}

template<typename T>
constexpr size_t FixedSizedTypeVector<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
constexpr size_t FixedSizedTypeVector<T>::size() const
{
    return m_data.size();
}

template<typename T>
void FixedSizedTypeVector<T>::push_back(const Builder<T>& builder)
{
    m_data.push_back(View<T>(m_storage.write(builder.buffer().data(), builder.buffer().size())));
}

template<typename T>
void FixedSizedTypeVector<T>::push_back(const View<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size())));
}

template<typename T>
void FixedSizedTypeVector<T>::push_back(const ConstView<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.buffer(), view.buffer_size())));
}

template<typename T>
void FixedSizedTypeVector<T>::resize(size_t count)
{
    if (count < size())
    {
        throw std::logic_error("Resize to size smaller than current size is not supported. Use clear instead.");
    }
    const uint8_t* default_data = m_default_builder.buffer().data();
    size_t default_size = m_default_builder.buffer().size();
    while (size() <= count)
    {
        uint8_t* written_data = m_storage.write(default_data, default_size);
        m_data.push_back(View<T>(written_data));
    }
}

template<typename T>
void FixedSizedTypeVector<T>::clear()
{
    m_data.clear();
    m_storage.clear();
}

}

#endif
