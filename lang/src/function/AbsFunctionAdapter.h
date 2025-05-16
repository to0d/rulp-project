// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_ABS_FUNCTION_ADAPTER_H_
#define __RULP_XIMPL_RUNTIME_ABS_FUNCTION_ADAPTER_H_
#include "rulp/runtime/IRFunction.h"
#include "rulp/runtime/AbsRefCallableAdapter.h"
namespace lfc {

class AbsFunctionAdapter 
  : public AbsRefCallableAdapter
  , virtual public IRFunction
{

public:

  AbsFunctionAdapter() = default;

  virtual ~AbsFunctionAdapter() = default;

public:
   
  virtual IRFunction* clone() const override { throw RException("not support"); };

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_ABS_FUNCTION_ADAPTER_H_