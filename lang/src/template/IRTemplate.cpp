// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRTemplate.h"
#include <sstream>

using namespace lfc;

namespace lfc {

TemplatePara::TemplatePara(const TemplatePara& para) {
  isVar     = para.isVar;
  paraType  = para.paraType;
  paraValue = para.paraValue;
}

std::string TemplatePara::toString() const {

  std::stringstream ss;

  ss << "'(";
  if (isVar) {
    ss << '?';
  }

  if (paraValue != null) {
    ss << paraValue->asString();
  }

  if (paraType != null && paraType != O_Nil) {
    ss << ' ';
    ss << paraType->asString();
  }

  ss << ')';

  return ss.str();
}

std::string TemplateParaEntry::toString() const {
  
  std::stringstream ss;

  ss << "'(";

  int i = 0;
  for(auto& tp : fixedParas){
    if (i++ != 0) {
      ss << ' ';
    }

    ss << tp.toString();
  }

  if (isVary) {
    ss << " ?...";
  }

  ss << ')';

  return ss.str();
}

} // namespace lfc