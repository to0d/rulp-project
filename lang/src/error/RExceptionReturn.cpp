// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/error/RExceptionReturn.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RulpUtil.h"
#include <iostream>

using namespace lfc;

namespace lfc {

RExceptionReturn::RExceptionReturn(IRObject* fromObject, IRFrame* fromFrame, IRObject* rtValue) 
  : RExceptionI(fromObject, fromFrame)
  , rtValue(rtValue)
{
  RULP_INC_REF(rtValue);
};

RExceptionReturn::RExceptionReturn(const RExceptionReturn& E)
  : RExceptionI(E)
  , rtValue(E.rtValue)
{
  RULP_INC_REF(rtValue);
}

RExceptionReturn::RExceptionReturn(RExceptionReturn&& E)
  : RExceptionI(E)
  , rtValue(E.rtValue)
{
  E.rtValue = NULL;
}

RExceptionReturn::~RExceptionReturn() {
  RULP_DEC_REF(rtValue);
}

IRObject* RExceptionReturn::returnValue(IRFrame* frame){
  auto returnValue = this->rtValue;

  if (returnValue != null && returnValue != O_Nan) {

    auto returnVar = frame->findLocalObject(A_RETURN_VAR);
    if (returnVar == null) {
      returnVar = RulpFactory::createVar(A_RETURN_VAR);
      frame->setEntry(A_RETURN_VAR, returnVar);
    }

    // std::cout << "rv: " << returnValue->asString() << ", ref=" << returnValue->getRef() << "\n";
    
    RulpUtil::asVar(returnVar)->setValue(returnValue);
    
    RULP_DEC_REF(rtValue);
    this->rtValue = null;
  }

  return returnValue;
}


} // namespace lfc