// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRLongRef.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRLongRef::XRLongRef()
  : value(0)
{}

XRLongRef::XRLongRef(RLong value)
  : value(value)
{}

RLong XRLongRef::asLong() const {
  return value;
}

RType XRLongRef::getType() const {
  return T_LONG;
}

const std::string& XRLongRef::asString() const{
  if( _string.empty() ){
    _string = RulpUtil::formatLong(value);
  }

  return _string;
}

} // namespace lfc