// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRMACRO_H__
#define __RULP_RUNTIME_IRMACRO_H__

#include "rulp/object/IRObject.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRCallable.h"
namespace lfc {

class IRMacro 
  : virtual public IRObject
  , virtual public IRCallable 
{
public:
 
  virtual std::string getName() const = 0;

  virtual std::string getSignature() const = 0;

  virtual IRExpr* getMacroBody() const = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRMACRO_H__