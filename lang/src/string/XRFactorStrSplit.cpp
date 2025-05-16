// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrSplit)

  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  ROH obj1 = interpreter->compute(frame, args->get(1));
  ROH obj2 = interpreter->compute(frame, args->get(2));

  auto str = AS_STR(obj1)->asString();
  auto sep = AS_STR(obj2)->asString();

  return RulpFactory::createListOfString(STR_SPLIT_BY_MULTI_CHAR(str, sep));

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrSplit, F_STR_SPLIT_BY_CHAR);

} // namespace lfc