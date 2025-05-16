// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorCompute)

  auto obj = interpreter->compute(frame, args->get(1));
  AUTO_INC_DEC(obj);

	while (TYPE_INDEX_OF(obj) == E_EXPR) {
    obj = interpreter->compute(frame, obj);
  }

  return obj;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorCompute, F_COMPUTE);

} // namespace lfc
