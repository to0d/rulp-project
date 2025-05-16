// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

static boolean _isCatchExpr(IRExpr* expr) {
  return expr->size() >= 3 && RulpUtil::isAtom(expr->get(0), A_CATCH) && TYPE_INDEX_OF(expr->get(1)) == E_ATOM;
}

static void _addCatchExpr(IRFrame* tryFrame, IRExpr* expr) {

  // (e1 (action1) (action2))
  auto errId = AS_ATOM(expr->get(1));

  if (RulpUtil::isVarAtom(errId)) {

    tryFrame->setEntry(C_HANDLE_ANY, expr);

    // Save default error id
    tryFrame->setEntry(C_ERROR_DEFAULT, errId);

  } 
  else {
    tryFrame->setEntry(C_HANDLE + errId->getName(), expr);
  }

}

XRFACTOR_IMPL_BEGIN(XRFactorTry)

  int size = args->size();

  auto tryFrame = RulpFactory::createFrame(frame, F_TRY);
  AUTO_RLS_FRAME(tryFrame);
  
  int stmtEnd = size - 1;

  try {


    int catchCount = 0;

    while (stmtEnd > 0) {

      auto expr = AS_EXPR(args->get(stmtEnd));
      if (!_isCatchExpr(expr)) {
        break;
      }

      _addCatchExpr(tryFrame, expr);
      stmtEnd--;
      catchCount++;
    }

    if (stmtEnd == 0) {
      throw RException("no action expr: " + args->asString());
    }

    if (catchCount == 0) {
      throw RException("no catch expr: " + args->asString());
    }

    IRObject* rst = O_Nil;

    for (int i = 1; i <= stmtEnd; ++i) {
      rst = interpreter->compute(tryFrame, args->get(i));
    }

    return rst;

  }
  catch (const RExceptionError& err) {

    auto rst = RulpUtil::handle_error(err.getError(), interpreter, tryFrame);
    if (rst == null) {
      throw err;
    }

    return rst;

  }

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorTry, F_TRY);

} // namespace lfc
