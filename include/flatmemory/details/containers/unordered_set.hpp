
#ifndef FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_
#define FLATMEMORY_CONTAINERS_UNORDERED_SET_HPP_

#include "../byte_stream_segmented.hpp"
#include "../builder.hpp"
#include "../view_const.hpp"

#include <unordered_set>


namespace flatmemory {

/**
 * UnorderedSet behaves like std::unordered_set
 * 
 * We use it for states.
*/
template<typename T, typename Hash = std::hash<ConstView<T>>, typename Equal = std::equal_to<ConstView<T>>, typename Allocator = std::allocator<ConstView<T>>>
class UnorderedSet
{
private:
    // Persistent storage 1MiB blocks
    ByteStreamSegmented<1000000> m_storage;

    // Data to be accessed
    std::unordered_set<ConstView<T>, Hash, Equal, Allocator> m_data;

public:
    UnorderedSet() = default;
    // Move only
    UnorderedSet(const UnorderedSet& other) = delete;
    UnorderedSet& operator=(const UnorderedSet& other) = delete;
    UnorderedSet(UnorderedSet&& other) = default;
    UnorderedSet& operator=(UnorderedSet&& other) = default;

    [[nodiscard]] ConstView<T> insert(const Builder<T>& builder) {
        const uint8_t* data = builder.get_data();
        size_t amount = builder.get_size();
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

    [[nodiscard]] size_t get_size() const {
        return m_data.size();
    }
};





}


#endif