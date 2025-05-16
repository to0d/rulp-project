// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRDefInstance.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/string/format.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

XRDefInstance::XRDefInstance(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame) 
  : AbsRInstance(rClass, instanceName, definedFrame) 
{
  // std::cout << "create instance: name=" << instanceName << ", addr=" << this << "\n";
}

XRDefInstance::~XRDefInstance() {
  // std::cout << "delete instance: name=" << instanceName << ", addr=" << this << "\n";
}

void XRDefInstance::_delete() {

  /******************************************/
  // Check ~init parameters
  /******************************************/
  auto member = getMember(F_UNINIT);

  if (member != null) {

    std::vector<IRObject*> initArgs;
    initArgs.push_back(member);

    auto expr = RuntimeUtil::rebuildFuncExpr(
                  AS_FUNC(member->getValue())
                  , RulpFactory::createExpression(std::move(initArgs))
                  , interpreter
                  , getSubjectFrame());

    auto ROH = interpreter->compute(getSubjectFrame(), expr);
  }

  AbsRInstance::_delete();
}

void XRDefInstance::init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  /******************************************/
  // Check init parameters
  /******************************************/
  auto member = getMember(F_INIT);
  if (member == null) {

    // has argument parameter
    if (args != null && args->size() > 0) {
      throw RException(LFC_STR_FORMAT_BGN 
                          "not init defined for class<%s>: arg=%s"
                        , this->asString().c_str()
                        , args->asString().c_str()
                        LFC_STR_FORMAT_END);
    }

  } 
  else {

    std::vector<IRObject*> initArgs;
    initArgs.push_back(member);
    RulpUtil::addAll(initArgs, args);

    auto expr = RulpFactory::createExpression(std::move(initArgs));
    AUTO_INC_DEC(expr);
  
    auto newExpr = RuntimeUtil::rebuildFuncExpr(AS_FUNC(member->getValue()), expr, interpreter, frame);
    AUTO_INC_DEC(newExpr);

    interpreter->compute(getSubjectFrame(), newExpr);
  }

  this->interpreter = interpreter;
}


} // namespace lfc