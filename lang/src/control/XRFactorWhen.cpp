// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorWhen)

  auto cond = args->get(1);
  auto whenClause = interpreter->compute(frame, cond);

  // false
  if (!RulpUtil::toBoolean(whenClause)) {
    return O_Nil;
  }

  IRObject* rstClause = null;
  auto iter = args->listIterator(2);
  while (iter->hasNext()) {
    rstClause = interpreter->compute(frame, iter->next());
  }

  return rstClause;

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorWhen, F_WHEN);

} // namespace lfc
