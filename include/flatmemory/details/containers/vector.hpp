
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
template<IsTriviallyCopyableOrNonTrivialType T>
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
    explicit VariableSizedTypeVector(NumBytes initial_num_bytes_per_segment = 1024, NumBytes maximum_num_bytes_per_segment = 1024 * 1024);
    // Move only to avoid invalidating views.
    VariableSizedTypeVector(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector& operator=(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector(VariableSizedTypeVector&& other) = default;
    VariableSizedTypeVector& operator=(VariableSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    View<T> operator[](size_t pos);
    ConstView<T> operator[](size_t pos) const;

    View<T> at(size_t pos);
    ConstView<T> at(size_t pos) const;

    View<T> back();
    ConstView<T> back() const;

    const ByteBufferSegmented& get_storage() const;

    /**
     * Iterators
     */

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    /**
     * Capacity
     */

    constexpr size_t empty() const;
    constexpr size_t size() const;

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
template<IsTriviallyCopyableOrNonTrivialType T>
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
    explicit FixedSizedTypeVector(NumBytes initial_num_bytes_per_segment = 1024, NumBytes maximum_num_bytes_per_segment = 1024 * 1024);
    /// @brief Constructor that ensure that a resize yields non trivially initialized objects.
    FixedSizedTypeVector(Builder<T> default_builder, NumBytes initial_num_bytes_per_segment = 1024, NumBytes maximum_num_bytes_per_segment = 1024 * 1024);
    // Move only to avoid invalidating views.
    FixedSizedTypeVector(const FixedSizedTypeVector& other) = default;
    FixedSizedTypeVector& operator=(const FixedSizedTypeVector& other) = default;
    FixedSizedTypeVector(FixedSizedTypeVector&& other) = default;
    FixedSizedTypeVector& operator=(FixedSizedTypeVector&& other) = default;

    /**
     * Element access
     */

    View<T> operator[](size_t pos);
    ConstView<T> operator[](size_t pos) const;

    View<T> at(size_t pos);
    ConstView<T> at(size_t pos) const;

    View<T> back();
    ConstView<T> back() const;

    const ByteBufferSegmented& get_storage() const;

    /**
     * Iterators
     */

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    /**
     * Capacity
     */

    constexpr size_t empty() const;
    constexpr size_t size() const;

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

template<IsTriviallyCopyableOrNonTrivialType T>
VariableSizedTypeVector<T>::VariableSizedTypeVector(NumBytes initial_num_bytes_per_segment, NumBytes maximum_num_bytes_per_segment) :
    m_storage(ByteBufferSegmented(initial_num_bytes_per_segment, maximum_num_bytes_per_segment))
{
}

template<IsTriviallyCopyableOrNonTrivialType T>
void VariableSizedTypeVector<T>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("VariableSizedTypeVector::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> VariableSizedTypeVector<T>::operator[](size_t pos)
{
    assert(pos <= size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> VariableSizedTypeVector<T>::operator[](size_t pos) const
{
    assert(pos <= size());
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> VariableSizedTypeVector<T>::at(size_t pos)
{
    range_check(pos);
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> VariableSizedTypeVector<T>::at(size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> VariableSizedTypeVector<T>::back()
{
    assert(!m_data.empty());
    return m_data.back();
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> VariableSizedTypeVector<T>::back() const
{
    assert(!m_data.empty());
    return m_data.back();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const ByteBufferSegmented& VariableSizedTypeVector<T>::get_storage() const
{
    return m_storage;
}

template<IsTriviallyCopyableOrNonTrivialType T>
VariableSizedTypeVector<T>::iterator VariableSizedTypeVector<T>::begin()
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
VariableSizedTypeVector<T>::const_iterator VariableSizedTypeVector<T>::begin() const
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
VariableSizedTypeVector<T>::iterator VariableSizedTypeVector<T>::end()
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
VariableSizedTypeVector<T>::const_iterator VariableSizedTypeVector<T>::end() const
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr size_t VariableSizedTypeVector<T>::empty() const
{
    return m_data.empty();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr size_t VariableSizedTypeVector<T>::size() const
{
    return m_data.size();
}

template<IsTriviallyCopyableOrNonTrivialType T>
void VariableSizedTypeVector<T>::push_back(const Builder<T>& builder)
{
    m_data.push_back(View<T>(m_storage.write(builder.get_buffer().data(), builder.get_buffer().size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void VariableSizedTypeVector<T>::push_back(const View<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.get_buffer(), view.get_buffer_size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void VariableSizedTypeVector<T>::push_back(const ConstView<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.get_buffer(), view.get_buffer_size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void VariableSizedTypeVector<T>::clear()
{
    m_data.clear();
    m_storage.clear();
}

// FixedSizedTypeVector

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::FixedSizedTypeVector(NumBytes initial_num_bytes_per_segment, NumBytes maximum_num_bytes_per_segment) :
    m_storage(ByteBufferSegmented(initial_num_bytes_per_segment, maximum_num_bytes_per_segment))
{  //
    m_default_builder.finish();
}

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::FixedSizedTypeVector(Builder<T> default_builder, NumBytes initial_num_bytes_per_segment, NumBytes maximum_num_bytes_per_segment) :
    m_storage(ByteBufferSegmented(initial_num_bytes_per_segment, maximum_num_bytes_per_segment)),
    m_default_builder(std::move(default_builder))
{
    if (m_default_builder.get_buffer().data() == nullptr)
    {
        throw std::runtime_error("Builder is not fully initialized! Did you forget to call finish()?");
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::range_check(size_t pos) const
{
    if (pos >= size())
    {
        throw std::out_of_range("FixedSizedTypeVector::range_check: pos (which is " + std::to_string(pos) + ") >= this->size() (which is "
                                + std::to_string(size()) + ")");
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> FixedSizedTypeVector<T>::operator[](size_t pos)
{
    if (pos >= size())
    {
        resize(pos);
    }
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> FixedSizedTypeVector<T>::operator[](size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> FixedSizedTypeVector<T>::at(size_t pos)
{
    if (pos >= size())
    {
        resize(pos);
    }
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> FixedSizedTypeVector<T>::at(size_t pos) const
{
    range_check(pos);
    return m_data[pos];
}

template<IsTriviallyCopyableOrNonTrivialType T>
View<T> FixedSizedTypeVector<T>::back()
{
    return m_data.back();
}

template<IsTriviallyCopyableOrNonTrivialType T>
ConstView<T> FixedSizedTypeVector<T>::back() const
{
    return m_data.back();
}

template<IsTriviallyCopyableOrNonTrivialType T>
const ByteBufferSegmented& FixedSizedTypeVector<T>::get_storage() const
{
    return m_storage;
}

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::iterator FixedSizedTypeVector<T>::begin()
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::const_iterator FixedSizedTypeVector<T>::begin() const
{
    return m_data.begin();
}

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::iterator FixedSizedTypeVector<T>::end()
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
FixedSizedTypeVector<T>::const_iterator FixedSizedTypeVector<T>::end() const
{
    return m_data.end();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr size_t FixedSizedTypeVector<T>::empty() const
{
    return m_data.empty();
}

template<IsTriviallyCopyableOrNonTrivialType T>
constexpr size_t FixedSizedTypeVector<T>::size() const
{
    return m_data.size();
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::push_back(const Builder<T>& builder)
{
    m_data.push_back(View<T>(m_storage.write(builder.get_buffer().data(), builder.get_buffer().size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::push_back(const View<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.get_buffer(), view.get_buffer_size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::push_back(const ConstView<T>& view)
{
    m_data.push_back(View<T>(m_storage.write(view.get_buffer(), view.get_buffer_size())));
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::resize(size_t count)
{
    if (count < size())
    {
        throw std::logic_error("Resize to size smaller than current size is not supported. Use clear instead.");
    }
    const uint8_t* default_data = m_default_builder.get_buffer().data();
    size_t default_size = m_default_builder.get_buffer().size();
    while (size() <= count)
    {
        uint8_t* written_data = m_storage.write(default_data, default_size);
        m_data.push_back(View<T>(written_data));
    }
}

template<IsTriviallyCopyableOrNonTrivialType T>
void FixedSizedTypeVector<T>::clear()
{
    m_data.clear();
    m_storage.clear();
}

}

#endif
