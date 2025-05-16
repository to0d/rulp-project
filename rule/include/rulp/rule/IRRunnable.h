// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_IRRUNNABLE_H__
#define __RULP_RULE_IRRUNNABLE_H__

#include "rulp/rule/RRunState.h"
namespace lfc {

class IRRunnable {

public:
 
  virtual int getPriority() = 0;

  virtual RRunState getRunState() = 0;

  virtual RRunState halt() = 0;

  virtual int start(int priority, int limit) = 0;

};

} // namespace lfc
#endif //__RULP_RULE_IRRUNNABLE_H__