// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorCompare)

  ROH a = interpreter->compute(frame, args->get(1));
  ROH b = interpreter->compute(frame, args->get(2));

  return RulpFactory::createInteger(RulpUtil::compare(a, b));

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorCompare, F_CMP_DEF);

} // namespace lfc