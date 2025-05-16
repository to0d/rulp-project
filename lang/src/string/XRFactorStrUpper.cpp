// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrUpper)

  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto a = interpreter->compute(frame, args->get(1));
  auto a_str = a->asString();
  auto new_str = STR_TO_UPPER(a_str);

  if(a_str == new_str){
    return a;
  }

  AUTO_INC_DEC(a);
  return RulpFactory::createString(new_str);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrUpper, F_STR_UPPER);

} // namespace lfc