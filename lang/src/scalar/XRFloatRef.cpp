// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFloatRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRFloatRef::XRFloatRef(float value)
: value(value)
{}

const std::string& XRFloatRef::asString() const {
  if(_string.empty() ){
    _string = RulpUtil::formatFloat(value);
  }

  return _string;
}

float XRFloatRef::asFloat() const {
  return value;
}

RType XRFloatRef::getType() const {
  return T_FLOAT;
}


} // namespace lfc