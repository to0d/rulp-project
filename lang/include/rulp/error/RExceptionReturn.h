// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_RETURN_H__
#define __RULP_ERROR_REXCEPTION_RETURN_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionReturn 
  : public RExceptionI 
{

public:
 
  RExceptionReturn(IRObject* fromObject, IRFrame* fromFrame, IRObject* rtValue);
  RExceptionReturn(const RExceptionReturn& E);
  RExceptionReturn(RExceptionReturn&& E);

  virtual ~RExceptionReturn();

  IRObject* returnValue(IRFrame* frame);
  
private:
  
  IRObject* rtValue;

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_RETURN_H__