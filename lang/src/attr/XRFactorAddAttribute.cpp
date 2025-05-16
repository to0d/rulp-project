// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAddAttribute)

  auto obj = RulpUtil::lookup(args->get(1), interpreter, frame);
  ROH  rst = interpreter->compute(frame, args->get(2));
  auto attr = rst.get()->asString();

  if (args->size() == 3) {
    AttrUtil::addAttribute(obj, attr);
  } 
  else {
    AttrUtil::setAttribute(obj, attr, args->get(3));
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(3, 4)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAddAttribute, F_ADD_ATTRIBUTE);

} // namespace lfc
