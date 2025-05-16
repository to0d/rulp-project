// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RName.h"

#include "lfc/base/to_string.h"

using namespace lfc;

namespace lfc {

RName::RName(std::string nameSpace, std::string prefix, std::string subName, std::string fullName)
  : nameSpace(nameSpace)
  , prefix(prefix)
  , subName(subName)
  , fullName(fullName)
{
  shortName = prefix + ":" + subName;
}

RName::RName(const RName& R)
  : nameSpace(R.nameSpace)
  , prefix(R.prefix)
  , subName(R.subName)
  , fullName(R.fullName)
{
  shortName = prefix + ":" + subName;
}

const std::string& RName::getShorName() const{
  return shortName;
}

} // namespace lfc

namespace lfc {

LFC_TO_STRING_IMPL(lfc::RName, RN){
  if( !RN )
    return "RN(null)";

  std::string out = "RN(";

  out += "ns=";
  out += RN->nameSpace;

  out += ", pre=";
  out += RN->prefix;

  out += ", sub=";
  out += RN->subName;

  out += ", full=";
  out += RN->fullName;

  out += ")";

  return out;
}
  
} // namespace lfc