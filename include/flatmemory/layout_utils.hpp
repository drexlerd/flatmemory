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
#include <iostream>
#include <iomanip>


namespace flatmemory 
{
    /**
     * Common data types
    */
    using offset_type = uint16_t;


    /**
     * Compute the amount of bytes needed to store the header of type T
     *   - For trivial type T use sizeof(T)
     *   - For dynamic custom type T use sizeof(offset_type) since we store the data with an offset
     *   - For static custom type T use Layout<T>::size which is computed in the Layout of type T.
    */
    template<typename T>
    inline consteval size_t compute_type_size() {
        constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
        if constexpr (is_trivial) {
            return sizeof(T);
        } else {
            constexpr bool is_dynamic = is_dynamic_type<T>::value;
            if constexpr (is_dynamic) {
                return sizeof(offset_type);
            } else {
                return Layout<T>::size;
            }
        }
    }


    /**
     * Compute alignment needed to be added to cur_pos to obtain correct alignment for header information of type T.
     *   - For trivial type T use alignof(T)
     *   - For dynamic custom type T use alignof(offset_type) since we store the data with an offset
     *   - For static custom type T use Layout<T>::final_alignment which is computed in the Layout of type T.
    */
    template<typename T>
    inline consteval size_t calculate_header_alignment() {
        constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
        if constexpr (is_trivial) {
            return alignof(T);
        } else {
            constexpr bool is_dynamic = is_dynamic_type<T>::value;
            if constexpr (is_dynamic) {
                return alignof(offset_type); 
            } else {
                return Layout<T>::final_alignment;
            }
        }
    }


    /**
     * Compute alignment needed to be added to cur_pos to obtain correct alignment for storing information of type T. 
    */
    template<typename T>
    inline consteval size_t calculate_overall_alignment() {
        constexpr bool is_trivial = is_trivial_and_standard_layout_v<T>;
        if constexpr (is_trivial) {
            return alignof(T);
        } else {
            constexpr bool is_dynamic = is_dynamic_type<T>::value;
            if constexpr (is_dynamic) {
                return std::max(Layout<T>::final_alignment, alignof(offset_type)); 
            } else {
                return Layout<T>::final_alignment;
            }
        }
    }


    /**
     * Compute alignment needed for a collection of types.
    */
    template<typename... Ts>
    inline consteval size_t calculate_final_alignment() {
        size_t max_alignment = 0;
        ((max_alignment = std::max(max_alignment, calculate_overall_alignment<Ts>())), ...);
        return max_alignment;
    }


    /**
     * Compute padding needed to store an object with given alignment factor from the given position.
    */
    inline constexpr size_t compute_amount_padding(size_t pos, size_t align_factor) {
        if (align_factor == 0) return 1;
        return (align_factor - (pos % align_factor)) % align_factor;
    }

}

#endif 
