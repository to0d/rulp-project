// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRFUNCTION_LIST_H__
#define __RULP_LANG_IRFUNCTION_LIST_H__
#include "rulp/runtime/IRFunction.h"
namespace lfc {

class IRFunctionList 
  : virtual public IRObject
  , virtual public IRFunction 
{

public:

  virtual void addFunc(IRFunction* fun) = 0;

  virtual const std::vector<IRFunction*>& getAllFuncList() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRFUNCTION_LIST_H__