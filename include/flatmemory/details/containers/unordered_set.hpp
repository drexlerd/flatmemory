
#ifndef FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_
#define FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_

#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer_segmented.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/types/tags.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <functional>
#include <unordered_set>

namespace flatmemory
{

/**
 * Declarations
 */

/// @brief UnorderedSet behaves like std::unordered_set
/// but without the functionality to erase elements
/// since m_storage would keep growing.
/// @tparam T
/// @tparam Hash
/// @tparam Equal
template<IsTag T, typename Hash = std::hash<ConstView<T>>, typename Equal = std::equal_to<ConstView<T>>>
class UnorderedSet
{
private:
    // Persistent storage
    ByteBufferSegmented m_storage;

    // Data to be accessed
    std::unordered_set<ConstView<T>, Hash, Equal> m_data;

    using iterator = typename std::unordered_set<ConstView<T>, Hash, Equal>::iterator;
    using const_iterator = typename std::unordered_set<ConstView<T>, Hash, Equal>::const_iterator;

public:
    explicit UnorderedSet(NumBytes initial_num_bytes_per_segment = 1024, NumBytes maximum_num_bytes_per_segment = 1024 * 1024);
    // Move only to avoid invalidating views.
    UnorderedSet(const UnorderedSet& other) = delete;
    UnorderedSet& operator=(const UnorderedSet& other) = delete;
    UnorderedSet(UnorderedSet&& other) = default;
    UnorderedSet& operator=(UnorderedSet&& other) = default;

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

    bool empty() const;
    size_t size() const;

    /**
     * Modifiers
     */

    void clear();

    std::pair<const_iterator, bool> insert(const Builder<T>& builder);
    std::pair<const_iterator, bool> insert(ConstView<T>& view);
    std::pair<const_iterator, bool> insert(View<T>& view);

    /**
     * Lookup
     */

    size_t count(ConstView<T> key) const;
    iterator find(ConstView<T> key);
    const_iterator find(ConstView<T> key) const;
    bool contains(ConstView<T> key) const;

    const ByteBufferSegmented& get_storage() const;
};

/**
 * Definitions
 */

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::UnorderedSet(NumBytes initial_num_bytes_per_segment, NumBytes maximum_num_bytes_per_segment) :
    m_storage(ByteBufferSegmented(initial_num_bytes_per_segment, maximum_num_bytes_per_segment))
{
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::begin()
{
    return m_data.begin();
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::begin() const
{
    return m_data.begin();
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::end()
{
    return m_data.end();
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::end() const
{
    return m_data.end();
}

template<IsTag T, typename Hash, typename Equal>
bool UnorderedSet<T, Hash, Equal>::empty() const
{
    return m_data.empty();
}

template<IsTag T, typename Hash, typename Equal>
size_t UnorderedSet<T, Hash, Equal>::size() const
{
    return m_data.size();
}

template<IsTag T, typename Hash, typename Equal>
void UnorderedSet<T, Hash, Equal>::clear()
{
    m_storage.clear();
    m_data.clear();
}

template<IsTag T, typename Hash, typename Equal>
std::pair<typename UnorderedSet<T, Hash, Equal>::const_iterator, bool> UnorderedSet<T, Hash, Equal>::insert(const Builder<T>& builder)
{
    const uint8_t* data = builder.buffer().data();
    size_t amount = builder.buffer().size();
    const uint8_t* new_data = m_storage.write(data, amount);
    auto view = ConstView<T>(new_data);
    auto it = m_data.find(view);
    if (it != m_data.end())
    {
        // not unique, mark the storage as free again
        m_storage.undo_last_write();
        return std::make_pair(it, false);
    }
    auto result = m_data.insert(view);
    return std::make_pair(result.first, true);
}

template<IsTag T, typename Hash, typename Equal>
std::pair<typename UnorderedSet<T, Hash, Equal>::const_iterator, bool> UnorderedSet<T, Hash, Equal>::insert(ConstView<T>& view)
{
    const uint8_t* data = view.buffer();
    size_t amount = view.buffer_size();
    const uint8_t* new_data = m_storage.write(data, amount);
    auto result_view = ConstView<T>(new_data);
    auto it = m_data.find(result_view);
    if (it != m_data.end())
    {
        // not unique, mark the storage as free again
        m_storage.undo_last_write();
        return std::make_pair(it, false);
    }

    auto result = m_data.insert(result_view);
    return std::make_pair(result.first, true);
}

template<IsTag T, typename Hash, typename Equal>
std::pair<typename UnorderedSet<T, Hash, Equal>::const_iterator, bool> UnorderedSet<T, Hash, Equal>::insert(View<T>& view)
{
    const uint8_t* data = view.buffer();
    size_t amount = view.buffer_size();
    const uint8_t* new_data = m_storage.write(data, amount);
    auto result_view = ConstView<T>(new_data);
    auto it = m_data.find(result_view);
    if (it != m_data.end())
    {
        // not unique, mark the storage as free again
        m_storage.undo_last_write();
        return std::make_pair(it, false);
    }
    auto result = m_data.insert(result_view);
    return std::make_pair(result.first, true);
}

template<IsTag T, typename Hash, typename Equal>
size_t UnorderedSet<T, Hash, Equal>::count(ConstView<T> key) const
{
    return m_data.count(key);
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::find(ConstView<T> key)
{
    return m_data.find(key);
}

template<IsTag T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::find(ConstView<T> key) const
{
    return m_data.find(key);
}

template<IsTag T, typename Hash, typename Equal>
bool UnorderedSet<T, Hash, Equal>::contains(ConstView<T> key) const
{
    return m_data.contains(key);
}

template<IsTag T, typename Hash, typename Equal>
const ByteBufferSegmented& UnorderedSet<T, Hash, Equal>::get_storage() const
{
    return m_storage;
}

}

#endif
