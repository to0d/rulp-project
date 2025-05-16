// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_PARSE_H__
#define __RULP_ERROR_REXCEPTION_PARSE_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionParse
  : public RException 
{

public:
 
  RExceptionParse(StrConstRef message, int line, int pos);
  RExceptionParse(const RExceptionParse& E);
  RExceptionParse(RExceptionParse&& E);

  virtual ~RExceptionParse() {}

  virtual std::string getMessage() const;

protected:

  int line = -1;
  int pos  = 1;
  
};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_PARSE_H__