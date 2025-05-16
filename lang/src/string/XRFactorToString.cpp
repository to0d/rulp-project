// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorToString)

  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto obj = interpreter->compute(frame, args->get(1));
  if(TYPE_INDEX_OF(obj) == E_STRING ){
    return obj;
  }

  AUTO_INC_DEC(obj);
  return RulpUtil::toString(obj, interpreter);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorToString, F_TO_STRING);

} // namespace lfc