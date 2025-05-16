// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAlias)

  int argSize = args->size();

  if (argSize < 3) {
    throw RException("Invalid parameter number: " + args->asString());
  }

  IRFrameEntry* srcEntry = null;

  for (int i = 1; i < argSize; ++i) {

    auto arg = RulpUtil::asAtom(args->get(i));
    auto entry = frame->getEntry(arg->getName());

    if (i == 1) {

        if (entry == null) {
          throw RException("src entry not found: " + arg->asString());
        }

        switch (TYPE_INDEX_OF(entry->getObject())) {
        case E_ATOM:
        case E_FACTOR:
        case E_FUNC:
        case E_MACRO:
        case E_VAR:
            break;
        default:
            throw RException("src entry type not support: " + entry->asString());
        }

        srcEntry = entry;

    } 
    else {

      if (entry != null) {
        throw RException(
                    LFC_STR_FORMAT_BGN 
                        "the name of arg %d is already defined: %s, entry=%s"
                      , i
                      , arg->asString().c_str()
                      , entry->asString().c_str()
                    LFC_STR_FORMAT_END);
      }

    }
  }

  for (int i = 2; i < argSize; ++i) {
    frame->setEntryAliasName(srcEntry, AS_ATOM(args->get(i))->getName());
  }

  return srcEntry->getObject();

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAlias, F_ALIAS);

} // namespace lfc