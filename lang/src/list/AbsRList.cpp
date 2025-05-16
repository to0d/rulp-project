// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "AbsRList.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

RType AbsRList::getType() const{
  return type;
}

const std::string& AbsRList::getNamedName() const{
  return name;
}

IRIteratorPtr AbsRList::iterator() const{
  return listIterator(0);
}

const std::string& AbsRList::asString() const {
  if(_string.empty()){
    _string = RulpUtil::toString(this);
  }

  return _string;
}

} // namespace lfc