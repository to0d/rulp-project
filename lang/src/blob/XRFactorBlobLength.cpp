// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorBlobLength)

  ROH obj = interpreter->compute(frame, args->get(1));
  auto blob   = AS_BLOB(obj.get());

  return RulpFactory::createInteger(blob->length());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorBlobLength, F_BLOB_LENGTH);

} // namespace lfc
