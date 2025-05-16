// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_RUNTIME_H__
#define __RULP_ERROR_REXCEPTION_RUNTIME_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionRuntime
  : public RExceptionI 
{

public:
  
  RExceptionRuntime(IRObject* fromObject, IRFrame* fromFrame, StrConstRef message) : RExceptionI(fromObject, fromFrame, message) {};
  RExceptionRuntime(const RExceptionRuntime& E) : RExceptionI(E) {};
  RExceptionRuntime(RExceptionI&& E) : RExceptionI(E) {};

  virtual ~RExceptionRuntime() {}

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_RUNTIME_H__