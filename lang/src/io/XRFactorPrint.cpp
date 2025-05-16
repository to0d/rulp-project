// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorPrint)

  auto iter = args->listIterator(1);
  while (iter->hasNext()) {
    ROH rst = interpreter->compute(frame, iter->next());
    if (TYPE_INDEX_OF(rst.get()) == E_INSTANCE) {
      ROH str = RulpUtil::toString(rst, interpreter);
      interpreter->write(str.get()->asString());
    } 
    else {
      interpreter->write(RulpUtil::toStringPrint(rst));
    }
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(2, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrint, F_PRINT);

} // namespace lfc