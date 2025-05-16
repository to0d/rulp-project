// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/to_string.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorMakeBlob)

  ROH obj = interpreter->compute(frame, args->get(1));
  int blobLen = AS_INT(obj.get())->asInteger();
  if (blobLen < 0) {
    throw RException("invalid blob length: " + TO_STR(blobLen));
  }

  return RulpFactory::createBlob(blobLen);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorMakeBlob, F_MAKE_BLOB);
} // namespace lfc