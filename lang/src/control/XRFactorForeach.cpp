// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include <iostream>

namespace lfc {

static boolean isForeachParaList(IRObject* obj) {

  if (TYPE_INDEX_OF(obj) != E_EXPR) {
    return false;
  }

  auto list = AS_LIST(obj);

  return list->size() == 2 && RulpUtil::isVarAtom(list->get(0));
}

static IRObject* getResultObject(IRList* args, IRInterpreter* interpreter, IRFrame* frame, IRFrame* rtFrame) {

  try {

    IRObject* rstObj = null;
    auto iter = args->listIterator(2);
    while (iter->hasNext()) {
      rstObj = interpreter->compute(frame, iter->next());
    }
    return rstObj;

  }
  catch (RExceptionReturn& r) {
    // std::cout << "return: \n";
    auto rst = r.returnValue(rtFrame);
    // std::cout << rst->asString() << "\n";
    return rst;
  }
  catch (RExceptionContinue& c) {
    return O_Nan;
  }
}

static IRObject* _do_foreach(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  // std::cout << "_do_foreach: " << args->asString() << "\n";

  auto doFrame = RulpFactory::createFrame(frame, A_DO);
  AUTO_RLS_FRAME(doFrame);

  return getResultObject(args, interpreter, doFrame, frame);
}

XRFACTOR_IMPL_BEGIN(XRFactorForeach)

  // (foreach (var cond) (action))

  if (!isForeachParaList(args->get(1))) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto paraObj = AS_LIST(args->get(1));
  auto factorFrame = RulpFactory::createFrame(frame, F_FOREACH);
  AUTO_RLS_FRAME(factorFrame);

  auto rstList = RulpFactory::createVaryList();

  auto var = RuntimeUtil::addVar(frame, AS_ATOM(paraObj->get(0))->getName());

  auto cond = interpreter->compute(factorFrame, paraObj->get(1));
  AUTO_INC_DEC(cond);

  try {

    switch (TYPE_INDEX_OF(cond)) {
    case E_LIST: {

      auto iter = AS_LIST(cond)->iterator();
      while (iter->hasNext()) {
        var->setValue(iter->next());
        auto rst = _do_foreach(args, interpreter, factorFrame);
        if (rst != null && rst != O_Nan) {
          rstList->add(rst);
        }
      }

      break;
    }

    case E_ARRAY: {

      auto arr = AS_ARRAY(cond);
      int size = arr->size();
      for (int i = 0; i < size; ++i) {
        var->setValue(arr->get(i));
        auto rst = _do_foreach(args, interpreter, factorFrame);
        if (rst != null && rst != O_Nan) {
          rstList->add(rst);
        }
      }

      break;
    }

    case E_ATOM: {

      var->setValue(cond);
      auto rst = getResultObject(args, interpreter, factorFrame, factorFrame);
      if (rst != O_Nan) {
        rstList->add(rst);
      }

      break;
    }

    default:
      throw RException("Not support cond type: " + cond->asString());
    }

  } 
  catch (RExceptionBreak& b) {
    // break the loop
  } 

  return rstList;

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorForeach, F_FOREACH);

} // namespace lfc
