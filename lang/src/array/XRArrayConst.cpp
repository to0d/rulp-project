// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRArrayConst.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/lang/RException.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

void XRArrayConst::_delete() {
  RULP_DEC_REF(elements);
  AbsRefObject::_delete();
}

XRArrayConst* XRArrayConst::build(std::vector<IRObject*>&& elements){

  int dimension = 1;
  for (auto element : elements) {
    if (TYPE_INDEX_OF(element) == E_ARRAY) {
      auto elementArray = RulpUtil::asArray(element);
      if (elementArray->getDimension() >= dimension) {
        dimension = elementArray->getDimension() + 1;
      }
    }
  }

  if (dimension < 1 || dimension > 2) {
    throw RException("support dimension: " + TO_STR(dimension));
  }

  int elementCount = 0;
  int arrayDimension = dimension;

  std::vector<int> arraySize(dimension, 0);

  for (int i = 0; i < dimension; ++i) {
    arraySize[i] = 0;
  }

  arraySize[0] = elements.size();

  for (auto element : elements) {
    if (element != null && TYPE_INDEX_OF(element) != E_NIL) {
      elementCount++;
      RULP_INC_REF(element);
      if (TYPE_INDEX_OF(element) == E_ARRAY) {
        auto elementArray = RulpUtil::asArray(element);
        int size1 = elementArray->size();
        if (size1 > arraySize[1]) {
          arraySize[1] = size1;
        }
      }
    }
  }

  XRArrayConst* array = new XRArrayConst();

  array->arraySize    = std::move(arraySize);
  array->elements     = std::move(elements);
  array->elementCount = elementCount;

  return array;

}

void XRArrayConst::add(IRObject* obj) {
  throw RException("not support");
}

IRArray* XRArrayConst::cloneArray() const {

  XRArrayConst* newArray  = new XRArrayConst();
  RULP_INC_OBJ_CREATE_COUNT(T_ARRAY);
  
  newArray->elementCount  = elementCount;
  newArray->elements      = elements;
  newArray->arraySize     = arraySize;

  RULP_INC_REF(elements);
  return newArray;
}

IRObject* XRArrayConst::get(int index) const {
  return elements[index];
}

IRObject* XRArrayConst::_get(const IRObject* arrayObj, const std::vector<int>& indexs, int from) const {
  if (from == indexs.size()) {
    return const_cast<IRObject*>(arrayObj);
  }

  const int index = indexs[from];
  if (index < 0 || index >= arraySize[from]) {
    throw RException("Invalid index: " + TO_STR(index));
  }

  if (arrayObj == null) {
    return null;
  }

  if (TYPE_INDEX_OF(arrayObj) != E_ARRAY) {
    return index == 0 ? const_cast<IRObject*>(arrayObj) : null;
  }

  auto array = AS_ARRAY(arrayObj);
  IRObject* obj = null;
  if (index < array->size()) {
    obj = array->get(index);
  }

  return _get(&*obj, indexs, from + 1);
}

IRObject* XRArrayConst::get(const std::vector<int>& indexs) const {
  if (indexs.size() == 1) {

    int index = indexs[0];
    if (index < 0 || index >= size()) {
      throw RException("Invalid index: " + TO_STR(index));
    }

    return index < elements.size() ? elements[index] : null;

  } else {

    return _get(this, indexs, 0);
  }
}

int XRArrayConst::getDimension() const {
  return arraySize.size();
}

int XRArrayConst::getElementCount() const {
  return elementCount;
}

bool XRArrayConst::isEmpty() const {
  return getDimension() == 0 || size() == 0;
}

void XRArrayConst::set(int index, IRObject* obj) {
  throw RException("not support");
}

int XRArrayConst::size() const {
  return arraySize[0];
}

int XRArrayConst::size(int dim) const {
  if (dim < 0) {
    throw RException("Invalid dim: " + TO_STR(dim));
  }

  if (dim < arraySize.size()) {
    return arraySize[dim];
  }

  return 0;
}

const std::string& XRArrayConst::asString() const {
  if(_string.empty()){
    _string = RulpUtil::toString(this);
  }

  return _string;
}

RType XRArrayConst::getType() const {
  return T_ARRAY;
}


} // namespace lfc