// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ABSREFOBJECT
#define __RULP_LANG_ABSREFOBJECT
#include "rulp/object/IRObject.h"
#include "AbsObject.h"
namespace lfc {

class AbsRefObject 
  : public AbsObject
  , virtual public IRObject
{

public:
  virtual ~AbsRefObject() = default;

public:

  virtual void addObjectDeletedListener(object_listener listener) override;

  virtual void decRef() override;
  
  virtual int getMaxRef() const override;
  
  virtual int getRef() const override;
  
  virtual void incRef() override;
  
  virtual bool isCallable() const override { return false; } 

  virtual bool isDeleted() const override;

  virtual bool isSubject() const override { return false; }

protected:

  virtual void _delete() override;

protected:

  int ref = 0;
  int max_ref = 0;

  std::vector<object_listener>* objDeletedListenerList = null;
};

} // namespace lfc
#endif //__RULP_LANG_ABSREFOBJECT