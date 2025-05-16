// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/ReturnTypeUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorGetAttribute)

  auto obj  = RulpUtil::lookup(args->get(1), interpreter, frame);
  ROH  rst  = interpreter->compute(frame, args->get(2));
  auto attr = AttrUtil::getAttributeValue(obj, RulpUtil::toString(rst));
  
  if (attr == null) {
    attr = O_Nil;
  }

  return attr;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorGetAttribute, F_GET_ATTRIBUTE);

} // namespace lfc
