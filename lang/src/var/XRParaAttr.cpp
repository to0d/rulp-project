// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRParaAttr.h"
#include "lfc/base/to_string.h"
#include "rulp/utils/RulpUtil.h"

namespace lfc {

XRParaAttr::XRParaAttr(StrConstRef paraName, IRAtom* paraType)
  : XRVarRef(paraName)
  , paraType(paraType)
{}

IRAtom* XRParaAttr::getParaType() const {
  return paraType;
}

std::string XRParaAttr::getParaName() const{
  return this->getName();
}

} // namespace lfc