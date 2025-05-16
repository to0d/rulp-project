// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorDo)

  RFH doFrame = RulpFactory::createFrame(frame, A_DO);
  auto it = args->listIterator(1);
  while (it->hasNext()) {
    interpreter->compute(doFrame, it->next());
  }

  return O_Nil;


XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDo, A_DO);

} // namespace lfc
