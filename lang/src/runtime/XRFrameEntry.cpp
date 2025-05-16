// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFrameEntry.h" 
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "lfc/base/auto/auto_free.h"
#include <iostream>

using namespace lfc;

namespace lfc {
 
XRFrameEntry::XRFrameEntry(int entryId, IRFrame* frame, StrConstRef name, IRObject* object) {
  this->entryId = entryId;
  this->frame   = frame;
  this->name    = name;
  this->object  = object;

  // if(name == "?value")

  // std::cout << "create frame member: name=" << name << ", frame=" << frame->getFrameName() << ", addr=" << this << "\n";
}

XRFrameEntry::~XRFrameEntry(){
  LFC_FREE(aliasNames);

  // if(name == "o1")
  // std::cout << "delete frame member: name=" << name << ", frame=" << frame->getFrameName() << ", addr=" << this << "\n";
}

const std::string& XRFrameEntry::asString() const {

  if (_string.empty()) {

    if(frame == NULL){
      _string += "null";
    }
    else {
      _string += frame->asString();
    }

    _string += "::";
    _string += name;
  }

  return _string;
}

RAccessType XRFrameEntry::getAccessType() const {
  return RAccessType::PUBLIC;
}

const StrList* XRFrameEntry::getAliasName() const {
  return aliasNames;
}

int XRFrameEntry::getEntryId() const {
  return entryId;
}

IRFrame* XRFrameEntry::getFrame() const {
  return frame;
}

std::string XRFrameEntry::getName() const {
  return name;
}

IRObject* XRFrameEntry::getObject() const {
  return object;
}

int XRFrameEntry::getProperty() const {
  return 0;
}

IRObject* XRFrameEntry::getSubject() const {
  return frame;
}

RType XRFrameEntry::getType() const {
  return T_MEMBER;
}

IRObject* XRFrameEntry::getValue() const {
  return object;
}

void XRFrameEntry::addAliasName(StrConstRef aliasName){
  if (aliasNames == null) {
    aliasNames = new std::vector<std::string>();
  }

  aliasNames->push_back(aliasName);
}

void XRFrameEntry::setAccessType(RAccessType accessType) {
  assert(false && "unable to update accessType for frame entry");
}

void XRFrameEntry::setObject(IRObject* object) {
  this->object = object;
}

void XRFrameEntry::setProperty(int property) {
  assert(false && "unable to set property for frame entry");
}

} // namespace lfc