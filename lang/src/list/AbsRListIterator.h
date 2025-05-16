// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ABSLIST_ITERATOR_H__
#define __RULP_LANG_ABSLIST_ITERATOR_H__
#include "rulp/object/IRList.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRIterator.h"
#include "AbsRList.h"
#include "assert.h"

namespace lfc {

class AbsRListIteratorIterator;
class AbsRListIterator 
  : public AbsRList
  , virtual public IRList
  , virtual public IRExpr
{
  friend class AbsRListIteratorIterator;

public:

  AbsRListIterator(RType type, std::string name) : AbsRList(type, name) {};

  virtual ~AbsRListIterator() = default;

public:

  virtual IRObject* get(int index) const override;  

  virtual bool isEarly() const override { return false; }

  virtual bool isEmpty() const override;

  virtual IRIteratorPtr listIterator(int from) const override;

protected:

  virtual void  _delete() override;

  virtual boolean _scanTo(int toIndex) const = 0;

protected:

  mutable std::vector<IRObject*>* elements = null;
  
  mutable int element_size = -1;

};


} // namespace lfc
#endif //__RULP_LANG_ABSLIST_ITERATOR_H__