// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/TraceUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorPrintFrameTree)

  interpreter->write(TraceUtil::outputFrameTree(interpreter));

  return O_Nil;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintFrameTree, F_PRINT_FRAME_TREE);

} // namespace lfc