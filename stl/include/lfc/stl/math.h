// SPDX-FileCopyrightText: 2023 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_MATH_H__
#define __LFC_STL_MATH_H__
#include "lfc/stl/limits.h"
#include "lfc/stl/string.h"
#include "lfc/stl/type_traits.h"
#include <cstdint>

namespace lfc {

/// \cond
namespace impl {

template< typename T
        , typename = lfc::enable_if_t<lfc::is_arithmetic_v<T>>>
constexpr
T abs_impl(T x) noexcept {
  if constexpr (lfc::is_unsigned_v<T>) {
    return x;  // No-op for unsigned types
  }
  else {
    return x < 0 ? -x : x;  // Standard absolute value for signed types
  }
}

} // namespace impl
/// \endcond

/**
 * @brief Computes the absolute value of a number
 * 
 * @tparam T Arithmetic type (integral or floating-point)
 * @param x Input value
 * @return The absolute value of x
 * 
 * @details
 * Returns the absolute value of the argument:
 * - For signed types: returns -x if x is negative, x otherwise
 * - For unsigned types: returns x unchanged
 * - For floating-point types: preserves NaN payloads and handles ±0.0 correctly
 * 
 * @note
 * - Works with all standard arithmetic types (int, float, double, etc.)
 * - constexpr compatible
 * - noexcept
 * - Part of the <lfc/stl/math.h> header
 * 
 * @see lfc::floor
 * @see lfc::ceil
 * 
 * @code
 * #include <lfc/stl/math.h>
 * 
 * int main() {
 *     int i = -5;
 *     double d = -3.14;
 *     unsigned u = 10;
 *     
 *     std::cout << lfc::abs(i);  // 5
 *     std::cout << lfc::abs(d);  // 3.14
 *     std::cout << lfc::abs(u);  // 10
 * }
 * @endcode
 */
template<typename T>
constexpr 
auto abs(T x) noexcept {
  if constexpr (lfc::is_arithmetic_v<T>) {
    return impl::abs_impl(x);
  }
  else {
    static_assert(lfc::is_arithmetic_v<T>
      , "lfc::abs requires arithmetic type");
  }
}

/// \cond
namespace impl {

template <typename T
        , typename = lfc::enable_if_t<lfc::is_float_v<T>>>
T ceil_impl(T x) {
  
  // NaN
  if (x != x) 
    return x;
  
  // +inf
  if (x > lfc::numeric_limits<T>::max() / 2) 
    return x;
  
  // -inf
  if (x < -lfc::numeric_limits<T>::max() / 2) 
    return x;
  
  if (x == 0.0) 
    return x;
  
  // for case: 2.0
  {
    T int_part = static_cast<T>(static_cast<long long>(x));
    if (int_part == x)
      return int_part;
  }

  // Get integer values
  T int_part;
  if (x > 0.0) {
    int_part = static_cast<T>(static_cast<long long>(x + 1));
  } 
  else {
    int_part = static_cast<T>(static_cast<long long>(x));
  }
  
  // Dealing with accuracy
  if (int_part < x) 
    int_part += 1;
  
  return int_part;
}

} // namespace impl
/// \endcond

/**
 * @brief Rounds up the given floating-point value to the nearest integer not less than the value.
 * 
 * @tparam T Floating-point type (float, double, or long double)
 * @param arg Floating-point value to round up
 * @return The smallest integer value not less than `arg`, returned as the same floating-point type
 * 
 * @details
 * Computes the ceiling of the floating-point value `arg`. The ceiling function returns:
 * - For finite values: the smallest integer value not less than `arg`
 * - For ±∞: returns the same value (∞ or -∞)
 * - For NaN: returns NaN
 * 
 * @note
 * - This function handles all standard floating-point types (float, double, long double)
 * - The return value is of the same type as the input (not an actual integer type)
 * - Equivalent to C's ceil() function but as a C++ template
 * - Part of the <lfc/stl/math.h> header
 * 
 * @see lfc::floor
 * @see lfc::round
 * 
 * @code
 * #include <lfc/stl/math.h>
 * #include <iostream>
 * 
 * int main() {
 *     double x = 3.2;
 *     double y = -2.7;
 *     
 *     std::cout << "ceil(" << x << ") = " << lfc::ceil(x) << '\n';  // 4.0
 *     std::cout << "ceil(" << y << ") = " << lfc::ceil(y) << '\n';  // -2.0
 *     std::cout << "ceil(-0.0) = " << lfc::ceil(-0.0) << '\n';      // -0.0
 * }
 * @endcode
 */
template<typename T>
constexpr
auto ceil(T arg) {
  if constexpr (lfc::is_integral_v<T>) {
    return arg;
  }
  else if constexpr (lfc::is_float_v<T>) {
    return impl::ceil_impl(arg);
  } 
  else {
    static_assert(lfc::is_float_v<T> || lfc::is_integral_v<T>
      , "Unsupported floating-point type");
  }
}

/// \cond
namespace impl {

template <typename T>
struct FloatTraits;

template <>
struct FloatTraits<float> {
  static constexpr int exponent_bits = 8;
  static constexpr int mantissa_bits = 23;
};

template <>
struct FloatTraits<double> {
  static constexpr int exponent_bits = 11;
  static constexpr int mantissa_bits = 52;
}; 

template <>
struct FloatTraits<long double> {
  static_assert(sizeof(long double) == 16
    , "Unsupported long double size");

  static constexpr int exponent_bits = 15;
  static constexpr int mantissa_bits = 64;
};

template<typename T, typename = lfc::enable_if_t<lfc::is_float_v<T>>>
T floor_impl(T x) {
  
  // NaN
  if (x != x) 
    return x;
  
  // +inf
  if (x > lfc::numeric_limits<T>::max() / 2) 
    return x;
  
  // -inf
  if (x < -lfc::numeric_limits<T>::max() / 2) 
    return x;
  
  if (x == 0.0) 
    return x;
  
  // for case: -2.0
  {
    T int_part = static_cast<T>(static_cast<long long>(x));
    if (int_part == x)
      return int_part;
  }

  // Get integer values
  T int_part;
  if (x > 0.0) {
    int_part = static_cast<T>(static_cast<long long>(x));
  } 
  else {
    int_part = static_cast<T>(static_cast<long long>(x - 1));
  }
  
  // Dealing with accuracy
  if (int_part > x) 
    int_part -= 1;
  
  return int_part;
}

} // namespace impl
/// \endcond

/**
 * @brief Rounds down the given floating-point value to the nearest integer not greater than the value.
 * 
 * @tparam T Floating-point type (float, double, or long double)
 * @param arg Floating-point value to round down
 * @return The largest integer value not greater than `arg`, returned as the same floating-point type
 * 
 * @details
 * Computes the floor of the floating-point value `arg`. The floor function returns:
 * - For finite values: the largest integer value not greater than `arg`
 * - For ±∞: returns the same value (∞ or -∞)
 * - For NaN: returns NaN
 * 
 * @note
 * - This function handles all standard floating-point types (float, double, long double)
 * - The return value is of the same type as the input (not an actual integer type)
 * - Equivalent to C's floor() function but as a C++ template
 * - Part of the <lfc/stl/math.h> header
 * 
 * @see lfc::ceil
 * @see lfc::round
 * 
 * @code
 * #include <lfc/stl/math.h>
 * #include <iostream>
 * 
 * int main() {
 *     double x = 3.7;
 *     double y = -2.3;
 *     
 *     std::cout << "floor(" << x << ") = " << lfc::floor(x) << '\n';  // 3.0
 *     std::cout << "floor(" << y << ") = " << lfc::floor(y) << '\n';  // -3.0
 *     std::cout << "floor(-0.0) = " << lfc::floor(-0.0) << '\n';      // -0.0
 * }
 * @endcode
 */
template<typename T>
constexpr
auto floor(T arg) {
  if constexpr (lfc::is_integral_v<T>) {
    return arg;
  }
  else if constexpr (lfc::is_float_v<T>) {
    return impl::floor_impl(arg);
  } 
  else {
    static_assert(lfc::is_float_v<T> || lfc::is_integral_v<T>
      , "Unsupported floating-point type");
  }
}

/**
 * @brief Checks if the given floating-point number is NaN (Not-a-Number).
 * 
 * @tparam T Floating-point type (float, double, or long double)
 * @param arg Floating-point value to check
 * @return true If the argument is NaN
 * @return false Otherwise
 * 
 * @details
 * This function detects whether the floating-point value `arg` is a NaN (Not-a-Number) value.
 * NaN values are generated by invalid floating-point operations such as:
 * - 0.0/0.0
 * - ∞ - ∞
 * - sqrt(-1)
 * 
 * @note
 * - Works with all standard floating-point types (float, double, long double)
 * - May be implemented as a macro in some implementations, but treated as a function here
 * - The behavior is equivalent to isnan() in C
 * 
 * @see lfc::isinf
 * 
 * @code
 * double x = lfc::sqrt(-1.0); // generates NaN
 * if (lfc::isnan(x)) {
 *     lfc::cout << "x is NaN\n";
 * }
 * @endcode
 */
template <typename T>
constexpr 
bool isnan(T value) {
  static_assert(is_float_v<T>
    , "isnan requires floating-point type");
  
  using Traits = impl::FloatTraits<T>;
  
  // Interpret floating-point numbers bitwise as integers
  using IntType = lfc::conditional_t<
      sizeof(T) == sizeof(uint32_t), uint32_t,
      lfc::conditional_t<
          sizeof(T) == sizeof(uint64_t), uint64_t,
          lfc::conditional_t<
            sizeof(T) == sizeof(__uint128_t), __uint128_t,
            void
          >
      >
  >;
  
  static_assert(!is_same_v<IntType, void>
    , "Unsupported floating-point type");

  IntType bits;
  impl::memcpy_impl( reinterpret_cast<unsigned char*>(&bits)
                     , reinterpret_cast<const unsigned char*>(&value)
                     , sizeof(T));
  
  // Check whether all the index digits are 1
  constexpr IntType exponent_mask = ((IntType(1) << Traits::exponent_bits) - 1) << Traits::mantissa_bits;
  constexpr IntType nan_exponent = exponent_mask;
  
  if ((bits & exponent_mask) != nan_exponent) {
    return false;
  }
  
  // Check whether the mantissa is non-zero
  constexpr IntType mantissa_mask = (IntType(1) << Traits::mantissa_bits) - 1;
  return (bits & mantissa_mask) != 0;
}

/**
 * @brief Checks if the given floating-point number is infinite (positive or negative infinity).
 * 
 * @tparam T Floating-point type (float, double, or long double)
 * @param arg Floating-point value to check
 * @return true If the argument is positive or negative infinity
 * @return false Otherwise
 * 
 * @details
 * This function detects whether the floating-point value `arg` is an infinity value.
 * Infinity values are generated by operations such as:
 * - 1.0 / 0.0 → +∞
 * - -1.0 / 0.0 → -∞
 * - log(0.0) → -∞
 * 
 * @note
 * - Works with all standard floating-point types (float, double, long double)
 * - The behavior is equivalent to isinf() in C
 * - Differentiates between +∞ and -∞ (see lfc::signbit)
 * 
 * @see lfc::isnan
 * 
 * @code
 * double x = 1.0 / 0.0; // generates +∞
 * if (lfc::isinf(x)) {
 *     lfc::cout << "x is infinite\n";
 * }
 * @endcode
 */
template <typename T>
constexpr 
bool isinf(T value) {
  static_assert(is_float_v<T>
    , "isinf requires floating-point type");
  
  using Traits = impl::FloatTraits<T>;
  
  // Interpret floating-point numbers bitwise as integers
  using IntType = lfc::conditional_t<
      sizeof(T) == sizeof(uint32_t), uint32_t,
      lfc::conditional_t<
          sizeof(T) == sizeof(uint64_t), uint64_t,
          lfc::conditional_t<
            sizeof(T) == sizeof(__uint128_t), __uint128_t,
            void
          >
      >
  >;
  
  static_assert(!is_same_v<IntType, void>
    , "Unsupported floating-point type");

  IntType bits;
  impl::memcpy_impl( reinterpret_cast<unsigned char*>(&bits)
                     , reinterpret_cast<const unsigned char*>(&value)
                     , sizeof(T));
  
  // Check if exponent bits are all 1 (infinity condition)
  constexpr IntType exponent_mask = ((IntType(1) << Traits::exponent_bits) - 1) << Traits::mantissa_bits;
  constexpr IntType infinity_exponent = exponent_mask;
  
  if ((bits & exponent_mask) != infinity_exponent) {
    return false;
  }
  
  // Check if mantissa bits are all 0 (distinguishes inf from NaN)
  constexpr IntType mantissa_mask = (IntType(1) << Traits::mantissa_bits) - 1;
  return (bits & mantissa_mask) == 0;
}

} // namespace lfc

#endif //__LFC_STL_MATH_H__