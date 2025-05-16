// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRTemplate.h" 
#include "rulp/lang.h"
#include <sstream>
#include <iostream>

using namespace lfc;

namespace lfc {

XRTemplate::XRTemplate(StrConstRef templateName, IRFrame* defineFrame)
  : templateName(templateName)
  , defineFrame(defineFrame)
{

}

void XRTemplate::_delete() {

  for(auto tp : templateParaEntryList){
    for(auto& pv : tp.fixedParas){
      if(pv.paraValue != null){
        RULP_DEC_REF(pv.paraValue);
      }
    }

    tp.fixedParas.clear();

    RULP_DEC_REF(tp.body);
    tp.body = null;
  }

  templateParaEntryList.clear();

  AbsRefCallableAdapter::_delete();
}

const std::string& XRTemplate::asString() const {
  return templateName;
}

void XRTemplate::addEntry(const TemplateParaEntry& entry) {

  if (entry.body == null) {
    throw RException("invalid entry");
  }

  signature = "";
  templateParaEntryList.push_back(entry);
  RULP_INC_REF(entry.body);

  for(auto& pv : entry.fixedParas){
    if(pv.paraValue != null){
      RULP_INC_REF(pv.paraValue);
    }    
  }

}

struct InputData {
  
  std::vector<IRObject*> actualValues;
  IRFrame* frame;
  IRList* inputArgs;
  IRInterpreter* interpreter;

  InputData(IRList* inputArgs, IRInterpreter* interpreter, IRFrame* frame) 
    : inputArgs(inputArgs)
    , interpreter(interpreter)
    , frame(frame)  
  {
    actualValues.resize(inputArgs->size());
  }

  IRObject* getActualValue(int index) {
    
    auto actualValue = actualValues[index];
    if (actualValue == null) {
      auto inputPara = inputArgs->get(index);
      actualValue = interpreter->compute(frame, inputPara);
      actualValues[index] = actualValue;
    }

    return actualValue;
  }

  boolean matchType(TemplatePara tp, int index) {
    auto inputPara = inputArgs->get(index);

    // match EXPR type
    if (tp.paraType == T_Expr) {
      return TYPE_INDEX_OF(inputPara) == E_EXPR;
    }

    // match result object
    return RulpUtil::matchType(tp.paraType, getActualValue(index));
  }

  boolean match(const TemplateParaEntry& tpEntry) {

    /******************************************/
    // Check parameter count
    /******************************************/
    int fixedParaCount = tpEntry.fixedParas.size();
    if (tpEntry.isVary) {
      if ((fixedParaCount + 1) > inputArgs->size())
        return false;
    }
    else {
      if ((fixedParaCount + 1) != inputArgs->size())
        return false;
    }

    /******************************************/
    // Check fixed parameters
    /******************************************/
    if (fixedParaCount > 0) {

      for (int i = 0; i < fixedParaCount; ++i) {

        auto& tp = tpEntry.fixedParas[i];

        if (!tp.isVar && (tp.paraType == O_Nil || tp.paraType == T_Atom)) {

          auto inputPara = inputArgs->get(i + 1);
          if (TYPE_INDEX_OF(inputPara) != E_ATOM) {
            return false;
          }

          if (!RulpUtil::equal(tp.paraValue, inputPara)) {
            return false;
          }

        } 
        else {

          // Check type
          if (!matchType(tp, i + 1)) {
            return false;
          }

          // Check value
          if (!tp.isVar && !RulpUtil::equal(tp.paraValue, getActualValue(i + 1))) {
            return false;
          }
        }
      }
    }

    return true;

  }
  
};

IRObject* XRTemplate::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  if (args->size() < 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  int matchedIndex = -1;

  // Search matched template entry
  {
    InputData inputData(args, interpreter, frame);
    int index = 0;
    for (auto& tpEntry : templateParaEntryList) {
      if (inputData.match(tpEntry)) {
        matchedIndex = index;
        break;
      }
      ++index;
    }
  }

  if (matchedIndex == -1) {
    throw RException("no template match");
  }

  TemplateParaEntry& matchedTpEntry = templateParaEntryList[matchedIndex];

  if (TYPE_INDEX_OF(matchedTpEntry.body) == E_FUNC) {
    return RuntimeUtil::computeFun(AS_FUNC(matchedTpEntry.body), args, interpreter, frame);
  } 
  else {
    return RuntimeUtil::computeCallable(matchedTpEntry.body, args, interpreter, frame);
  }
}

IRFrame* XRTemplate::getDefineFrame() const {
  return defineFrame;
}

std::string XRTemplate::getName() const {
  return templateName;
}

std::string XRTemplate::getSignature() const {
  if (signature.empty()) {

    std::vector<std::string> allSignatures;
    for (auto& tpEntry : templateParaEntryList) {
      allSignatures.push_back(tpEntry.toString());
    }

    std::stringstream ss;

    ss << "(";
    ss << templateName;

    for (auto sig : allSignatures) {
      ss << ' ';
      ss << sig;
    }

    ss << ')';
    signature = ss.str();
  }

  return signature;
}

RType XRTemplate::getType() const {
  return T_TEMPLATE;
}

const std::vector<TemplateParaEntry>& XRTemplate::getTemplateParaEntryList() const {
  return templateParaEntryList;
}

} // namespace lfc