// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRFRAME_H__
#define __RULP_RUNTIME_IRFRAME_H__

#include "rulp/object/IRObject.h"
#include "rulp/object/IRSubject.h"
#include "rulp/runtime/IRFrameEntry.h"
#include "rulp/runtime/IRThreadContext.h"
#include "rulp/runtime/IRListener1.h"
namespace lfc {

typedef IRListener1<IRFrame*> FrameListener;

class IRFrame 
  : virtual public IRObject
  , virtual public IRSubject 
{
public:
 
  virtual void addFrameReleaseListener(FrameListener* listener) = 0;

  virtual void addSearchFrame(IRFrame* frame) = 0;

  virtual IRFrameEntry* createFrameEntry(StrConstRef name, IRObject* object) = 0;

  virtual IRObject* findLocalObject(StrConstRef name) = 0;

  virtual IRFrameEntry* getEntry(StrConstRef name) = 0;

  virtual int getFrameId() const = 0;

  virtual std::string getFrameName() const = 0;

  // IRObject getObject(String name);
// 
  virtual IRFrame* getParentFrame() const = 0;

  virtual std::vector<IRFrame*>* getSearchFrameList() const = 0;

  virtual IRSubject* getSubject() = 0;

  virtual IRThreadContext* getThreadContext() const = 0;

  virtual const std::vector<IRFrameEntry*>& listEntries() const = 0;

  virtual void release() = 0;

  virtual IRFrameEntry* removeEntry(StrConstRef name) = 0;

  virtual void setEntry(StrConstRef name, IRObject* obj) = 0;

  virtual void setEntryAliasName(IRFrameEntry* entry, StrConstRef aliasName) = 0;

  // void setFrameLoader(IRFrameLoader frameLoader);

  virtual void setThreadContext(IRThreadContext* context) = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRFRAME_H__