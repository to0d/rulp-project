// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_FORMAT_UTIL_H__
#define __RULP_UTILS_FORMAT_UTIL_H__

#include "rulp/object/IRObject.h"
namespace lfc {

class FormatUtil {
public:
  
  static void format(IRObject* obj, std::vector<std::string>& outLines, int level);
  static std::vector<std::string> format(std::vector<std::string>& lines);

}; 

} // namespace lfc
#endif //__RULP_UTILS_FORMAT_UTIL_H__