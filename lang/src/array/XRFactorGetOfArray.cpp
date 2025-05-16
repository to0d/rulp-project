// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorGetOfArray)

  auto rst = interpreter->compute(frame, args->get(1));
  AUTO_INC_DEC(rst);

  auto array = AS_ARRAY(rst);
  int dim = array->getDimension();
  if (dim != (args->size() - 2)) {
    throw RException(LFC_STR_FORMAT_BGN 
                        "Unmatch dimension: expect=%d, actual=%d"
                      , args->size() - 2
                      , dim
                      LFC_STR_FORMAT_END);
  }

  std::vector<int> indexs (dim, 0);
  for (int i = 0; i < dim; ++i) {
    ROH obj = interpreter->compute(frame, args->get(2 + i));
    indexs[i] = AS_INT(obj.get())->asInteger();
  }

  return array->get(indexs);

XRFACTOR_IMPL_ARG(3, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorGetOfArray, F_GET_OF_ARRAY);

} // namespace lfc
