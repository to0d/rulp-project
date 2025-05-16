// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "AbsRListIterator.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

void AbsRListIterator::_delete() {
  if(elements != null){
    for(auto& e : *elements){
      RULP_DEC_REF(e);
      e = NULL;
    }

    elements->clear();

    delete elements;
    elements = null;
  }

  AbsRList::_delete();
}

IRObject* AbsRListIterator::get(int index) const {
  _scanTo(index);

  if (element_size == -1) {
    return (*elements)[index];
  }

  return (element_size == -1 || index < element_size) ? (*elements)[index] : null;
}

bool AbsRListIterator::isEmpty() const {
  _scanTo(0);
  return element_size == 0;
}

class AbsRListIteratorIterator 
  : virtual public IRIterator
{

public:

  AbsRListIteratorIterator(const AbsRListIterator* iter, int index) 
    : index(index)
    , iter(iter)
  {}

  AbsRListIteratorIterator(AbsRListIteratorIterator& A){
    this->index = A.index;
    this->iter  = A.iter;
  }

  virtual ~AbsRListIteratorIterator() {};

  virtual bool hasNext() const override {
    return iter->_scanTo(index);
  }

  virtual IRObject* next() const override {
    return iter->get(index++);
  }

private:

  mutable int index;
  const AbsRListIterator* iter;

};


IRIteratorPtr AbsRListIterator::listIterator(int from) const {
  return IRIteratorPtr(new AbsRListIteratorIterator(this, from));
}



} // namespace lfc