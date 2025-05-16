// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSeta)

  auto obj1 = interpreter->compute(frame, args->get(1));
  auto obj2 = interpreter->compute(frame, args->get(2));
  auto obj3 = interpreter->compute(frame, args->get(3));

  auto arr   = AS_ARRAY(obj1);
  auto index = AS_INT(obj2)->asInteger();

  arr->set(index, obj3);

  return arr;

XRFACTOR_IMPL_ARG(4, 4)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSeta, F_SETA);

} // namespace lfc
