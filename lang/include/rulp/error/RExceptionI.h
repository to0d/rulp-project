// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_I_H__
#define __RULP_ERROR_REXCEPTION_I_H__
#include "rulp/error/RExceptionBase.h"
#include "rulp/runtime/IRFrame.h"
namespace lfc {

class RExceptionI
  : public RException 
{

public:
 
  RExceptionI(IRObject* fromObject, IRFrame* fromFrame);
  RExceptionI(IRObject* fromObject, IRFrame* fromFrame, StrConstRef message);
  RExceptionI(const RExceptionI& E);
  RExceptionI(RExceptionI&& E);

  virtual ~RExceptionI() {}

public:

  boolean isHandle() {
		return handle;
	}

  void setHandle(boolean handle) {
		this->handle = handle;
	}
  
protected:

  IRFrame* fromFrame;
  bool handle = false;

};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_I_H__