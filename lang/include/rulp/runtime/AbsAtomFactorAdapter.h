// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_ABSATOMFACTORADAPTER_H_
#define __RULP_XIMPL_RUNTIME_ABSATOMFACTORADAPTER_H_
#include "rulp/runtime/IRFactor.h"
#include "rulp/runtime/AbsAtomCallableAdapter.h"
namespace lfc {

class AbsAtomFactorAdapter 
  : public AbsAtomCallableAdapter
  , virtual public IRFactor
{

public:

  AbsAtomFactorAdapter(StrConstRef factorName);

  virtual ~AbsAtomFactorAdapter();

public:

  virtual StrConstRef asString() const override;
  
  virtual RType getType() const override;

  virtual StrConstRef getName() const override;

  virtual int getMinArgCount() const override {return -1;}

  virtual int getMaxArgCount() const override {return -1;}

  virtual bool isRebuild() const override { return false; }

private:

  std::string factorName;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_ABSATOMFACTORADAPTER_H_