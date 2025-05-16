// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRulpObjectCount)

  auto type = RRType::toType(AS_ATOM(interpreter->compute(frame, args->get(1)))->asString());
  int count = RULP_GET_OBJ_CREATE_COUNT(type) - RULP_GET_OBJ_DELETE_COUNT(type);
  return RulpFactory::createInteger(count);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRulpObjectCount, F_RULP_OBJ_COUNT);

} // namespace lfc