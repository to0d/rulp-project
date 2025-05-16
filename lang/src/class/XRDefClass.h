// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_XRDEFCLASS_H__
#define __RULP_CLASS_XRDEFCLASS_H__
#include "rulp/object/IRClass.h"
#include "rulp/class/AbsRClass.h"
namespace lfc {

class XRDefClass 
  : public AbsRClass
  , virtual public IRClass
{

public:
  XRDefClass(StrConstRef className) : AbsRClass(className, null, null){};
  
  XRDefClass(StrConstRef className, IRFrame* definedFrame, IRClass* superClass) : AbsRClass(className, definedFrame, superClass){};

  virtual ~XRDefClass() = default;

public:

  virtual IRInstance* newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

};

} // namespace lfc
#endif //__RULP_CLASS_XRDEFCLASS_H__