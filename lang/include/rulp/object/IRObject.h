// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IROBJECT_H__
#define __RULP_LANG_IROBJECT_H__

#include "lfc/base/trace_macro.h"
#include "rulp/lang/base.h"
#include "rulp/lang/RType.h"
namespace lfc {

class IRObject;

class IRObjectDeleteListener {

public:
	virtual ~IRObjectDeleteListener() = default;

	virtual void objectBeforeDelete(IRObject* obj) = 0;

	virtual void release() = 0;

};

typedef IRObjectDeleteListener* object_listener;

class IRObject{
  friend class RulpFactory;

public:
  virtual ~IRObject() = default;

public:

  virtual void  decRef() = 0;
  virtual int   getMaxRef() const = 0;
  virtual int   getRef() const = 0;
  virtual void  incRef() = 0;
  virtual bool  isDeleted() const = 0;

public:

  virtual void addObjectDeletedListener(object_listener listener) = 0;

  virtual RType getType() const = 0;
  
  virtual const std::string& asString() const = 0;
  
  virtual bool  isCallable() const = 0;

  virtual bool  isSubject() const = 0;

protected:

  virtual void  _delete() = 0;

};

} // namespace lfc
TRACE_SUB_MODULE_DEF(rulp_obj)
LFC_TO_STRING_DEF(lfc::IRObject);
#endif //__RULP_LANG_IROBJECT_H__