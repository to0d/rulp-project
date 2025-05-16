// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRBooleanGlobal.h"
#include "rulp/lang/RGlobal.h"

namespace lfc {

XRBooleanGlobal::XRBooleanGlobal(bool value)
  : value(value)
{}

bool XRBooleanGlobal::asBoolean() const {
  return value;
}

const std::string& XRBooleanGlobal::asString() const {
  return _string;
}

RType XRBooleanGlobal::getType() const {
  return T_BOOL;
}

void XRBooleanGlobal::setString(std::string str){
  this->_string = str;
}

} // namespace lfc