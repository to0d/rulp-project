// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_SRC_XRMODEL_H__
#define __RULP_RULE_SRC_XRMODEL_H__
#include "rulp/rule/IRModel.h"
#include "rulp/class/AbsRInstance.h"
#include "rulp/object/IRClass.h"
#include "XRModelCount.h"

namespace lfc {

class XRModel
  : public AbsRInstance 
  , virtual public IRModel
{
public:

  XRModel(StrConstRef modelName, IRClass* rclass, IRFrame* frame);

public:

  virtual IRRule* addRule(StrConstRef ruleName, IRList* condList, IRList* actionList) override;

  virtual int getPriority() override;

  virtual RRunState getRunState() override;

  virtual RRunState halt() override;

  virtual int start(int priority, int limit) override;

protected:

  void _setRunState(RRunState state, bool force = false);

protected:
  
  int modelPriority = RETE_PRIORITY_DEFAULT;

  IRVar* modelStatsVar = nullptr;
  
  RRunState modelRunState = RRunState::Completed; // default

  XRModelCount counter;

  // XRRModelCounter modelCounter;

};


} // namespace lfc
#endif //__RULP_RULE_SRC_XRMODEL_H__