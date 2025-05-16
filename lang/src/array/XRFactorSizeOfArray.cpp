// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSizeOfArray)

  int argSize = args->size();

  auto array = AS_ARRAY(interpreter->compute(frame, args->get(1)));
  AUTO_INC_DEC(array);
  if (argSize == 2) {
    return RulpFactory::createInteger(array->size());
  }

  auto dim = AS_INT(interpreter->compute(frame, args->get(2)));
  AUTO_INC_DEC(dim);

  return RulpFactory::createInteger(array->size(dim->asInteger()));

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSizeOfArray, F_SIZE_OF_ARRAY);

} // namespace lfc
