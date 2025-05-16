// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "XRCollection.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorJoin)

  XRCollection joinCol;
  
  for (int i = 1; i < args->size(); ++i) {

    ROH arg = interpreter->compute(frame, args->get(i));
    if (TYPE_INDEX_OF(arg.get()) != E_LIST) {
      throw RException( LFC_STR_FORMAT_BGN 
                            "the type of arg %d is not %s: %s"
                          , 1
                          , T_LIST->getName().c_str()
                          , args->get(1)->asString().c_str()
                          LFC_STR_FORMAT_END);
    }

    if (i == 1) {
      joinCol.add(arg.get());
    }
    else {
      XRCollection thisCol;
      thisCol.add(arg);
      joinCol.retainAll(thisCol);
    }

    if (joinCol.isEmpty()) {
      break;
    }
  }

  return joinCol.toList();

XRFACTOR_IMPL_ARG(2, -1)    
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorJoin, F_JOIN);

} // namespace lfc
