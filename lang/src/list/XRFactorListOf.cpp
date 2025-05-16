// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include <algorithm>

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorListOf)

  IRSubject* sub = frame;
  RRType* type = NULL;

  if (args->size() >= 2) {
    sub = RulpUtil::asSubject(interpreter->compute(frame, args->get(1)));
  }

  if (args->size() >= 3) {
    type = RRType::toType(RulpUtil::asAtom(args->get(2))->getName());
    if (type == null) {
      throw RException("Unknow type:" + args->get(2)->asString());
    }
  }

  int mbr_size = sub->getMemberCount();
  if (mbr_size == 0) {
    return O_EMPTY_LIST;
  }

  std::vector<IRObject*> list;
  for (int i = 0;i < mbr_size; ++i) {
    auto mbr = sub->getMember(i);
    if(type!= NULL){
      auto obj = mbr->getValue();
      if (obj == null || obj->getType() != type) {
        continue;
      }
    }
    list.push_back(mbr);
  }

  std::sort( list.begin()
           , list.end()
           , [](auto a, auto b){ 
              return std::less<std::string>()(a->asString(), b->asString() ); 
              }
          );

  return RulpFactory::createList(std::move(list));

XRFACTOR_IMPL_ARG(-1, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorListOf, F_LIST_OF);

} // namespace lfc