// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"
#include "XRCollection.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorUnion)

  XRCollection unionCol;

  if (args->size() == 2) {
    auto arg = interpreter->compute(frame, args->get(1));
    if (TYPE_INDEX_OF(arg) != E_LIST) {
        throw RException(LFC_STR_FORMAT_BGN 
                            "the type of arg %d is not %s: %s"
                          , 1
                          , T_LIST->getName().c_str()
                          , args->get(1)->asString().c_str()
                          LFC_STR_FORMAT_END);
    }

    auto iter = AS_LIST(arg)->iterator();
    while (iter->hasNext()) {
      auto obj = iter->next();
      if (TYPE_INDEX_OF(obj) != E_LIST) {
          throw RException(LFC_STR_FORMAT_BGN 
                              "the type of obj %d is not %s: %s"
                            , 1
                            , T_LIST->getName().c_str()
                            , arg->asString().c_str()
                            LFC_STR_FORMAT_END);
      }
      unionCol.add(obj);
    }
  }
  else {

    for (int i = 1; i < args->size(); ++i) {
      auto arg = interpreter->compute(frame, args->get(i));
      if (TYPE_INDEX_OF(arg) != E_LIST) {
        throw RException(LFC_STR_FORMAT_BGN 
                                "the type of arg %d is not %s: %s"
                              , i
                              , T_LIST->getName().c_str()
                              , arg->asString().c_str()
                              LFC_STR_FORMAT_END);
      }
      unionCol.add(arg);
    }
  }

  return unionCol.toList();

XRFACTOR_IMPL_ARG(2, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorUnion, F_UNION);

} // namespace lfc
