// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFunctionLambda.h" 
#include "rulp/lang/RException.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/ReturnTypeUtil.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"

using namespace lfc;

namespace lfc {

void XRFunctionLambda::_delete() {
  if (definedFrame != null) {
    RULP_DEC_REF(definedFrame);
    definedFrame = null;
  }

  if (func != null) {
    RULP_DEC_REF(func);
    func = null;
  }

  AbsFunctionAdapter::_delete();
}

XRFunctionLambda::XRFunctionLambda(IRFunction* func, IRFrame* definedFrame, int lambdaId) 
  : func(func)
  , definedFrame(definedFrame)
  , lambdaId(lambdaId)
{
  RULP_INC_REF(func);
  RULP_INC_REF(definedFrame);
}

IRObject* XRFunctionLambda::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame){
	return func->compute(args, interpreter, definedFrame);
}

IRFunction* XRFunctionLambda::clone() const {

  XRFunctionLambda* newLambda = new XRFunctionLambda(func, definedFrame, lambdaId);
  RULP_INC_OBJ_CREATE_COUNT(T_FUNC);

  return newLambda;
}



} // namespace lfc