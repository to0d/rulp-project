// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_IO_H__
#define __RULP_ERROR_REXCEPTION_IO_H__
#include "rulp/error/RExceptionRuntime.h"
namespace lfc {

class RExceptionIO
  : public RExceptionRuntime 
{

public:
  
  RExceptionIO(IRFrame* fromFrame, StrConstRef message) : RExceptionRuntime(NULL, fromFrame, message) {};
  RExceptionIO(const RExceptionIO& E) : RExceptionRuntime(E) {};
  RExceptionIO(RExceptionIO&& E) : RExceptionRuntime(E) {};

  virtual ~RExceptionIO() {}

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_IO_H__