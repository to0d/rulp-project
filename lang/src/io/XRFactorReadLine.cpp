// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorReadLine)

  return RulpFactory::createString(interpreter->read());

XRFACTOR_IMPL_ARG(1, 1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorReadLine, F_READ_LINE);

} // namespace lfc