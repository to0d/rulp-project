// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRError.h"
#include "rulp/lang.h"


using namespace lfc;
using namespace lfc;

namespace lfc {

XRError::XRError(IRClass* noClass, IRAtom* id, IRObject* value)
 : AbsRInstance(noClass, id->getName(), null)
 , id(id)
 , value(value)
{
  RULP_INC_REF(id);
  RULP_INC_REF(value);
}

void XRError::_delete() {
  RULP_DEC_REF(id);
  RULP_DEC_REF(value);
  AbsRInstance::_delete();
}

XRError::~XRError() {

}


StrConstRef XRError::asString() const {

  if(_string.empty()){
    _string += A_ERROR;
    _string += ": ";
    _string += id->getName();
    _string += ", ";
    _string += value->asString();
  }

  return _string;
}

IRAtom* XRError::getId() const {
  return id;
}

IRObject* XRError::getValue() const {
  return value;
}

} // namespace lfc