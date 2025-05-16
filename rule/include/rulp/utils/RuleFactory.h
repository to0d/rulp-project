// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_RULEFACTORY_H__
#define __RULP_RULE_RULEFACTORY_H__
#include "rulp/rule/IRModel.h"

namespace lfc {

class RuleFactory {
public:

  static IRModel* createModel(StrConstRef name, IRClass* rclass, IRFrame* frame);

};

} // namespace lfc
#endif //__RULP_RULE_RULEFACTORY_H__