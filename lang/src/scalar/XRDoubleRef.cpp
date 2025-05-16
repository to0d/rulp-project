// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRDoubleRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRDoubleRef::XRDoubleRef(double value)
: value(value)
{}

const std::string& XRDoubleRef::asString() const {
  if(_string.empty() ){
    _string = RulpUtil::formatDouble(value);
  }

  return _string;
}

double XRDoubleRef::asDouble() const {
  return value;
}

RType XRDoubleRef::getType() const {
  return T_DOUBLE;
}


} // namespace lfc