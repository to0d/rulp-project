// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string/format.h"
#include "lfc/base/to_string.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRemoveAllList)

  auto list1 = AS_LIST(interpreter->compute(frame, args->get(1)));
  if (list1->isEmpty()) {
    return list1;
  }

  auto list2 = AS_LIST(interpreter->compute(frame, args->get(2)));
  if (list2->isEmpty()) {
    AUTO_INC_DEC(list2);
    return list1;
  }

  std::set<std::string> removedNameSet;
  {
    auto it = list2->iterator();
    while (it->hasNext()) {
      removedNameSet.insert(RulpUtil::toUniqString(it->next()));      
    }
  }

  std::vector<IRObject*> rstList;
  bool head_copied = false;

  int size = list1->size();
  int deleteCount = 0;
  for (int i = 0; i < size; ++i) {

    auto obj = list1->get(i);

    // remove
    if (removedNameSet.count(RulpUtil::toUniqString(obj)) != 0) {
      if (!head_copied) {
        for (int j = 0; j < i; ++j) {
          rstList.push_back(list1->get(j));
        }
        head_copied = true;
      }

      deleteCount++;
    }
    // keep
    else {
      if (head_copied) {
        rstList.push_back(obj);
      }
    }
  }

  if (deleteCount == 0) {
    AUTO_INC_DEC(list2);
    return list1;
  }

  AUTO_INC_DEC(list1);
  AUTO_INC_DEC(list2);
  return RulpFactory::createList(std::move(rstList));

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRemoveAllList, F_REMOVE_ALL_LIST);

} // namespace lfc
