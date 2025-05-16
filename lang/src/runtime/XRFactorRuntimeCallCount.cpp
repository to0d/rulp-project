// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRuntimeCallCount)

  auto obj = RulpUtil::lookup(args->get(1), interpreter, frame);
  if (!IS_CALLABLE(obj)) {
    throw RException("not callable object: " + obj->asString());
  }

  return RulpFactory::createInteger(AS_CALL(obj)->getCallCount(RuntimeUtil::getCallStatsId())->getTotalCount());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRuntimeCallCount, F_RUNTIME_CALL_COUNT);

} // namespace lfc