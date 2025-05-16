// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrStartsWith)

  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  ROH a = interpreter->compute(frame, args->get(1));
  ROH b = interpreter->compute(frame, args->get(2));

  auto a_str = a.get()->asString();
  auto b_str = b.get()->asString();

  return RulpFactory::createBoolean(STR_START_WITH(a_str, b_str));

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrStartsWith, F_STR_START_WITH);

} // namespace lfc