// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/ReturnTypeUtil.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpOptUtil.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/lang/RGlobal.h"
#include "lfc/base/auto/auto_free.h"
#include <map>


using namespace lfc;
using namespace lfc;
namespace lfc {

class TypeMap {
  typedef std::map<std::string, IRAtom*> ObjTypeMapT;

public:

  TypeMap() = default;

  TypeMap(TypeMap* parent)
    : parent(parent)
  {}

  ~TypeMap(){
    LFC_FREE(localObjTypeMap);
  }

  void addType(StrConstRef name, IRAtom* type) {
    _buildMap();
    (*localObjTypeMap)[name] = type;
  }

  IRAtom* lookupType(StrConstRef name) {

    if (localObjTypeMap != null) {
      auto it = localObjTypeMap->find(name);
      if(it == localObjTypeMap->end()){
        return null;
      }
      return it->second;
    }

    return parent == null ? null : parent->lookupType(name);
  }

private:

  ObjTypeMapT* _buildMap() {

    if (localObjTypeMap == null) {
      localObjTypeMap = new ObjTypeMapT();
      if (parent != null) {
        auto parent_map = parent->_findMap();
        if(parent_map != NULL){
          for(auto it = parent_map->begin(); it != parent_map->end(); ++it){
            (*localObjTypeMap)[it->first] = it->second;
          }
        }
      }
    }

    return localObjTypeMap;
  }
  

  ObjTypeMapT* _findMap() {

    if (localObjTypeMap != null) {
      return localObjTypeMap;
    }

    return parent == null ? null : parent->_findMap();
  }

private:

  ObjTypeMapT*  localObjTypeMap = null;
  TypeMap*      parent = null;

};

class RTUtil{

public:
  ~RTUtil() {
    LFC_FREE_ARRAY(typeMaps);
  }

  TypeMap* newBranch(TypeMap* _map) {
    TypeMap* new_map = new TypeMap(_map);
    typeMaps.push_back(new_map);
    return new_map;
  }

  IRAtom* _exprReturnTypeOf(IRExpr* expr, TypeMap* typeMap, IRFrame* frame);
  IRAtom* _returnTypeOf(IRObject* obj, TypeMap* typeMap, IRFrame* frame);
  IRAtom* _funcRuntimeReturnTypeOf(IRFunction* func, IRExpr* expr, TypeMap* typeMap, IRFrame* frame);
  IRAtom* _funcDefinedReturnTypeOf(IRFunction* func, TypeMap* typeMap, IRFrame* frame);

private:

  std::vector<TypeMap*> typeMaps;

};

IRAtom* RTUtil::_exprReturnTypeOf(IRExpr* expr, TypeMap* typeMap, IRFrame* frame){
  if (expr->size() == 0) {
    return O_Nil;
  }

  auto e0 = expr->get(0);

  if (TYPE_INDEX_OF(e0) == E_ATOM) {

    auto entry = RuntimeUtil::lookupFrameEntry(frame, RulpUtil::asAtom(e0)->getName());
    // unknown factor
    if (entry != null && entry->getObject() != null) {
      e0 = entry->getObject();
    }
  }

  if (TYPE_INDEX_OF(e0) == E_FACTOR) {

    auto value = AttrUtil::getAttributeValue(e0, A_RETURN_TYPE);
    if (value == null) {
      return O_Nil;
    }

    if (TYPE_INDEX_OF(value) == E_ATOM) {
      return RulpUtil::asAtom(value);
    }

    if (TYPE_INDEX_OF(value) == E_INT) {

      int index = RulpUtil::asInteger(value)->asInteger();
      if (index >= 0 && index < expr->size()) {
        return _returnTypeOf(expr->get(index), typeMap, frame);
      }
    }
  }

  if (TYPE_INDEX_OF(e0) == E_FUNC) {

    auto attrValue = _returnTypeOf(e0, typeMap, frame);
    if (attrValue != O_Nil) {
      return attrValue;
    }


    if (!RulpUtil::asFunction(e0)->isList() && expr->size() > 1) {
      return _funcRuntimeReturnTypeOf(RulpUtil::asFunction(e0), expr, typeMap, frame);
    }

  }

  return O_Nil;
}


IRAtom* RTUtil::_returnTypeOf(IRObject* obj, TypeMap* typeMap, IRFrame* frame) {

  if (obj == null) {
    return O_Nil;
  }

  switch (TYPE_INDEX_OF(obj)) {

  case E_BOOL:
    return T_Bool;

  case E_INSTANCE:
    return RulpUtil::asInstance(obj)->getRClass()->getClassTypeAtom();

  case E_FLOAT:
    return T_Float;

  case E_DOUBLE:
    return T_Double;

  case E_INT:
    return T_Int;

  case E_LONG:
    return T_Long;

  case E_LIST:
    return T_List;

  case E_ITERATOR:
    return T_Iterator;

  case E_ARRAY:
    return T_Array;

  case E_NATIVE:
    return T_Native;

  case E_NIL:
    return O_Nil;

  case E_STRING:
    return T_String;

  case E_BLOB:
    return T_Blob;

  case E_MEMBER:
    return T_Member;

  case E_FACTOR: {
    auto attrValue = AttrUtil::getAttributeValue(obj, A_RETURN_TYPE);
    if (attrValue == null || TYPE_INDEX_OF(attrValue) != E_ATOM) {
      return O_Nil;
    }

    return RulpUtil::asAtom(attrValue);
  }

  case E_CONSTANT:
    return _returnTypeOf(AS_CONST(obj)->getValue(), typeMap, frame);

  case E_VAR:
    return _returnTypeOf(RulpUtil::asVar(obj)->getValue(), typeMap, frame);

  case E_EXPR:    
    return _exprReturnTypeOf(AS_EXPR(obj), typeMap, frame);

  case E_FUNC: {
    auto attrValue = AttrUtil::getAttributeValue(obj, A_RETURN_TYPE);
    if (attrValue == null) {      
      attrValue = _funcDefinedReturnTypeOf(RulpUtil::asFunction(obj), typeMap, frame);
      AttrUtil::setAttribute(obj, A_RETURN_TYPE, attrValue);
    }

    return RulpUtil::asAtom(attrValue);
  }

  case E_ATOM: {

    auto atomName = RulpUtil::asAtom(obj)->getName();
    auto _type = typeMap->lookupType(atomName);
    if (_type != null) {
      return _type;
    }

    auto entry = RuntimeUtil::lookupFrameEntry(frame, atomName);
    // is pure atom
    if (entry == null) {
      return O_Nil;
    }

    auto entryValue = entry->getObject();
    if (entryValue == null || TYPE_INDEX_OF(entryValue) == E_ATOM) {
      return O_Nil;
    }

    return _returnTypeOf(entryValue, typeMap, frame);
  }

  default:
    return O_Nil;
  }

}

IRAtom* RTUtil::_funcRuntimeReturnTypeOf(IRFunction* func, IRExpr* expr, TypeMap* typeMap, IRFrame* frame) {
  typeMap = newBranch(typeMap);
  typeMap->addType(func->getName(), T_Func);
  
  {
    int index = 1;
    for (auto para : func->getParaAttrs()) {
      auto paraType = para->getParaType();
      
      if (paraType != O_Nil) {
        typeMap->addType(para->getParaName(), paraType);
      } 
      else {
        auto value = expr->get(index);
        auto valueType = _returnTypeOf(value, typeMap, frame);
        typeMap->addType(para->getParaName(), valueType);
      }

      ++index;
    }
  }

  std::vector<IRObject*> returnList;
  RulpOptUtil::listReturnObject(func->getFunBody(), returnList);
  if (returnList.empty()) {
    return O_Nil;
  }

  IRAtom* funcRT = null;

  for (auto rtObj : returnList) {

    auto type = _returnTypeOf(rtObj, typeMap, frame);
    if (funcRT == null) {
      funcRT = type;
    } 
    else {
      if (!RulpUtil::equal(funcRT, type)) {
        return O_Nil;
      }
    }
  }

  return funcRT == null ? O_Nil : funcRT;
}

IRAtom* RTUtil::_funcDefinedReturnTypeOf(IRFunction* func, TypeMap* typeMap, IRFrame* frame) {
  if (func->isList()) {

    auto listFunc = AS_FUNC_LIST(func);
    assert(listFunc);

    IRAtom* listRT = null;

    for (auto childFunc : listFunc->getAllFuncList()) {

      auto childType = _funcDefinedReturnTypeOf(childFunc, typeMap, frame);
      if (listRT == null) {
        listRT = childType;
      }
       else {
        if (!RulpUtil::equal(childType, listRT)) {
          return O_Nil;
        }
      }
    }

    if (listRT == null) {
      return O_Nil;
    }

    return listRT;
  }

  typeMap = newBranch(typeMap);
  typeMap->addType(func->getName(), T_Func);
  for (auto para : func->getParaAttrs()) {
    auto paraType = para->getParaType();
    if (paraType != O_Nil) {
      typeMap->addType(para->getParaName(), paraType);
    }
  }

  std::vector<IRObject*> returnList;
  RulpOptUtil::listReturnObject(func->getFunBody(), returnList);
  if (returnList.empty()) {
    return O_Nil;
  }

  IRAtom* funcRT = null;

  for (auto rtObj : returnList) {
    auto type = _returnTypeOf(rtObj, typeMap, frame);
    if (funcRT == null) {
      funcRT = type;
    } 
    else {
      if (!RulpUtil::equal(funcRT, type)) {
        return O_Nil;
      }
    }
  }

  return funcRT == null ? O_Nil : funcRT;
}

IRAtom* ReturnTypeUtil::returnTypeOf(IRObject* obj, IRFrame* frame){
  TypeMap typeName;
  return RTUtil()._returnTypeOf(obj, &typeName, frame);
}

} // namespace lfc