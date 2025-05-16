// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorDelete)

  auto entryName = AS_ATOM(args->get(1))->getName();
  if (args->size() >= 3) {
    frame = AS_FRAME(interpreter->compute(frame, args->get(2)));
  }

  auto oldEntry = frame->removeEntry(entryName);
  if (oldEntry == null) {
    throw RException(LFC_STR_FORMAT_BGN 
                        "unable to delete: obj %s not found, frame=%s"
                      , entryName.c_str()
                      , frame->asString().c_str()
                    LFC_STR_FORMAT_END);
  }

  RULP_FREE(oldEntry);

  // auto obj = oldEntry->getObject();
  // if (TYPE_INDEX_OF(obj) == E_INSTANCE && !obj->isDeleted()) {
  //   AS_INSTANCE(obj)->deleteIt(interpreter, frame);
  // }

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDelete, F_DELETE);

} // namespace lfc
