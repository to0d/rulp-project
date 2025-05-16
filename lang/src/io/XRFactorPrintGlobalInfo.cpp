// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/TraceUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorPrintGlobalInfo)

  interpreter->write(TraceUtil::printInterpreterInfo(interpreter));
  interpreter->write("\n\n");
  interpreter->write(TraceUtil::printGlobalInfo());

  return O_Nil;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintGlobalInfo, F_PRINT_GLOBAL_INFO);

} // namespace lfc