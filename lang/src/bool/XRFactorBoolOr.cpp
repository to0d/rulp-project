// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorBoolOr)

  auto it = args->listIterator(1);
  while(it->hasNext()){
    if(RulpUtil::asBoolean(interpreter->compute(frame, it->next()))->asBoolean()){
      return O_True;
    }
  }

  return O_False;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorBoolOr, F_B_OR);
} // namespace lfc