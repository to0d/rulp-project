// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorAttributeOf)

  auto obj = RulpUtil::lookup(args->get(1), interpreter, frame);

  std::vector<IRObject*> attrList;
  for (auto key : AttrUtil::getAttributeKeyList(obj)) {

    auto value = AttrUtil::getAttributeValue(obj, key);
    if (value == O_Nil) {
      attrList.push_back(RulpUtil::toAtom(key));
    } 
    else {
      attrList.push_back(RulpFactory::createList({RulpUtil::toAtom(key), value}));
    }

  }

  return RulpFactory::createList(std::move(attrList));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorAttributeOf, F_ATTRIBUTE_OF);

} // namespace lfc
