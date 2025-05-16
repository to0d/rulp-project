// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorIsStable)

  return RulpFactory::createBoolean(AttrUtil::isStable(args->get(1), frame));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorIsStable, F_IS_STABLE);

} // namespace lfc
