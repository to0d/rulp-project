// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_INTERRUPT_H__
#define __RULP_ERROR_REXCEPTION_INTERRUPT_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionInterrupt 
  : public RExceptionI 
{

public:
 
  RExceptionInterrupt(IRObject* fromObject, IRFrame* fromFrame) : RExceptionI(fromObject, fromFrame){};
  RExceptionInterrupt(const RExceptionInterrupt& E) : RExceptionI(E) {}
  RExceptionInterrupt(RExceptionInterrupt&& E) : RExceptionI(E) {}

  virtual ~RExceptionInterrupt() {}

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_INTERRUPT_H__