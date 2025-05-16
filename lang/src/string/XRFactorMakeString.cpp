// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include <sstream>

using namespace lfc;

static IRString* makeString(IRBlob* blob)  {

  if (blob->length() == 0) {
    return O_EMPTY_STR;
  }

  std::string str(blob->getValue(), blob->length());
  return RulpFactory::createString(str);
}

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorMakeString)

  auto obj = interpreter->compute(frame, args->get(1));
  AUTO_INC_DEC(obj);
  
  switch (TYPE_INDEX_OF(obj)) {
  case E_BLOB:
    return makeString(AS_BLOB(obj));

  default:
    throw RException("not support: " + obj->asString());
  }

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorMakeString, F_MAKE_STRING);

} // namespace lfc