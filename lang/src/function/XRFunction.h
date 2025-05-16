// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFUNCTION_H_
#define __RULP_XIMPL_RUNTIME_XRFUNCTION_H_
#include "rulp/runtime/IRFunction.h"
#include "AbsFunctionAdapter.h"
namespace lfc {

class XRFunction 
  : public AbsFunctionAdapter
  , virtual public IRFunction
{

public:
  
  XRFunction(IRFrame* defineFrame, StrConstRef name, std::vector<IRParaAttr*>&& paraAttrList, IRExpr* funBod);
  
  virtual ~XRFunction();

public:

  virtual const std::string& asString() const override;

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

  virtual int getArgCount() const override { return paraCount; } 

  virtual IRFrame* getDefineFrame() const override { return defineFrame; } 

  virtual IRExpr* getFunBody() const override { return funBody; }

  virtual RType getType() const override;

  virtual std::string getName() const override { return name; }

  virtual const std::vector<IRParaAttr*>& getParaAttrs() const override { return paraAttrList;} 

  virtual StrConstRef getSignature() const override;
  
  virtual boolean isLambda() const override { return false; }

  virtual boolean isList() const override { return false; }

protected:

  void _matchTypeList(IRList* args, IRFrame* frame);
  
  virtual void  _delete() override;

protected:

  IRFrame* defineFrame = null;

	IRExpr* funBody = null;

	std::string name;

	std::vector<IRParaAttr*> paraAttrList;

	const int paraCount;

  mutable	std::string signature;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRFUNCTION_H_