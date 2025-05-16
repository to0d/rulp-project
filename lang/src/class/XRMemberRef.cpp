// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRMemberRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"
#include <iostream>

namespace lfc {

void XRMemberRef::_delete() {

  // if(subject != null) {
  if(subject != null && TYPE_INDEX_OF(subject) == E_ATOM) {
    RULP_DEC_REF(subject);
    subject = null;
  }

  // RULP_DEC_REF(value);
  // value = null;

  AbsRefObject::_delete();
}

XRMemberRef::XRMemberRef(IRObject* subject, StrConstRef name, IRObject* value)
  : subject(subject)
  , value(value)
  , name(name)
{
  // if(subject != null) {
  if(subject != null && TYPE_INDEX_OF(subject) == E_ATOM) {  
    RULP_INC_REF(subject);
  }

  // std::cout << "create member: name=" << name << ", addr=" << this << "\n";
  
  // if(value) {
  //   RULP_INC_REF(value);
  // }
  // std::cout << "XRMemberRef: this=" << this->asString() 
  //           << ", subject=" << subject->asString() << ", id=" << subject->getType()->getIndex()
  //           << ", name=" << name
  //           << ", value=" << TO_STR(value) << "\n";
}

XRMemberRef::~XRMemberRef() {
  // std::cout << "delete member: name=" << name << ", addr=" << this << "\n";
}

RType XRMemberRef::getType() const {
  return T_MEMBER;
}

const std::string& XRMemberRef::asString() const{
  if( _string.empty() ){
    _string = subject->asString();
    _string += "::";
    _string += name;
  }

  return _string;
}

RAccessType XRMemberRef::getAccessType() const {
  return accessType;
}

IRObject* XRMemberRef::getSubject() const {
  return subject;
}

IRObject* XRMemberRef::getValue() const {
  return value;
}

int XRMemberRef::getProperty() const {
  return property;
}

std::string XRMemberRef::getName() const {
  return name;
}

void XRMemberRef::setAccessType(RAccessType accessType) {
  this->accessType = accessType;
}

void XRMemberRef::setProperty(int property) {
  this->property = property;
}

} // namespace lfc