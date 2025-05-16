// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRMap.h"
#include "rulp/lang.h"
#include "rulp/runtime/IRLoaderImpl.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/collection.h"
#include "lfc/base/container.h"
#include <algorithm>
namespace lfc {

static boolean TRACE = false;

RMapEntry::RMapEntry(IRObject* key, IRObject* value)
 : key(key)
 , value(value)
{
  RULP_INC_REF(key);
  RULP_INC_REF(value);
}

void RMapEntry::deleteEntry() {

  if(key != null) {
    RULP_DEC_REF(key);
    key = null;
  }

  if(value != null) {
    RULP_DEC_REF(value);
    value = null;
  }

}

void RMapEntry::setValue(IRObject* value) {
  if (value != this->value) {
    RULP_INC_REF(value);
    RULP_DEC_REF(this->value);
    this->value = value;
  }
}

XRMap::XRMap(IRClass* noClass) 
 : XRDefInstance(noClass, "", null)
{

}

XRMap::~XRMap() {

}

void XRMap::_delete() {
  clear();
  XRDefInstance::_delete();
}

IRObject* XRMap::get(IRObject* key) {
  auto uniName = RulpUtil::toUniqString(key);

  // std::cout << "XRMap::get: uniqNmae=" << uniName << "\n";

  auto it = uniqMap.find(uniName);
  if(it == uniqMap.end()){
    // std::cout << "not found\n";
    return null;
  }

  auto entry = it->second;
  // std::cout << "entry: key=" << entry->key->asString() << ", value=" << entry->value->asString() << "\n";
  return entry->value;
}

std::vector<IRObject*> XRMap::getKeyList() {
  std::vector<IRObject*> keyList;

  for(auto it = uniqMap.begin(), end = uniqMap.end(); it != end; ++it) {
    keyList.push_back(it->second->key);
  }

  RulpUtil::sortByUniqString(keyList);
  return std::move(keyList);
}

std::vector<IRObject*> XRMap::getValueList() {
  std::vector<IRObject*> valueList;

  for(auto it = uniqMap.begin(), end = uniqMap.end(); it != end; ++it) {
    valueList.push_back(it->second->value);
  }

  RulpUtil::sortByUniqString(valueList);
  // for(auto val : valueList){
  //   std::cout << "uniq:" << RulpUtil::toUniqString(val) << "\n";
  // }
  return std::move(valueList);
}

void XRMap::put(IRObject* key, IRObject* value) {
  // std::cout << "put: " << key->asString() << ", value=" << value->asString() << "\n";
  auto uniName = RulpUtil::toUniqString(key);
  auto it = uniqMap.find(uniName);
  if(it == uniqMap.end()) {
    uniqMap[uniName] = new RMapEntry(key, value);
  }
  else {
    it->second->setValue(value);
  }
}

boolean XRMap::hasKey(IRObject* key) {
  auto uniName = RulpUtil::toUniqString(key);
  auto it = uniqMap.find(uniName);
  return it != uniqMap.end();
}

int XRMap::size() const {
  return uniqMap.size();
}

void XRMap::clear() {
  for(auto it = uniqMap.begin(), end = uniqMap.end(); it != end; ++it){
    auto* entry = it->second;
    entry->deleteEntry();
  }

  uniqMap.clear();
}

int XRMap::getInstanceKey() const {
  return INSTANCE_KEY_XRMAP;
}

boolean XRMap::isEmpty() const {
  return uniqMap.empty();
}

#define A_MBR_MAP_IMPL        "?impl"
#define F_MBR_MAP_CLEAR       "_map_clear"
#define F_MBR_MAP_GET         "_map_get"
#define F_MBR_MAP_HAS_KEY     "_map_has_key"
#define F_MBR_MAP_INIT        "_map_init"
#define F_MBR_MAP_IS_EMPTY    "_map_is_empty"
#define F_MBR_MAP_KEY_LIST    "_map_key_list"
#define F_MBR_MAP_PUT         "_map_put"
#define F_MBR_MAP_SIZE_OF     "_map_size_of"
#define F_MBR_MAP_VALUE_LIST  "_map_value_list"

static XRMap* asMap(IRObject* obj) {

  auto instance = AS_INSTANCE(obj);
  if (instance == null) {
    throw RException("Can't convert object to instance: " + obj->asString());
  }

  if(instance->getInstanceKey() != INSTANCE_KEY_XRMAP){
    throw RException("Can't convert object to map: " + instance->asString());
  }

  return dynamic_cast<XRMap*>(instance);
}

static IRObject* _map_init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRMap(RuntimeUtil::getNoClass(interpreter));
}

static IRObject* _map_put(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 4) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  auto key    = interpreter->compute(frame, args->get(2));
  auto value  = interpreter->compute(frame, args->get(3));
  map->put(key, value);
  return O_Nil;
}

static IRObject* _map_get(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  auto key    = interpreter->compute(frame, args->get(2));
  auto value  = map->get(key);
  return value == null ? O_Nil : value;
}

static IRObject* _map_size_of(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createInteger(map->size());
}

static IRObject* _map_is_empty(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createBoolean(map->isEmpty());
}

static IRObject* _map_clear(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  map->clear();
  return O_Nil;
}

static IRObject* _map_key_list(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createList(map->getKeyList());
}

static IRObject* _map_value_list(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createList(map->getValueList());
}

static IRObject* _map_has_key(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto map    = asMap(interpreter->compute(frame, args->get(1)));
  auto key    = interpreter->compute(frame, args->get(2));

  return RulpFactory::createBoolean(map->hasKey(key));
}

XRLOADER_IMPL_BEGIN(XRMapLoader)

auto mapClass = AS_CLASS(frame->getEntry(A_MAP)->getValue());
RulpUtil::setMember(mapClass, F_MBR_MAP_INIT      , _map_init       , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_PUT       , _map_put        , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_GET       , _map_get        , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_SIZE_OF   , _map_size_of    , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_IS_EMPTY  , _map_is_empty   , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_CLEAR     , _map_clear      , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_KEY_LIST  , _map_key_list   , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_VALUE_LIST, _map_value_list , RAccessType::PRIVATE);
RulpUtil::setMember(mapClass, F_MBR_MAP_HAS_KEY   , _map_has_key    , RAccessType::PRIVATE);

XRLOADER_IMPL_END;
STATIC_LOADER_REGISTER(XRMapLoader, A_XR_MAP_LOADER);

} // namespace lfc