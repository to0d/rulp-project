// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string/util.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrSubStr)

  if (args->size() != 3 && args->size() != 4) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto strObj     = interpreter->compute(frame, args->get(1));
  auto str        = strObj->asString();
  int  str_len    = str.length();

  auto beginObj   = interpreter->compute(frame, args->get(2));
  int  beginIndex = AS_INT(beginObj)->asInteger();
  if(beginIndex < 0) {
    beginIndex = 0;
  }

  if (beginIndex >= str_len) {
    AUTO_INC_DEC(strObj);
    AUTO_INC_DEC(beginObj);
    return O_EMPTY_STR;
  }

  if (args->size() == 3) {
    if(beginIndex == 0) {
      AUTO_INC_DEC(beginObj);
      return strObj;
    }

    AUTO_INC_DEC(strObj);
    AUTO_INC_DEC(beginObj);
    return RulpFactory::createString(str.substr(beginIndex));
  }

  auto endObj   = interpreter->compute(frame, args->get(3));
  int endIndex  = AS_INT(endObj)->asInteger();
  if (endIndex <= beginIndex) {
    AUTO_INC_DEC(strObj);
    AUTO_INC_DEC(beginObj);
    AUTO_INC_DEC(endObj);
    return O_EMPTY_STR;
  }

  if (endIndex > str_len) {
    endIndex = str_len;
  }

  if (beginIndex == 0 && endIndex == str_len) {
    AUTO_INC_DEC(beginObj);
    AUTO_INC_DEC(endObj);
    return strObj;
  }

  AUTO_INC_DEC(strObj);
  AUTO_INC_DEC(beginObj);
  AUTO_INC_DEC(endObj);
  return RulpFactory::createString(str.substr(beginIndex, endIndex));

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrSubStr, F_STR_SUBSTR);

} // namespace lfc