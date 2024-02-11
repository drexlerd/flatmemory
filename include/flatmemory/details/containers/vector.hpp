
#ifndef FLATMEMORY_CONTAINERS_VECTOR_HPP_
#define FLATMEMORY_CONTAINERS_VECTOR_HPP_

#include "../builder.hpp"
#include "../byte_stream_segmented.hpp"
#include "../view_const.hpp"
#include "../view.hpp"
#include "../type_traits.hpp"

#include <cassert>
#include <vector>


namespace flatmemory {

/**
 * Vector can handle different sized objects
 * but does not support resize since the exact 
 * amount of bytes needed is not known in advance.
 * 
 * We use it to store ground actions
 */
template<typename T, NumBytes N = 1000000>
class VariableSizedTypeVector
{
private:
    // Persistent storage 1MiB blocks
    ByteStreamSegmented<N> m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

public:
    VariableSizedTypeVector() = default;
    // Move only
    VariableSizedTypeVector(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector& operator=(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector(VariableSizedTypeVector&& other) = default;
    VariableSizedTypeVector& operator=(VariableSizedTypeVector&& other) = default;

    /**
     * Element access
    */

    [[nodiscard]] View<T> operator[](size_t pos) {
        assert(pos <= static_cast<int>(size()));
        return m_data[pos];
    }

    [[nodiscard]] ConstView<T> operator[](size_t pos) const {
        assert(pos <= static_cast<int>(size()));
        return m_data[pos];
    }

    [[nodiscard]] View<T> back() { 
        assert(!m_data.empty());
        return m_data.back(); 
    }

    [[nodiscard]] ConstView<T> back() const {
        assert(!m_data.empty());
        return m_data.back();
    }


    /**
     * Iterators
    */

    [[nodiscard]] auto begin() { return m_data.begin(); }
    [[nodiscard]] const auto begin() const { return m_data.begin(); }
    [[nodiscard]] auto end() { return m_data.end(); }
    [[nodiscard]] const auto end() const { return m_data.end(); }


    /**
     * Capacity
    */

    [[nodiscard]] constexpr size_t empty() const {
        return m_data.empty();
    }

    [[nodiscard]] constexpr size_t size() const {
        return m_data.size();
    }


    /**
     * Modifiers
    */

    void push_back(const Builder<T>& builder) {
        m_data.push_back(View<T>(m_storage.write(builder.buffer().data(), builder.buffer().size())));
    }
};

/**
 * AutomaticVector can handle only equally sized objects
 * because it is meant to be resizeable.
 * 
 * We use it to store SearchNodes.
 */
template<typename T, NumBytes N = 1000000>
class FixedSizedTypeVector
{
private:
    // Persistent storage 1MiB blocks
    ByteStreamSegmented<N> m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

    const Builder<T> m_default_builder;

public:
    FixedSizedTypeVector(Builder<T>&& default_builder) : m_default_builder(std::move(default_builder)) { 
        if (m_default_builder.buffer().data() == nullptr) {
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

    [[nodiscard]] View<T> operator[](size_t pos) {
        if (pos >= size()) {
            resize(pos);
        }
        return m_data[pos];
    }

    [[nodiscard]] ConstView<T> operator[](size_t pos) const {
        if (pos >= size()) {
            resize(pos);
        }
        return m_data[pos];
    }

    [[nodiscard]] View<T> back() {
        return m_data.back();
    }

    [[nodiscard]] ConstView<T> back() const {
        return m_data.back();
    }


    /**
     * Iterators
    */

    [[nodiscard]] auto begin() { return m_data.begin(); }
    [[nodiscard]] const auto begin() const { return m_data.begin(); }
    [[nodiscard]] auto end() { return m_data.end(); }
    [[nodiscard]] const auto end() const { return m_data.end(); }


    /**
     * Capacity
    */

    [[nodiscard]] constexpr size_t empty() const {
        return m_data.empty();
    }

    [[nodiscard]] constexpr size_t size() const {
        return m_data.size();
    }


    /**
     * Modifiers
    */

    void push_back(const Builder<T>& builder) {
        m_data.push_back(View<T>(m_storage.write(builder.get_data(), builder.size())));
    }

    void resize(size_t count) {
        const uint8_t* default_data = m_default_builder.buffer().data();
        size_t default_size = m_default_builder.buffer().size();
        while (size() <= count) {
            uint8_t* written_data = m_storage.write(default_data, default_size);
            m_data.push_back(View<T>(written_data));
        }
    }
};


}

#endif
