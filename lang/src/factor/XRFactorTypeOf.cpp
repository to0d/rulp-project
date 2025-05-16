// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorTypeOf)

  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto obj  = args->get(1);
  auto type = TYPE_INDEX_OF(obj);

  if (type == E_ATOM) {
    auto entry = frame->getEntry(RulpUtil::asAtom(obj)->getName());
    if (entry != null) {
      type = TYPE_INDEX_OF(entry->getObject());
    }
  }

  return toObject(type);

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorTypeOf, F_TYPE_OF);

} // namespace lfc