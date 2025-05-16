// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/class/AbsRInstance.h"
#include "rulp/lang.h"
#include "rulp/utils/SubjectUtil.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace lfc;
using namespace lfc;

namespace lfc {

AbsRInstance::AbsRInstance()
{
  instanceName = RulpUtil::getNextUnusedName();
  // std::cout << "create instance: name=" << instanceName << ", addr=" << this << "\n";
}

AbsRInstance::AbsRInstance(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame) 
  : AbsRSubject(definedFrame)
  , rClass(rClass)
{
  this->instanceName = instanceName.empty() ? RulpUtil::getNextUnusedName() : instanceName;
  RULP_INC_REF(rClass);
  // std::cout << "create instance: name=" << this->instanceName << ", addr=" << this << "\n";
}

void AbsRInstance::_delete() {
  RULP_DEC_REF(rClass);
  AbsRSubject::_delete();
}

StrConstRef AbsRInstance::asString() const {

  // return instanceName;

  if(_toString.empty()){
    std::string className = (rClass == null ? "nil" : rClass->getClassName());
		_toString = className + "@" + instanceName;
  }

  return _toString;
}

void AbsRInstance::deleteIt(IRInterpreter* interpreter, IRFrame* frame) {
  
  if (!isDeleted()) {
    ref = 0; // force deleted
    _delete();
  }
}

std::string AbsRInstance::getInstanceName() const {
  return instanceName;
}

IRMember* AbsRInstance::getMember(StrConstRef name) {
  if (name.empty()) {
    return null;
  }

  // Instance local member
  auto objMbr = AbsRSubject::getMember(name);
  if (objMbr == null && rClass != null) {
    objMbr = SubjectUtil::getClassMember(this, rClass, name);
    if (objMbr != null) {
      this->setMember(name, objMbr);
    }
  }

  return objMbr;
}

IRSubject* AbsRInstance::getParent() const {
  return rClass;
}

IRClass* AbsRInstance::getRClass() const {
  return rClass;
}

std::string AbsRInstance::getSubjectName() const {
  return instanceName;
}

RType AbsRInstance::getType() const {
  return T_INSTANCE;
}

void AbsRInstance::init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

}

void AbsRInstance::setRClass(IRClass* rClass) {
  this->rClass = rClass;
}

} // namespace lfc