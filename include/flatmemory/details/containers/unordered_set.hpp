
#ifndef FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_
#define FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_

#include "../byte_stream_segmented.hpp"
#include "../builder.hpp"
#include "../view_const.hpp"
#include "../type_traits.hpp"

#include <unordered_set>


namespace flatmemory {

/**
 * UnorderedSet behaves like std::unordered_set
 * but without the functionality to erase elements
 * since m_storage would keep growing.
*/
template<typename T, typename Hash = std::hash<ConstView<T>>, typename Equal = std::equal_to<ConstView<T>>, typename Allocator = std::allocator<ConstView<T>>>
class UnorderedSet
{
private:
    // Persistent storage
    ByteStreamSegmented m_storage;

    // Data to be accessed
    std::unordered_set<ConstView<T>, Hash, Equal, Allocator> m_data;

public:
    explicit UnorderedSet(NumBytes n = 1000000) 
        : m_storage(ByteStreamSegmented(n)) { }
    // Move only
    UnorderedSet(const UnorderedSet& other) = delete;
    UnorderedSet& operator=(const UnorderedSet& other) = delete;
    UnorderedSet(UnorderedSet&& other) = default;
    UnorderedSet& operator=(UnorderedSet&& other) = default;


    /**
     * Iterators
    */

    [[nodiscard]] decltype(auto) begin() { return m_data.begin(); }
    [[nodiscard]] decltype(auto) begin() const { return m_data.begin(); }
    [[nodiscard]] decltype(auto) end() { return m_data.end(); }
    [[nodiscard]] decltype(auto) end() const { return m_data.end(); }


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
        const uint8_t* data = builder.get_data();
        size_t amount = builder.size();
        uint8_t* new_data = m_storage.write(data, amount);
        auto view = View<T>(new_data);
        auto it = m_data.find(view);
        if (it != m_data.end()) {
            // not unique, mark the storage as free again
            m_storage.undo_last_write();
            return *it;
        }
        auto result = m_data.insert(view);
        return *result.first;
    }


    /**
     * Lookup
    */
   
    [[nodiscard]] size_t count(ConstView<T> key) const { return m_data.count(key); }

    [[nodiscard]] decltype(auto) find(ConstView<T> key) { return m_data.find(key); }
    [[nodiscard]] decltype(auto) find(ConstView<T> key) const { return m_data.find(key); }

    [[nodiscard]] bool contains(ConstView<T> key) const { return m_data.contains(key); }
};





}


#endif
