// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAddListToArray)

  auto obj1 = interpreter->compute(frame, args->get(1));
  auto obj2 = interpreter->compute(frame, args->get(2));

  auto arr   = AS_ARRAY(obj1);
  auto list  = AS_LIST(obj2);

  AUTO_INC_DEC(list);
  return RulpUtil::addAll(arr, list);

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAddListToArray, F_ADD_LIST_TO_ARRAY);

} // namespace lfc
