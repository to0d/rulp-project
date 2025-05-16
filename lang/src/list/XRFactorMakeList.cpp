// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorMakeList)

  auto varList = RulpFactory::createVaryList();
  RulpUtil::addAll(varList, args->listIterator(1));
  return varList;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorMakeList, F_MAKE_LIST);

} // namespace lfc