// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include <iostream>

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorReturn)

  int size = args->size();

  IRObject* rt = O_Nan;
  if(size == 2){
    rt = interpreter->compute(frame, args->get(1));
    // std::cout << "rst= " << rt->asString() << "\n"; 
  }

  throw RExceptionReturn(this, frame, rt);

XRFACTOR_IMPL_ARG(-1, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorReturn, F_RETURN);

} // namespace lfc
