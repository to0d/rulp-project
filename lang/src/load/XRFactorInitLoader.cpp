// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string.h"
#include "rulp/utils/LoadUtil.h"

namespace lfc {

XRFACTOR_IMPL_BEGIN(XRFactorInitLoader)

  ROH obj = interpreter->compute(frame, args->get(1));
  auto loaderName = AS_STR(obj.get())->asString();
  LoadUtil::initLoader(loaderName, interpreter, frame);

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorInitLoader, F_INIT_LOADER);

} // namespace lfc