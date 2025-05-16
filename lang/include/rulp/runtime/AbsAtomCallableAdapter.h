// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_ABSATOMCALLABLEADAPTER_H_
#define __RULP_XIMPL_RUNTIME_ABSATOMCALLABLEADAPTER_H_
#include "rulp/runtime/IRCallable.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class AbsAtomCallableAdapter 
  : public AbsAtomObject
  , virtual public IRCallable
{

public:

  AbsAtomCallableAdapter();

  virtual ~AbsAtomCallableAdapter();

public:
 
  virtual IRAfterAnnotation* getAfterAnnotation(StrConstRef attr) const override;

  virtual IRBeforeAnnotation* getBeforeAnnotation(StrConstRef attr) const override;

  virtual DeCounter* getCallCount(int statsId) override;

  virtual boolean hasAfterAnnotation() const override;

  virtual boolean hasBeforeAnnotation() const override;

  virtual void incCallCount(int statsId, int callId) override;

  virtual bool isCallable() const override { return true; }

  virtual const std::vector<std::string>& listAfterAnnotationAttr() const override;

  virtual const std::vector<std::string>& listBeforeAnnotationAttr() const override;

  virtual void registerAfterAnnotation(StrConstRef attr, IRAfterAnnotation* anno) override;

  virtual void registerBeforeAnnotation(StrConstRef attr, IRBeforeAnnotation* anno) override;

private:

  DeCounter* callCounter = NULL;

  int statsId = -1;

  mutable std::vector<std::string>* _afterAnnotationAttrList = null;

  mutable std::vector<std::string>* _beforeAnnotationAttrList = null;

  std::map<std::string, IRAfterAnnotation*>* afterAnnotationMap = null;

  std::map<std::string, IRBeforeAnnotation*>* beforeAnnotationMap = null;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_ABSATOMCALLABLEADAPTER_H_