// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrCharAt)

  auto a = interpreter->compute(frame, args->get(1));
  auto b = interpreter->compute(frame, args->get(2));

  auto rst = AS_STR(a);
  auto loc = AS_INT(b);

  return RulpFactory::createInteger(rst->asString().at(loc->asInteger()));

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrCharAt, F_STR_CHAR_AT);

} // namespace lfc