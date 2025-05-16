// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorBitNot)

  auto obj = interpreter->compute(frame, args->get(1));

  switch (TYPE_INDEX_OF(obj)) {
  case E_INT:
    return RulpFactory::createInteger(~AS_INT(obj)->asInteger());

  case E_LONG:
    return RulpFactory::createLong(~AS_LONG(obj)->asLong());

  default:
    throw RException(LFC_STR_FORMAT_BGN 
                        "Not support type<%s>: %s"
                      , obj->getType()->getName().c_str()
                      , obj->asString().c_str()
                    LFC_STR_FORMAT_END);
  }

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorBitNot, F_O_NOT);
} // namespace lfc