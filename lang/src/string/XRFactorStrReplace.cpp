// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrReplace)

  if (args->size() != 4) {
    throw RException("Invalid parameters: " + args->asString());
  }

  ROH obj1 = interpreter->compute(frame, args->get(1));
  ROH obj2 = interpreter->compute(frame, args->get(2));
  ROH obj3 = interpreter->compute(frame, args->get(3));

  auto str = AS_STR(obj1)->asString();
  auto target = AS_STR(obj2)->asString();
  auto replacement = AS_STR(obj3)->asString();

  return RulpFactory::createString(STR_REPLACE_ALL(str, target, replacement));

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrReplace, F_STR_REPLACE);

} // namespace lfc