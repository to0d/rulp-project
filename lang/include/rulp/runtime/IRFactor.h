// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRFACTOR_H__
#define __RULP_RUNTIME_IRFACTOR_H__

#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRCallable.h"
namespace lfc {

typedef IRObject* (*factor_func) (IRList*, IRInterpreter*, IRFrame*) ;

class IRFactor : virtual public IRCallable 
{
public:
 
  virtual StrConstRef getName() const = 0;  

  virtual int getMinArgCount() const = 0;

  virtual int getMaxArgCount() const = 0;

  virtual bool isRebuild() const = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRFACTOR_H__