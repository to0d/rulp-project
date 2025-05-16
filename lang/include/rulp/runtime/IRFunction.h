// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRFUNCTION_H__
#define __RULP_LANG_IRFUNCTION_H__
#include "rulp/object/IRObject.h"
#include "rulp/object/IRParaAttr.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRCallable.h"
namespace lfc {

class IRFunction 
  : virtual public IRObject
  , virtual public IRCallable 
{

public:

  virtual int getArgCount() const = 0;
 
  virtual IRFrame* getDefineFrame() const = 0;

  virtual IRExpr* getFunBody() const = 0;

  virtual std::string getName() const = 0;

  virtual const std::vector<IRParaAttr*>& getParaAttrs() const = 0;

  virtual StrConstRef getSignature() const = 0;

  virtual boolean isLambda() const = 0;

  virtual boolean isList() const = 0;

  virtual IRFunction* clone() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRFUNCTION_H__