// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <sstream>
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(rulp_util)
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/LCOUtil.h"
#include "rulp/utils/RulpOptUtil.h"
#include "rulp/utils/RulpMathUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
#include "lfc/base/string/format.h"
#include "lfc/base/string/util.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

void RulpUtil::addAll(IRList* list, IRIteratorPtr it) {
  while (it->hasNext()) {
    list->add(it->next());
  }
}

void RulpUtil::addAll(std::vector<IRObject*>& l1, IRIteratorPtr it) {
  while (it->hasNext()) {
    l1.push_back(it->next());
  }
}

void RulpUtil::addAll(std::vector<IRObject*>& l1, IRList* l2) {
  addAll(l1, l2->iterator());
}

IRList* RulpUtil::addAll(IRList* l1, IRList* l2) {
  if (l2->isEmpty()) {
    return l1;
  }

  if (l1->isEmpty()) {
    return l2;
  }

  std::vector<IRObject*> rstList;
  addAll(rstList, l1);
  addAll(rstList, l2);

  return RulpFactory::createList(std::move(rstList));
}

IRList* RulpUtil::addAll(IRList* list, IRArray* array) {
  if (array->isEmpty()) {
    return list;
  }

  std::vector<IRObject*> rstList;
  RulpUtil::addAll(rstList, list);

  int size = array->size();
  for (int i = 0; i < size; ++i) {
    auto obj = array->get(i);
    if (obj == null) {
      obj = O_Nil;
    }

    rstList.push_back(obj);
  }

  return RulpFactory::createList(std::move(rstList));
}

IRArray* RulpUtil::addAll(IRArray* array, IRList* list){
  if (array->isConst()) {
    throw RException("Can't add const vary: " + array->asString());
  }

  if (!list->isEmpty()) {
    auto it = list->iterator();
    while (it->hasNext()) {
      array->add(it->next());
    }
  }

  return array;
}

IRList* RulpUtil::buildListOfString(const std::vector<std::string>& strlist) {
  if (strlist.empty()) {
    return RulpFactory::createList();
  }

  std::vector<IRObject*> objList;
  for (auto str : strlist) {
    objList.push_back(RulpFactory::createString(str));
  }

  return RulpFactory::createList(std::move(objList));
}

void RulpUtil::incRef(IRObject* obj){
  if (obj == NULL) {
    return;
  }

  obj->incRef();
}

void RulpUtil::decRef(IRObject* obj){
  if (obj == NULL) {
    return;
  }

  obj->decRef();
}

bool RulpUtil::isValidAtomName(const std::string& name){
  if(name.empty())
    return false;

  for(char c : name)
    if(c == ' ')
      return false;

  return true;
}

boolean RulpUtil::isVarAtom(const IRObject* obj) {
  return TYPE_INDEX_OF(obj) == E_ATOM && isVarName((AS_ATOM(obj))->getName());
}

boolean RulpUtil::isVarName(StrConstRef var) {
  return var.length() > 1 && var.at(0) == A_QUESTION_C;
}

boolean RulpUtil::isCallable(const IRObject* a){
  return a != null && a->isCallable();
}

boolean RulpUtil::isNil(const IRObject* a){
  return a == null || TYPE_INDEX_OF(a) == E_NIL;
}

boolean RulpUtil::isSubject(const IRObject* a){
  return a != null && a->isSubject();
}

boolean RulpUtil::equal(IRObject* a, IRObject* b){

  if (a == b) {
    return true;
  }

  if (IS_NIL(a)) {
    return IS_NIL(b);
  }

  if (IS_NIL(b)) {
    return false;
  }

  if (TYPE_INDEX_OF(a) != TYPE_INDEX_OF(b)) {
    return false;
  }

  switch (TYPE_INDEX_OF(a)) {
  case E_ATOM:
  case E_STRING:
    return a->asString() == b->asString();

  case E_BOOL:
    return RulpUtil::asBoolean(a)->asBoolean() == RulpUtil::asBoolean(b)->asBoolean();

  case E_FLOAT:
    return RulpUtil::asFloat(a)->asFloat() == RulpUtil::asFloat(b)->asFloat();

  case E_INT:
    return RulpUtil::asInteger(a)->asInteger() == RulpUtil::asInteger(b)->asInteger();

  case E_LONG:
    return RulpUtil::asLong(a)->asLong() == RulpUtil::asLong(b)->asLong();

  case E_DOUBLE:  
    return RulpUtil::asDouble(a)->asDouble() ==   RulpUtil::asDouble(b)->asDouble();

  case E_NIL:
    return true;

  case E_EXPR:
  case E_LIST: {

    IRList* la = RulpUtil::asList(a);
    IRList* lb = RulpUtil::asList(b);
    
    if (la->size() != lb->size()) {
      return false;
    }

    auto ia = la->iterator();
    auto ib = lb->iterator();

    while (ia->hasNext()) {
      if (!RulpUtil::equal(ia->next(), ib->next())) {
        return false;
      }
    }

    return true;
  }

  default:
    return false;
  }
}

static IRObject* _compare_obj(IRObject* obj) {

  switch (TYPE_INDEX_OF(obj)) {

  case E_CONSTANT:
    return _compare_obj(AS_CONST(obj)->getValue());

  case E_MEMBER:
    return _compare_obj(AS_MEMBER(obj)->getValue());

  case E_VAR:
    return _compare_obj(AS_VAR(obj)->getValue());

  default:
    return obj;
  }
}

int RulpUtil::compare(IRObject* a, IRObject* b){
  if (a == b) {
    return 0;
  }

  if (a == null || a == O_Nil) {
    if (b == null || b == O_Nil) {
      return 0;
    }
    return -1;
  }

  if (b == null || b == O_Nil) {
    return -compare(b, a);
  }

  a = _compare_obj(a);
  b = _compare_obj(b);

  if (a == b) {
    return 0;
  }

  auto at = TYPE_INDEX_OF(a);
  auto bt = TYPE_INDEX_OF(b);

  switch (at) {
  case E_BOOL:
  case E_ATOM:
  case E_STRING:
  case E_LIST:

    switch (bt) {
    case E_BOOL:
    case E_ATOM:
    case E_STRING:
    case E_LIST:
      return STR_COMPARE(a->asString(), b->asString());

    default:
      throw RException( LFC_STR_FORMAT_BGN
                            "can't compare: %s %s"
                          , a->asString().c_str()
                          , b->asString().c_str()
                        LFC_STR_FORMAT_END);
    }

  default:
    break;
  }

  auto rt = RulpMathUtil::getTypeConvert(at, bt);
  if (rt == RTypeIndex::E_NIL) {
    throw RException( LFC_STR_FORMAT_BGN
                          "can't compare: %s %s"
                        , a->asString().c_str()
                        , b->asString().c_str()
                      LFC_STR_FORMAT_END);
  }

  switch (rt) {
  case E_DOUBLE: {

    double av = RulpUtil::toDouble(a);
    double bv = RulpUtil::toDouble(b);

    if (av > bv) {
      return 1;
    } 
    else if (av < bv) {
      return -1;
    } 
    else {
      return 0;
    }
  }

  case E_FLOAT: {

    float av = RulpUtil::toFloat(a);
    float bv = RulpUtil::toFloat(b);

    if (av > bv) {
      return 1;
    } 
    else if (av < bv) {
      return -1;
    }
    else {
      return 0;
    }
  }

  case E_INT: {

    int av = RulpUtil::toInt(a);
    int bv = RulpUtil::toInt(b);

    if (av > bv) {
      return 1;
    } 
    else if (av < bv) {
      return -1;
    } 
    else {
      return 0;
    }
  }

  case E_LONG: {

    long av = RulpUtil::toLong(a);
    long bv = RulpUtil::toLong(b);

    if (av > bv) {
      return 1;
    } 
    else if (av < bv) {
      return -1;
    }
     else {
      return 0;
    }
  }

  default:
    throw RException( LFC_STR_FORMAT_BGN
                          "can't compare: %s %s"
                        , a->asString().c_str()
                        , b->asString().c_str()
                      LFC_STR_FORMAT_END);
  }
}

IRObject* RulpUtil::clone(IRObject* obj) {

  switch (TYPE_INDEX_OF(obj)) {
  case E_ATOM:
  case E_BOOL:
  case E_FLOAT:
  case E_DOUBLE:
  case E_INT:
  case E_LONG:
  case E_STRING:
  case E_NIL:
  case E_FACTOR:
  case E_TEMPLATE:
  case E_MACRO:
    return obj;

  case E_FUNC: {
    auto F = AS_FUNC(obj);
    if(F->isLambda()){
      return F->clone();
    }
    return obj;
  } 

  case E_CONSTANT:
    return AS_CONST(obj)->getValue();

  case E_LIST:
  case E_EXPR:
    return RuntimeUtil::rebuild(obj, {});

  case E_CLASS:
  case E_MEMBER:
  case E_INSTANCE:
    return obj;

  case E_ARRAY:
    return AS_ARRAY(obj)->cloneArray();

  case E_BLOB:
    return AS_BLOB(obj)->cloneBlob();

  case E_VAR:
    return clone(AS_VAR(obj)->getValue());

  case E_NATIVE:
  case E_FRAME:
  default:
    throw RException("not support: " + obj->asString());
  }
}

boolean RulpUtil::containFunc(IRObject* obj, StrConstRef name){
  switch (TYPE_INDEX_OF(obj)) {
  case E_EXPR: {
    auto expr = AS_EXPR(obj);
    if (expr->isEmpty()) {
      return false;
    }

    auto e0 = expr->get(0);
    if (RulpUtil::isObject(e0, name, {E_ATOM, E_FUNC})) {
      return true;
    }

    auto it = expr->listIterator(1);
    while (it->hasNext()) {
      if (containFunc(it->next(), name)) {
        return true;
      }
    }

    return false;
  }

  case E_LIST: {
    auto list = RulpUtil::asList(obj);
    auto it = list->iterator();
    while (it->hasNext()) {
      if (containFunc(it->next(), name)) {
        return true;
      }
    }

    return false;
  }

  default:
    return false;
  }
}

void RulpUtil::addPathVar(IRFrame* frame, StrConstRef path) {

  auto value = getVarValue(frame, A_PATH);


  if(value == null || TYPE_INDEX_OF(value) == E_NIL){
    value = RulpFactory::createListOfString({path});
  }
  else {
    assert(TYPE_INDEX_OF(value) == E_LIST);

    std::vector<IRObject*> rstList;
    RulpUtil::addAll(rstList, AS_LIST(value));
    rstList.push_back(RulpFactory::createString(path));
    value = RulpFactory::createList(std::move(rstList));
  }

  setLocalVar(frame, A_PATH, value);
}

IRObject* RulpUtil::getVarValue(IRFrame* frame, StrConstRef varName) {
  auto entry = RuntimeUtil::lookupFrameEntry(frame, varName);
  if (entry == null) {
    return null;
  }

  auto entryValue = entry->getValue();
  if (entryValue == null || TYPE_INDEX_OF(entryValue) != E_VAR) {
    return null;
  }

  return AS_VAR(entryValue)->getValue();
}

boolean RulpUtil::isAtom(const IRObject* obj){
  return TYPE_INDEX_OF(obj) == E_ATOM;
}

boolean RulpUtil::isAtom(const IRObject* obj, StrConstRef name){
  return TYPE_INDEX_OF(obj) == E_ATOM &&  RulpUtil::asAtom(obj)->getName() == name;
}

boolean RulpUtil::isFactor(const IRObject* obj, StrConstRef name){
  return RulpUtil::isObject(obj, name, {E_ATOM, E_FACTOR});
}

boolean RulpUtil::isFunctionList(const IRObject* obj){
  return TYPE_INDEX_OF(obj) == E_FUNC && RulpUtil::asFunction(obj)->isList();
}

boolean RulpUtil::isObject(const IRObject* obj, StrConstRef name, std::initializer_list<RTypeIndex> types){
  for (auto type : types) {

    if (TYPE_INDEX_OF(obj) == type) {
      switch (type) {
      case E_ATOM:
        return RulpUtil::asAtom(obj)->getName() == name;

      case E_FACTOR:
        return RulpUtil::asFactor(obj)->getName() == name;

      case E_FUNC:
        return RulpUtil::asFunction(obj)->getName() == name;

      case E_VAR:
        return RulpUtil::asVar(obj)->getName() == name;

      default:
        return false;

      }
    }
  }

  return false;
}


boolean RulpUtil::isPropertyStatic(IRMember* mbr){
  return (P_STATIC & mbr->getProperty()) != 0;
}

boolean RulpUtil::isPropertyFinal(IRMember* mbr){
  return (P_FINAL & mbr->getProperty()) != 0;
}

boolean RulpUtil::isPropertyInherit(IRMember* mbr){
  return (P_INHERIT & mbr->getProperty()) != 0;
}

boolean RulpUtil::isPureAtomList(IRObject* obj){
  auto type = TYPE_INDEX_OF(obj);
  if (type != E_LIST && type != E_EXPR) {
    return false;
  }

  auto iter = RulpUtil::asList(obj)->iterator();
  while (iter->hasNext()) {
    if (TYPE_INDEX_OF(iter->next()) != E_ATOM) {
      return false;
    }
  }

  return true;
}

boolean RulpUtil::isTrace(IRFrame* frame) {
  return AS_BOOL(RulpUtil::getVarValue(frame, A_TRACE))->asBoolean();
}

IRObject* RulpUtil::lookup(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame){
  if (TYPE_INDEX_OF(obj) == E_ATOM) {

    auto entry = RuntimeUtil::lookupFrameEntry(frame, RulpUtil::asAtom(obj)->getName());
    if (entry != null) {
      obj = entry->getObject();
    }

  } 
  else if (TYPE_INDEX_OF(obj) == E_MEMBER) {
    obj = RuntimeUtil::getActualMember(RulpUtil::asMember(obj), interpreter, frame);
  }

  return obj;
}

void RulpUtil::setMember(IRSubject* subject, StrConstRef name, factor_func factor, RAccessType accessType, int property){
  setMember(subject, name, RulpFactory::createFactor(name, factor, true), accessType, property);
}

void RulpUtil::setMember(IRSubject* subject, StrConstRef name, IRObject* obj, RAccessType accessType, int property) {
  auto mbr = RulpFactory::createMember(subject, name, obj);
  if (accessType != RAccessType::NIL) {
    mbr->setAccessType(accessType);
    mbr->setProperty(property);
  }

  subject->setMember(name, mbr);
}

void RulpUtil::setPropertyFinal(IRMember* mbr, boolean bValue){
  if (isPropertyFinal(mbr) == bValue) {
    return;
  }

  if (bValue) {
    mbr->setProperty(mbr->getProperty() | P_FINAL);
  } else {
    mbr->setProperty(mbr->getProperty() & ~P_FINAL);
  }
}

void RulpUtil::setPropertyInherit(IRMember* mbr, boolean bValue){
  if (isPropertyInherit(mbr) == bValue) {
    return;
  }

  if (bValue) {
    mbr->setProperty(mbr->getProperty() | P_INHERIT);
  } else {
    mbr->setProperty(mbr->getProperty() & ~P_INHERIT);
  }
}

void RulpUtil::setPropertyStatic(IRMember* mbr, boolean bValue){
  if (isPropertyStatic(mbr) == bValue) {
    return;
  }

  if (bValue) {
    mbr->setProperty(mbr->getProperty() | P_STATIC);
  } else {
    mbr->setProperty(mbr->getProperty() & ~P_STATIC);
  }
}

void RulpUtil::setLocalVar(IRFrame* frame, StrConstRef varName, IRObject* value) {
  auto varObj = frame->findLocalObject(varName);
  
  IRVar* var = null;
  
  if (varObj == null) {
    var = RuntimeUtil::addVar(frame, varName);
  }
  else {
    var = AS_VAR(varObj);
  }

  var->setValue(value);
}

void RulpUtil::sortByStr(std::vector<IRObject*> list) {
  // if(list.size() <= 1)
  //   return;

  std::sort(list.begin(), list.end(), [](auto& a, auto& b){
    // std::cout << "a: " << a->asString()  << ", b: " << b->asString();
    auto rc = std::greater<std::string>()(a->asString(), b->asString());  // #TODO: maybe not work
    // std::cout << ", rc: " << rc << "\n";
    return rc;
  });
}

void RulpUtil::sortByUniqString(std::vector<IRObject*> list) {
  // std::cout << "sortByUniqString:\n";
  std::sort(list.begin(), list.end(), [](auto a, auto b){
    // std::cout << "a: " << a->asString()  << ", b: " << b->asString();
    // std::cout << "  ,a: " << toUniqString(a)  << ", b: " << toUniqString(b);
    auto rc = std::greater<std::string>()(RulpUtil::toUniqString(a), RulpUtil::toUniqString(b));  // #TODO: why not work, see test_map_1
    // std::cout << ", rc: " << rc << "\n";
    return rc;
  });
}

std::string RulpUtil::toOneLine(const std::vector<std::string>& lines) {
  std::stringstream ss;
  int index = 0;

  for (auto line : lines) {
    if (index++ != 0) {
      ss << '\n';
    }
    ss << line;
  }

  return ss.str();
}

static int unusedNameCount = 0;

std::string RulpUtil::getNextUnusedName() {
  return LFC_STR_FORMAT_BGN "un%d", unusedNameCount++ LFC_STR_FORMAT_END;
}

IRAtom* RulpUtil::getObjectType(IRObject* obj){
  auto valAtom = toObject(TYPE_INDEX_OF(obj));
  if(valAtom == T_Instance) {
     valAtom = RulpUtil::asInstance(obj)->getRClass()->getClassTypeAtom();
  }
  return valAtom;
}

boolean RulpUtil::matchType(IRAtom* typeAtom, IRObject* obj) {
  // Match any object
  if (typeAtom == O_Nil) {
    return true;
  }

  return getObjectType(obj) == typeAtom;
}

std::string RulpUtil::nameOf(IRObject* obj, IRFrame* frame){
	if (obj == null) {
    return "";
  }

  switch (TYPE_INDEX_OF(obj)) {

  case E_ATOM: {
    auto entry = frame->getEntry(RulpUtil::asAtom(obj)->getName());
    if (entry != null && entry->getObject() != obj) {
      return nameOf(entry->getObject(), frame);
    }

    return RulpUtil::asAtom(obj)->getName();
  }

  case E_INSTANCE:
    return RulpUtil::asInstance(obj)->getInstanceName();

  case E_CLASS:
    return RulpUtil::asClass(obj)->getClassName();

  case E_FACTOR:
    return RulpUtil::asFactor(obj)->getName();

  case E_TEMPLATE:
    return RulpUtil::asTemplate(obj)->getName();

  case E_FUNC:
    return RulpUtil::asFunction(obj)->getSignature();

  case E_MACRO:
    return RulpUtil::asMacro(obj)->getName();

  case E_VAR:
    return RulpUtil::asVar(obj)->getName();

  case E_MEMBER:
    return RulpUtil::asMember(obj)->getName();

  case E_FRAME:
    return RulpUtil::asFrame(obj)->getFrameName();

  case E_LIST:
    return RulpUtil::asList(obj)->getNamedName();

  case E_NIL:
  
  default:
    return "";
  }
}


void RulpUtil::tryOverride(IRFunction* oldFun, IRFunction* newFun){
  auto oldFrame = oldFun->getDefineFrame();
  auto newFrame = newFun->getDefineFrame();

  int oldFrameId = oldFrame->getFrameId();
  int newFrameId = newFrame->getFrameId();

  if (oldFrameId == newFrameId) {
    throw RException("duplicate funcion: " + oldFun->getSignature());
  }

  if (oldFrameId > newFrameId) {
    throw RException(LFC_STR_FORMAT_BGN "invalid new frame: new=%s, old=%s"
                                         , newFrame->asString().c_str()
                                         , oldFrame->asString().c_str() 
                     LFC_STR_FORMAT_END);
  }
}

IRObject* RulpUtil::toConst(IRObject* obj, IRFrame* frame){
  if (AttrUtil::isConst(obj, frame)) {
    return obj;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_VAR:
    return toConst(AS_VAR(obj)->getValue(), frame);

  case E_LIST: {

    auto list = AS_LIST(obj);
    if (list->isEmpty()) {
      return O_EMPTY_LIST;
    }

    std::vector<IRObject*> newObjs;
    auto it = list->iterator();
    while (it->hasNext()) {
      newObjs.push_back(toConst(it->next(), frame));
    }

    return RulpFactory::createConstArray(std::move(newObjs));
  }

  default:
    throw RException("Can't to-const: " + obj->asString());
  }
}

std::vector<IRObject*> RulpUtil::toArray(IRList* list) {
  std::vector<IRObject*> arr;
  auto iter = list->iterator();
  while (iter->hasNext()) {
    arr.push_back(iter->next());
  }

  return std::move(arr);
}

void RulpUtil::reset(){
  RulpOptUtil::reset();
  LCOUtil::reset();
  RulpFactory::reset();
  RuntimeUtil::reset();
  RGlobal::reset();

  unusedNameCount = 0;
  // FileUtil::reset()
}

} // namespace lfc