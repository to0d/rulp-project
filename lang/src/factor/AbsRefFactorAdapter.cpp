// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/AbsRefFactorAdapter.h"

using namespace lfc;

namespace lfc {

AbsRefFactorAdapter::AbsRefFactorAdapter(StrConstRef factorName)
  : factorName(factorName)
{

}

AbsRefFactorAdapter::~AbsRefFactorAdapter(){

}

StrConstRef AbsRefFactorAdapter::asString() const {
  return factorName;
}

RType AbsRefFactorAdapter::getType() const {
  return T_FACTOR;
}

StrConstRef AbsRefFactorAdapter::getName() const {
  return factorName;
}

} // namespace lfc