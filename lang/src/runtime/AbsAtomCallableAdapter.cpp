// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/AbsAtomCallableAdapter.h"
#include "rulp/lang/RConstant.h"
#include "lfc/base/auto/auto_free.h"
#include <algorithm>

using namespace lfc;

namespace lfc {

AbsAtomCallableAdapter::AbsAtomCallableAdapter()
{
}

static std::vector<std::string> EMPTY_VEC;

AbsAtomCallableAdapter::~AbsAtomCallableAdapter(){

  LFC_FREE(callCounter);
  callCounter = null;

  if(_afterAnnotationAttrList != &EMPTY_VEC){
    LFC_FREE(_afterAnnotationAttrList);
  }

  if(_beforeAnnotationAttrList != &EMPTY_VEC){
    LFC_FREE(_beforeAnnotationAttrList);
  }
  
  LFC_FREE(afterAnnotationMap);
  LFC_FREE(beforeAnnotationMap);
}

IRAfterAnnotation* AbsAtomCallableAdapter::getAfterAnnotation(StrConstRef attr) const {
  if (afterAnnotationMap == null) {
    return null;
  }

  auto it = afterAnnotationMap->find(attr);
  if(it == afterAnnotationMap->end()){
    return null;
  }

  return it->second;
}

IRBeforeAnnotation* AbsAtomCallableAdapter::getBeforeAnnotation(StrConstRef attr) const {
  if (beforeAnnotationMap == null) {
    return null;
  }

  auto it = beforeAnnotationMap->find(attr);
  if(it == beforeAnnotationMap->end()){
    return null;
  }

  return it->second;
}

boolean AbsAtomCallableAdapter::hasAfterAnnotation() const {
  return afterAnnotationMap != null && !afterAnnotationMap->empty();
}

boolean AbsAtomCallableAdapter::hasBeforeAnnotation() const {
  return beforeAnnotationMap != null && !beforeAnnotationMap->empty();
}

DeCounter* AbsAtomCallableAdapter::getCallCount(int statsId){
  if (this->statsId != statsId) {
    this->statsId = statsId;
    LFC_FREE(callCounter);
    this->callCounter = new DeCounter(MAX_COUNTER_SIZE);
  }

  return callCounter;
}

void AbsAtomCallableAdapter::incCallCount(int statsId, int callId){
  if (this->statsId != statsId) {
    this->statsId     = statsId;
    this->callCounter = new DeCounter(MAX_COUNTER_SIZE);
  }

  callCounter->add(callId);
}


const std::vector<std::string>& AbsAtomCallableAdapter::listAfterAnnotationAttr() const {

  if (_afterAnnotationAttrList == null) {

    if (!hasAfterAnnotation()) {
      _afterAnnotationAttrList = &EMPTY_VEC;
    } 
    else {
      
      _afterAnnotationAttrList = new std::vector<std::string>();

      for(auto it = afterAnnotationMap->begin(); it != afterAnnotationMap->end(); ++it){
        _afterAnnotationAttrList->push_back(it->first);
      }

      std::sort(_afterAnnotationAttrList->begin(), _afterAnnotationAttrList->end());
    }
  }

  return *_afterAnnotationAttrList;
}

const std::vector<std::string>& AbsAtomCallableAdapter::listBeforeAnnotationAttr() const {

  if (_beforeAnnotationAttrList == null) {
    
    if (!hasBeforeAnnotation()) {
      _beforeAnnotationAttrList = &EMPTY_VEC;
    } 
    else {      
      _beforeAnnotationAttrList = new std::vector<std::string>();

      for(auto it = beforeAnnotationMap->begin(); it != beforeAnnotationMap->end(); ++it){
        _beforeAnnotationAttrList->push_back(it->first);
      }

      std::sort(_beforeAnnotationAttrList->begin(), _beforeAnnotationAttrList->end());
    }
  }

  return *_beforeAnnotationAttrList;
}

void AbsAtomCallableAdapter::registerAfterAnnotation(StrConstRef attr, IRAfterAnnotation* anno) {

  if (afterAnnotationMap == null) {
    afterAnnotationMap = new std::map<std::string, IRAfterAnnotation*>();
  }

  (*afterAnnotationMap)[attr] = anno; 

  LFC_FREE(_afterAnnotationAttrList);
  _afterAnnotationAttrList = null;

}

void AbsAtomCallableAdapter::registerBeforeAnnotation(StrConstRef attr, IRBeforeAnnotation* anno) {

  if (beforeAnnotationMap == null) {
    beforeAnnotationMap = new std::map<std::string, IRBeforeAnnotation*>();
  }

  (*beforeAnnotationMap)[attr] = anno; 

  LFC_FREE(_beforeAnnotationAttrList);
  _beforeAnnotationAttrList = null;

}

} // namespace lfc