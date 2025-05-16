// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/TraceUtil.h"
#include <sstream>

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorOptStatus)

  std::stringstream ss;
  TraceUtil::printOptimizeInfo(ss, interpreter);
  interpreter->write(ss.str());

  return O_Nil;

XRFACTOR_IMPL_ARG(1, 1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorOptStatus, F_OPT_STATUS);
} // namespace lfc