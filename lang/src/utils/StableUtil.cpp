// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpOptUtil.h"
#include "rulp/utils/StableUtil.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
namespace lfc {

class NameSet{

  typedef std::vector<IRFunction*> func_vec_type;
  typedef std::map<IRFunction*, func_vec_type*> dep_map_type;

public:

  NameSet(): funcDepMap(new dep_map_type())
  {}

  NameSet(NameSet* parent)
    : parent(parent)
  {
    this->funcDepMap = parent->funcDepMap;
  }

  ~NameSet(){
    
    if(auto_free_func_list != NULL){
      for(auto* funcList: *auto_free_func_list){
        LFC_FREE(funcList);
      }
      auto_free_func_list->clear();
    }

    funcDepMap = NULL;
    LFC_FREE(localObjTypeMap);
    LFC_FREE(auto_free_func_list);
  }


  RTypeIndex lookupType(StrConstRef name){
    if (localObjTypeMap != null) {
      auto it = localObjTypeMap->find(name);
      if (it == localObjTypeMap->end()){
        return E_NIL;
      }

      return it->second;
    }

    return parent == null ? E_NIL : parent->lookupType(name);
  }

  void addDepFun(IRFunction* curFun, IRFunction* depFunc);

  void addVar(StrConstRef name){
    (*_buildMap())[name] = E_VAR;
  }

  void addFunName(StrConstRef name){
    (*_buildMap())[name] = E_FUNC;
	}
  
  std::map<std::string, RTypeIndex>* _findMap() {

		if (localObjTypeMap != null) {
			return localObjTypeMap;
		}

		return parent == null ? null : parent->_findMap();
	}

  std::map<std::string, RTypeIndex>* _buildMap(){

		if (localObjTypeMap == null) {
			localObjTypeMap = new std::map<std::string, RTypeIndex>();
			if (parent != null) {
        auto parent_map = parent->_findMap();
        if(parent_map != null){
          for(auto it = parent_map->begin(); it != parent_map->end(); ++it){
            (*localObjTypeMap)[it->first] = it->second;
          }
        }
			}
		}

		return localObjTypeMap;
	}

  boolean hasDepFuncs(IRFunction* curFun){
    return funcDepMap != null && lfc::find(*funcDepMap, curFun);
  }

  std::vector<IRFunction*>* removeDepFun(IRFunction* curFun){
    if(funcDepMap == null){
      return null;
    }

    auto it = funcDepMap->find(curFun);
    if(it == funcDepMap->end())
      return null;

    auto list = it->second;
    funcDepMap->erase(it);

    return list;
  }

  void updateExpr(IRObject* e0, IRExpr* expr){
    // (defvar ?x)
    if (RulpUtil::isFactor(e0, F_DEFVAR)) {
      addVar(AS_ATOM(expr->get(1))->getName());
      return;
    }

    // (defun fun)
    if (RulpUtil::isFactor(e0, F_DEFUN)) {
      addFunName(AS_ATOM(expr->get(1))->getName());
      return;
    }

    // (loop for x in '(1 2 3) do ...
    // (loop for x from 1 to 3 do ...
    // (loop stmt1 ...
    if (RulpUtil::isFactor(e0, F_LOOP)) {
      
      if (RulpUtil::isAtom(expr->get(1), F_FOR)) {
        addVar(AS_ATOM(expr->get(2))->getName());
      }

      return;
    }
  }

private:

  std::shared_ptr<dep_map_type> funcDepMap = null;

  std::map<std::string, RTypeIndex>* localObjTypeMap = null;

  std::vector<func_vec_type*>* auto_free_func_list = null;

  NameSet* parent = null;

};

void NameSet::addDepFun(IRFunction* curFun, IRFunction* depFunc){
  assert(funcDepMap != NULL);
  auto depFuncs = lfc::find(*funcDepMap, curFun);
  if (depFuncs == null) {
    depFuncs = new std::vector<IRFunction*>();
    if(auto_free_func_list == null){
      auto_free_func_list = new std::vector<func_vec_type*>();
    }
    auto_free_func_list->push_back(depFuncs);
    (*funcDepMap)[curFun] = depFuncs;
  }

  if(!lfc::find(*depFuncs, depFunc)){
    depFuncs->push_back(depFunc);
  }
}

class STUtil{
public:
  ~STUtil() {
    LFC_FREE_ARRAY(nameSets);
    LFC_FREE(checkingStack);
    LFC_FREE(assuingFuncs);
  }

  boolean isStable(IRObject* obj, NameSet* nameSet, IRFrame* frame);

  boolean _isStable(IRObject* obj, NameSet* nameSet, IRFrame* frame);

  boolean _isStableFunc(IRFunction* func, NameSet* nameSet, IRFrame* frame);

  NameSet* newBranch(NameSet* _set) {
    NameSet* new_set = new NameSet(_set);
    nameSets.push_back(new_set);
    return new_set;
  }

  boolean _containAssuingFunc(IRFunction* func) {
    return assuingFuncs != null && assuingFuncs->count(func) != 0;
  }

  void _addAssuingFunc(IRFunction* func) {

    if (assuingFuncs == null) {
      assuingFuncs = new std::set<IRFunction*>();
    }

    assuingFuncs->insert(func);
  }

  void _removeAssuingFunc(IRFunction* func) {

    if (assuingFuncs != null) {
      lfc::erase(*assuingFuncs, func);
    }
  }

  boolean _isStableFuncList(IRFunctionList* func, NameSet* nameSet, IRFrame* frame){
    for (auto childFunc : func->getAllFuncList()) {
      if (!_isStable(childFunc, nameSet, frame)) {
        return false;
      }
    }

    return true;
  }

  boolean _isStableList(IRIteratorPtr it, NameSet* nameSet, IRFrame* frame) {

    while (it->hasNext()) {
      if (!_isStable(it->next(), nameSet, frame)) {
        return false;
      }
    }
    return true;
  }

private:

  std::vector<NameSet*> nameSets;

  std::set<IRFunction*>* assuingFuncs = null;

  std::vector<IRFunction*>* checkingStack = null;
};

boolean STUtil::isStable(IRObject* obj, NameSet* nameSet, IRFrame* frame){
  if (obj == null) {
    return true;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_BOOL:
  case E_DOUBLE:
  case E_FLOAT:
  case E_INT:
  case E_LONG:
  case E_NATIVE:
  case E_NIL:
  case E_STRING:
  case E_CONSTANT:
    return true;

  case E_FACTOR:
    return AttrUtil::containAttribute(obj, ATTR_STABLE);

  case E_ATOM: {

    auto atomName = RulpUtil::asAtom(obj)->getName();

    auto entry = RuntimeUtil::lookupFrameEntry(frame, atomName);
    // is pure atom
    if (entry == null) {
      return true;
    }

    auto entryValue = entry->getObject();
    if (entryValue == null || TYPE_INDEX_OF(entryValue) == E_ATOM) {
      return true;
    }

    return isStable(entryValue, nameSet, frame);
  }

  case E_MACRO:
  case E_TEMPLATE:
  case E_MEMBER:
  case E_FRAME:
  case E_CLASS:
  case E_INSTANCE:
  case E_ARRAY:
  case E_BLOB:
    return false;

  default:
    break;
  }

  if (nameSet == null) {
    nameSet = new NameSet();
    nameSets.push_back(nameSet);
  }

  return _isStable(obj, nameSet, frame);
}

boolean STUtil::_isStable(IRObject* obj, NameSet* nameSet, IRFrame* frame){
  if (obj == null) {
    return true;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_BOOL:
  case E_DOUBLE:
  case E_FLOAT:
  case E_INT:
  case E_LONG:
  case E_NATIVE:
  case E_NIL:
  case E_STRING:
  case E_CONSTANT:
    return true;

  case E_FACTOR:
    return AttrUtil::containAttribute(obj, ATTR_STABLE);

  case E_VAR:
    return nameSet->lookupType(RulpUtil::asVar(obj)->getName()) != E_NIL;

  case E_ATOM: {

    auto atomName = AS_ATOM(obj)->getName();

    // is local atom
    if (nameSet->lookupType(atomName) == E_VAR) {
      return true;
    }

    auto entry = RuntimeUtil::lookupFrameEntry(frame, atomName);

    // is pure atom
    if (entry == null) {
      return true;
    }

    auto entryValue = entry->getObject();
    if (entryValue == null || TYPE_INDEX_OF(entryValue) == E_ATOM) {
      return true;
    }

    return _isStable(entryValue, nameSet, frame);
  }

  case E_EXPR: {

    auto expr = AS_EXPR(obj);
    if (expr->size() == 0) {
      return true;
    }

    auto e0 = expr->get(0);

    // Local defined function
    if (TYPE_INDEX_OF(e0) == E_ATOM && nameSet->lookupType(e0->asString()) == E_FUNC) {

      // need new branch
      return _isStableList(expr->listIterator(1), newBranch(nameSet), frame);
    }

    // External defined function
    if (TYPE_INDEX_OF(e0) == E_ATOM) {
      auto entry = RuntimeUtil::lookupFrameEntry(frame, AS_ATOM(e0)->getName());
      if (entry != null && entry->getValue() != null && TYPE_INDEX_OF(entry->getValue()) == E_FUNC) {
        return _isStableList(expr->listIterator(0), nameSet, frame);
      }
    }

    // do foreach, let
    if (RulpOptUtil::isNewFrameFactor(e0)) {

      // need new branch
      return _isStableList(expr->listIterator(1), newBranch(nameSet), frame);
    }

    nameSet->updateExpr(e0, expr);

    return _isStableList(expr->listIterator(0), nameSet, frame);
  }

  case E_LIST:
    return _isStableList(AS_LIST(obj)->listIterator(0), nameSet, frame);

  case E_FUNC: {

    auto attrValue = AttrUtil::getAttributeValue(obj, ATTR_STABLE);
    if (attrValue != null) {
      return AS_BOOL(attrValue)->asBoolean();
    }

    auto func = AS_FUNC(obj);
    boolean rc = false;

    if (IS_FUNC_LIST(obj)) {
      rc = _isStableFuncList(RulpUtil::asFunctionList(func), newBranch(nameSet), frame);
    } 
    else if (func->isLambda()) {
      rc = StableUtil::isStable(func->getFunBody(), func->getDefineFrame());
    }
    else {
      rc = _isStableFunc(func, newBranch(nameSet), frame);
    }

    // Updating function's stable value
    AttrUtil::setAttribute(obj, ATTR_STABLE, RulpFactory::createBoolean(rc));

    return rc;
  }

  case E_TEMPLATE:
  case E_MACRO:
  case E_MEMBER:
  case E_FRAME:
  case E_CLASS:
  case E_INSTANCE:
  case E_ARRAY:
  case E_BLOB:
  default:
    return false;
  }
}

boolean STUtil::_isStableFunc(IRFunction* func, NameSet* nameSet, IRFrame* frame){
	
  if (checkingStack == null) {
    checkingStack = new std::vector<IRFunction*>();
  }

  int checkSize = checkingStack->size();

  // assuming
  if (_containAssuingFunc(func)) {
    return true;
  }

  int lastPos = indexOf(*checkingStack, func);
  if (lastPos != -1) {

    // recursion self
    if ((lastPos + 1) == checkSize) {
      return true; // not update function's table value
    }

    // recursion cycle detected: A call B, B call C, C call A
    for (int i = (lastPos + 1); i < checkSize; ++i) {

      // Add B and C to A's dep list
      nameSet->addDepFun(func, (*checkingStack)[i]);
    }

    // jump to B
    throw RExceptionInterrupt((*checkingStack)[lastPos + 1], frame);
  }

  for (auto pa : func->getParaAttrs()) {
    nameSet->addVar(pa->getParaName());
  }

  checkingStack->push_back(func);


  LFC_AUTO_DO([&](){
    checkingStack->erase(checkingStack->begin() + checkSize);
  });

  try {

    boolean stable = _isStable(func->getFunBody(), nameSet, frame);

    // assume A is stable, check all dep functions again
    if (stable && nameSet->hasDepFuncs(func)) {

      auto depList = nameSet->removeDepFun(func);
      if(depList != NULL){

        for(auto depFunc : *depList){

          if (_containAssuingFunc(func)) {
            throw RException("duplicated assume func: " + func->asString());
          }

          _addAssuingFunc(func);
          
          {
            LFC_AUTO_DO([&](){
              _removeAssuingFunc(func);
            });

            // find one non-stable function
            if (!_isStable(depFunc, newBranch(nameSet), frame)) {
              stable = false;
              break;
            }
          
          }
        } 
      }
    }

    // Updating dep function list
    if (nameSet->hasDepFuncs(func)) {

      auto depList = nameSet->removeDepFun(func);
      if(depList != NULL){
        for (auto depFunc : *depList) {
          AttrUtil::setAttribute(depFunc, ATTR_STABLE, RulpFactory::createBoolean(stable));
        }
      }
    }

    return stable;

  }
  catch (RExceptionInterrupt& e) {

    auto fromFunc = e.getFromObject();
    if (fromFunc != func) {
      throw e;
    }

    return true; // return true, will check B later

  }
}

boolean StableUtil::isStable(IRObject* obj, IRFrame* frame){
  return STUtil().isStable(obj, null, frame);
}

} // namespace lfc