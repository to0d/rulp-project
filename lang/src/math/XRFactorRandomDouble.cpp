// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/random.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRandomDouble)

  if (args->size() != 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  return RulpFactory::createDouble(lfc::random_double());


XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRandomDouble, F_RANDOM_DOUBLE);
} // namespace lfc