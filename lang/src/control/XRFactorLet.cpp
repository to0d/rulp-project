// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorLet)

  auto varList = AS_EXPR(args->get(1));
  if ((varList->size() % 2) != 0) {
    throw RException("Invalid parameters: " + args->asString());
  }

  RFH letFrame = RulpFactory::createFrame(frame, F_LET);

  if (varList->size() > 0) {
    auto it = varList->iterator();
    while (it->hasNext()) {
      auto varName  = (RulpUtil::asAtom(it->next()))->getName();
      auto var      = RulpFactory::createVar(varName);
      letFrame.get()->setEntry(varName, var);
      auto val = interpreter->compute(letFrame, it->next());
      var->setValue(val);
    }
  }

  auto it = args->listIterator(2);
  IRObject* rst = O_Nil;
  while (it->hasNext()) {
    rst = interpreter->compute(letFrame, it->next());
  }

  return rst;

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorLet, F_LET);

} // namespace lfc