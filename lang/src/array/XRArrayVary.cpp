// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRArrayVary.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/lang/RException.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/to_string.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

XRArrayVary* XRArrayVary::build(const std::vector<int>& sizes){
  int dimension = sizes.size();

  if (dimension < 1 || dimension > 2) {
    throw RException("support dimension: " + TO_STR(dimension));
  }

  XRArrayVary* array = new XRArrayVary();
  array->arraySize = sizes;

  if (dimension == 2) {
    array->arraySize[0] = 0;
    int size1 = sizes[1];
    for (int i = 0; i < sizes[0]; ++i) {
      array->add(RulpFactory::createVaryArray({size1}));
    }
  }

  if (dimension == 1) {
    array->elements.resize(sizes[0]);
  }
  
  return array;
}


void XRArrayVary::_add(IRObject* obj) {
  elements.push_back(obj);
  arraySize[0]++;

  if (obj != null && TYPE_INDEX_OF(obj) != E_NIL) {
    elementCount++;
    RULP_INC_REF(obj);
  }
}

void XRArrayVary::add(IRObject* obj) {

  if (obj == null || TYPE_INDEX_OF(obj) == E_NIL) {
    _add(obj);
    return;
  }

  if (TYPE_INDEX_OF(obj) != E_ARRAY) {
    _add(obj);
    return;
  }

  auto ei = AS_ARRAY(obj);
  if (ei->getDimension() != 1) {
    throw RException("Invalid element: " + obj->asString());
  }

//		if (ei.getElementCount() == 0) {
//			return;
//		}

  if (getDimension() > 2) {
    throw RException("Invalid array: " + this->asString());
  }

  if (getDimension() == 1) {
    arraySize.push_back(0);
  }

  _add(ei);

  int elementSize = ei->size();
  if (arraySize[1] < elementSize) {
    arraySize[1] = elementSize;
  }

}

IRArray* XRArrayVary::cloneArray() const {

  XRArrayVary* newArray  = new XRArrayVary();
  RULP_INC_OBJ_CREATE_COUNT(T_ARRAY);

  newArray->elementCount  = elementCount;
  newArray->elements      = elements;
  newArray->arraySize     = arraySize;

  return newArray;
}

void XRArrayVary::_set(int index, IRObject* obj) {
  for (int i = elements.size(); i <= index; ++i) {
    elements.push_back(null);
  }

  elements[index] = obj;
}

void XRArrayVary::set(int index, IRObject* newObj) {
  if (index < 0 || index >= size()) {
    throw RException("invalid index: " + TO_STR(index));
  }

  auto oldObj = get(index);
  int on = oldObj == null ? 0 : 1;
  int nn = 0;

  if (newObj != null && TYPE_INDEX_OF(newObj) != E_NIL) {
    nn = 1;
    RULP_INC_REF(newObj);
  }

  _set(index, nn == 1 ? newObj : null);
  elementCount += nn - on;


  RULP_DEC_REF(oldObj);
}

} // namespace lfc