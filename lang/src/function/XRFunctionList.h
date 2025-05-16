// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFUNCTION_LIST_H_
#define __RULP_XIMPL_RUNTIME_XRFUNCTION_LIST_H_
#include "rulp/runtime/IRFunction.h"
#include "rulp/runtime/IRFunctionList.h"
#include "AbsFunctionAdapter.h"
#include <memory>
namespace lfc {

class FuncList {
public:

  IRFunction* addFunc(IRFunction* fun);

  IRFunction* findMatchFun(IRList* args);

private:

  IRFunction* defaultFun = NULL;
  std::map<std::string, IRFunction*> signatureMap;
  std::vector<IRFunction*> funcList;
};

typedef std::shared_ptr<FuncList> FuncListPtr;

class XRFunctionList 
  : public AbsFunctionAdapter
  , virtual public IRFunctionList
{

public:
  
  XRFunctionList(StrConstRef name);
  
  virtual ~XRFunctionList() = default;

public:

  virtual void addFunc(IRFunction* fun) override;

  virtual const std::string& asString() const override;

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

  virtual const std::vector<IRFunction*>& getAllFuncList() const override { return allFuncList; };

  virtual int getArgCount() const override { return -1; } 

  virtual IRFrame* getDefineFrame() const override { return null; } 

  virtual IRExpr* getFunBody() const override { return null; }

  virtual RType getType() const override;

  virtual std::string getName() const override { return name; }

  virtual const std::vector<IRParaAttr*>& getParaAttrs() const override;

  virtual StrConstRef getSignature() const override;;

  virtual boolean isLambda() const override { return false; }

  virtual boolean isList() const override { return true; }

protected:

  virtual void  _delete() override;

protected:

  std::vector<IRFunction*> allFuncList;
  
  std::map<int, FuncListPtr> funListMap;
  
  std::string name;
  
  mutable std::string signature;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRFUNCTION_LIST_H_