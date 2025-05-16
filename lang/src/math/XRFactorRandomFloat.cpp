// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/random.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRandomFloat)

  return RulpFactory::createFloat(lfc::random_float());

XRFACTOR_IMPL_ARG(1, 1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRandomFloat, F_RANDOM_FLOAT);
} // namespace lfc