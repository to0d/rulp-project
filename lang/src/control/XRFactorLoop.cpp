// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/to_string.h"

namespace lfc {

static IRIteratorPtr getLoop2DoList(IRList* args) {
  return args->listIterator(8);
}

static IRObject* getLoop2FromObject(IRList* args) {
  return args->get(4);
}

static IRObject* getLoop2IndexObject(IRList* args) {
  return args->get(2);
}

static IRObject* getLoop2ToObject(IRList* args) {
  return args->get(6);
}

static IRIteratorPtr getLoop3DoList(IRList* args) {
  return args->listIterator(1);
}

static IRObject* getLoop4ByObject(IRList* args) {
  return args->get(8);
}

static IRIteratorPtr getLoop4DoList(IRList* args) {
  return args->listIterator(10);
}

static IRObject* getLoop4FromObject(IRList* args) {
  return args->get(4);
}

static IRObject* getLoop4ToObject(IRList* args) {
  return args->get(6);
}

static void loop1(IRList* args, IRInterpreter* interpreter, IRFrame* loopFrame) {

  auto indexName  = RulpUtil::asAtom(args->get(2))->getName();
  auto values     = RulpUtil::asList(interpreter->compute(loopFrame, args->get(4)));
  AUTO_INC_DEC(values);

  IRIteratorPtr valIter = values->iterator();
  while (valIter->hasNext()) {

    loopFrame->setEntry(indexName, valIter->next());
    auto argIter = args->listIterator(6);

    RFH loopDoFrame = RulpFactory::createFrame(loopFrame, F_LOOP);

    try {

      while (argIter->hasNext()) {
        auto expr = argIter->next();
        if (TYPE_INDEX_OF(expr) != E_EXPR) {
          throw RException("Invalid expr in loop: " + expr->asString());
        }
      
        interpreter->compute(loopDoFrame, expr);
      }
    } 
    catch (RExceptionBreak& r) {
      break;
    } 
    catch (RExceptionContinue& c) {
      continue;
    } 
  }
}

static void loop2(IRList* args, IRInterpreter* interpreter, IRFrame* loopFrame) {

  // (loop for x from 1 to 3 do ...)

  auto indexName = RulpUtil::asAtom(getLoop2IndexObject(args))->getName();
  int fromIndex = RulpUtil::toInt(RulpUtil::asInteger(interpreter->compute(loopFrame, getLoop2FromObject(args))));
  int toIndex = RulpUtil::toInt(RulpUtil::asInteger(interpreter->compute(loopFrame, getLoop2ToObject(args))));

  for (int i = fromIndex; i <= toIndex; ++i) {

    loopFrame->setEntry(indexName, RulpFactory::createInteger(i));
    IRIteratorPtr iter = getLoop2DoList(args);

    RFH loopDoFrame = RulpFactory::createFrame(loopFrame, F_LOOP);

    try {

      while (iter->hasNext()) {

        auto expr = iter->next();
        if (TYPE_INDEX_OF(expr) != E_EXPR) {
          throw RException("Invalid expr in loop: " + expr->asString());
        }

        interpreter->compute(loopDoFrame, expr);
      }

    } 
    catch (RExceptionBreak& r) {
      break;
    } 
    catch (RExceptionContinue& c) {
      continue;
    } 
  }
}

static void loop3(IRList* args, IRInterpreter* interpreter, IRFrame* loopFrame) {

  IRIteratorPtr iter = null;

  RFH loopDoFrame;

  while (true) {

    if (iter == null || !iter->hasNext()) {
      iter = args->listIterator(1); // skip head
      loopDoFrame = RulpFactory::createFrame(loopFrame, F_LOOP);
    }

    auto expr = iter->next();
    if (TYPE_INDEX_OF(expr) != E_EXPR) {
      throw RException("Invalid expr in loop: " + expr->asString());
    }

    try {
      interpreter->compute(loopDoFrame, expr);
    } 
    catch (RExceptionBreak& r) {
      break;
    } 
    catch (RExceptionContinue& c) {
      continue;
    }
  }

}

static void loop4(IRList* args, IRInterpreter* interpreter, IRFrame* loopFrame) {

  // (loop for x from 1 to 3 by 1 do ...) A_By

  auto indexName = RulpUtil::asAtom(args->get(2))->getName();
  int fromIndex = RulpUtil::toInt(RulpUtil::asInteger(interpreter->compute(loopFrame, getLoop4FromObject(args))));
  int toIndex = RulpUtil::toInt(RulpUtil::asInteger(interpreter->compute(loopFrame, getLoop4ToObject(args))));
  int byValue = RulpUtil::toInt(RulpUtil::asInteger(interpreter->compute(loopFrame, getLoop4ByObject(args))));
  if (byValue == 0) {
    throw RException("Invalid by value in loop: " + TO_STR(byValue));
  }

  boolean add = byValue > 0;
  int i = fromIndex;

   while (true) {

    if (add) {
      if (i > toIndex) {
        break;
      }
    } 
    else {
      if (i < toIndex) {
        break;
      }
    }

    loopFrame->setEntry(indexName, RulpFactory::createInteger(i));
    IRIteratorPtr iter = getLoop4DoList(args);

    RFH loopDoFrame = RulpFactory::createFrame(loopFrame, F_LOOP);

    try {

      while (iter->hasNext()) {

        auto expr = iter->next();
        if (TYPE_INDEX_OF(expr) != E_EXPR) {
          throw RException("Invalid expr in loop: " + expr->asString());
        }

        interpreter->compute(loopDoFrame, expr);
      }

      i += byValue;

    } 
    catch (RExceptionBreak& r) {
      break;
    } 
    catch (RExceptionContinue& c) {
      continue;
    } 
  }
}


XRFACTOR_IMPL_BEGIN(XRFactorLoop)

  RFH loopFrame = RulpFactory::createFrame(frame, F_LOOP);

  // (loop for x in '(1 2 3) do (print x))
  if (RulpUtil::isLoop1(args)) {
    loop1(args, interpreter, loopFrame);
    return O_Nil;
  }

  // (loop for x from 1 to 3 do ...)
  if (RulpUtil::isLoop2(args)) {
    loop2(args, interpreter, loopFrame);
    return O_Nil;
  }

  // (loop stmt1 ...)
  if (RulpUtil::isLoop3(args)) {
    loop3(args, interpreter, loopFrame);
    return O_Nil;
  }

  // (loop for x from 1 to 3 by 1 do ...)
  if (RulpUtil::isLoop4(args)) {
    loop4(args, interpreter, loopFrame);
    return O_Nil;
  }

  throw RException("Invalid loop expr: " + args->asString());

XRFACTOR_IMPL_ARG(2, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorLoop, F_LOOP);

} // namespace lfc
