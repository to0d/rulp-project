// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {

static IRObject* getPropertyList(IRObject* obj) {

  std::vector<IRObject*> properties;

  switch (TYPE_INDEX_OF(obj)) {
  case E_MEMBER: {

    auto mbr = AS_MEMBER(obj);
    properties.push_back(toObject(mbr->getAccessType()));

    if (RulpUtil::isPropertyFinal(mbr)) {
      properties.push_back(O_Final);
    }

    if (RulpUtil::isPropertyStatic(mbr)) {
      properties.push_back(O_Static);
    }

    break;
    }

  case E_CLASS: {
    auto rclass = AS_CLASS(obj);
    if (rclass->isFinal()) {
      properties.push_back(O_Final);
    }

    break;
  }

  default:
    break;
  }

  return RulpFactory::createList(std::move(properties));
}


XRFACTOR_IMPL_BEGIN(XRFactorPropertyOf)

  auto obj = args->get(1);
  switch (TYPE_INDEX_OF(obj)) {
  case E_MEMBER:
    obj = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
    break;

  case E_ATOM: {
    auto entry = frame->getEntry(AS_ATOM(obj)->getName());
    if (entry != null) {
      obj = entry->getValue();
    }

    break;
  }

  default:
    break;
  }

  return getPropertyList(obj);

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPropertyOf, F_PROPERTY_OF);

} // namespace lfc
