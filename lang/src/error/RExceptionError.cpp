// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/error/RExceptionError.h"
#include "lfc/base/auto/auto_free.h"
#include "rulp/utils/RulpUtil.h"
using namespace lfc;

namespace lfc {

RExceptionError::RExceptionError(IRObject* fromObject, IRFrame* fromFrame, IRError* err)
  : RException(fromObject)
  , fromFrame(fromFrame)
  , err(err)
{
  exceptionMessage = err->asString();
  RULP_INC_REF(err);
}

RExceptionError::RExceptionError(const RExceptionError& E) 
  : RException(E) 
  , fromFrame(E.fromFrame)
  , err(E.err)
{
  exceptionMessage = err->asString();
  RULP_INC_REF(err);
}

RExceptionError::~RExceptionError() {
  RULP_DEC_REF(err);
}

IRError* RExceptionError::getError() const {
  return err;
}

IRFrame* RExceptionError::getFromFrame() const {
  return fromFrame;
}

} // namespace lfc