// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_OBJ_ITER_LIST_WRAPPER_H__
#define __RULP_OBJ_ITER_LIST_WRAPPER_H__
#include "rulp/object/IRObjectIterator.h"
#include "rulp/object/IRList.h"
#include "rulp/runtime/IRIterator.h"
#include "AbsRefObjectIterator.h"


namespace lfc {

class XRObjectIteratorListWrapper 
  : public AbsRefObjectIterator
  , virtual public IRObjectIterator
{

public:

  XRObjectIteratorListWrapper(IRList* list);
  
  virtual ~XRObjectIteratorListWrapper() = default;

public:

  virtual boolean hasNext() const override;

  virtual IRObject* next() override;

  virtual IRObject* peek() const override;

protected:

  virtual void  _delete() override;

private:

	IRList* list;

	int pos = 0;

	int element_size;

};


} // namespace lfc
#endif //__RULP_OBJ_ITER_LIST_WRAPPER_H__