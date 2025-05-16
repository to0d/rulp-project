// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrIndexOf)

  ROH a = interpreter->compute(frame, args->get(1));
  ROH b = interpreter->compute(frame, args->get(2));

  auto a_str = a.get()->asString();
  auto b_str = b.get()->asString();

  if (args->size() == 3) {
    return RulpFactory::createInteger(STR_INDEX_OF(a_str, b_str));
  } 
  else {
    ROH pos = interpreter->compute(frame, args->get(3));
    return RulpFactory::createInteger(STR_INDEX_OF_FROM(a_str, b_str, AS_INT(pos)->asInteger()));
  }

XRFACTOR_IMPL_ARG(3, 4)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrIndexOf, F_STR_INDEX_OF);

} // namespace lfc