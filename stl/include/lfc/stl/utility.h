// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_UTILITY_H__
#define __LFC_STL_UTILITY_H__
#include "lfc/stl/type_traits.h"

namespace lfc {

/**
 *  @brief  Forward an lvalue.
 *  @return The parameter cast to the specified type.
 *
 *  This function is used to implement "perfect forwarding".
 */
template<typename T>
  constexpr T&&
  forward(typename impl::remove_reference<T>::type& t) noexcept
  { return static_cast<T&&>(t); }

/**
 *  @brief  Forward an rvalue.
 *  @return The parameter cast to the specified type.
 *
 *  This function is used to implement "perfect forwarding".
 */
template<typename T>
  constexpr T&&
  forward(typename impl::remove_reference<T>::type&& t) noexcept
  {
    static_assert(!impl::is_lvalue_reference<T>::value
      , "std::forward must not be used to convert an rvalue to an lvalue");
    return static_cast<T&&>(t);
  }

/**
 *  @brief  Convert a value to an rvalue.
 *  @param  t  A thing of arbitrary type.
 *  @return The parameter cast to an rvalue-reference to allow moving it.
*/
template<typename T>
  constexpr typename impl::remove_reference<T>::type&&
  move(T&& t) noexcept
  { 
    return static_cast<typename impl::remove_reference<T>::type&&>(t); 
  }

} // namespace lfc

#endif //__LFC_STL_UTILITY_H__