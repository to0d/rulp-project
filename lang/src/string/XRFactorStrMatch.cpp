// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string.h"

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorStrMatch)

  ROH mode = interpreter->compute(frame, args->get(1));
  ROH content = interpreter->compute(frame, args->get(2));

  boolean rc;

  if (args->size() == 3) {
    rc = STR_MATCH(mode.get()->asString(), content.get()->asString());
  } 
  else {

    auto outObjs = AS_LIST(args->get(3));
    AUTO_INC_DEC(outObjs);
    if (outObjs->isEmpty()) {
      throw RException("Invalid parameters: " + args->asString());
    }

    std::vector<IRVar*> outVars;
    auto it = outObjs->iterator();
    while(it->hasNext()){
      auto var = it->next();

      if (TYPE_INDEX_OF(var) == E_ATOM) {

        auto entry = frame->getEntry(AS_ATOM(var)->getName());
        if (entry == null) {
          throw RException("var not found: " + var->asString());
        }

        if (TYPE_INDEX_OF(entry->getObject()) != E_VAR) {
          throw RException("not var: " + entry->getObject()->asString());
        }

        outVars.push_back(AS_VAR(entry->getObject()));
      } 
      else {
        outVars.push_back(AS_VAR(interpreter->compute(frame, var)));
      }
    }

    std::vector<std::string> values;
    rc = lfc::StringUtil::matchFormat(mode.get()->asString(), content.get()->asString(), values);

    if (values.size() != outVars.size()) {
      return RulpFactory::createBoolean(false);
    }
    for (int i = 0; i < values.size(); ++i) {
      outVars[i]->setValue(RulpFactory::createString(values[i]));
    }
  }

  return RulpFactory::createBoolean(rc);

XRFACTOR_IMPL_ARG(3, 4)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrMatch, F_STR_MATCH);

} // namespace lfc