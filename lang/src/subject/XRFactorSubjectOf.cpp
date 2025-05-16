// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
namespace lfc {

static IRObject* subjectOf(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) {

  switch (TYPE_INDEX_OF(obj)) {

  case E_ATOM: {

    auto entry = RuntimeUtil::lookupFrameEntry(frame, obj->asString());
    if (entry == null) {
      return O_Nil;
    }

    return entry->getFrame();
  }

  case E_MEMBER: {

    auto mbr = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
    if (!RuntimeUtil::canAccess(mbr, interpreter, frame)) {
      throw RException("Can't access member<" + mbr->asString() + "> in frame<" + frame->asString() + ">");
    }

    return mbr->getSubject();
  }

  default:
    return O_Nil;
  }
}

XRFACTOR_IMPL_BEGIN(XRFactorSubjectOf)

  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  return subjectOf(args->get(1), interpreter, frame);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSubjectOf, F_SUBJECT_OF);

} // namespace lfc
