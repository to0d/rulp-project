// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/system.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSystemTime)

  if (args->size() > 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  return RulpFactory::createLong(SYS_TIME);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSystemTime, F_SYS_TIME);

} // namespace lfc