// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorSearchFrameOf)

  int size = args->size();

  IRFrame* tgtFrame = frame;
  if (size > 1) {
    tgtFrame = AS_FRAME(interpreter->compute(frame, args->get(1)));
  }

  auto frameList = tgtFrame->getSearchFrameList();
  if(frameList == NULL){
    return O_EMPTY_LIST;
  }

  std::vector<IRObject*> objs;
  for(auto f : *frameList){
    objs.push_back(f); 
  }


  return RulpFactory::createList(std::move(objs));

XRFACTOR_IMPL_ARG(1, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorSearchFrameOf, F_SEARCH_FRAEM_OF);

} // namespace lfc