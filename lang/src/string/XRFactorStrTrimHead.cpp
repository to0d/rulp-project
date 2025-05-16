// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrTrimHead)

  auto a = interpreter->compute(frame, args->get(1));
  auto a_str = a->asString();

  if (a_str.length() == 0 || a_str.at(0) != ' ') {
    return a;
  }

  AUTO_INC_DEC(a);
  return RulpFactory::createString(lfc::StringUtil::trimHead(a_str, {' '}));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrTrimHead, F_STR_TRIM_HEAD);

} // namespace lfc