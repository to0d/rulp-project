// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_NS_XRNAMESAPCE_CLASS_H__
#define __RULP_NS_XRNAMESAPCE_CLASS_H__
#include "rulp/class/AbsRClass.h"
namespace lfc {

class XRNameSpaceClass 
  : public AbsRClass
  , virtual public IRClass
{

public:

  XRNameSpaceClass(StrConstRef className, IRFrame* definedFrame)
    : AbsRClass(className, definedFrame, null)
  {}
  
  virtual ~XRNameSpaceClass() = default;

  virtual IRInstance* newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

};

} // namespace lfc
#endif //__RULP_NS_XRNAMESAPCE_CLASS_H__