// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRCALLABLE_H__
#define __RULP_RUNTIME_IRCALLABLE_H__

#include "rulp/object/IRObject.h"
#include "rulp/object/IRList.h"
#include "rulp/runtime/IRAfterAnnotation.h"
#include "rulp/runtime/IRBeforeAnnotation.h"
#include "rulp/runtime/IRInterpreter.h"
#include "rulp/utils/DeCounter.h"
namespace lfc {

class IRCallable
  : virtual public IRObject
{
public:
 
  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) = 0;

  virtual IRAfterAnnotation* getAfterAnnotation(StrConstRef attr) const = 0;

  virtual IRBeforeAnnotation* getBeforeAnnotation(StrConstRef attr) const = 0;

  virtual DeCounter* getCallCount(int statsId) = 0;

  virtual boolean hasAfterAnnotation() const = 0;

  virtual boolean hasBeforeAnnotation() const = 0;

  virtual void incCallCount(int statsId, int callId) = 0;

    // boolean isDebug();

  virtual const std::vector<std::string>& listAfterAnnotationAttr() const = 0;

  virtual const std::vector<std::string>& listBeforeAnnotationAttr() const = 0;

  virtual void registerAfterAnnotation(StrConstRef attr, IRAfterAnnotation* anno) = 0;

  virtual void registerBeforeAnnotation(StrConstRef attr, IRBeforeAnnotation* anno) = 0;

    // void setDebug(boolean debug);

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRCALLABLE_H__