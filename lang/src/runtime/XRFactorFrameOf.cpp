// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorFrameOf)

  auto obj = args->get(1);
  switch (TYPE_INDEX_OF(obj)) {
  case E_ATOM: {
      auto entry = frame->getEntry(AS_ATOM(obj)->getName());
      if (entry != null) {
        return entry->getFrame();
      }
      break;
    }

  case E_MEMBER: {
      auto mbr = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
      if (!RuntimeUtil::canAccess(mbr, interpreter, frame)) {
        throw RException("Can't access member<" + mbr->asString() + "> in frame<" + frame->asString() + ">");
      }

      return AS_SUBJECT(mbr->getSubject())->getSubjectFrame();
    }

  case E_INSTANCE: {
    return AS_INSTANCE(obj)->getSubjectFrame();
  }

  default:
    break;
  }

#define instanceof(a, b)            (typeid(a) == typeid(b))

  //		obj = interpreter.compute(frame, args.get(1));
  //		if (obj instanceof IRSubject) {
  //			return ((IRSubject) obj).getSubjectFrame();
  //		}

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorFrameOf, F_FREAME_OF);

} // namespace lfc