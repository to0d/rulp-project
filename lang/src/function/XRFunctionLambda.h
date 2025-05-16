// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFUNCTION_LAMBDA_H_
#define __RULP_XIMPL_RUNTIME_XRFUNCTION_LAMBDA_H_
#include "rulp/runtime/IRFunction.h"
#include "AbsFunctionAdapter.h"
namespace lfc {

class XRFunctionLambda 
  : public AbsFunctionAdapter
  , virtual public IRFunction
{

public:
  
  XRFunctionLambda(IRFunction* func, IRFrame* definedFrame, int lambdaId);
  
  virtual ~XRFunctionLambda() = default;

public:

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

public:

  virtual const std::string& asString() const override { return func->asString(); } 

  virtual IRFunction* clone() const override;
  
  virtual int getArgCount() const override { return func->getArgCount(); }

  virtual IRFrame* getDefineFrame() const override { return definedFrame; }

  virtual IRExpr* getFunBody() const override { return func->getFunBody(); }

  virtual RType getType() const override { return T_FUNC; }

  virtual std::string getName() const override { return func->getName(); }

  virtual const std::vector<IRParaAttr*>& getParaAttrs() const override { return func->getParaAttrs(); } 

  virtual StrConstRef getSignature() const override { return func->getSignature(); }

  virtual boolean isLambda() const override { return true; }

  virtual boolean isList() const override { return false; }

protected:

  virtual void _delete() override;

protected:

	IRFrame* definedFrame;

	IRFunction* func;

	int lambdaId;
};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRFUNCTION_LAMBDA_H_