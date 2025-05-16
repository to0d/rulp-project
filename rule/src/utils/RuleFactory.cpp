// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/RuleFactory.h"
#include "../model/XRModel.h"

namespace lfc {

IRModel* RuleFactory::createModel(StrConstRef name, IRClass* rclass, IRFrame* frame) {
  return new XRModel(name, rclass, frame);
}


}