// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRINSTANCE_H__
#define __RULP_LANG_IRINSTANCE_H__
#include "rulp/object/IRObject.h"
#include "rulp/object/IRSubject.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class IRClass;
class IRInstance 
  : virtual public IRObject
  , virtual public IRSubject 
{

public:

  virtual void deleteIt(IRInterpreter* interpreter, IRFrame* frame) = 0;

  virtual int getInstanceKey() const = 0;

  virtual std::string getInstanceName() const = 0;

  virtual IRClass* getRClass() const = 0;

  virtual void init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) = 0;

  virtual bool isError() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRINSTANCE_H__