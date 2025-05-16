// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/LCOUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/AttrUtil.h"
#include "lfc/base/string/util.h"
#include "rulp/object/AbsObject.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

static int argCount = 0;

static int hitCount = 0;

static int passCount = 0;

static int rebuildCount = 0;

int LCOUtil::getArgCount(){
  return argCount;
}

int LCOUtil::getHitCount(){
  return hitCount;
}

int LCOUtil::getPassCount(){
  return passCount;
}

int LCOUtil::getRebuildCount(){
  return rebuildCount;
}

void LCOUtil::incHitCount(){
  ++hitCount;
}

void LCOUtil::incPassCount(){
  ++passCount;
}

boolean LCOUtil::rebuild(const std::vector<IRParaAttr*>& paras){
  ++rebuildCount;

  int update = 0;
  for (auto attr : paras) {
    if (attr->getParaType() != T_Expr) {
      AttrUtil::addAttribute(attr, A_OPT_LCO);
      ++argCount;
      ++update;
    }
  }

  return update > 0;
}

void LCOUtil::reset(){
  argCount = 0;
  hitCount = 0;
  passCount = 0;
  rebuildCount = 0;
}

} // namespace lfc