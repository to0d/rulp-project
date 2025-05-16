// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/AbsAtomFactorAdapter.h"

using namespace lfc;

namespace lfc {

AbsAtomFactorAdapter::AbsAtomFactorAdapter(StrConstRef factorName)
  : factorName(factorName)
{

}

AbsAtomFactorAdapter::~AbsAtomFactorAdapter(){

}

StrConstRef AbsAtomFactorAdapter::asString() const {
  return factorName;
}

RType AbsAtomFactorAdapter::getType() const {
  return T_FACTOR;
}
 
StrConstRef AbsAtomFactorAdapter::getName() const {
  return factorName;
}

} // namespace lfc