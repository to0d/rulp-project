// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRObjectIteratorListWrapper.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

XRObjectIteratorListWrapper::XRObjectIteratorListWrapper(IRList* list) : list(list) {
  element_size = list->size();
  RULP_INC_REF(list);
}

void XRObjectIteratorListWrapper::_delete() {
  if(list != NULL) {
    RULP_DEC_REF(list);
    list = NULL;
  }
  AbsRefObjectIterator::_delete();
}

boolean XRObjectIteratorListWrapper::hasNext() const {
  return pos < element_size;
}

IRObject* XRObjectIteratorListWrapper::next() {
  if (pos >= element_size) {
    throw RException(LFC_STR_FORMAT_BGN "Iterator out of space: pos=%d, size=%d", pos, element_size LFC_STR_FORMAT_END);
  }

  return list->get(pos++);
}

IRObject* XRObjectIteratorListWrapper::peek() const {
  return list->get(pos);
}

} // namespace lfc