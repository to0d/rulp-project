// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRConstRef.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRConstRef::XRConstRef(StrConstRef varName, IRObject* value)
  : varName(varName)
  , value(value)
{
  RULP_INC_REF(value);
}

const std::string& XRConstRef::asString() const {

  if(_asString.empty()){
    _asString = varName + ":\"" + value->asString() + "\"";
  }

  return _asString;
}

RType XRConstRef::getType() const {
  return T_CONSTANT;
}

std::string XRConstRef::getName() const {
  return varName;
}

IRObject* XRConstRef::getValue() const {
  return value;
}

void XRConstRef::_delete(){
  if (value != null) {
    RULP_DEC_REF(value);
    value = null;
  }

  AbsRefObject::_delete();
}


} // namespace lfc