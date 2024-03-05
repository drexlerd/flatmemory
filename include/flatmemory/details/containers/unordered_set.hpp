
#ifndef FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_
#define FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_

#include "../byte_buffer_segmented.hpp"
#include "../builder.hpp"
#include "../view.hpp"
#include "../view_const.hpp"
#include "../type_traits.hpp"
#include "../byte_buffer_utils.hpp"

#include <unordered_set>
#include <iostream>


namespace flatmemory {

template<typename T>
struct CustomHash {
    size_t operator()(const T& element) const {
        return element.hash();
    }
};

template<typename T>
struct CustomEqual {
    bool operator()(const T& left_element, const T& right_element) const {
        return left_element == right_element;
    }
};

/**
 * UnorderedSet behaves like std::unordered_set
 * but without the functionality to erase elements
 * since m_storage would keep growing.
*/
template<typename T>
class UnorderedSet
{
private:
    // Persistent storage
    ByteBufferSegmented m_storage;

    // Data to be accessed
    std::unordered_set<ConstView<T>, CustomHash<ConstView<T>>, CustomEqual<ConstView<T>>> m_data;

    using iterator = std::unordered_set<ConstView<T>>::iterator;
    using const_iterator = std::unordered_set<ConstView<T>>::const_iterator;

public:
    explicit UnorderedSet(NumBytes n = 1000000)
        : m_storage(ByteBufferSegmented(n)) { }
    // Move only
    UnorderedSet(const UnorderedSet& other) = delete;
    UnorderedSet& operator=(const UnorderedSet& other) = delete;
    UnorderedSet(UnorderedSet&& other) = default;
    UnorderedSet& operator=(UnorderedSet&& other) = default;


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

    [[nodiscard]] bool empty() const { return m_data.empty(); }

    [[nodiscard]] size_t size() const { return m_data.size(); }


    /**
     * Modifiers
    */

    void clear() {
        m_storage.clear();
        m_data.clear();
    }

    [[nodiscard]] ConstView<T> insert(const Builder<T>& builder) {
        const uint8_t* data = builder.buffer().data();
        size_t amount = builder.buffer().size();
        const uint8_t* new_data = m_storage.write(data, amount);
        auto view = ConstView<T>(new_data);
        auto it = m_data.find(view);
        if (it != m_data.end()) {
            // not unique, mark the storage as free again
            m_storage.undo_last_write();
            return *it;
        }
        auto result = m_data.insert(view);
        return *result.first;
    }


    [[nodiscard]] ConstView<T> insert(const ConstView<T>& view) {
        const uint8_t* data = view.buffer();
        size_t amount = view.buffer_size();
        const uint8_t* new_data = m_storage.write(data, amount);
        auto result_view = ConstView<T>(new_data);
        auto it = m_data.find(result_view);
        if (it != m_data.end()) {
            // not unique, mark the storage as free again
            m_storage.undo_last_write();
            return *it;
        }

        auto result = m_data.insert(result_view);
        return *result.first;
    }


    [[nodiscard]] ConstView<T> insert(const View<T>& view) {
        const uint8_t* data = view.buffer();
        size_t amount = view.buffer_size();
        const uint8_t* new_data = m_storage.write(data, amount);
        auto result_view = ConstView<T>(new_data);
        auto it = m_data.find(result_view);
        if (it != m_data.end()) {
            // not unique, mark the storage as free again
            m_storage.undo_last_write();
            return *it;
        }
        auto result = m_data.insert(result_view);
        return *result.first;
    }


    /**
     * Lookup
    */

    [[nodiscard]] size_t count(ConstView<T> key) const { return m_data.count(key); }

    [[nodiscard]] iterator find(ConstView<T> key) { return m_data.find(key); }
    [[nodiscard]] const_iterator find(ConstView<T> key) const { return m_data.find(key); }

    [[nodiscard]] bool contains(ConstView<T> key) const { return m_data.contains(key); }
};





}


#endif
