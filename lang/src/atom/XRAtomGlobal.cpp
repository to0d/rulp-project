// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRAtomGlobal.h"

namespace lfc {

XRAtomGlobal::XRAtomGlobal(const std::string atomName)
  : atomName(atomName)
{}

XRAtomGlobal::XRAtomGlobal(const std::string atomName, RName* rName)
  : atomName(atomName)
  , rName(rName)
{}

const std::string& XRAtomGlobal::asString() const {
  return atomName;
}

std::string XRAtomGlobal::getName() const {
  return atomName;
}

RName* XRAtomGlobal::getRName() const {
  return rName;
}

RType XRAtomGlobal::getType() const {
  return T_ATOM;
}

void XRAtomGlobal::setName(StrConstRef name){
  atomName = name;
}

} // namespace lfc