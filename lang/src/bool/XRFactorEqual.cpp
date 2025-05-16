// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorEqual)
  
  auto a = interpreter->compute(frame, args->get(1));
  auto b = interpreter->compute(frame, args->get(2));

  return RulpUtil::equal(a, b) ? O_True : O_False;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorEqual, F_EQUAL_DEFAULT);
} // namespace lfc