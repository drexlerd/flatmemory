
#ifndef FLATMEMORY_CONTAINERS_VECTOR_HPP_
#define FLATMEMORY_CONTAINERS_VECTOR_HPP_

#include "../builder.hpp"
#include "../byte_stream_segmented.hpp"
#include "../view.hpp"

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
template<typename T>
class VariableSizedTypeVector
{
private:
    // Persistent storage
    ByteStreamSegmented<100000> m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

public:
    VariableSizedTypeVector() = default;
    // Move only
    VariableSizedTypeVector(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector& operator=(const VariableSizedTypeVector& other) = delete;
    VariableSizedTypeVector(VariableSizedTypeVector&& other) = default;
    VariableSizedTypeVector& operator=(VariableSizedTypeVector&& other) = default;

    void push_back(const Builder<T>& builder) {
        m_data.push_back(View<T>(m_storage.write(builder.buffer().data(), builder.buffer().size())));
    }

    [[nodiscard]] View<T> back() {
        return m_data.back();
    }

    [[nodiscard]] const View<T> back() const {
        return m_data.back();
    }

    [[nodiscard]] View<T> operator[](size_t pos) {
        assert(pos <= static_cast<int>(size()));
        return m_data[pos];
    }

    [[nodiscard]] const View<T> operator[](size_t pos) const {
        assert(pos <= static_cast<int>(size()));
        return m_data[pos];
    }

    [[nodiscard]] size_t size() const {
        return m_data.size();
    }
};

/**
 * AutomaticVector can handle only equally sized objects
 * because it is meant to be resizeable.
 * 
 * We use it to store SearchNodes.
 */
template<typename T>
class FixedSizedTypeVector
{
private:
    // Persistent storage
    ByteStreamSegmented<100000> m_storage;

    // Data to be accessed
    std::vector<View<T>> m_data;

    const Builder<T> m_default_builder;

public:
    FixedSizedTypeVector(Builder<T>&& default_builder) : m_default_builder(std::move(default_builder)) { }
    // Move only
    FixedSizedTypeVector(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector& operator=(const FixedSizedTypeVector& other) = delete;
    FixedSizedTypeVector(FixedSizedTypeVector&& other) = default;
    FixedSizedTypeVector& operator=(FixedSizedTypeVector&& other) = default;

    void push_back(const Builder<T>& builder) {
        m_data.push_back(View<T>(m_storage.write(builder.get_data(), builder.size()), builder.size()));
    }

    [[nodiscard]] View<T> back() {
        return m_data.back();
    }

    [[nodiscard]] const View<T> back() const {
        return m_data.back();
    }

    [[nodiscard]] View<T> operator[](size_t pos) {
        if (pos >= size()) {
            resize(pos);
        }
        return m_data[pos];
    }

    [[nodiscard]] const View<T> operator[](size_t pos) const {
        if (pos >= size()) {
            resize(pos);
        }
        return m_data[pos];
    }

    void resize(size_t count) {
        const uint8_t* default_data = m_default_builder.get_data();
        size_t default_size = m_default_builder.size();
        while (size() <= count) {
            uint8_t* written_data = m_storage.write(default_data, default_size);
            m_data.push_back(View<T>(written_data));
        }
    }

    [[nodiscard]] constexpr size_t size() const {
        return m_data.size();
    }
};


}

#endif
