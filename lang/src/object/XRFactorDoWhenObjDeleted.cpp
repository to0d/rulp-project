// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/RObjectHandler.h"

namespace lfc {

class ObjectDeleteListener : public IRObjectDeleteListener {

public:

  ObjectDeleteListener(IRFunction* func, IRInterpreter* interpreter, IRFrame* frame) 
    : func(func)
    , interpreter(interpreter)
    , frame(frame)
  {
    RULP_INC_REF(func);
  }

  ~ObjectDeleteListener() {
    release();
  }

  virtual void release() override {
    if(func != null){
      RULP_DEC_REF(func);
      func = null;
    }
  }

  virtual void objectBeforeDelete(IRObject* obj) override {
    auto list = RulpFactory::createList({func, obj});
    AUTO_INC_DEC(list);
    ROH rst = RuntimeUtil::computeCallable(func, list, interpreter, frame);
  }

private:

  IRFunction* func;
  IRInterpreter* interpreter;
  IRFrame* frame;

};

XRFACTOR_IMPL_BEGIN(XRFactorDoWhenObjDeleted)

  auto obj = args->get(1);
  if (TYPE_INDEX_OF(obj) == E_ATOM) {
    auto objName = AS_ATOM(obj)->getName();
    auto entry = frame->getEntry(objName);
    if (entry == null) {
      throw RException("object not found: " + objName);
    }

    obj = entry->getObject();
  }

  auto fun = AS_FUNC(interpreter->compute(frame, args->get(2)));
  if (fun->getArgCount() != 1) {
    throw RException("the func need 2 arguments");
  }

  obj->addObjectDeletedListener(new ObjectDeleteListener(fun, interpreter, frame));

  return fun;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDoWhenObjDeleted, F_DO_WHEN_OBJ_DELETED);

} // namespace lfc