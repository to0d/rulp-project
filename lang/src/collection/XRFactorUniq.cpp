// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"

namespace lfc {

static std::string _getKey(IRFunction* fun, IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) {

  if (fun == null) {
    return RulpUtil::toString(obj);
  }

  ROH rst = RuntimeUtil::computeFun2(fun, interpreter, frame, {obj});

  return RulpUtil::toString(rst.get());
}

XRFACTOR_IMPL_BEGIN(XRFactorUniq)

  auto list = AS_LIST(interpreter->compute(frame, args->get(1)));
  IRFunction* fun = args->size() == 3 ? AS_FUNC(interpreter->compute(frame, args->get(2))) : null;
  AUTO_INC_DEC(fun);

  std::vector<IRObject*> newList;
  std::set<std::string> keySet;
  auto it = list->iterator();

  while (it->hasNext()) {

    auto obj = it->next();
    auto key = _getKey(fun, obj, interpreter, frame);
    if (keySet.count(key) == 0) {
      keySet.insert(key);
      newList.push_back(obj);
    }
  }

  if (newList.size() == list->size()) {
    return list;
  }

  return RulpFactory::createList(std::move(newList));

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorUniq, F_UNIQ);

} // namespace lfc
