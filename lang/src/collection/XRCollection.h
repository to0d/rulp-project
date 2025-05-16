// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_IMPL_COLLECTION_XRCOLLECTION_H__
#define __RULP_IMPL_COLLECTION_XRCOLLECTION_H__
#include "rulp/collection/IRCollection.h"
#include "rulp/object/IRObject.h"
#include "rulp/object/IRList.h"
#include <map>
#include <set>
namespace lfc {

class XRCollection {

public:
  ~XRCollection();

public:

  void add(IRObject* obj);

  boolean isEmpty();

  int remove(IRObject* obj);

  void retainAll(const XRCollection& another);

  IRList* toList();

private:

  void _add(IRObject* obj);

  int _remove(IRObject* obj);

private:
 
  std::map<std::string, IRObject*>* nameObjMap = null;

	std::set<IRObject*>* objectCollection = null;

};

} // namespace lfc
#endif //__RULP_IMPL_COLLECTION_XRCOLLECTION_H__