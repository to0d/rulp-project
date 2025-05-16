// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_XRDEFINSTANCE_H__
#define __RULP_CLASS_XRDEFINSTANCE_H__
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRClass.h"
#include "rulp/class/AbsRInstance.h"
namespace lfc {

class XRDefInstance 
  : public AbsRInstance
  , virtual public IRInstance
{

public:
  
  XRDefInstance(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame);

  virtual ~XRDefInstance();

public:

  virtual void init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

protected:

  virtual void _delete() override;

private:

  IRInterpreter* interpreter = NULL;

};

} // namespace lfc
#endif //__RULP_CLASS_XRDEFINSTANCE_H__