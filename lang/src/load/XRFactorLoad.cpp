// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string.h"
#include "rulp/utils/LoadUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorLoad)

  int size = args->size();

  std::string name;
  std::string charset;

  auto loadObj = interpreter->compute(frame, args->get(1));

  switch (TYPE_INDEX_OF(loadObj)) {
  case E_STRING:
    name = AS_STR(loadObj)->asString();
    break;

  case E_ATOM:
    name = AS_ATOM(loadObj)->asString();
    break;

  default:
    throw RException("Invalid parameters: " + args->asString());
  }

  if (size== 3) {
    charset = AS_STR(interpreter->compute(frame, args->get(2)))->asString();
  }
  

  if (STR_END_WITH(name, ".jar")) {
    // LoadUtil.loadJar(interpreter, frame, name);
    throw RException("not support load: " + name);
  } 
  else {
    LoadUtil::loadScript(interpreter, frame, name, charset);
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorLoad, F_LOAD);

} // namespace lfc