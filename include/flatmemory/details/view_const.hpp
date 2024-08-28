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

#ifndef FLATMEMORY_VIEW_CONST_HPP_
#define FLATMEMORY_VIEW_CONST_HPP_

#include <type_traits>

namespace flatmemory
{
/**
 * Interface class.
 */
template<typename Derived>
class IConstView
{
private:
    /// @brief Helper to cast to Derived.
    constexpr const auto& self() const { return static_cast<const Derived&>(*this); }
    constexpr auto& self() { return static_cast<Derived&>(*this); }

public:
    /// @brief Get the pointer to the beginning of the buffer.
    const uint8_t* get_buffer() const { return self().get_buffer_impl(); }

    /// @brief Get the buffer size.
    /// @return
    size_t get_buffer_size() const { return self().get_buffer_size_impl(); }
};

/**
 * Implementation class.
 *
 * Provide overload with your Tag.
 */
template<typename Tag>
class ConstView : public IConstView<View<Tag>>
{
};

}

#endif
