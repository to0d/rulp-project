// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRIntegerRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRIntegerRef::XRIntegerRef()
  : value(0)
{}

XRIntegerRef::XRIntegerRef(int value)
  : value(value)
{}

int XRIntegerRef::asInteger() const {
  return value;
}

RType XRIntegerRef::getType() const {
  return T_INT;
}

const std::string& XRIntegerRef::asString() const{
  if( _string.empty() ){
    _string = RulpUtil::formatInt(value);
  }

  return _string;
}

} // namespace lfc