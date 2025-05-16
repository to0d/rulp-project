// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorThrow)

  int size = args->size();

  auto errId = AS_ATOM(interpreter->compute(frame, args->get(1)));
  IRObject* errValue = null;
  if (size == 3) {
    errValue = interpreter->compute(frame, args->get(2));
  }

  return RulpUtil::throw_error(interpreter, frame, errId, errValue, this);

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorThrow, F_THROW);

} // namespace lfc
