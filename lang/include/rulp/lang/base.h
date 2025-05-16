// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_BASE_H__
#define __RULP_LANG_BASE_H__
#include "lfc/base/to_string_macro.h"
#include <vector>
#include <cassert>
namespace lfc {

typedef const std::string&        StrConstRef; 
typedef std::vector<std::string>  StrList; 
typedef bool                      boolean;
#define null                      NULL

} // namespace lfc
#endif //__RULP_LANG_IRTOKENER_H__