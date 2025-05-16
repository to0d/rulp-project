// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRStringRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"
#include <iostream>

namespace lfc {

XRStringRef::XRStringRef(){
  
}

XRStringRef::XRStringRef(StrConstRef value) : value(value){
  // std::cout << "create string: value=" << value << ", addr=" << this << "\n";
}

 XRStringRef::~XRStringRef() {
  // std::cout << "delete string: value=" << value << ", addr=" << this << "\n";
 }

RType XRStringRef::getType() const {
  return T_STRING;
}

const std::string& XRStringRef::asString() const{
  return value;
}

} // namespace lfc