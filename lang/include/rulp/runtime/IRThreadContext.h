// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRTHREAD_CONTEXT_H__
#define __RULP_RUNTIME_IRTHREAD_CONTEXT_H__

#include "rulp/error/RExceptionBase.h"
#include "rulp/object/IRObject.h"
namespace lfc {

class IRThreadContext
{
public:

  virtual void addError(IRObject* inObject, RException& outException) = 0;

  virtual void addResult(IRObject* inObject, IRObject* outResult) = 0;

  virtual int getErrorCount() = 0;

  virtual RException& getException(int index) = 0;

  virtual IRObject* getResult(int index) = 0;

  virtual int getResultCount() = 0;

  virtual boolean isCompleted() = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRTHREAD_CONTEXT_H__