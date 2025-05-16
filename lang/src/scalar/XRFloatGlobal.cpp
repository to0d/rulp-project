// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFloatGlobal.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRFloatGlobal::XRFloatGlobal(float value)
: value(value)
{}

const std::string& XRFloatGlobal::asString() const {
  return _string;
}

float XRFloatGlobal::asFloat() const {
  return value;
}

RType XRFloatGlobal::getType() const {
  return T_FLOAT;
}

void XRFloatGlobal::setString(std::string str){
  this->_string = str;
}

} // namespace lfc