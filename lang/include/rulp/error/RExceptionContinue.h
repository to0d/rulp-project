// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_CONTINUE_H__
#define __RULP_ERROR_REXCEPTION_CONTINUE_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionContinue 
  : public RExceptionI 
{

public:
 
  RExceptionContinue(IRObject* fromObject, IRFrame* fromFrame) : RExceptionI(fromObject, fromFrame){};
  RExceptionContinue(const RExceptionContinue& E) : RExceptionI(E) {}
  RExceptionContinue(RExceptionContinue&& E) : RExceptionI(E) {}

  virtual ~RExceptionContinue() {}
  
};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_CONTINUE_H__