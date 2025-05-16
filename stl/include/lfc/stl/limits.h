// SPDX-FileCopyrightText: 2023 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_LIMITS_H__
#define __LFC_STL_LIMITS_H__
#include <climits>
#include "lfc/stl/type_traits.h"

namespace lfc {

/**
 * @class numeric_limits
 * @brief A custom implementation of numeric type traits similar to std::numeric_limits
 * 
 * @tparam T The type to query numeric properties for
 * 
 * This template class provides compile-time information about the properties
 * of arithmetic types. It serves as a simplified version of std::numeric_limits,
 * providing minimum and maximum values as well as precision information.
 * 
 */
template<typename T>
struct numeric_limits {

  /**
   * @brief Returns the minimum finite value representable by the type
   * 
   * @return Minimum finite value for the type
   */
  static constexpr 
  T min() noexcept { return T(); }

  /**
   * @brief Returns the maximum finite value representable by the type
   * 
   * @return Maximum finite value for the type
   */
  static constexpr 
  T max() noexcept { return T(); }

  /**
   * @brief Returns the machine epsilon (difference between 1 and the next value)
   * 
   * @return The machine epsilon for floating-point types
   */
  static constexpr 
  T epsilon() noexcept { return T(); }

  static_assert(lfc::is_float_v<T> || lfc::is_integral_v<T>, "Unsupported type");
};

/// \cond

#define DEFINE_LIMITS_INTEGRAL(Type, Min, Max) \
template<> \
struct numeric_limits<Type> { \
  static constexpr Type min() noexcept { return Min; } \
  static constexpr Type max() noexcept { return Max; } \
  static constexpr Type epsilon() noexcept { return 0; } \
};

#define DEFINE_LIMITS_FLOAT(Type, Min, Max, Epsilon) \
template<> \
struct numeric_limits<Type> { \
  static constexpr Type min() noexcept { return Min; } \
  static constexpr Type max() noexcept { return Max; } \
  static constexpr Type epsilon() noexcept { return Epsilon; } \
};

DEFINE_LIMITS_INTEGRAL(bool, false, true)
DEFINE_LIMITS_INTEGRAL(char, CHAR_MIN, CHAR_MAX)
DEFINE_LIMITS_INTEGRAL(signed char, SCHAR_MIN, SCHAR_MAX)
DEFINE_LIMITS_INTEGRAL(unsigned char, 0, UCHAR_MAX)
DEFINE_LIMITS_INTEGRAL(short, SHRT_MIN, SHRT_MAX)
DEFINE_LIMITS_INTEGRAL(unsigned short, 0, USHRT_MAX)
DEFINE_LIMITS_INTEGRAL(int, INT_MIN, INT_MAX)
DEFINE_LIMITS_INTEGRAL(unsigned int, 0, UINT_MAX)
DEFINE_LIMITS_INTEGRAL(long, LONG_MIN, LONG_MAX)
DEFINE_LIMITS_INTEGRAL(unsigned long, 0, ULONG_MAX)
DEFINE_LIMITS_INTEGRAL(long long, LLONG_MIN, LLONG_MAX)
DEFINE_LIMITS_INTEGRAL(unsigned long long, 0, ULLONG_MAX)

DEFINE_LIMITS_FLOAT(float, __FLT_MIN__, __FLT_MAX__, __FLT_EPSILON__)
DEFINE_LIMITS_FLOAT(double, __DBL_MIN__, __DBL_MAX__, __DBL_EPSILON__)
DEFINE_LIMITS_FLOAT(long double, __LDBL_MIN__, __LDBL_MAX__, __LDBL_EPSILON__)

#undef DEFINE_LIMITS_INTEGRAL
#undef DEFINE_LIMITS_FLOAT

/// \endcond

} // namespace lfc

#endif //__LFC_STL_LIMITS_H__