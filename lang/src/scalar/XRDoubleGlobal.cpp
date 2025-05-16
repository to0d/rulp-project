// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRDoubleGlobal.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRDoubleGlobal::XRDoubleGlobal(double value)
: value(value)
{}

const std::string& XRDoubleGlobal::asString() const {
  return _string;
}

double XRDoubleGlobal::asDouble() const {
  return value;
}

RType XRDoubleGlobal::getType() const {
  return T_DOUBLE;
}

void XRDoubleGlobal::setString(std::string str){
  this->_string = str;
}

} // namespace lfc