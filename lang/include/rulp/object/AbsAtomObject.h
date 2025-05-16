// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ABSATOMOBJECT
#define __RULP_LANG_ABSATOMOBJECT
#include "rulp/object/IRAtom.h"
#include "AbsObject.h"

namespace lfc {

class AbsAtomObject
  : public AbsObject
  , virtual public IRObject 
{

public:

  virtual ~AbsAtomObject() = default;

public:

  virtual void addObjectDeletedListener(object_listener listener) override {};

  virtual void decRef() override {}

  virtual int getMaxRef() const override { return 0; }

  virtual int getRef() const override { return 0; }

  virtual void incRef() override {} 

  virtual bool isCallable() const override { return false; } 

  virtual bool isDeleted() const override { return false; }

  virtual bool isSubject() const override { return false; }

protected:

  virtual void  _delete() override {};

};


} // namespace lfc
#endif //__RULP_LANG_ABSATOMOBJECT