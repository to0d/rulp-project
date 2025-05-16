// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRMACRO_H_
#define __RULP_XIMPL_RUNTIME_XRMACRO_H_
#include "rulp/runtime/IRMacro.h"
#include "../function/AbsFunctionAdapter.h"
namespace lfc {

class XRMacro 
  : public AbsRefCallableAdapter
  , virtual public IRMacro
{

public:
  
  XRMacro(StrConstRef macroName, StrList paraNameList, IRExpr* macroBody);
  
  virtual ~XRMacro() = default;

public:

  virtual const std::string& asString() const override {return macroName; }

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

  virtual RType getType() const override { return T_MACRO; }

  virtual std::string getName() const override { return macroName; }

  virtual std::string getSignature() const override;

  virtual IRExpr* getMacroBody() const override { return macroBody; }

protected:

  virtual void _delete() override;

protected:

	IRExpr* macroBody;

	std::string macroName;

	const StrList paraNameList;

protected:

  mutable std::string _macroSignature;
};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRMACRO_H_