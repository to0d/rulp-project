// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAddArrayToList)

  auto obj1 = interpreter->compute(frame, args->get(1));
  auto obj2 = interpreter->compute(frame, args->get(2));

  auto l1   = AS_LIST(obj1);
  auto arr2 = AS_ARRAY(obj2);
  if(arr2->isEmpty()){
    AUTO_INC_DEC(arr2);
    return l1;
  }

  AUTO_INC_DEC(l1);
  AUTO_INC_DEC(arr2);

  return RulpUtil::addAll(l1, arr2);

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAddArrayToList, F_ADD_ARRAY_TO_LIST);

} // namespace lfc
