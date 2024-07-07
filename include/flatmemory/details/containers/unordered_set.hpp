
#ifndef FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_
#define FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_

#include "flatmemory/details/builder.hpp"
#include "flatmemory/details/byte_buffer_segmented.hpp"
#include "flatmemory/details/concepts.hpp"
#include "flatmemory/details/view.hpp"
#include "flatmemory/details/view_const.hpp"

#include <unordered_set>

namespace flatmemory
{

template<typename T>
struct CustomHash
{
    size_t operator()(const ConstView<T>& element) const { return element.hash(); }
};

template<typename T>
struct CustomEqual
{
    bool operator()(const ConstView<T>& left_element, const ConstView<T>& right_element) const { return left_element == right_element; }
};

/**
 * Declarations
 */

/// @brief UnorderedSet behaves like std::unordered_set
/// but without the functionality to erase elements
/// since m_storage would keep growing.
/// @tparam T
/// @tparam Hash
/// @tparam Equal
template<typename T, typename Hash = CustomHash<T>, typename Equal = CustomEqual<T>>
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
    explicit UnorderedSet(NumBytes n = 1000000);
    // Move only to avoid invalidating views.
    UnorderedSet(const UnorderedSet& other) = delete;
    UnorderedSet& operator=(const UnorderedSet& other) = delete;
    UnorderedSet(UnorderedSet&& other) = default;
    UnorderedSet& operator=(UnorderedSet&& other) = default;

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

    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;

    /**
     * Modifiers
     */

    void clear();

    [[nodiscard]] std::pair<const_iterator, bool> insert(const Builder<T>& builder);
    [[nodiscard]] std::pair<const_iterator, bool> insert(ConstView<T>& view);
    [[nodiscard]] std::pair<const_iterator, bool> insert(View<T>& view);

    /**
     * Lookup
     */

    [[nodiscard]] size_t count(ConstView<T> key) const;
    [[nodiscard]] iterator find(ConstView<T> key);
    [[nodiscard]] const_iterator find(ConstView<T> key) const;
    [[nodiscard]] bool contains(ConstView<T> key) const;

    [[nodiscard]] const ByteBufferSegmented& get_storage() const;
};

/**
 * Definitions
 */

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::UnorderedSet(NumBytes n) : m_storage(ByteBufferSegmented(n))
{
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::begin()
{
    return m_data.begin();
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::begin() const
{
    return m_data.begin();
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::end()
{
    return m_data.end();
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::end() const
{
    return m_data.end();
}

template<typename T, typename Hash, typename Equal>
bool UnorderedSet<T, Hash, Equal>::empty() const
{
    return m_data.empty();
}

template<typename T, typename Hash, typename Equal>
size_t UnorderedSet<T, Hash, Equal>::size() const
{
    return m_data.size();
}

template<typename T, typename Hash, typename Equal>
void UnorderedSet<T, Hash, Equal>::clear()
{
    m_storage.clear();
    m_data.clear();
}

template<typename T, typename Hash, typename Equal>
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

template<typename T, typename Hash, typename Equal>
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

template<typename T, typename Hash, typename Equal>
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

template<typename T, typename Hash, typename Equal>
size_t UnorderedSet<T, Hash, Equal>::count(ConstView<T> key) const
{
    return m_data.count(key);
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::iterator UnorderedSet<T, Hash, Equal>::find(ConstView<T> key)
{
    return m_data.find(key);
}

template<typename T, typename Hash, typename Equal>
UnorderedSet<T, Hash, Equal>::const_iterator UnorderedSet<T, Hash, Equal>::find(ConstView<T> key) const
{
    return m_data.find(key);
}

template<typename T, typename Hash, typename Equal>
bool UnorderedSet<T, Hash, Equal>::contains(ConstView<T> key) const
{
    return m_data.contains(key);
}

template<typename T, typename Hash, typename Equal>
const ByteBufferSegmented& UnorderedSet<T, Hash, Equal>::get_storage() const
{
    return m_storage;
}

}

#endif
