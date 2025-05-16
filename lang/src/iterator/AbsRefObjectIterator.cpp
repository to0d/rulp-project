// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "AbsRefObjectIterator.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

RType AbsRefObjectIterator::getType() const{
  return T_ITERATOR;
}

const std::string& AbsRefObjectIterator::asString() const {
  
  if(_string.empty()){
    _string = RulpUtil::toString(this);
  }

  return _string;
}

} // namespace lfc