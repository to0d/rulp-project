// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorBoolNot)

  return RulpFactory::createBoolean(!AS_BOOL(interpreter->compute(frame, args->get(1)))->asBoolean());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorBoolNot, F_B_NOT);
} // namespace lfc