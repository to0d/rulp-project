// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorToNoNamedList)

  auto list = AS_LIST(interpreter->compute(frame, args->get(1)));
  return RulpUtil::toList("", list, frame);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorToNoNamedList, F_TO_NONAMED_LIST);

} // namespace lfc