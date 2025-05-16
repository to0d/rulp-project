// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/object/AbsObject.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpOptUtil.h"
#include "rulp/lang/RException.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace lfc;
using namespace lfc;

namespace lfc {

static std::vector<std::string> EMPTY_VEC = {};

AbsObject::~AbsObject() {
  LFC_FREE(_attributeKeyList);
  LFC_FREE(attributeMap);
}

void AbsObject::addAttribute(StrConstRef key){
  setAttribute(key, null);
}

boolean AbsObject::containAttribute(StrConstRef key){
  if (attributeMap == null) {
    return false;
  }

  auto attrKey = AttrUtil::toValidAttribute(key);
  if (attrKey.empty()) {
    return false;
  }

  return attributeMap->find(key) != attributeMap->end();
}

int AbsObject::getAttributeCount() const {
  return attributeMap == null ? 0 : attributeMap->  size();
}

const std::vector<std::string>& AbsObject::getAttributeKeyList() {
  if (_attributeKeyList == null) {

    if (attributeMap == null) {
      return EMPTY_VEC;
    }

    _attributeKeyList = new std::vector<std::string>();
    for(auto it = attributeMap->begin(); it != attributeMap->end(); ++it){
      _attributeKeyList->push_back(it->first);
    }

    std::sort(_attributeKeyList->begin(), _attributeKeyList->end());
  }

  return *_attributeKeyList;
}

IRObject* AbsObject::getAttributeValue(StrConstRef key){
  if (attributeMap == null) {
    return null;
  }

  auto attrKey = AttrUtil::toValidAttribute(key);
  if (attrKey.empty()) {
    throw RException("invalid attribute key: " + key);
  }

  auto it = attributeMap->find(key);
  if(it == attributeMap->end())
    return null;

  return it->second;
}

void AbsObject::removeAllAttributes(){

  LFC_FREE(_attributeKeyList);
  LFC_FREE(attributeMap);
  
  attributeMap = null;
  _attributeKeyList = null;
}

IRObject* AbsObject::removeAttribute(StrConstRef key){
  if (attributeMap == null) {
    return null;
  }

  std::string attrKey = AttrUtil::toValidAttribute(key);
  if (attrKey.empty()) {
    throw RException("invalid attribute key: " + key);
  }

  auto value = lfc::erase(*attributeMap, attrKey);
  if (attributeMap->empty()) {
    attributeMap = null;
  }

  if (value != null) {
    _attributeKeyList = null;
  }

  return value;
}

void AbsObject::setAttribute(StrConstRef key, IRObject* value){
  auto attrKey = AttrUtil::toValidAttribute(key);
  if (attrKey.empty()) {
    throw RException("invalid attribute key: " + key);
  }

  if (value == null) {
    value = O_Nil;
  } 
  else if (TYPE_INDEX_OF(value) != E_ATOM && !RulpOptUtil::isConstValue(value)) {
    throw RException("invalid attribute value: " + value->asString());
  }

  if (attributeMap == null) {
    attributeMap = new std::map<std::string, IRObject*>();
  }

  (*attributeMap)[attrKey] = value;
  _attributeKeyList = null;
}

} // namespace lfc