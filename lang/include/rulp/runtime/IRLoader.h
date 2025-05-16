// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IROBJECTLOADER_H__
#define __RULP_RUNTIME_IROBJECTLOADER_H__

#include "rulp/runtime/IRInterpreter.h"
#include "rulp/runtime/IRFrame.h"
namespace lfc {

class IRLoader {
public:

  virtual void load(IRInterpreter* interpreter, IRFrame* frame) = 0;
 
};


} // namespace lfc
#endif //__RULP_RUNTIME_IROBJECTLOADER_H__