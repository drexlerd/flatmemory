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

#include "builder.hpp"
#include "layout_utils.hpp"

#include <type_traits>


namespace flatmemory 
{
    /**
     * Base ID class for custom types.
    */
    struct Custom {};

    template<typename T>
    concept IsCustom = std::derived_from<T, Custom>;

    template<typename T>
    concept IsTrivial = std::is_trivial_v<T>;

    /**
     * Base template assuming all types are static.
     * 
     * For dynamic types we need to write an offset instead of the data directly.
     */
    template<IsCustom T>
    struct is_dynamic_type : std::false_type {};


    template<typename T>
    concept IsTrivialOrCustom = (IsTrivial<T> || IsCustom<T>);


    template<IsTrivialOrCustom T, bool = IsTrivial<T>>
    struct maybe_builder {
        using type = T;
    };

    template<IsTrivialOrCustom T>
    struct maybe_builder<T, false> {
        using type = Builder<T>;
    };
}

#endif 
