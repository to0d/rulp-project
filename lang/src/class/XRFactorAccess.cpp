// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAccess)

  auto obj = args->get(1);
  switch (TYPE_INDEX_OF(obj)) {
  case E_MEMBER:
    obj = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
    break;

  default:
    break;
  }

  return RulpFactory::createBoolean(RuntimeUtil::canAccess(obj, interpreter, frame));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAccess, F_ACCESS);

} // namespace lfc
