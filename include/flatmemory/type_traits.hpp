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

#ifndef FLATMEMORY_TYPE_TRAITS_HPP_
#define FLATMEMORY_TYPE_TRAITS_HPP_

#include <type_traits>


namespace flatmemory 
{
    /**
     * Base template assuming all types are static.
     * 
     * For dynamic types we need to write an offset instead of the data directly.
     */
    template<typename T>
    struct is_dynamic_type : std::false_type {};


    /**
     * Distinguish between types that do not require a layout/builder/view and those that do.
    */
    template<typename T>
    inline constexpr bool is_trivial_and_standard_layout_v = std::is_trivial_v<T> && std::is_standard_layout_v<T>;

    template<typename T, bool = is_trivial_and_standard_layout_v<T>>
    struct maybe_builder {
        using type = T;
    };

    template<typename T>
    struct maybe_builder<T, false> {
        using type = Builder<T>;
    };
}

#endif 
