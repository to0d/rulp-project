// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/system.h"


using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSystemOSType)

  if (args->size() != 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  switch (SYS_TYPE) {

  case lfc::OSType::Linux:
    return O_LINUX;

  case lfc::OSType::Win:
    return O_WIN;

  default:
    return O_Nil;
  }

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSystemOSType, F_SYS_OS_TYPE);

} // namespace lfc