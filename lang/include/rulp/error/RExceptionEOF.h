// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_EOF_H__
#define __RULP_ERROR_REXCEPTION_EOF_H__
#include "rulp/error/RExceptionBase.h"
namespace lfc {

class RExceptionEOF
  : public RException 
{

public:
  
  RExceptionEOF() : RException(){};
  RExceptionEOF(const RExceptionEOF& E) : RException(E) {}
  RExceptionEOF(RExceptionEOF&& E) : RException(E) {}

  virtual ~RExceptionEOF() {}

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_EOF_H__