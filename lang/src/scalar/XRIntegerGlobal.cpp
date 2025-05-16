// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRIntegerGlobal.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRIntegerGlobal::XRIntegerGlobal()
  : value(0)
{}

XRIntegerGlobal::XRIntegerGlobal(int value)
  : value(value)
{}

int XRIntegerGlobal::asInteger() const {
  return value;
}

RType XRIntegerGlobal::getType() const {
  return T_INT;
}

const std::string& XRIntegerGlobal::asString() const{
  return _string;
}

void XRIntegerGlobal::setValue(int value){
  this->value = value;
}

void XRIntegerGlobal::setString(std::string str){
  this->_string = str;
}

} // namespace lfc