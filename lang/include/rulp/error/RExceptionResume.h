// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_RESUME_H__
#define __RULP_ERROR_REXCEPTION_RESUME_H__
#include "rulp/error/RExceptionBase.h"
namespace lfc {

class RExceptionResume 
  : public RException 
{

public:
 
  RExceptionResume() : RException(){};
  RExceptionResume(const RExceptionResume& E) : RException(E) {}
  RExceptionResume(RExceptionResume&& E) : RException(E) {}

  virtual ~RExceptionResume() {}
  
};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_RESUME_H__