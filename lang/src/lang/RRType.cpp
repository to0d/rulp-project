// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RRType.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/IRAtom.h"
#include "lfc/base/container.h"
#include <assert.h>
#include <map>

using namespace lfc;

static_assert(sizeof(RInt)  == 4);
static_assert(sizeof(RLong) == 8);
static_assert(sizeof(RFloat) == 4);
static_assert(sizeof(RDouble) == 8);

RRType RR_NIL     (RTypeIndex::E_NIL     , A_NIL);
RRType RR_ATOM    (RTypeIndex::E_ATOM    , A_ATOM);
RRType RR_BOOL    (RTypeIndex::E_BOOL    , A_BOOL);
RRType RR_INT     (RTypeIndex::E_INT     , A_INTEGER);
RRType RR_LONG    (RTypeIndex::E_LONG    , A_LONG);
RRType RR_FLOAT   (RTypeIndex::E_FLOAT   , A_FLOAT);
RRType RR_DOUBLE  (RTypeIndex::E_DOUBLE  , A_DOUBLE);
RRType RR_STRING  (RTypeIndex::E_STRING  , A_STRING);
RRType RR_BLOB    (RTypeIndex::E_BLOB    , A_BLOB);
RRType RR_LIST    (RTypeIndex::E_LIST    , A_LIST);
RRType RR_EXPR    (RTypeIndex::E_EXPR    , A_EXPRESSION);
RRType RR_ARRAY   (RTypeIndex::E_ARRAY   , A_ARRAY);
RRType RR_VAR     (RTypeIndex::E_VAR     , A_VAR);
RRType RR_CONSTANT(RTypeIndex::E_CONSTANT, A_CONSTANT);
RRType RR_FACTOR  (RTypeIndex::E_FACTOR  , A_FACTOR);
RRType RR_FUNC    (RTypeIndex::E_FUNC    , A_FUNCTION);
RRType RR_TEMPLATE(RTypeIndex::E_TEMPLATE, A_TEMPLATE);
RRType RR_MACRO   (RTypeIndex::E_MACRO   , A_MACRO);
RRType RR_INSTANCE(RTypeIndex::E_INSTANCE, A_INSTANCE);
RRType RR_CLASS   (RTypeIndex::E_CLASS   , A_CLASS);
RRType RR_NATIVE  (RTypeIndex::E_NATIVE  , A_NATIVE);
RRType RR_MEMBER  (RTypeIndex::E_MEMBER  , A_MEMBER);
RRType RR_FRAME   (RTypeIndex::E_FRAME   , A_FRAME);
RRType RR_ITERATOR(RTypeIndex::E_ITERATOR, A_ITERATOR);

RRType* RRType::type_of_NIL     (){ return &RR_NIL     ; }
RRType* RRType::type_of_ATOM    (){ return &RR_ATOM    ; }
RRType* RRType::type_of_BOOL    (){ return &RR_BOOL    ; }
RRType* RRType::type_of_INT     (){ return &RR_INT     ; }
RRType* RRType::type_of_LONG    (){ return &RR_LONG    ; }
RRType* RRType::type_of_FLOAT   (){ return &RR_FLOAT   ; }
RRType* RRType::type_of_DOUBLE  (){ return &RR_DOUBLE  ; }
RRType* RRType::type_of_STRING  (){ return &RR_STRING  ; }
RRType* RRType::type_of_BLOB    (){ return &RR_BLOB    ; }
RRType* RRType::type_of_LIST    (){ return &RR_LIST    ; }
RRType* RRType::type_of_EXPR    (){ return &RR_EXPR    ; }
RRType* RRType::type_of_ARRAY   (){ return &RR_ARRAY   ; }
RRType* RRType::type_of_VAR     (){ return &RR_VAR     ; }
RRType* RRType::type_of_CONSTANT(){ return &RR_CONSTANT; }
RRType* RRType::type_of_FACTOR  (){ return &RR_FACTOR  ; }
RRType* RRType::type_of_FUNC    (){ return &RR_FUNC    ; }
RRType* RRType::type_of_TEMPLATE(){ return &RR_TEMPLATE; }
RRType* RRType::type_of_MACRO   (){ return &RR_MACRO   ; }
RRType* RRType::type_of_INSTANCE(){ return &RR_INSTANCE; }
RRType* RRType::type_of_CLASS   (){ return &RR_CLASS   ; }
RRType* RRType::type_of_NATIVE  (){ return &RR_NATIVE  ; }
RRType* RRType::type_of_MEMBER  (){ return &RR_MEMBER  ; }
RRType* RRType::type_of_FRAME   (){ return &RR_FRAME   ; }
RRType* RRType::type_of_ITERATOR(){ return &RR_ITERATOR; }

namespace lfc {

IRAtom* toObject(RTypeIndex type){
  switch (type) {
  case E_ATOM:      return T_Atom;
  case E_BOOL:      return T_Bool;
  case E_INSTANCE:  return T_Instance;
  case E_EXPR:      return T_Expr;
  case E_FACTOR:    return T_Factor;
  case E_FLOAT:     return T_Float;
  case E_DOUBLE:    return T_Double;
  case E_FUNC:      return T_Func;
  case E_INT:       return T_Int;
  case E_LONG:      return T_Long;
  case E_LIST:      return T_List;
  case E_ARRAY:     return T_Array;
  case E_MACRO:     return T_Macro;
  case E_NATIVE:    return T_Native;
  case E_NIL:       return O_Nil;
  case E_STRING:    return T_String;
  case E_BLOB:      return T_Blob;
  case E_VAR:       return T_Var;
  case E_CONSTANT:  return T_Constant;
  case E_CLASS:     return T_Class;
  case E_MEMBER:    return T_Member;
  case E_FRAME:     return T_Frame;
  case E_TEMPLATE:  return T_Template;
  case E_ITERATOR:  return T_Iterator;
  default:          return O_Nan;
  }
}


RRType::RRType(RTypeIndex index, std::string name)
  : index(index)
  , name(name)
  , createCount(0)
  , deleteCount(0)
{

}

int RRType::getCreateCount() {
  return createCount;
}

int RRType::getDeleteCount() {
  return deleteCount;
}

RTypeIndex RRType::getIndex() {
  return index;
}

const std::string& RRType::getName() {
  return name;
}

int RRType::incCreateCount() {
  return createCount++;
}

void RRType::incDeleteCount() {
  deleteCount++;
}

void RRType::reset() {
  createCount = 0;
  deleteCount = 0;
}

static std::vector<RRType*> all_rtypes = {
    &RR_NIL      
  , &RR_ATOM     
  , &RR_BOOL     
  , &RR_INT      
  , &RR_LONG     
  , &RR_FLOAT    
  , &RR_DOUBLE   
  , &RR_STRING   
  , &RR_BLOB     
  , &RR_LIST     
  , &RR_EXPR     
  , &RR_ARRAY    
  , &RR_VAR      
  , &RR_CONSTANT 
  , &RR_FACTOR   
  , &RR_FUNC     
  , &RR_TEMPLATE 
  , &RR_MACRO    
  , &RR_INSTANCE 
  , &RR_CLASS    
  , &RR_NATIVE   
  , &RR_MEMBER   
  , &RR_FRAME    
  , &RR_ITERATOR
};

static std::map<std::string, RRType*> rtype_map;

const std::vector<RRType*>& RRType::get_all_rtypes(){
  return all_rtypes;
}

RRType* RRType::toType(const std::string& name){

  if(rtype_map.empty()){
    for(auto type : all_rtypes){
      rtype_map[type->getName()] = type;
    }
  }

  return lfc::find(rtype_map, name);
}

} // namespace lfc

namespace lfc {

std::string to_string(lfc::RRType* type){
  assert(type != NULL);
  return type->getName();
}

} // namespace lfc