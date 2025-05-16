// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorToFloat)

  auto obj = interpreter->compute(frame, args->get(1));
  if (TYPE_INDEX_OF(obj) == E_FLOAT) {
    return obj;
  }

  AUTO_INC_DEC(obj);  
  return RulpFactory::createFloat(RulpUtil::toFloat(obj));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorToFloat, F_TO_FLOAT);

} // namespace lfc