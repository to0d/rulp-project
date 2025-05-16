// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_ERROR_H__
#define __RULP_ERROR_REXCEPTION_ERROR_H__
#include "rulp/error/RExceptionBase.h"
#include "rulp/object/IRError.h"
namespace lfc {

class RExceptionError 
  : public RException
{

public:
 
  RExceptionError(IRObject* fromObject, IRFrame* fromFrame, IRError* err);
  RExceptionError(const RExceptionError& E);

  virtual ~RExceptionError();

public:

  IRError* getError() const;

  IRFrame* getFromFrame() const;

protected:

  IRError* err = null;

	IRFrame* fromFrame = null;

};


} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_ERROR_H__