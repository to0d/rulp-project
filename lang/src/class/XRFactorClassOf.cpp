// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/ClassUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorClassOf)

  return ClassUtil::findClass(args->get(1), frame);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorClassOf, F_CLASS_OF);

} // namespace lfc
