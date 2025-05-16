// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRListConst.h"
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

XRListConst::XRListConst(RType type)
  : AbsRList(type)
  , earlyExpresion(false)
  {

// std::cout << "create const list: name=" << name << ", addr=" << this << "\n";
  }

XRListConst::XRListConst(RType type, std::string name, std::vector<IRObject*>&& elements, bool earlyExpresion)
  : AbsRList(type, name)
  , earlyExpresion(earlyExpresion)
  , elements(elements)
{
  RULP_INC_REF(elements);
}

void XRListConst::_delete(){
  RULP_DEC_REF(elements);
  AbsRList::_delete();
}

void XRListConst::add(IRObject* obj) {
  assert(false && "Can't add object to const list");
}

IRObject* XRListConst::get(int index) const {
  return index < elements.size() ? elements[index] : NULL;
}

int XRListConst::size() const { 
  return elements.size(); 
}

bool XRListConst::isConst() const { 
  return true; 
}

bool XRListConst::isEarly() const { 
  return earlyExpresion;
} 

bool XRListConst::isEmpty() const {
  return elements.empty();
}

class XRListConstIterator 
  : virtual public IRIterator
{

public:

  XRListConstIterator(const XRListConst* list, int index) 
    : index(index)
    , list(list)
  {}

  XRListConstIterator(XRListConstIterator& A){
    this->index = A.index;
    this->list  = A.list;
  }

  virtual ~XRListConstIterator() {};

  virtual bool hasNext() const override {
    return index < list->size();
  }

  virtual IRObject* next() const override {
    return list->get(index++);
  }

private:

  mutable int index;
  const XRListConst* list;

};

IRIteratorPtr XRListConst::listIterator(int from) const {
  return IRIteratorPtr(new XRListConstIterator(this, from));
}

} // namespace lfc