// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRVarRef.h"
#include "lfc/base/to_string.h"
#include "lfc/base/container.h"
#include "rulp/utils/RulpUtil.h"
#include <iostream>

namespace lfc {

XRVarRef::XRVarRef(StrConstRef varName)
  : varName(varName)
{
  // std::cout << "create var: name=" << varName << ", addr=" << this << "\n";
}

XRVarRef::~XRVarRef() {
  // std::cout << "delete var: name=" << varName << ", addr=" << this << "\n";
}

void XRVarRef::_delete() {
  
  if(value != NULL){
    RULP_DEC_REF(value);
    value = NULL;
  }

  if(varListenerList != NULL) {

    for(auto listener: *varListenerList){
      listener->release();
      delete listener;
    }

    varListenerList->clear();
    delete varListenerList;
    varListenerList = NULL;
  }
  
  AbsRefObject::_delete();
}

RType XRVarRef::getType() const {
  return T_VAR;
}

void XRVarRef::addVarListener(var_change_listener listener) {
  if (varListenerList == null) {
    varListenerList = new std::vector<var_change_listener>();
  }

  varListenerList->push_back(listener);
}

class VarChangeListenerFuncWrapper : public IRVar::IRVarChangeListener {
public:

  VarChangeListenerFuncWrapper(IRVar::var_change_func func) 
    : func(func)
  {}

  ~VarChangeListenerFuncWrapper() {
    release();
  }

  virtual void release() override {
    if(func != null){
      func = nullptr;
    }
  }

  virtual void change(IRVar* var, IRObject* oldValue, IRObject* newValue) override {
    func(var, oldValue, newValue);
  }

private:
  IRVar::var_change_func func;
};

void XRVarRef::addVarListener(var_change_func func) {
  addVarListener(new VarChangeListenerFuncWrapper(func));
}

const std::string& XRVarRef::asString() const{
  if (_asString.empty()) {
    _asString  = varName;
    _asString += ":\"";
    _asString += value->asString();
    _asString += "\"";
  }

  return _asString;
}

std::string XRVarRef::getName() const{
  return varName;
}

IRObject* XRVarRef::getValue() const {
  return value;
}

void XRVarRef::fireValueChanged(IRObject* oldVal, IRObject* newVal) {
  if (varListenerList == null) {
    return;
  }

  if (RulpUtil::equal(oldVal, newVal)) {
    return;
  }

  for (auto& listener : *varListenerList) {
    listener->change(this, oldVal, newVal);
  }
}

void XRVarRef::setValue(IRObject* newVal) {

  IRObject* oldVal = value; 
  value = newVal;
  _asString = "";
  
  fireValueChanged(oldVal, newVal);

  if(newVal != NULL){
    RULP_INC_REF(newVal);
  }
  
  RULP_DEC_REF(oldVal);
}

} // namespace lfc