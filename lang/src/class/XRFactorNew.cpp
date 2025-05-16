// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/ClassUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorNew)

  return ClassUtil::newInstance(args, interpreter, frame);
   
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorNew, F_NEW);

} // namespace lfc
