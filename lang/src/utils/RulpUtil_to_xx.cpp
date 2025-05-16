// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <sstream>
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RuntimeUtil.h"
#include "lfc/base/encode.h"

#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
#include "lfc/base/cast.h"
#include "lfc/base/string.h"
#include "lfc/base/container.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

static std::map<std::string, IRAtom*> _atom_name_map;

IRAtom* RulpUtil::toAtom(StrConstRef name){
  if(_atom_name_map.empty()){
    for(auto atom : RGlobal::get_global_object_all_atoms()){
      _atom_name_map[atom->getName()] = atom;
    }
  }

  auto obj = lfc::find(_atom_name_map, name);
  if(obj == NULL)  {
    obj = RulpFactory::createAtom(name);;
  }

  return obj;
}

IRList* RulpUtil::toList(StrConstRef name, std::vector<IRObject*>&& elements){
  if (name.empty())
    return RulpFactory::createList(std::move(elements));
  else
    return RulpFactory::createNamedList(name, std::move(elements));
}

boolean RulpUtil::toBoolean(const IRObject* a){
  switch (TYPE_INDEX_OF(a)) {
  case E_NIL:
    return false;

  case E_BOOL:
    return RulpUtil::asBoolean(a)->asBoolean();

  case E_FLOAT:
  case E_DOUBLE:
  case E_EXPR:
    return true;

  case E_INT:
  case E_LONG:
    return RulpUtil::toLong(a) != 0;

  case E_ATOM:
    if(a == O_Nil) {
      return false;
    }
    break;
  
  default:
    break;
  }

  throw RException(LFC_STR_FORMAT_BGN 
                    "Not support type: value=%s, type=%s"
                  , a->asString().c_str()
                  , a->getType()->getName().c_str()
                  LFC_STR_FORMAT_END);
}

IRBlob* RulpUtil::toBlob(IRObject* a) {

  switch (TYPE_INDEX_OF(a)) {
  case E_BLOB:
    return AS_BLOB(a);

  case E_INT: {
    auto intBlob = RulpFactory::createBlob(4);
    EncodeUtil::encodeInt(AS_INT(a)->asInteger(), intBlob->getValue(), 0);
    return intBlob;
  }

  case E_LONG: {
    auto longBlob = RulpFactory::createBlob(8);
    EncodeUtil::encodeLong(AS_LONG(a)->asLong(), longBlob->getValue(), 0);
    return longBlob;
  }

  case E_FLOAT: {
    auto floatBlob = RulpFactory::createBlob(4);
    EncodeUtil::encodeFloat(AS_FLOAT(a)->asFloat(), floatBlob->getValue(), 0);
    return floatBlob;
  }

  case E_DOUBLE: {
    auto doubleBlob = RulpFactory::createBlob(8);
    EncodeUtil::encodeDouble(AS_DOUBLE(a)->asDouble(), doubleBlob->getValue(), 0);
    return doubleBlob;
  }

  case E_STRING: {
    std::string str = AS_STR(a)->asString();
    return RulpFactory::createBlob(str.length(), str.c_str());
  }

  default:
    throw RException("Not support type: " + a->asString());
  }
}

IRExpr* RulpUtil::toDoExpr(IRIteratorPtr it){
  std::vector<IRObject*> newExpr;
  newExpr.push_back(RulpFactory::createAtom(A_DO));

  while (it->hasNext()) {
    newExpr.push_back(AS_EXPR(it->next()));
  }

  return RulpFactory::createExpression(std::move(newExpr));
}

float RulpUtil::toFloat(const IRObject* a){
  switch (TYPE_INDEX_OF(a)) {
  case E_FLOAT:    
    return RulpUtil::asFloat(a)->asFloat();

  case E_DOUBLE: 
    return (float) RulpUtil::asDouble(a)->asDouble();

  case E_INT:  
    return RulpUtil::asInteger(a)->asInteger();

  case E_LONG: 
    return (float) RulpUtil::asLong(a)->asLong();

  case E_STRING:
    return TO_FLOAT(AS_STR(a)->asString());

  default:
    throw RException("Can't convert to float: " + a->asString());
  }
}

double RulpUtil::toDouble(const IRObject* a){
  switch (TYPE_INDEX_OF(a)) {
  case E_FLOAT:    
    return RulpUtil::asFloat(a)->asFloat();

  case E_DOUBLE: 
    return RulpUtil::asDouble(a)->asDouble();

  case E_INT:  
    return RulpUtil::asInteger(a)->asInteger();

  case E_LONG: 
    return (double) RulpUtil::asLong(a)->asLong();

  case E_STRING:
    return TO_DOUBLE(AS_STR(a)->asString());

  default:
    throw RException("Can't convert to double: " + a->asString());
  }
}

int RulpUtil::toInt(const IRObject* a){
  switch (TYPE_INDEX_OF(a)) {
  case E_FLOAT:    
    return (int) RulpUtil::asFloat(a)->asFloat();

  case E_DOUBLE: 
    return (int) RulpUtil::asDouble(a)->asDouble();

  case E_INT:  
    return RulpUtil::asInteger(a)->asInteger();

  case E_LONG: 
    return (int) RulpUtil::asLong(a)->asLong();

  case E_STRING:
    return TO_INT(AS_STR(a)->asString());

  default:
    throw RException("Can't convert to int: " + a->asString());
  }
}

long RulpUtil::toLong(const IRObject* a){
  switch (TYPE_INDEX_OF(a)) {
  case E_FLOAT:    
    return (long) RulpUtil::asFloat(a)->asFloat();

  case E_DOUBLE: 
    return (long) RulpUtil::asDouble(a)->asDouble();

  case E_INT:  
    return RulpUtil::asInteger(a)->asInteger();

  case E_LONG: 
    return  RulpUtil::asLong(a)->asLong();

  case E_STRING:
    return TO_LONG(AS_STR(a)->asString());

  default:
    throw RException("Can't convert to long: " + a->asString());
  }
}

IRList* RulpUtil::toList(StrConstRef name, IRArray* array) {
  if (array->isEmpty()) {
    return O_EMPTY_LIST;
  }

  std::vector<IRObject*> rstList;

  int size = array->size();
  for (int i = 0; i < size; ++i) {
    auto obj = array->get(i);
    if (obj == null) {
      obj = O_Nil;
    }
    rstList.push_back(obj);
  }

  return RulpFactory::createNamedList(name, std::move(rstList));
}

IRList* RulpUtil::toList(StrConstRef name, IRObject* listObj, IRFrame* frame) {
  switch (TYPE_INDEX_OF(listObj)) {
  case E_ARRAY:
    return toList(name, AS_ARRAY(listObj));

  case E_LIST: {
    
    auto list = AS_LIST(listObj);
    // remove list name
    if (name.empty() || STR_TRIM(name).empty()) {

      if (list->getNamedName() == "") {
        return list;
      }

      return RulpFactory::createList(list, list->iterator());

    } 
    else {

      if (name == list->getNamedName()) {
        return list;
      }

      if (frame != null && !AttrUtil::isConst(list, frame)) {
        auto varList = RulpFactory::createVaryNamedList(name);
        RulpUtil::addAll(varList, list->iterator());
        return varList;
      }

      return RulpFactory::createNamedList(name, list, list->iterator());
    }
  }

  default:
    throw RException("Can't convert to list: " + listObj->asString());

  }
}

IRList* RulpUtil::toNamedList(IRObject* nameObj, IRObject* listObj, IRFrame* frame) {
  std::string name;

  if (nameObj != null) {

    switch (TYPE_INDEX_OF(nameObj)) {
    case E_ATOM:
      name = AS_ATOM(nameObj)->getName();
      break;

    case E_STRING:
      name = AS_STR(nameObj)->asString();
      break;

    default: throw RException( LFC_STR_FORMAT_BGN 
                                  "Invalid name object type<%s>: %s"
                                , nameObj->getType()->getName().c_str()
                                , nameObj->asString().c_str()
                               LFC_STR_FORMAT_END);
    }
  }

  return RulpUtil::toList(name, listObj, frame);
}

static void _toStringList(IRObject* obj, StrList& list){
  switch (TYPE_INDEX_OF(obj)) {
  case E_STRING:
    list.push_back(AS_STR(obj)->asString());
    break;
  
  case E_ATOM:
    list.push_back(AS_ATOM(obj)->getName());
    break;

  case E_EXPR:
  case E_LIST: {
    auto iter = AS_LIST(obj)->iterator();
    while (iter->hasNext()) {
      _toStringList(iter->next(), list);
    }
    break;
  }

  default:
    throw RException("Can't conver to string list: " + obj->asString());
  }
}

StrList RulpUtil::toStringList(IRObject* obj){
  StrList list;
  _toStringList(obj, list);
  return std::move(list);
}


static IRObject* computeInstanceToString(IRInstance* ins, IRInterpreter* interpreter) {

  auto mbr = ins->getMember(F_TO_STRING);
  if (mbr == null || !IS_TYPE_INDEX_OF(mbr->getValue(), E_FUNC)) {
    return null;
  }

  IRFunction* func = null;
  IRFunction* mbrFun = AS_FUNC(mbr->getValue());
  if (!mbrFun->isList()) {
    if (mbrFun->getParaAttrs().size() == 0) {
      func = mbrFun;
    }
  } 
  else {

    auto funList = AS_FUNC_LIST(mbrFun);
    for (auto f : funList->getAllFuncList()) {
      if (f->getParaAttrs().size() == 0) {
        func = f;
      }
    }
  }

  if (func == null) {
    return null;
  }

  return interpreter->compute( ins->getSubjectFrame()
                             , RulpFactory::createExpression({RulpFactory::createMember(ins, F_TO_STRING, func)}));
}


IRObject* RulpUtil::toString(IRObject* obj, IRInterpreter* interpreter){
  if (obj->getType()->getIndex() == E_STRING) {
    return obj;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_INSTANCE:
    {      
      IRObject* rst = computeInstanceToString(AS_INSTANCE(obj), interpreter);
      if (rst != null) {
        return rst;
      }
    }
    break;

  default:
    break;
  }

  return RulpFactory::createString(RulpUtil::toString(obj));
}

IRObject* RulpUtil::toVary(IRObject* obj, IRFrame* frame) {
  if (!AttrUtil::isConst(obj, frame)) {
    return obj;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_ARRAY: {

    auto varyArray = RulpFactory::createVaryArray();
    auto constArray = AS_ARRAY(obj);

    int size = constArray->size();
    for (int i = 0; i < size; ++i) {
      varyArray->add(constArray->get(i));
    }

    return varyArray;
  }

  default:
    throw RException("Can't to-vary: " + obj->asString());
  }
}

} // namespace lfc