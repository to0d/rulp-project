// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorToExpr)

  auto obj = interpreter->compute(frame, args->get(1));
  if (TYPE_INDEX_OF(obj) != E_LIST) {
    return RulpFactory::createExpression({obj});
  }

  auto list = AS_LIST(obj);

  return RulpFactory::createExpression(list, list->iterator());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorToExpr, F_TO_EXPR);

} // namespace lfc