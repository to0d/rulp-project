// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include <string.h>

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrEqualNoCase)

  ROH a = interpreter->compute(frame, args->get(1));
  ROH b = interpreter->compute(frame, args->get(2));

  auto a_str = a.get()->asString();
  auto b_str = b.get()->asString();

  if(a_str.length() != b_str.length())
    return O_False;

  return strncasecmp(a_str.c_str(), b_str.c_str(), a_str.length()) == 0 ? O_True : O_False;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrEqualNoCase, F_STR_EQUAL_NOCASE);

} // namespace lfc