
# LFC Standard Template Library Guide

- Floating point types: float, double, long double (128 bit)
- Integer types: bool, char, signed char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long
- Namespace: [lfc](@ref lfc)

## 1. STL library

### 1.1 algorithm

- Header file: [#include <lfc/stl/algorithm.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::max](@ref lfc::max)   | Function Template | Returns the greater of two values. |
    | [lfc::min](@ref lfc::min)   | Function Template | Returns the lesser of two values.  |

### 1.2 limits

- Header file: [#include <lfc/stl/limits.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::numeric_limits](@ref lfc::numeric_limits)   | Class Template  | numeric limits. |
    | [lfc::numeric_limits<int>::max()](@ref lfc::numeric_limits)     | Member Function | Maximum finite value. |
    | [lfc::numeric_limits<int>::max()](@ref lfc::numeric_limits)     | Member Function | Minimum finite value. |
    | [lfc::numeric_limits<int>::epsilon()](@ref lfc::numeric_limits) | Member Function | Epsilon for floating-point types. |

### 1.3 math

- Header file: [#include <lfc/stl/math.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::abs](@ref lfc::abs)                     | Function Template  | Computes the absolute value of a number. |
    | [lfc::ceil](@ref lfc::ceil)                   | Function Template  | Floating-Point Rounds up. |
    | [lfc::floor](@ref lfc::floor)                 | Function Template  | Floating-Point Rounds down. |
    | [lfc::isnan](@ref lfc::isnan)                 | Function Template  | Floating-Point NaN Check. |
    | [lfc::isinf](@ref lfc::isinf)                 | Function Template  | Floating-Point Infinite Check. |

### 1.4 ostream

- Header file: [#include <lfc/stl/ostream.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::ostream](@ref lfc::ostream)             | Class Template  | Basic output stream class. |
    | [lfc::cout](@ref lfc::cout)                   | Global object   | Global ostream instance for standard output. |
    | [lfc::endl](@ref lfc::endl)                   | Global Function | stream manipulator function. |

### 1.5 string

- Header file: [#include <lfc/stl/string.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::memcpy](@ref lfc::memcpy)                       | Function Template    | Copies bytes between memory areas.  |
    | [lfc::memset](@ref lfc::memset)                       | Function Template    | Fills memory with a specified byte value.  |
    | [lfc::strcpy](@ref lfc::strcpy)                       | Function Template    | Copies a null-terminated string from source to destination. |
    | [lfc::strcmp](@ref lfc::strcmp)                       | Function Template    | Compares two null-terminated strings. |
    | [lfc::strlen](@ref lfc::strlen)                       | Function Template    | Computes the length of the given null-terminated character string. |


### 1.6 type_traits

- Header file: [#include <lfc/stl/type_traits.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::decay](@ref lfc::decay)                         | Class Template    | Performs type decay transformation. |
    | [lfc::decay_t](@ref lfc::decay_t)                     | Alias Template    | Performs type decay transformation. |
    | [lfc::is_same](@ref lfc::is_same)                     | Function Template | Determines if two types are the same. |
    | [lfc::is_same_v](@ref lfc::is_same_v)                 | Variable Template | Determines if two types are the same. |
    | [lfc::is_float_v](@ref lfc::is_float_v)               | Variable Template | Determines if the type is a floating point type. |
    | [lfc::is_floating_point](@ref lfc::is_floating_point) | Class Template    | Determines if the type is a floating point type. |
    | [lfc::is_member_function_pointer](@ref lfc::is_member_function_pointer)   | Class Template | Determines if the type is a pointer to non-static member function. |
    | [lfc::is_integral_v](@ref lfc::is_integral_v)         | Variable Template | Determines if the type is an integer type. |
    | [lfc::remove_pointer](@ref lfc::remove_pointer)       | Class Template    | Removes pointer qualification from a type. |
    | [lfc::remove_pointer_t](@ref lfc::remove_pointer_t)   | Alias Template    | Removes pointer qualification from a type. |
  
### 1.7 utility

- Header file: [#include <lfc/stl/utility.h>](#)

- Support List

    | Item | Type | Description |
    |---|---|---|
    | [lfc::forward](@ref lfc::forward)                    | Function Template    | Forward an lvalue or rvalue.  |
    | [lfc::move](@ref lfc::move)                          | Function Template    | Convert a value to an rvalue. |

