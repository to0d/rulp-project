// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_NS_XRNAMESAPCE
#define __RULP_NS_XRNAMESAPCE
#include "rulp/runtime/IRNameSpace.h"
#include "rulp/class/AbsRInstance.h"
namespace lfc {

class XRNameSpace 
  : public AbsRInstance
  , virtual public IRNameSpace
{

public:

  XRNameSpace(StrConstRef spaceName, IRClass* rclass, IRFrame* frame)
    : AbsRInstance(rclass, spaceName, frame)
  {}
  
  virtual ~XRNameSpace() = default;

};

} // namespace lfc
#endif //__RULP_NS_XRNAMESAPCE