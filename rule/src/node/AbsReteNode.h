// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_SRC_ABSRETENODE_H__
#define __RULP_RULE_SRC_ABSRETENODE_H__
#include "rulp/rule/IRReteNode.h"
#include "rulp/class/AbsRInstance.h"

namespace lfc {

class AbsReteNode
  : public AbsRInstance 
  , virtual public IRReteNode
{
public:

};


} // namespace lfc
#endif //__RULP_RULE_SRC_ABSRETENODE_H__