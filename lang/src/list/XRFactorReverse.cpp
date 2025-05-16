// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"
#include <algorithm>

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorReverse)

  auto list = AS_LIST(interpreter->compute(frame, args->get(1)));
  if (list->size() <= 1) {
    return list;
  }

  std::vector<IRObject*> rvsList;
  auto it = list->iterator();
  while (it->hasNext()) {
    rvsList.push_back(it->next());
  }

  std::reverse(rvsList.begin(), rvsList.end());
  AUTO_INC_DEC(list);

  return RulpFactory::createList(std::move(rvsList));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorReverse, F_REVERSE);

} // namespace lfc
