// SPDX-FileCopyrightText: 2023 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_ALGO_H__
#define __LFC_STL_ALGO_H__
#include "lfc/stl/limits.h"
#include "lfc/stl/type_traits.h"
#include <cstdint>

namespace lfc {

/**
 * @brief Returns the greater of two values
 * 
 * @tparam T Arithmetic type (integral or floating-point)
 * @param a First value to compare
 * @param b Second value to compare
 * @return The greater of a and b. If they are equivalent, returns a.
 * 
 * @details
 * Returns the greater of the two arguments:
 * - For signed types: compares numerically
 * - For unsigned types: compares numerically
 * - For floating-point types: handles NaN and ±0.0 correctly according to standard comparison rules
 * 
 * @note
 * - Works with all standard arithmetic types (int, float, double, etc.)
 * - constexpr compatible
 * - noexcept
 * - Part of the <lfc/stl/algorithm.h> header
 * 
 * @see lfc::min
 * 
 * @code
 * #include <lfc/stl/algorithm.h>
 * 
 * int main() {
 *     int i1 = 5, i2 = 10;
 *     double d1 = 3.14, d2 = 2.71;
 *     unsigned u1 = 10, u2 = 20;
 *     
 *     std::cout << lfc::max(i1, i2);  // 10
 *     std::cout << lfc::max(d1, d2);  // 3.14
 *     std::cout << lfc::max(u1, u2);  // 20
 * }
 * @endcode
 */
template<typename T, typename>
constexpr 
T max(const T& a, const T& b) noexcept;

template< typename T
        , typename = lfc::enable_if_t<lfc::is_arithmetic_v<T>>>
constexpr 
T max(const T& a, const T& b) noexcept {
  static_assert(lfc::is_arithmetic_v<T>
    , "lfc::max requires arithmetic type");
  return (a < b) ? b : a;
}


/**
 * @brief Returns the lesser of two values
 * 
 * @tparam T Arithmetic type (integral or floating-point)
 * @param a First value to compare
 * @param b Second value to compare
 * @return The lesser of a and b. If they are equivalent, returns a.
 * 
 * @details
 * Returns the lesser of the two arguments:
 * - For signed types: compares numerically
 * - For unsigned types: compares numerically
 * - For floating-point types: handles NaN and ±0.0 correctly according to standard comparison rules
 * 
 * @note
 * - Works with all standard arithmetic types (int, float, double, etc.)
 * - constexpr compatible
 * - noexcept
 * - Part of the <lfc/stl/algorithm.h> header
 * 
 * @see lfc::max
 * 
 * @code
 * #include <lfc/stl/algorithm.h>
 * 
 * int main() {
 *     int i1 = 5, i2 = 10;
 *     double d1 = 3.14, d2 = 2.71;
 *     unsigned u1 = 10, u2 = 20;
 *     
 *     std::cout << lfc::min(i1, i2);  // 5
 *     std::cout << lfc::min(d1, d2);  // 2.71
 *     std::cout << lfc::min(u1, u2);  // 10
 * }
 * @endcode
 */
template<typename T, typename>
constexpr 
T min(const T& a, const T& b) noexcept;

template< typename T
        , typename = lfc::enable_if_t<lfc::is_arithmetic_v<T>>>
constexpr 
T min(const T& a, const T& b) noexcept {
  static_assert(lfc::is_arithmetic_v<T>
    , "lfc::min requires arithmetic type");
  return (b < a) ? b : a;
}

} // namespace lfc

#endif //__LFC_STL_ALGO_H__