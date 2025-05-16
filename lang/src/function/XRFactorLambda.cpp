// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/to_string.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorLambda)

  /*****************************************************/
  // Parameter list
  /*****************************************************/
  auto paraObj = args->get(1);
  if (!RulpUtil::isPureAtomList(paraObj)) {
    throw RException("Invalid para type: " + paraObj->asString());
  }

  std::vector<IRParaAttr*> paraAttrs;
  auto iter = AS_LIST(paraObj)->iterator();
  while (iter->hasNext()) {
    paraAttrs.push_back(RulpFactory::createParaAttr(AS_ATOM(iter->next())->getName()));
  }

  /*****************************************************/
  // Function body
  /*****************************************************/
  IRExpr* funBody = null;
  if (args->size() == 3) {
    funBody = AS_EXPR(args->get(2));

  } 
  else if (args->size() > 3) {
    funBody = RulpUtil::toDoExpr(args->listIterator(2));

  } 
  else {
    throw RException("Invalid args size: " + TO_STR(args->size()));
  }

  return RulpFactory::createFunctionLambda(RulpFactory::createFunction(frame, F_LAMBDA, std::move(paraAttrs), funBody), frame);

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorLambda, F_LAMBDA);

} // namespace lfc