// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorValueTypeOf)

  ROH obj = interpreter->compute(frame, args->get(1));
  return toObject(obj.get()->getType()->getIndex());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorValueTypeOf, F_VALUE_TYPE_OF);

} // namespace lfc