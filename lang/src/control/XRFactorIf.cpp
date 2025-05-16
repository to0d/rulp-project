// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {


XRFACTOR_IMPL_BEGIN(XRFactorIf)

  // (if condition true-expr)
  // (if condition true-expr false-expr)
  // (if condition do expr1 expr2 expr3 ...)

  // (if condition true-expr)
  if (RulpUtil::isIf1(args)) {

    // condition
    if (!RulpUtil::toBoolean(interpreter->compute(frame, args->get(1)))) {
      return O_Nil;
    }

    return interpreter->compute(frame, args->get(2));
  }

  // (if condition true-expr false-expr)
  if (RulpUtil::isIf2(args)) {

    // condition
    if (!RulpUtil::toBoolean(interpreter->compute(frame, args->get(1)))) {
      return interpreter->compute(frame, args->get(3));
    }

    return interpreter->compute(frame, args->get(2));
  }

  // (if condition do expr1 expr2 expr3 ...)
  if (RulpUtil::isIf3(args)) {

    ROH cond = interpreter->compute(frame, args->get(1));
    
    // condition
    if (!RulpUtil::toBoolean(cond)) {
      return O_Nil;
    }

    if (args->size() == 4) {
      return interpreter->compute(frame, args->get(3));
    }

    auto expr = RulpUtil::toDoExpr(args->listIterator(3));
    AUTO_INC_DEC(expr);

    return interpreter->compute(frame, expr);
  }

  throw RException("Invalid parameters: " + args->asString());

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorIf, F_IF);

} // namespace lfc
