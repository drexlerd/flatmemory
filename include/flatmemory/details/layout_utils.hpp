/*
 * Copyright (C) 2024 Dominik Drexler
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FLATMEMORY_LAYOUT_UTILS_HPP_
#define FLATMEMORY_LAYOUT_UTILS_HPP_

#include "type_traits.hpp"
#include "layout.hpp"

#include <cstdint>
#include <cstddef>
#include <type_traits>


namespace flatmemory 
{
    /**
     * Common data types
    */
    using offset_type = uint16_t;

    using buffer_size_type = uint32_t;


    /**
     * Compute the amount of bytes needed to store the header information of type T
     *   - For trivial type T use sizeof(T)
     *   - For non trivial type T use sizeof(offset_type) since we store the data with an offset
    */
    template<typename T>
    inline consteval size_t calculate_header_offset_type_size() {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial) {
            return sizeof(T);
        } else {
            return sizeof(offset_type);
        }
    }


    /**
     * Compute alignment needed to be added to cur_pos to obtain correct header alignment of type T.
     *   - For trivial type T use alignof(T)
     *   - For non-trivial type T use alignof(offset_type) since we store the data with an offset
    */
    template<typename T>
    inline consteval size_t calculate_header_offset_alignment() {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial) {
            return alignof(T);
        } else {
            return alignof(offset_type); 
        }
    }
    // special case when directly storing type T in the header
    template<typename T>
    inline consteval size_t calculate_header_direct_alignment() {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial) {
            return alignof(T);
        } else {
            return Layout<T>::final_alignment; 
        }
    }


    /**
     * Compute alignment needed for a type T.
    */
    template<typename T>
    inline consteval size_t calculate_final_alignment_helper() {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        if constexpr (is_trivial) {
            return alignof(T);
        } else {
            return std::max(Layout<T>::final_alignment, alignof(offset_type)); 
        }
    }

    template<typename... Ts>
    inline consteval size_t calculate_final_alignment() {
        size_t max_alignment = 0;
        ((max_alignment = std::max(max_alignment, calculate_final_alignment_helper<Ts>())), ...);
        return std::max(static_cast<size_t>(1), max_alignment);
    }


    /**
     * Compute padding needed to store an object with given alignment factor from the given position.
    */
    inline constexpr size_t calculate_amount_padding(size_t pos, size_t align_factor) {
        return (align_factor - (pos % align_factor)) % align_factor;
    }

    // new
    template<typename T>
    inline constexpr size_t calculate_header_amount_padding_to_next_type(size_t pos) {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        size_t alignment = 1;
        if constexpr (is_trivial) {
            alignment = alignof(T);
        } else {
            alignment = alignof(offset_type); 
        }
        return calculate_amount_padding(pos, alignment);
    }

    template<typename T>
    inline constexpr size_t calculate_data_amount_padding_to_next_type(size_t pos) {
        constexpr bool is_trivial = IsTriviallyCopyable<T>;
        size_t alignment = 1;
        if constexpr (is_trivial) {
            alignment = alignof(T);
        } else {
            alignment = Layout<T>::final_alignment; 
        }
        return calculate_amount_padding(pos, alignment);
    }


    /**
     * Compute the position in the header when storing type T with offset
    */
    template<typename T_Prev, typename T>
    inline consteval size_t calculate_header_offset_pos(size_t cur_pos) {
        cur_pos += sizeof(T_Prev);
        cur_pos += calculate_amount_padding(cur_pos, calculate_header_offset_alignment<T>());
        return cur_pos;
    }
    // special case when directly storing type T in the header
    template<typename T_Prev, typename T>
    inline consteval size_t calculate_header_direct_pos(size_t cur_pos) {
        cur_pos += sizeof(T_Prev);
        cur_pos += calculate_amount_padding(cur_pos, calculate_header_direct_alignment<T>());
        return cur_pos;
    }

}

#endif 
