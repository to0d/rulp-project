// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFunctionList.h" 
#include "rulp/lang.h"
#include "rulp/utils/ReturnTypeUtil.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"
#include "lfc/base/container.h"
#include "lfc/base/to_string.h"

using namespace lfc;

namespace lfc {

static boolean isDefaultFun(IRFunction* fun) {

  for (auto attr : fun->getParaAttrs()) {
    if (attr->getParaType() != O_Nil) {
      return false;
    }
  }

  return true;
}

static int matchFunParaCount(IRFunction* fun, IRList* args){

  int para_size = fun->getParaAttrs().size();
  if ((para_size + 1) != args->size()) {
    return -1;
  }

  int matchCount = 0;

  for(int i = 0; i < para_size; ++i){
    auto attr     = fun->getParaAttrs()[i];
    auto valObj   = args->get(i+1);
    auto typeAtom = attr->getParaType();

    // Match any type
    if (typeAtom == O_Nil || valObj == null) {
      continue;
    }

    if (typeAtom != RulpUtil::getObjectType(valObj)) {
      return -1;
    } 
    else {
      ++matchCount;
    }
  }

  return matchCount;
}

IRFunction* FuncList::addFunc(IRFunction* fun){
  IRFunction* oldFun = null;

  if (isDefaultFun(fun)) {

    if (defaultFun != null) {
      RulpUtil::tryOverride(defaultFun, fun);
      oldFun = defaultFun;
    }

    this->defaultFun = fun;

  } 
  else {

    auto signature = fun->getSignature();

    oldFun = signatureMap[signature];
    if (oldFun != null) {
      RulpUtil::tryOverride(oldFun, fun);
    }

    signatureMap[signature] = fun;
    funcList.push_back(fun);
  }

  return oldFun;
}

IRFunction* FuncList::findMatchFun(IRList* args){
  int lastMatchCount = -1;
  std::vector<IRFunction*> lastMatchFuns;

  for (auto fun : funcList) {

    int matchCount = matchFunParaCount(fun, args);
    if (matchCount < 0) {
      continue;
    }

    if (lastMatchCount == -1) {
      lastMatchFuns.push_back(fun);
      lastMatchCount = matchCount;
      continue;
    }

    if (matchCount < lastMatchCount) {
      continue;
    }

    if (matchCount == lastMatchCount) {
      lastMatchFuns.push_back(fun);
      continue;
    }

    // matchCount > lastMatchCount
    lastMatchFuns.clear();
    lastMatchFuns.push_back(fun);
    lastMatchCount = matchCount;
  }

  // not match fun found
  if (lastMatchCount < 0) {
    return defaultFun;
  }

  if (lastMatchCount == 0 && defaultFun != null) {
    throw RException( LFC_STR_FORMAT_BGN 
                          "ambiguous funcion found: def=%s, funs=%s, expr=%s"
                        , defaultFun->asString().c_str()
                        , TO_STR(lastMatchFuns).c_str()
                        , args->asString().c_str()
                      LFC_STR_FORMAT_END);
  }

  if (lastMatchFuns.size() > 1) {
    throw RException( LFC_STR_FORMAT_BGN
                          "ambiguous funcion found: funs=%s, expr=%s"
                        , TO_STR(lastMatchFuns).c_str()
                        , args->asString().c_str() 
                      LFC_STR_FORMAT_END);
  }

  return lastMatchFuns[0];
}

XRFunctionList::XRFunctionList(StrConstRef name) :name(name) {

}

void XRFunctionList::_delete(){

  for(auto func : allFuncList){
    RULP_DEC_REF(func);
  }

  allFuncList.clear();

  AbsFunctionAdapter::_delete();
}

const std::string& XRFunctionList::asString() const {
  return name;
}

void XRFunctionList::addFunc(IRFunction* fun){
  int argCount = fun->getArgCount();

  FuncListPtr funcList = funListMap[argCount];
  if (funcList == null) {
    funcList = FuncListPtr(new FuncList());
    funListMap[argCount] = funcList;
  }

  auto oldFun = funcList->addFunc(fun);
  if (oldFun != null) {
    lfc::erase_first_of(allFuncList, oldFun);
    RULP_DEC_REF(oldFun);
  }

  allFuncList.push_back(fun);
  RULP_INC_REF(fun);

  signature = "";
  
  AttrUtil::removeAllAttributes(this);
}

IRObject* XRFunctionList::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame){
  int argCount = args->size() - 1;
  auto funcList = funListMap[argCount];
  if (funcList == null) {
    throw RException("match funcion not found: expr=" + args->asString());
  }

  auto matchFun = funcList->findMatchFun(args);
  if (matchFun == null) {
    throw RExceptionUnmatchPara 
                ( this
                , frame
                , LFC_STR_FORMAT_BGN 
                      "match funcion not found:  expr=%s"
                    , args->asString().c_str() 
                  LFC_STR_FORMAT_END);
  }

  return RuntimeUtil::computeCallable(matchFun, args, interpreter, frame);
}

RType XRFunctionList::getType() const{
  return T_FUNC;
}

static std::vector<IRParaAttr*> EMPTY_VEC;

const std::vector<IRParaAttr*>& XRFunctionList::getParaAttrs() const {
  return EMPTY_VEC;
}

StrConstRef XRFunctionList::getSignature() const{
  if (signature.empty()) {

    std::vector<std::string> allSignatures;
    for (auto func : allFuncList) {
      allSignatures.push_back(func->getSignature());
    }

    std::sort(allSignatures.begin(), allSignatures.end());
    signature = TO_STR(allSignatures);
  }

  return signature;
}

} // namespace lfc