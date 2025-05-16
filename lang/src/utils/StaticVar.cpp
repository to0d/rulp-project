// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/StaticVar.h"
#include "rulp/lang.h"

namespace lfc {

StaticVar::StaticVar(const std::string& varName, IRObject* value)
    : varName(varName)
    , defaultValue(value)
    , curValue(value)
    , var(nullptr) 
{
}

StaticVar::~StaticVar() {
    // Clean up resources if needed
    // Note: We don't own defaultValue (passed from outside)
    // and var might be managed elsewhere
}

bool StaticVar::getBoolValue() {
  return AS_BOOL(curValue)->asBoolean();
}

IRObject* StaticVar::getValue() {
  return curValue;
}

IRVar* StaticVar::getVar() {
  if (var == nullptr) {
    var = RulpFactory::createVar(varName, defaultValue);
    
    var->addVarListener([this](IRVar* _var, IRObject* _oldVal, IRObject* _newVal) {
      curValue = _newVal;
    });

    curValue = defaultValue;
  }
  return var;
}

void StaticVar::init(IRFrame* frame) {
  var = nullptr;
  RuntimeUtil::addFrameObject(frame, getVar());
}

void StaticVar::setBoolValue(bool newVal) {
  if (var == nullptr) {
    curValue = RulpFactory::createBoolean(newVal);
  } 
  else {
    var->setValue(RulpFactory::createBoolean(newVal));
  }
}

} // namespace lfc