// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_SUBJECT_UTIL_H__
#define __RULP_UTILS_SUBJECT_UTIL_H__

#include "rulp/object/IRAtom.h"
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRClass.h"
namespace lfc {

class SubjectUtil{
public:

  static IRMember*  defineMemberFun(IRSubject* sub, StrConstRef mbrName, IRList* mbrExpr, IRInterpreter* interpreter, IRFrame* frame);

  static IRVar*     defineMemberVar(IRMember* mbrObj, IRObject* val, IRInterpreter* interpreter, IRFrame* frame);

  static void       defineMemberVar(IRSubject* sub, IRList* mbrExpr, IRInterpreter* interpreter, IRFrame* frame);

  static IRClass*   findMatchClass(IRInstance* instance, IRAtom* classAtom);

  static IRMember*  getClassMember(IRInstance* instance, IRClass* rClass, StrConstRef name);

  static IRMember*  lookUpMember(IRSubject* subject, StrConstRef name);
};

} // namespace lfc
#endif //__RULP_UTILS_SUBJECT_UTIL_H__