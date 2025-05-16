// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRCollection.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/collection.h"
#include "lfc/base/container.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

XRCollection::~XRCollection(){
  LFC_FREE(nameObjMap);
  LFC_FREE(objectCollection);

  nameObjMap = null;
  objectCollection = null;
}

void XRCollection::_add(IRObject* obj) {
  if (TYPE_INDEX_OF(obj) == E_ATOM) {

    if (nameObjMap == null) {
      nameObjMap = new std::map<std::string, IRObject*>();
    }

    (*nameObjMap)[AS_ATOM(obj)->getName()] = obj;
  } 
  else {

    if (objectCollection == null) {
      objectCollection = new std::set<IRObject*>();
    }

    objectCollection->insert(obj);
  }
}

int XRCollection::_remove(IRObject* obj) {

  if (TYPE_INDEX_OF(obj) == E_ATOM) {

    if (nameObjMap != null) {
      auto key  = AS_ATOM(obj)->getName();
      auto it   = nameObjMap->find(key);
      if(it != nameObjMap->end()){
        nameObjMap->erase(it);
        return 1;
      }
    }

  } 
  else {
    auto it = objectCollection->find(obj);
    if(it != objectCollection->end()){
      objectCollection->erase(it);
      return 1;
    }
  }

  return 0;
}

void XRCollection::add(IRObject* obj) {
  if (TYPE_INDEX_OF(obj) == E_LIST) {

    auto iter = AS_LIST(obj)->iterator();
    while (iter->hasNext()) {
      _add(iter->next());
    }

  }
  else {
    _add(obj);
  }
}

boolean XRCollection::isEmpty() {
  return (nameObjMap == null || nameObjMap->empty()) && (objectCollection == null || objectCollection->empty());
}

int XRCollection::remove(IRObject* obj) {

  int removed = 0;

  if (TYPE_INDEX_OF(obj) == E_LIST) {

    auto iter = AS_LIST(obj)->iterator();
    while (iter->hasNext()) {
      removed += _remove(iter->next());
    }

  } 
  else {
    removed += _remove(obj);
  }

  return removed;
}

void XRCollection::retainAll(const XRCollection& another) {

  if (this->objectCollection != null) {
    if (another.objectCollection != null) {
      CT_RETAIN_ALL(*this->objectCollection, *another.objectCollection);
    } 
    else {
      LFC_FREE(objectCollection);
      objectCollection = null;
    }
  }

  if (this->nameObjMap != null) {
    if (another.nameObjMap != null) {
      CT_RETAIN_ALL(*this->nameObjMap, *another.nameObjMap);
    } 
    else {
      LFC_FREE(nameObjMap);
      nameObjMap = null;
    }
  }

}

IRList* XRCollection::toList() {
  
  std::vector<IRObject*> rstList;

  if (objectCollection != null) {
    for (auto obj : *objectCollection) {
      rstList.push_back(obj);
    }
  }

  if (nameObjMap != null) {   
    for (auto& e : *nameObjMap) {
      rstList.push_back(e.second);
    }
  }

  RulpUtil::sortByStr(rstList);

  return RulpFactory::createList(std::move(rstList));
}

} // namespace lfc