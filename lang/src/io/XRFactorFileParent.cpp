// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/file.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorFileParent)

  ROH obj = interpreter->compute(frame, args->get(1));
  auto path = AS_STR(obj.get())->asString();

  return RulpFactory::createString(FS_TO_VALID_PATH(FS_FILE_PARENT(path)));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorFileParent, F_FILE_PARENT);

} // namespace lfc