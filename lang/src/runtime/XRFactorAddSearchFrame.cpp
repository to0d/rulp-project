// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAddSearchFrame)

  ROH obj1 = interpreter->compute(frame, args->get(1));
  auto tgtFrame = AS_FRAME(obj1);
  auto searchFrame = AS_FRAME(interpreter->compute(frame, args->get(2)));
  tgtFrame->addSearchFrame(searchFrame);

  return searchFrame;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAddSearchFrame, F_ADD_SEARCH_FRAME);

} // namespace lfc
