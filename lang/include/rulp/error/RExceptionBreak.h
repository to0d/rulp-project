// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_BREAK_H__
#define __RULP_ERROR_REXCEPTION_BREAK_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionBreak 
  : public RExceptionI 
{

public:
 
  RExceptionBreak(IRObject* fromObject, IRFrame* fromFrame) : RExceptionI(fromObject, fromFrame){};
  RExceptionBreak(const RExceptionBreak& E) : RExceptionI(E) {}
  RExceptionBreak(RExceptionBreak&& E) : RExceptionI(E) {}

  virtual ~RExceptionBreak() {}
  
};


} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_BREAK_H__