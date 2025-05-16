// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

class VarChangeListener : public IRVar::IRVarChangeListener {

public:

  VarChangeListener(IRFunction* func, IRInterpreter* interpreter, IRFrame* frame) 
    : func(func)
    , interpreter(interpreter)
    , frame(frame)
  {
    RULP_INC_REF(func);
  }

  ~VarChangeListener() {
    release();
  }

  virtual void release() override {
    if(func != null){
      RULP_DEC_REF(func);
      func = null;
    }
  }

  virtual void change(IRVar* var, IRObject* oldValue, IRObject* newValue) override {
    auto list = RulpFactory::createList({func, var, oldValue, newValue});
    AUTO_INC_DEC(list);
    ROH obj = RuntimeUtil::computeCallable(func, list, interpreter, frame);
  }

private:

  IRFunction* func;
  IRInterpreter* interpreter;
  IRFrame* frame;

};

XRFACTOR_IMPL_BEGIN(XRFactorDoWhenVarChanged)

  int size = args->size();
  if (size != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto varName = AS_ATOM(args->get(1))->getName();

  auto entry = frame->getEntry(varName);
  if (entry == null) {
    throw RException("var not found: " + varName);
  }

  auto var = AS_VAR(entry->getObject());
  auto fun = AS_FUNC(interpreter->compute(frame, args->get(2)));

  if (fun->getArgCount() != 3) {
    throw RException("the func need 2 arguments");
  }

  var->addVarListener(new VarChangeListener(fun, interpreter, frame));

  return O_Nil;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDoWhenVarChanged, F_DO_WHEN_VAR_CHANGED);

} // namespace lfc