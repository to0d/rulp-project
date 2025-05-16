// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRMacro.h" 
#include "rulp/lang.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"
#include "lfc/base/auto/auto_do.h"
#include <sstream>
#include <iostream>

using namespace lfc;

namespace lfc {

XRMacro::XRMacro(StrConstRef macroName, StrList paraNameList, IRExpr* macroBody)
  : macroName(macroName)
  , paraNameList(paraNameList)
  , macroBody(macroBody)
{
  if(macroBody != NULL){
    RULP_INC_REF(macroBody);
  }
}


void XRMacro::_delete() {

  RULP_DEC_REF(macroBody);
  macroBody = NULL;

  AbsRefCallableAdapter::_delete();

}

std::string XRMacro::getSignature() const {
  if(_macroSignature.empty()){

  }

  return _macroSignature;
}

IRObject* XRMacro::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != (paraNameList.size() + 1)) {
    throw RException("Invalid parameters: " + args->asString());
  }

  std::map<std::string, IRObject*> macroMap;
  int size = paraNameList.size();
  for(int i = 0; i < size; ++i){
    auto  arg   = args->get(i+1);
    auto& name  = paraNameList[i];
    macroMap[name] = arg;
  }

  ROH obj = RuntimeUtil::rebuild(macroBody, macroMap);
  return interpreter->compute(frame, obj);
}

} // namespace lfc