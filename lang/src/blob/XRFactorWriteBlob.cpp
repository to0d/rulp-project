// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/to_string.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorWriteBlob)

  ROH obj1 = interpreter->compute(frame, args->get(1));
  ROH obj2 = interpreter->compute(frame, args->get(2));
  ROH obj3 = interpreter->compute(frame, args->get(3));
  ROH obj4 = interpreter->compute(frame, args->get(4));
  ROH obj5 = interpreter->compute(frame, args->get(5));

  auto dstBlob = AS_BLOB(obj1.get());
  auto blobPos = AS_INT(obj2.get())->asInteger();
  auto srcBlob = AS_BLOB(obj3.get());
  auto srcPos  = AS_INT(obj4.get())->asInteger();
  auto cpyLen  = AS_INT(obj5.get())->asInteger();

  int len = dstBlob->write(blobPos, srcBlob->getValue(), srcBlob->length(), srcPos, cpyLen);

  return RulpFactory::createInteger(len);

XRFACTOR_IMPL_ARG(6, 6)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorWriteBlob, F_WRITE_BLOB);
} // namespace lfc