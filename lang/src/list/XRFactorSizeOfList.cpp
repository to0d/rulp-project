// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSizeOfList)

  ROH obj1 = interpreter->compute(frame, args->get(1));
  auto list = AS_LIST(obj1.get());

  return RulpFactory::createInteger(list->size());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSizeOfList, F_SIZE_OF_LIST);

} // namespace lfc
