// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRAtomRef.h"
#include <iostream>

namespace lfc {

XRAtomRef::XRAtomRef(const std::string atomName)
  : atomName(atomName)
{
  //  if(atomName == "?value")
  // std::cout << "create atom: name=" << atomName << ", addr=" << this << "\n";
}

XRAtomRef::XRAtomRef(const std::string atomName, RName* rName)
  : atomName(atomName)
  , rName(rName)
{
  //  std::cout << "create named atom: name=" << atomName << ", addr=" << this << "\n";
}

XRAtomRef::~XRAtomRef(){

  //  if(atomName == "?value")
  // std::cout << "delete atom: name=" << atomName << ", addr=" << this << "\n";
}

const std::string& XRAtomRef::asString() const {
  return atomName;
}

std::string XRAtomRef::getName() const {
  return atomName;
}

RName* XRAtomRef::getRName() const {
  return rName;
}

RType XRAtomRef::getType() const {
  return T_ATOM;
}

} // namespace lfc