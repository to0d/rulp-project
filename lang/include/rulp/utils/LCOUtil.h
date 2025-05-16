// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_LCO_UTIL_H__
#define __RULP_UTILS_LCO_UTIL_H__

#include "rulp/object/IRParaAttr.h"
namespace lfc {

class LCOUtil{
public:

  static int getArgCount();
  
  static int getHitCount();
  
  static int getPassCount();
  
  static int getRebuildCount();

  static void incHitCount();

  static void incPassCount();

  static boolean rebuild(const std::vector<IRParaAttr*>& paras);

  static void reset();

};

} // namespace lfc
#endif //__RULP_UTILS_LCO_UTIL_H__