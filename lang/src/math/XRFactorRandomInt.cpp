// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/random.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRandomInt)

  int size = args->size();

  int value = 0;

  if(size == 1) {
    value = lfc::random_int();
  }
  else {
    ROH obj = interpreter->compute(frame, args->get(1));
    int bound = AS_INT(obj.get())->asInteger();
    value =  lfc::random_int(bound);
  }

  return RulpFactory::createInteger(value);

XRFACTOR_IMPL_ARG(1, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRandomInt, F_RANDOM_INT);
} // namespace lfc