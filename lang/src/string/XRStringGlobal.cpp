// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRStringGlobal.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRStringGlobal::XRStringGlobal()
  : value(0)
{}

XRStringGlobal::XRStringGlobal(StrConstRef value)
  : value(value)
{}


RType XRStringGlobal::getType() const {
  return T_STRING;
}

const std::string& XRStringGlobal::asString() const{
  return value;
}

} // namespace lfc