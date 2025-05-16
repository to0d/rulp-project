// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

static IRObject* valueOf2(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) {

  switch (TYPE_INDEX_OF(obj)) {
  case E_VAR:
    return AS_VAR(obj)->getValue();

//		case MEMBER:
//
//			IRMember mbr = RuntimeUtil.getActualMember((IRMember) obj, interpreter, frame);
//			if (!RuntimeUtil.canAccess(mbr, interpreter, frame)) {
//				throw RException("Can't access member<" + mbr + "> in frame<" + frame + ">");
//			}

  default:
    return obj;
  }
}

static IRObject* valueOf(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) {

  switch (TYPE_INDEX_OF(obj)) {

  case E_VAR:
    return AS_VAR(obj)->getValue();

  case E_ATOM: {

    auto entry = RuntimeUtil::lookupFrameEntry(frame, AS_ATOM(obj)->getName());
    if (entry == null) {
      throw RException("object not found: " + obj->asString());
    }

    return valueOf2(entry->getObject(), interpreter, frame);
  }

  case E_LIST:
    return interpreter->compute(frame, obj);

  case E_EXPR:
    return valueOf2(interpreter->compute(frame, obj), interpreter, frame);

  case E_MEMBER: {

    auto mbr = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
    if (!RuntimeUtil::canAccess(mbr, interpreter, frame)) {
      throw RException("Can't access member<" + mbr->asString() + "> in frame<" + frame->asString() + ">");
    }

    return mbr->getValue();
  }

  case E_NIL:
  case E_BOOL:
  case E_INT:
  case E_LONG:
  case E_FLOAT:
  case E_DOUBLE:
  case E_STRING:
  case E_FACTOR:
  case E_TEMPLATE:
  case E_FUNC:
  case E_MACRO:
  case E_INSTANCE:
  case E_CLASS:
  case E_FRAME:
    return obj;

  default:
    throw RException("invalid object: " + obj->asString());
  }
}

XRFACTOR_IMPL_BEGIN(XRFactorValueOf)

  auto obj = args->get(1);
  if (TYPE_INDEX_OF(obj) == E_EXPR) {
    obj = interpreter->compute(frame, obj);
  }

  return valueOf(obj, interpreter, frame);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorValueOf, F_VALUE_OF);

} // namespace lfc