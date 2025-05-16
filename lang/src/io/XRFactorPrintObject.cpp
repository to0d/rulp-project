// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorPrintObject)

  ROH obj = args->get(1);

  interpreter->write(RulpUtil::toString(obj));

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintObject, F_PRINT_OBJECT);

} // namespace lfc