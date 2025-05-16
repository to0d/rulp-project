// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRef)

  int size = args->size();
  if (size !=2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto varName = AS_ATOM(args->get(1))->getName();
  auto entry = frame->getEntry(varName);
  if (entry != null) {
    return AS_VAR(entry->getObject());
  }

  auto var = RulpFactory::createVar(varName);
  frame->setEntry(varName, var);

  return var;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRef, F_REF);

} // namespace lfc