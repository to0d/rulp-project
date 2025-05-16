// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "rulp/utils/TraceUtil.h"

namespace lfc {

static void printFrame(IRFrame* frame, int prtLevel, IRInterpreter* interpreter) {

  IRFrame* curframe = frame;

  if (prtLevel < 0) {
    prtLevel = frame->getLevel() + 1;
  }

  while (prtLevel > 0) {
    interpreter->write(TraceUtil::printFrame(curframe));
    interpreter->write("\n");
    curframe = curframe->getParentFrame();
    prtLevel--;
  }
}

static void printSubject(IRSubject* subject, int prtLevel, IRInterpreter* interpreter) {

  if (prtLevel < 0) {
    prtLevel = subject->getLevel() + 1;
  }

  IRSubject* curSubject = subject;

  while (prtLevel > 0 && curSubject != null) {
    interpreter->write(TraceUtil::printSubject(curSubject));
    interpreter->write("\n");
    curSubject = curSubject->getParent();
    prtLevel--;
  }
}

XRFACTOR_IMPL_BEGIN(XRFactorPrintSubject)

  int size = args->size();
  if (size == 1) {
    printFrame(frame, 1, interpreter);
    return O_Nil;
  }


  int prtLevel = 1;

  auto obj = interpreter->compute(frame, args->get(1));
  switch (TYPE_INDEX_OF(obj)) {
  case E_INT: {

    if (size != 2) {
      throw RException("Invalid parameters: " + args->asString());
    }

    prtLevel = AS_INT(obj)->asInteger();

    printFrame(frame, prtLevel, interpreter);
    break;
  }

  case E_FRAME: {

    if (size > 2) {
      prtLevel = AS_INT(interpreter->compute(frame, args->get(2)))->asInteger();
    }

    printFrame(AS_FRAME(obj), prtLevel, interpreter);
    break;
  }

  default: 

    if(!IS_SUBJECT(obj)) {
      throw RException("Invalid parameters: " + args->asString());
    }
 
    if (size > 2) {
      prtLevel = AS_INT(interpreter->compute(frame, args->get(2)))->asInteger();
    }

    printSubject(AS_SUBJECT(obj), prtLevel, interpreter);

    break;
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(-1, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintSubject, F_PRINT_SUBJECT);

} // namespace lfc