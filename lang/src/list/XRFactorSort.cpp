// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"
#include <algorithm>

namespace lfc {

static IRObject* _compare_default(IRList* list) {
  int size = list->size();

  boolean needSort = false;
  for (int i = 1; !needSort && i < size; ++i) {
    int d = RulpUtil::compare(list->get(i - 1), list->get(i));
    if (d != 0) {
      needSort = true;
    }
  }

  if (!needSort) {
    return list;
  }

  auto newList = RulpUtil::toArray(list);
  std::sort(newList.begin(), newList.end(), [](auto& a, auto& b){
    return RulpUtil::compare(a, b) <= 0;
  });

  AUTO_INC_DEC(list);
  return RulpFactory::createList(std::move(newList));
}


XRFACTOR_IMPL_BEGIN(XRFactorSort)

  int argSize = args->size();

  auto list = AS_LIST(interpreter->compute(frame, args->get(1)));
  int size = list->size();
  if (size <= 1) {
    return list;
  }

  if (args->size() == 2) {
    return _compare_default(list);
  }

  ROH obj2 = interpreter->compute(frame, args->get(2));
  auto cmpFunc = AS_FUNC(obj2);
  auto sortFrame = RulpFactory::createFrame(frame, F_SORT);
  AUTO_RLS_FRAME(sortFrame);

  boolean needSort = false;
  for (int i = 1; !needSort && i < size; ++i) {
    ROH expr = RulpFactory::createExpression({cmpFunc, list->get(i - 1), list->get(i)});
    ROH rslt = interpreter->compute(sortFrame, expr);
    int d = AS_INT(rslt.get())->asInteger();
    if (d != 0) {
      needSort = true;
    }
  }

  if (!needSort) {
    return list;
  }

  auto newList = RulpUtil::toArray(list);
  std::sort(newList.begin(), newList.end(), [=](auto& a, auto& b){
    ROH expr = RulpFactory::createExpression({cmpFunc, a, b});
    ROH rslt = interpreter->compute(sortFrame, expr);
    return AS_INT(rslt.get())->asInteger() <= 0;
  });

  return RulpFactory::createList(std::move(newList));

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSort, F_SORT_LIST);

} // namespace lfc
