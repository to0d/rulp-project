// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/class/AbsRClass.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

namespace lfc {

AbsRClass::AbsRClass(StrConstRef className, IRFrame* definedFrame, IRClass* superClass)
  : AbsRSubject(definedFrame)
  , className(className)
  , superClass(superClass)
{
  classTypeAtom = RulpFactory::createAtom(A_TYPE + className);
  RULP_INC_REF(classTypeAtom);
}

void AbsRClass::_delete() {

  if(classTypeAtom != null){
    RULP_DEC_REF(classTypeAtom);
    classTypeAtom = null;
  }

  AbsRSubject::_delete();
}

const std::string& AbsRClass::asString() const {
  return className;
}

StrConstRef AbsRClass::getClassName() const {
  return className;
}

IRAtom* AbsRClass::getClassTypeAtom() const {
  return classTypeAtom;
}

IRSubject* AbsRClass::getParent() const {
  return superClass;
}

std::string AbsRClass::getSubjectName() const {
  return getClassName();
}

IRClass* AbsRClass::getSuperClass() const {
  return superClass;
}

RType AbsRClass::getType() const {
  return T_CLASS;
}

boolean AbsRClass::isConst() const {
  return false;
}


} // namespace lfc