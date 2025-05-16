// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRSet.h"
#include "rulp/lang.h"
#include "rulp/runtime/IRLoaderImpl.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/collection.h"
#include "lfc/base/container.h"
#include <algorithm>

namespace lfc {

XRSet::XRSet(IRClass* noClass) 
 : XRDefInstance(noClass, "", null)
{

}

XRSet::~XRSet() {

}

void XRSet::_delete() {
  clear();
  XRDefInstance::_delete();
}

int XRSet::size() const {
  return uniqMap.size();
}

void XRSet::clear() {
  for(auto it = uniqMap.begin(), end = uniqMap.end(); it != end; ++it){
    auto* value = it->second;
    RULP_DEC_REF(value);
  }

  uniqMap.clear();
}

int XRSet::getInstanceKey() const {
  return INSTANCE_KEY_XRSET;
}

void XRSet::add(IRObject* newObj) {

  if (newObj == null) {
    return;
  }

  IRObject* oldObj = null;

  auto key = RulpUtil::toUniqString(newObj);
  auto it  = uniqMap.find(key); 
  if(it != uniqMap.end()) {
    oldObj = it->second;
  }

  if (oldObj == newObj) {
    return;
  }

  RULP_INC_REF(newObj);
  RULP_DEC_REF(oldObj);
  uniqMap[key] = newObj;
}

boolean XRSet::has(IRObject* obj) {
  auto uniName = RulpUtil::toUniqString(obj);
  auto it = uniqMap.find(uniName);
  return it != uniqMap.end();
}

boolean XRSet::isEmpty() const {
  return uniqMap.empty();
}

std::vector<IRObject*> XRSet::getValueList() {
  std::vector<IRObject*> valueList;

  for(auto it = uniqMap.begin(), end = uniqMap.end(); it != end; ++it) {
    valueList.push_back(it->second);
  }

  RulpUtil::sortByUniqString(valueList);
  return std::move(valueList);
}

#define F_MBR_SET_ADD       "_set_add"
#define F_MBR_SET_CLEAR     "_set_clear"
#define F_MBR_SET_HAS       "_set_has"
#define F_MBR_SET_INIT      "_set_init"
#define F_MBR_SET_IS_EMPTY  "_set_is_empty"
#define F_MBR_SET_SIZE_OF   "_set_size_of"
#define F_MBR_SET_TO_LIST   "_set_to_list"

static XRSet* asSet(IRObject* obj) {

  auto instance = AS_INSTANCE(obj);
  if (instance == null) {
    throw RException("Can't convert object to instance: " + obj->asString());
  }

  if(instance->getInstanceKey() != INSTANCE_KEY_XRSET){
    throw RException("Can't convert object to set: " + instance->asString());
  }

  return dynamic_cast<XRSet*>(instance);
}

static IRObject* _set_init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRSet(RuntimeUtil::getNoClass(interpreter));
}

static IRObject* _set_add(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set = asSet(interpreter->compute(frame, args->get(1)));
  auto obj = interpreter->compute(frame, args->get(2));

  set->add(obj);
  return O_Nil;
}

static IRObject* _set_has(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set    = asSet(interpreter->compute(frame, args->get(1)));
  auto obj    = interpreter->compute(frame, args->get(2));

  return RulpFactory::createBoolean(set->has(obj));
}

static IRObject* _set_size_of(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set = asSet(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createInteger(set->size());
}

static IRObject* _set_is_empty(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set = asSet(interpreter->compute(frame, args->get(1)));

  return RulpFactory::createBoolean(set->isEmpty());
}

static IRObject* _set_clear(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set = asSet(interpreter->compute(frame, args->get(1)));
  set->clear();
  return O_Nil;
}

static IRObject* _set_to_list(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto set = asSet(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createList(set->getValueList());
}

XRLOADER_IMPL_BEGIN(XRSetLoader)

auto setClass = AS_CLASS(frame->getEntry(A_SET)->getValue());
RulpUtil::setMember(setClass, F_MBR_SET_INIT      , _set_init       , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_ADD       , _set_add        , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_HAS       , _set_has        , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_SIZE_OF   , _set_size_of    , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_IS_EMPTY  , _set_is_empty   , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_CLEAR     , _set_clear      , RAccessType::PRIVATE);
RulpUtil::setMember(setClass, F_MBR_SET_TO_LIST   , _set_to_list    , RAccessType::PRIVATE);

XRLOADER_IMPL_END;
STATIC_LOADER_REGISTER(XRSetLoader, A_XR_SET_LOADER);

} // namespace lfc