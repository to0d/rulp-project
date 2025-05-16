// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_LOAD_UTIL_H__
#define __RULP_UTILS_LOAD_UTIL_H__

#include "rulp/runtime/IRInterpreter.h"
#include "rulp/runtime/IRLoader.h"

namespace lfc {

class LoadUtil {
public:

  static void initSystemVars(IRInterpreter* interpreter, IRFrame* frame);

  static void initSystemScript(IRInterpreter* interpreter, IRFrame* frame);

  static void initSystemClass(IRInterpreter* interpreter, IRFrame* frame);
 
  static void initLoader(StrConstRef loaderName, IRInterpreter* interpreter, IRFrame* frame);

  static IRList* loadRulp(IRInterpreter* interpreter, IRFrame* frame, StrConstRef path, StrConstRef charset);

  static void loadScript(IRInterpreter* interpreter, IRFrame* frame, StrConstRef script);
  
  static void loadScript(IRInterpreter* interpreter, IRFrame* frame, StrConstRef path, StrConstRef charset);

  static std::string lookupFile(StrConstRef path, IRInterpreter* interpreter, IRFrame* frame);

};

} // namespace lfc
#endif //__RULP_UTILS_LOAD_UTIL_H__