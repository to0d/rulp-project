// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_TO_STRING_MACRO_H__
#define __LFC_TO_STRING_MACRO_H__

#include <string>

#define LFC_TO_STRING_DEF(XX)  \
namespace lfc { \
std::string to_string(const XX&); \
std::string to_string(const XX*); \
}

#define LFC_TO_STRING_IMPL(XX, val) \
std::string to_string(const XX& val){ \
  return lfc::to_string(&val); \
} \
std::string to_string(const XX* val)

#endif // __LFC_TO_STRING_MACRO_H__

