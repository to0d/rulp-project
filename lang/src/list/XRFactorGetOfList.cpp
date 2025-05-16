// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorGetOfList)

  ROH obj1 = interpreter->compute(frame, args->get(1));
  ROH obj2 = interpreter->compute(frame, args->get(2));

  auto list = AS_LIST(obj1.get());
  auto idx  = AS_INT(obj2.get());

  return list->get(idx->asInteger());

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorGetOfList, F_GET_OF_LIST);

} // namespace lfc
