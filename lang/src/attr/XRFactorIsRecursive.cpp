// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorIsRecursive)

  RListHandler RLH;

  auto obj = args->get(1);
  while (TYPE_INDEX_OF(obj) != E_FUNC) {

    switch (TYPE_INDEX_OF(obj)) {
    case E_EXPR: {
      obj = interpreter->compute(frame, obj);
      RLH.addResult(obj);
      break;
    }
    
    case E_ATOM: {
      auto obj2 = RulpUtil::lookup(obj, interpreter, frame);
      if (obj2 == obj) {
        throw RException("func not found: " + obj->asString());
      }
      RLH.addResult(obj);
      obj = obj2;
      break;
    }
    
    default:
      throw RException("not func: " + obj->asString());
    }

  }

  return RulpFactory::createBoolean(AttrUtil::isRecursive(RulpUtil::asFunction(obj)));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorIsRecursive, F_IS_RECURSIVE);

} // namespace lfc
