// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorDefConst)

  auto constantName = AS_ATOM(args->get(1))->getName();
  ROH valObj = interpreter->compute(frame, args->get(2));

  auto entry = frame->getEntry(constantName);
  if (entry != null && entry->getFrame() == frame) {
    throw RException("duplicate local variable: " + constantName);
  }

  switch (TYPE_INDEX_OF(valObj.get())) {
  case E_ARRAY:
  case E_ATOM:
  case E_BLOB:
  case E_BOOL:
  case E_DOUBLE:
  case E_FLOAT:
  case E_FUNC:
  case E_INSTANCE:
  case E_INT:
  case E_LIST:
  case E_LONG:
  case E_STRING:
    break;
  default:
    throw RException("invalid constant value: " + valObj.get()->asString());
  }

  auto constant = RulpFactory::createConstant(constantName, RulpUtil::toConst(valObj, frame));
  frame->setEntry(constantName, constant);

  return constant;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDefConst, F_DEF_CONST);

} // namespace lfc