// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

static boolean matchCaseValue(IRObject* value, IRObject* caseValue) {

  if (TYPE_INDEX_OF(caseValue) == E_ATOM && caseValue->asString() == A_QUESTION) {
    return true;
  }

  if (RulpUtil::equal(value, caseValue)) {
    return true;
  }

  if (TYPE_INDEX_OF(caseValue) == E_LIST) {

    auto it = AS_LIST(caseValue)->iterator();
    while (it->hasNext()) {
      if (RulpUtil::equal(value, it->next())) {
        return true;
      }
    }
  }

  return false;
}

XRFACTOR_IMPL_BEGIN(XRFactorCase)

  ROH value = interpreter->compute(frame, args->get(1));

  auto it = args->listIterator(2);
  while (it->hasNext()) {

    auto caseClause = AS_EXPR(it->next());
    if (caseClause->size() != 2) {
      throw RException("Invalid case clause: " + caseClause->asString());
    }

    auto caseValue = interpreter->compute(frame, caseClause->get(0));
    if (matchCaseValue(value, caseValue)) {
      return interpreter->compute(frame, caseClause->get(1));
    }
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorCase, F_CASE);

} // namespace lfc
