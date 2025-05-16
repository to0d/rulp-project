// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_OSTREAM_H__
#define __LFC_STL_OSTREAM_H__

/**
 * @file lfc/stl/ostream.h
 * @brief Lightweight ostream implementation for embedded systems
 */

extern "C" int printf(const char* format, ...);

namespace lfc {

/**
 * @class ostream
 * @brief Basic output stream class mimicking std::ostream functionality
 * 
 * Provides type-safe output operations using operator<< overloading.
 * Designed for embedded systems with minimal dependencies.
 *
 * @example Basic usage:
 * @code
 * lfc::cout << "Value: " << 42 << lfc::endl;
 * lfc::cout << "PI: " << 3.14159 << lfc::endl;
 * @endcode
 *
 * @example Chaining operations:
 * @code
 * lfc::cout << "X: " << x << " Y: " << y << " Z: " << z << lfc::endl;
 * @endcode
 *
 * @example Custom type support (requires print_impl specialization):
 * @code
 * struct Point { int x, y; };
 * 
 * namespace lfc {
 * template<>
 * void ostream::print_impl<Point>(const Point& p) {
 *     printf("(%d,%d)", p.x, p.y);
 * }
 * }
 * 
 * Point pt{10,20};
 * lfc::cout << "Position: " << pt << lfc::endl;
 * @endcode
 */
class ostream {
public:
  /**
   * @brief Generic output operator for printable types
   * @tparam T Type of the value to output
   * @param value The value to output
   * @return Reference to the stream for chaining
   *
   * @example Basic output:
   * @code
   * lfc::cout << 42;       // Prints "42"
   * lfc::cout << "Hello";  // Prints "Hello"
   * @endcode
   */
  template<typename T>
  ostream& operator<<(const T& value) {
    print_impl(value);
    return *this;
  }

  /**
   * @brief Handles stream manipulators
   * @param manip Manipulator function to apply
   * @return Reference to the stream
   *
   * @example Using endl:
   * @code
   * lfc::cout << "Line 1" << lfc::endl << "Line 2" << lfc::endl;
   * @endcode
   */
  ostream& operator<<(ostream& (*manip)(ostream&)) {
    return manip(*this);
  }

private:
  // Type-specific implementations
  static void print_impl(const char* s) { printf("%s", s); }
  static void print_impl(char c) { printf("%c", c); }
  static void print_impl(int val) { printf("%d", val); }
  static void print_impl(double val) { printf("%f", val); }
};

/**
 * @brief Global ostream instance for standard output
 * @example Simple output:
 * @code
 * lfc::cout << "System initialized" << lfc::endl;
 * @endcode
 */
inline ostream cout;

/**
 * @brief Insert newline and flush the stream
 * @param os The output stream
 * @return Reference to the stream
 *
 * @example Typical usage:
 * @code
 * lfc::cout << "Error code: " << errno << lfc::endl;
 * @endcode
 */
inline ostream& endl(ostream& os) {
  printf("\n");
  return os;
}

} // namespace lfc

#endif // __LFC_STL_OSTREAM_H__