// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_UNMATCHPARA_H__
#define __RULP_ERROR_REXCEPTION_UNMATCHPARA_H__
#include "rulp/error/RExceptionI.h"
namespace lfc {

class RExceptionUnmatchPara
  : public RExceptionI 
{

public:
  
  RExceptionUnmatchPara(IRObject* fromObject, IRFrame* fromFrame, StrConstRef message) : RExceptionI(fromObject, fromFrame, message) {};
  RExceptionUnmatchPara(const RExceptionUnmatchPara& E) : RExceptionI(E) {};
  RExceptionUnmatchPara(RExceptionI&& E) : RExceptionI(E) {};

  virtual ~RExceptionUnmatchPara() {}

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_UNMATCHPARA_H__