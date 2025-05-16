// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef SIMPLE_UT_H
#define SIMPLE_UT_H

#include <stdio.h>
#include "lfc/stl/type_traits.h"

template<typename T>
inline void rut_print(T arg) {
  if constexpr (lfc::is_integral_v<T>) {
    printf("%d", arg);
  }
  else if constexpr (lfc::is_float_v<T>) {
    printf("%f", arg);
  } 
  else if constexpr (lfc::is_bool_v<T>) {
    printf("%s", arg ? "true" : "false");
  }
  else if constexpr (lfc::is_pointer_v<T> && lfc::is_char_v<lfc::remove_pointer_t<T>> ) {
    printf("%s", arg);
  }
  else {
    static_assert(lfc::is_float_v<T> || lfc::is_integral_v<T> || lfc::is_bool_v<T> , "Unsupported type");
  }
};


#define RUT_START     printf("RV test start:\n"); int rut_index = 0;
#define RUT_FINISH    printf("\nRV test finish.\n");

#define RUT_RUN(x)    printf("  %s=", #x); rut_print(x); printf("\n");
#define RUT_TEST(x)   printf("\n%03d: %s\n", rut_index++, #x);

#endif // SIMPLE_UT_H