// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorMakeArray)

  int dimension = args->size() - 1;
  if (dimension == 0) {
    return RulpFactory::createVaryArray();
  }

  std::vector<int> sizes;
  auto it = args->listIterator(1);
  while (it->hasNext()) {
    ROH obj = interpreter->compute(frame, it->next());
    sizes.push_back(AS_INT(obj.get())->asInteger());
  }

  return RulpFactory::createVaryArray(sizes);

XRFACTOR_IMPL_ARG(-1, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorMakeArray, F_MAKE_ARRAY);

} // namespace lfc
