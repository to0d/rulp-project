// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorToNamedList)

  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  ROH name = interpreter->compute(frame, args->get(1));
  ROH list = interpreter->compute(frame, args->get(2));

  return RulpUtil::toNamedList(name, list, frame);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorToNamedList, F_TO_NAMED_LIST);

} // namespace lfc