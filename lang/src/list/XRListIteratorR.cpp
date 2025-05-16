// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRListIteratorR.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {


XRListIteratorR::XRListIteratorR(IRObject* list, IRIteratorPtr iter, RType type, std::string name) 
  : AbsRListIterator(type, name)
  , list(list)
  , inputIterator(iter)
{
  RULP_INC_REF(list);
}

void XRListIteratorR::_delete() {

  if(list != null ){
    RULP_DEC_REF(list);
    list = null;
  }

  AbsRListIterator::_delete();
}

boolean XRListIteratorR::_scanTo(int toIndex) const {
  
  if (element_size != -1) {
    return toIndex < element_size;
  }

  while (toIndex >= scanSize) {

    if (!inputIterator->hasNext()) {
      element_size = scanSize;
      return toIndex < element_size;
    }

    auto obj = inputIterator->next();

    if (elements == null) {
      elements = new std::vector<IRObject*>();
    }

    elements->push_back(obj);
    RULP_INC_REF(obj);
    ++scanSize;
  }

  return true;
}

void XRListIteratorR::add(IRObject* obj) {
  assert(false && "Can't add object to const list");
}

bool XRListIteratorR::isConst() const { 
  return true; 
}

int XRListIteratorR::size() const {
  if (element_size == -1) {

    while (inputIterator->hasNext()) {

      auto obj = inputIterator->next();

      if (elements == null) {
        elements = new std::vector<IRObject*>();
      }

      elements->push_back(obj);
      RULP_INC_REF(obj);
      ++scanSize;
    }

    element_size = scanSize;
  }

  return element_size;
}

} // namespace lfc
