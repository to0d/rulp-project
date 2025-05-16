// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRNoClass.h"
#include "lfc/base/to_string.h"
#include "rulp/lang.h"
#include "rulp/utils/RulpFactory.h"

namespace lfc {

XRNoClass::XRNoClass(StrConstRef className, IRFrame* definedFrame) 
  : className(className)
  , definedFrame(definedFrame)
{
  classTypeAtom = RulpFactory::createAtom(A_TYPE + className);
}

void XRNoClass::addLoader(ISubjectLoader* loader) {
  throw RException("Can't operation");
}

const std::string& XRNoClass::asString() const {
  return className;  
}

StrConstRef XRNoClass::getClassName() const {
  return className;
}

IRAtom* XRNoClass::getClassTypeAtom() const {
  return classTypeAtom;
}

int XRNoClass::getLevel() const {
  return 0;
}

IRMember* XRNoClass::getMember(StrConstRef name) {
  return null;
}

IRMember* XRNoClass::getMember(int idx) const {
  return null;
}

int XRNoClass::getMemberCount() const {
  return 0;
}

IRSubject* XRNoClass::getParent() const {
  return null;
}

IRFrame* XRNoClass::getSubjectFrame() {
  return definedFrame;
}

std::string XRNoClass::getSubjectName() const {
  return className;
}

IRClass* XRNoClass::getSuperClass() const {
  return null;
}

RType XRNoClass::getType() const {
  return T_CLASS;
}

boolean XRNoClass::hasMember(StrConstRef name) const {
  return false;
}

boolean XRNoClass::hasSubjectFrame() const {
  return true;
}

boolean XRNoClass::isConst() const {
  return true;
}

boolean XRNoClass::isFinal() const {
  return true;
}

IRInstance* XRNoClass::newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  return RulpFactory::createInstanceOfDefault(this, instanceName, getSubjectFrame());
}

void XRNoClass::setFinal(boolean bFinal) {
  throw RException("Can't operation");
}

void XRNoClass::setMember(StrConstRef name, IRMember* mbr) {
  throw RException("Can't operation");  
}

} // namespace lfc