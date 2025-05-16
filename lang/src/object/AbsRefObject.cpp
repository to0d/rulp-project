// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <assert.h>
#define LFC_TRACE_NAME   "[rulp_obj]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_obj)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#define USE_LFC_NEW_TRACE
#include "rulp/object/AbsRefObject.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RulpUtil.h"
#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"

using namespace lfc;
using namespace lfc;

namespace lfc {

void AbsRefObject::addObjectDeletedListener(object_listener listener) {
  if (objDeletedListenerList == null) {
    objDeletedListenerList = new std::vector<object_listener>();
  }

  objDeletedListenerList->push_back(listener);
}

void AbsRefObject::decRef(){

  // if(TYPE_INDEX_OF(this) == E_ATOM){
  //   std::cout << "--atom: " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_CLASS){
  //   std::cout << "--class: " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_INSTANCE){
  //   std::cout << "--instance: " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_VAR && AS_VAR(this)->getName() == "student"){
  //   std::cout << "-- " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_MEMBER){
  //   std::cout << "-- " << this->asString() << ", ref=" << ref << ", addr=" << this  << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_MEMBER && AS_MEMBER(this)->getName() == "o1"){
  //   std::cout << "-- " << this->asString() << ", ref=" << ref << ", addr=" << this  << "\n";
  // }

  if (ref <= 0){
    LFC_TRACE4("obj=", lfc::to_string(this), ", ref=", lfc::to_string(ref));
    assert(false && "invalid ref, can't decRef object");
  }

  if (--ref == 0) {
    RULP_FREE(this);
  }
}

void AbsRefObject::_delete(){
 
  if (ref != 0) {
    LFC_TRACE4("obj=", lfc::to_string(this), ", ref=", lfc::to_string(ref));
    assert(false && "invalid ref, can't delete object");
  }

  if (objDeletedListenerList != null) {

    std::vector<object_listener> _tmpListeners(*objDeletedListenerList);
    delete objDeletedListenerList;
    objDeletedListenerList = null;

    for (auto listener : _tmpListeners) {
      listener->objectBeforeDelete(this);
    }

    for (auto listener : _tmpListeners) {
      listener->release();
      delete listener;
    }

  }

  ref = -1;    
}

int AbsRefObject::getMaxRef() const { 
  return max_ref; 
}

int AbsRefObject::getRef() const { 
  return ref; 
}

void AbsRefObject::incRef(){

  // if(TYPE_INDEX_OF(this) == E_ATOM){
  //   std::cout << "++atom:" << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_CLASS){
  //   std::cout << "++class: " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_INSTANCE){
  //   std::cout << "++instance: " << this->asString() << ", ref=" << ref << ", addr=" << this << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_FRAME){
  //   std::cout << "\n";
  // }
  // if(TYPE_INDEX_OF(this) == E_VAR && AS_VAR(this)->getName() == "student"){
  //   std::cout << "++ " << this->asString() << ", ref=" << ref << ", addr=" << this  << "\n";
  // }

  // if(TYPE_INDEX_OF(this) == E_MEMBER ){
  //   std::cout << "++ " << this->asString() << ", ref=" << ref << ", addr=" << this  << "\n";
  // } 

  // if(TYPE_INDEX_OF(this) == E_MEMBER && AS_MEMBER(this)->getName() == "o1" ){
  //   std::cout << "++ " << this->asString() << ", ref=" << ref << ", addr=" << this  << "\n";
  // }

  if (ref < 0) {    
    LFC_TRACE4("obj=", lfc::to_string(this), ", ref=", lfc::to_string(ref));
    assert(false && "invalid ref, can't incRef object");
  }

  if (++ref > max_ref) {
    max_ref = ref;
  }
} 

bool AbsRefObject::isDeleted() const { 
  return ref < 0;
}


} // namespace lfc