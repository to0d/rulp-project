// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorGetMbr)

  auto sub  = AS_SUBJECT(interpreter->compute(frame, args->get(1)));
  auto name = AS_ATOM(args->get(2));

  auto rst = sub->getMember(name->getName())->getValue();
  if (TYPE_INDEX_OF(rst) == E_VAR) {
    rst = AS_VAR(rst)->getValue();
  }

  return rst;

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorGetMbr, F_O_MBR);

} // namespace lfc
