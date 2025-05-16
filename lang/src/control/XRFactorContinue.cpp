// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorContinue)

  throw RExceptionContinue(this, frame);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorContinue, F_CONTINUE);

} // namespace lfc
