// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_IRCONTEXT_H__
#define __RULP_RULE_IRCONTEXT_H__

#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class IRModel;
class IRContext {

public:

  virtual IRFrame* findFrame() = 0;

  virtual IRFrame* getFrame() = 0;

  virtual IRInterpreter* getInterpreter() = 0;

  virtual IRModel* getModel() = 0;

  virtual void clean() = 0;

};

} // namespace lfc
#endif //__RULP_RULE_IRCONTEXT_H__