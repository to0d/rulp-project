// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_CLASS_UTIL_H__
#define __RULP_UTILS_CLASS_UTIL_H__

#include "rulp/object/IRInstance.h"
#include "rulp/object/IRClass.h"
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class ClassUtil{
public:
  
  static IRClass*     findClass(IRObject* obj, IRFrame* frame);
  static IRInstance*  newInstance(IRList* args, IRInterpreter* interpreter, IRFrame* frame);

}; 

} // namespace lfc
#endif //__RULP_UTILS_CLASS_UTIL_H__