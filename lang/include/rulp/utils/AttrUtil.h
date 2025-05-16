// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_ATTR_UTIL_H__
#define __RULP_UTILS_ATTR_UTIL_H__

#include "rulp/object/IRAtom.h"
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRClass.h"
#include "rulp/object/IRParaAttr.h"
#include "rulp/runtime/IRFunction.h"
namespace lfc {

class AttrUtil{
public:
  
  static void           addAttribute(IRObject* obj, StrConstRef key);
  static std::vector<IRParaAttr*> buildAttrList(IRObject* paraObj, IRInterpreter* interpreter, IRFrame* frame);
  static boolean        containAttribute(IRObject* obj, StrConstRef attr);
  static IRObject*      getAttributeValue(IRObject* obj, StrConstRef key);
  static const StrList& getAttributeKeyList(IRObject* obj);
  static boolean        hasAttributeList(IRObject* obj);
  static boolean        isConst(IRObject* obj, IRFrame* frame);
  static boolean        isRecursive(IRFunction* func);
  static boolean        isStable(IRObject* obj, IRFrame* frame);
  static void           removeAllAttributes(IRObject* obj);
  static IRObject*      removeAttribute(IRObject* obj, StrConstRef attr);
  static void           setAttribute(IRObject* obj, StrConstRef key, IRObject* value);
  static std::string    toValidAttribute(StrConstRef attr);

}; 

} // namespace lfc
#endif //__RULP_UTILS_ATTR_UTIL_H__