// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRLIST_H__
#define __RULP_LANG_IRLIST_H__
#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRIterator.h"

namespace lfc {

class IRList 
  : virtual public IRObject 
{

public:

  virtual void add(IRObject* obj) = 0;

  virtual IRObject* get(int index) const = 0;

  virtual const std::string& getNamedName() const = 0;

  virtual int size() const = 0;

  virtual bool isEmpty() const = 0;

  virtual bool isConst() const = 0;

  virtual IRIteratorPtr iterator() const = 0;

  virtual IRIteratorPtr listIterator(int from) const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRLIST_H__