// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorErrorValue)

  auto value = AS_ERROR(interpreter->compute(frame, args->get(1)))->getValue();
  return value == null ? O_Nil : value;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorErrorValue, F_E_ERROR_VALUE);

} // namespace lfc
