// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRLongGlobal.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRLongGlobal::XRLongGlobal()
  : value(0)
{}

XRLongGlobal::XRLongGlobal(RLong value)
  : value(value)
{}

RLong XRLongGlobal::asLong() const {
  return value;
}

RType XRLongGlobal::getType() const {
  return T_LONG;
}

const std::string& XRLongGlobal::asString() const{
  return _string;
}

void XRLongGlobal::setValue(long value){
  this->value = value;
}

void XRLongGlobal::setString(std::string str){
  this->_string = str;
}

} // namespace lfc