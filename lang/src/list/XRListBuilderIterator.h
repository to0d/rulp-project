// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_OBJECT_XRLIST_BUILDER_ITER_H__
#define __RULP_OBJECT_XRLIST_BUILDER_ITER_H__
#include "AbsRListIterator.h"
#include "rulp/object/IRList.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRIterator.h"

namespace lfc {


template <typename _Ty, typename _T_builder>
class XRListBuilderIterator 
  : public AbsRListIterator
  , virtual public IRList
  , virtual public IRExpr
{

public:

  XRListBuilderIterator(RType type, std::string name, std::vector<_Ty>&& inputElements, _T_builder builder) 
    : AbsRListIterator(type, name)
    , inputElements(inputElements)
    , builder(builder)
  {}
 
  virtual ~XRListBuilderIterator() = default;

public:

  virtual void add(IRObject* obj) override {
    assert(false && "Can't add object to const list");
  }
 
  virtual int size() const override {

    if (element_size == -1) {

      while (scanSize < inputElements.size()) {
        auto obj = builder(inputElements[scanSize]);
            if (elements == null) {
          elements = new std::vector<IRObject*>();
        }

        elements->push_back(obj);
        RULP_INC_REF(obj);
        ++scanSize;
      }

      element_size = scanSize;
    }

    return element_size;
  }
  
  virtual bool isConst() const override {
    return true;
  }

protected:

  virtual boolean _scanTo(int toIndex) const override {
    if (element_size != -1) {
      return toIndex < element_size;
    }

    while (toIndex >= scanSize) {
      if (scanSize == inputElements.size()) {
        element_size = scanSize;
        return toIndex < element_size;
      }

      auto obj = builder(inputElements[scanSize]);
      if (elements == null) {
        elements = new std::vector<IRObject*>();
      }

      elements->push_back(obj);
      RULP_INC_REF(obj);
      ++scanSize;
    }

    return true;
  }

protected:

  mutable _T_builder        builder;
  mutable std::vector<_Ty>  inputElements;
  mutable int               scanSize = 0;

};


} // namespace lfc
#endif //__RULP_OBJECT_XRLIST_BUILDER_ITER_H__