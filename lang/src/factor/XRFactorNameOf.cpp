// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorNameOf)

  int size = args->size();
  if (size > 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto name = RulpUtil::nameOf(args->get(1), frame);
  if(name.empty()){
    return O_Nil;
  }

  return RulpFactory::createString(name);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorNameOf, F_NAME_OF);

} // namespace lfc