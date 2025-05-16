// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorHasMbr)

  auto sub  = AS_SUBJECT(interpreter->compute(frame, args->get(1)));
  auto name = AS_ATOM(args->get(2));

  return RulpFactory::createBoolean(sub->hasMember(name->getName()));
   
XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorHasMbr, F_HAS_MBR);

} // namespace lfc
