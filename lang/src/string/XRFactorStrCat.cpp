// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include <sstream>

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrCat)

  std::stringstream ss;

  auto it = args->listIterator(1);
  while (it->hasNext()) {
    ROH next = interpreter->compute(frame, it->next());
    ROH rst  = RulpUtil::toString(next, interpreter);
    ss << AS_STR(rst.get())->asString();
  }

  return RulpFactory::createString(ss.str());

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrCat, F_STRCAT);

} // namespace lfc