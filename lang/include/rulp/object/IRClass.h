// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRCLASS_H__
#define __RULP_LANG_IRCLASS_H__
#include "rulp/object/IRObject.h"
#include "rulp/object/IRSubject.h"
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRList.h"

namespace lfc {

class IRClass 
  : virtual public IRObject
  , virtual public IRSubject
{

public:

  virtual StrConstRef getClassName() const = 0;

  virtual IRAtom* getClassTypeAtom() const = 0;

  virtual IRClass* getSuperClass() const = 0;

  virtual boolean isConst() const = 0;

  virtual IRInstance* newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRCLASS_H__