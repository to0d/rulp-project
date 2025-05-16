// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

XRFACTOR_IMPL_BEGIN(XRFactorSetq)

  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  return RuntimeUtil::setVar(args->get(1), args->get(2), interpreter, frame);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSetq, F_SETQ);

} // namespace lfc
