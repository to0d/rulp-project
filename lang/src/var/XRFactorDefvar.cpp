// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/AbsAtomFactorAdapter.h"
#include "rulp/lang.h"
#include "rulp/utils/SubjectUtil.h"

using namespace lfc;

namespace lfc {

class XRFactorDefvar
  : public AbsAtomFactorAdapter
  , virtual public IRFactor
{

public:
  XRFactorDefvar(StrConstRef factorName, boolean rtVar, boolean allowRedefin) 
    : AbsAtomFactorAdapter(factorName) 
    , returnVar(rtVar) 
    , allowRedefine(allowRedefin) 
  {}
 
  virtual ~XRFactorDefvar() = default;

public:

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

  IRObject* defVar(StrConstRef varName, IRObject* valObj, IRInterpreter* interpreter, IRFrame* frame);

private:

	const boolean allowRedefine;

	const boolean returnVar;

};

IRObject* XRFactorDefvar::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame){

  if (args->size() != 2 && args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  IRObject* varObj = args->get(1);
  IRObject* valObj = args->size() > 2 ? args->get(2) : null;

  if (TYPE_INDEX_OF(varObj) == E_ATOM) {
    return defVar(RulpUtil::asAtom(varObj)->getName(), valObj, interpreter, frame);
  }

  if (TYPE_INDEX_OF(varObj) == E_MEMBER) {
    auto var = SubjectUtil::defineMemberVar(RulpUtil::asMember(varObj), valObj, interpreter, frame);
    return returnVar ? var : var->getValue();
  }

  throw RException("Invalid var type, : " + args->asString());
}

IRObject* XRFactorDefvar::defVar(StrConstRef varName, IRObject* valObj, IRInterpreter* interpreter, IRFrame* frame){
  if (!allowRedefine) {
    auto entry = frame->getEntry(varName);
    if (entry != null && entry->getFrame() == frame) {
      throw RException("duplicate local variable: " + varName);
    }
  }

  auto var = RulpFactory::createVar(varName);
  frame->setEntry(varName, var);

  auto val = var->getValue();
  if (valObj != null) {
    val = interpreter->compute(frame, valObj);
    var->setValue(val);
  }

  return returnVar ? var : val;
}

class XRFactorDefvarImpl : public XRFactorDefvar
{
public:
  XRFactorDefvarImpl(StrConstRef factorName) 
    : XRFactorDefvar(factorName, true, false) 
  {}
  virtual ~XRFactorDefvarImpl() = default;
};

STATIC_FACTOR_REGISTER(XRFactorDefvarImpl, F_DEFVAR);

} // namespace lfc