// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_IRRULE_H__
#define __RULP_RULE_IRRULE_H__
#include "rulp/object/IRVar.h"
#include "rulp/rule/IRReteNode.h"
#include "rulp/rule/IRRunnable.h"

namespace lfc {

class IRRule 
  : virtual public IRReteNode
  , virtual public IRRunnable
{
public:

  // void addRuleExecutedListener(IRListener1<IRRule> listener);

  // void addRuleFailedListener(IRListener1<IRRule> listener);

  // List<IAction> getActionList();

  virtual std::vector<IRExpr*> getActionStmtList() = 0;
 
  virtual std::vector<IRReteNode*> getAllNodes() = 0;

  // IRRuleCounter getCounter();

  virtual IRList* getLastValues() = 0;

  virtual IRModel* getModel() = 0;

  // IReteNodeMatrix getNodeMatrix();

  virtual int getPriority() = 0;

  virtual std::string getRuleDecription() = 0;

  virtual std::string getRuleName() = 0;

  virtual IRReteNode* getRuleNode() = 0;

  virtual std::vector<IRVar*> getVars() = 0;

  virtual void setRuleDecription(StrConstRef ruleDecription) = 0;

  virtual const std::vector<IRList*>& getMatchStmtList() = 0;

};

} // namespace lfc
#endif //__RULP_RULE_IRRULE_H__