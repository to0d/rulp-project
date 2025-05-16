// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRListVary.h"
#include "rulp/utils/RulpUtil.h"
#include "lfc/base/auto/auto_free.h"
#define LFC_TRACE_NAME   "[rulp_obj]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_obj)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#define USE_LFC_NEW_TRACE

using namespace lfc;
using namespace lfc;

namespace lfc {

XRListVary::XRListVary(RType type, std::string name)
  : AbsRList(type, name)
{
  // std::cout << "create verylist: name=" << name << ", addr=" << this << "\n";
}

void XRListVary::_delete(){
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

void XRListVary::add(IRObject* obj) {
  if (elements == null) {
    elements = new std::vector<IRObject*>();
  }

  elements->push_back(obj);
  element_size++;

  RULP_INC_REF(obj);
}

IRObject* XRListVary::get(int index) const {
  return index < element_size ? (*elements)[index] : null;
}

int XRListVary::size() const { 
  return element_size; 
}

bool XRListVary::isConst() const { 
  return false; 
}

bool XRListVary::isEarly() const { 
  return false;
} 

bool XRListVary::isEmpty() const {
  return element_size == 0;
}

class XRListVaryIterator 
  : virtual public IRIterator
{

public:

  XRListVaryIterator(const XRListVary* list, int index) 
    : index(index)
    , list(list)
  {}

  XRListVaryIterator(XRListVaryIterator& A){
    this->index = A.index;
    this->list  = A.list;
  }

  virtual ~XRListVaryIterator() {};

  virtual bool hasNext() const override {
    return index < list->size();
  }

  virtual IRObject* next() const override {
    return list->get(index++);
  }

private:

  mutable int index;
  const XRListVary* list;

};

IRIteratorPtr XRListVary::listIterator(int from) const {
  return IRIteratorPtr(new XRListVaryIterator(this, from));
}

} // namespace lfc