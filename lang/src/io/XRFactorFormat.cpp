// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/FormatUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorFormat)

  std::vector<std::string> lines ;
  FormatUtil::format(args->get(1), lines, 0);

  for (auto line : lines) {
    interpreter->write(line + "\n");
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorFormat, F_FORMAT);

} // namespace lfc