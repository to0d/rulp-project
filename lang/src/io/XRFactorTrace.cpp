// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include <sstream>

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorTrace)

  if (RulpUtil::isTrace(frame) && args->size() > 1) {
    std::stringstream ss;

    auto it = args->listIterator(1);
    while (it->hasNext()) {

      auto obj = interpreter->compute(frame, it->next());
      if (TYPE_INDEX_OF(obj) == E_STRING) {
        ss << AS_STR(obj)->asString();
      } 
      else {
        ss << obj->asString();
      }
    }

    interpreter->write(ss.str());
    interpreter->write("\n");
  }

  return O_Nil;

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorTrace, F_TRACE);

} // namespace lfc