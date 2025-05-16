// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/opt.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorPrintTree)


  return O_Nil;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintTree, "xxx");

} // namespace lfc