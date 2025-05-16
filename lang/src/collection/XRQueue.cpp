// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRQueue.h"
#include "rulp/lang.h"
#include "rulp/runtime/IRLoaderImpl.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/collection.h"
#include "lfc/base/to_string.h"
#include <algorithm>

namespace lfc {

XRQueue::XRQueue(IRClass* noClass) 
 : XRDefInstance(noClass, "", null)
{

}

XRQueue::~XRQueue() {

}

void XRQueue::_delete() {
  clear();
  XRDefInstance::_delete();
}

int XRQueue::size() const {
  return elementQueue.size();
}

void XRQueue::clear() {
  while(!elementQueue.empty()){
    auto obj = elementQueue.front();
    elementQueue.pop_front();
    RULP_DEC_REF(obj);
  }
}

int XRQueue::getInstanceKey() const {
  return INSTANCE_KEY_XRQUEUE;
}

boolean XRQueue::isEmpty() const {
  return elementQueue.empty();
}

std::vector<IRObject*> XRQueue::getValueList() {
  std::vector<IRObject*> valueList;

  int size = elementQueue.size();
  for(int i = 0; i < size; ++i) {
    valueList.push_back(elementQueue.at(i));
  }

  return std::move(valueList);
}

IRObject* XRQueue::get(int index) {
  if(index < 0 || index >= size())
    throw RException("invalid index: " + TO_STR(index));

  return elementQueue.at(index);
}

IRObject* XRQueue::peek_back() {
  if(elementQueue.empty()) {
    return null;
  }

  return elementQueue.back();
}

IRObject* XRQueue::pop_back() {

  if(elementQueue.empty()) {
    return null;
  }

  auto obj = elementQueue.back();
  elementQueue.pop_back();
  
  RULP_DEC_REF(obj);
  return obj;
}

IRObject* XRQueue::peek_front() {
  if(elementQueue.empty()) {
    return null;
  }

  return elementQueue.front();
}

IRObject* XRQueue::pop_front() {

  if(elementQueue.empty()) {
    return null;
  }

  auto obj = elementQueue.front();
  elementQueue.pop_front();
  
  RULP_DEC_REF(obj);
  return obj;
}

void XRQueue::push_back(IRObject* obj) {
  if (obj == null) {
    elementQueue.push_back(O_Nil);
    return;
  }

  RULP_INC_REF(obj);
  elementQueue.push_back(obj);
}

void XRQueue::push_front(IRObject* obj) {
  if (obj == null) {
    elementQueue.push_front(O_Nil);
    return;
  }

  RULP_INC_REF(obj);
  elementQueue.push_front(obj);
}

#define F_MBR_QUEUE_CLEAR       "_queue_clear"
#define F_MBR_QUEUE_GET         "_queue_get"
#define F_MBR_QUEUE_INIT        "_queue_init"
#define F_MBR_QUEUE_IS_EMTPY    "_queue_is_empty"
#define F_MBR_QUEUE_PEEK_BACK   "_queue_peek_back"
#define F_MBR_QUEUE_PEEK_FRONT  "_queue_peek_front"
#define F_MBR_QUEUE_POP_BACK    "_queue_pop_back"
#define F_MBR_QUEUE_POP_FRONT   "_queue_pop_front"
#define F_MBR_QUEUE_PUSH_BACK   "_queue_push_back"
#define F_MBR_QUEUE_PUSH_FRONT  "_queue_push_front"
#define F_MBR_QUEUE_SIZE_OF     "_queue_size_of"
#define F_MBR_QUEUE_TO_LIST     "_queue_to_list"

static XRQueue* asQueue(IRObject* obj) {

  auto instance = AS_INSTANCE(obj);
  if (instance == null) {
    throw RException("Can't convert object to instance: " + obj->asString());
  }

  if(instance->getInstanceKey() != INSTANCE_KEY_XRQUEUE){
    throw RException("Can't convert object to queue: " + instance->asString());
  }

  return dynamic_cast<XRQueue*>(instance);
}

static IRObject* _queue_init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 1) {
    throw RException("Invalid parameters: " + args->asString());
  }

  RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRQueue(RuntimeUtil::getNoClass(interpreter));
}

static IRObject* _queue_push_back(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  auto obj   = interpreter->compute(frame, args->get(2));
  queue->push_back(obj);
  return O_Nil;
}

static IRObject* _queue_push_front(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  auto obj   = interpreter->compute(frame, args->get(2));
  queue->push_front(obj);
  return O_Nil;
}

static IRObject* _queue_pop_back(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return queue->pop_back();
}

static IRObject* _queue_pop_front(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return queue->pop_front();
}

static IRObject* _queue_peek_back(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return queue->peek_back();
}

static IRObject* _queue_peek_front(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  auto obj   = interpreter->compute(frame, args->get(2));
  return queue->peek_front();
}

static IRObject* _queue_get(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  ROH obj    = interpreter->compute(frame, args->get(2));
  
  return queue->get(AS_INT(obj)->asInteger());
}

static IRObject* _queue_size_of(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createInteger(queue->size());
}

static IRObject* _queue_is_empty(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createBoolean(queue->isEmpty());
}

static IRObject* _queue_clear(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  queue->clear();
  return O_Nil;
}

static IRObject* _queue_to_list(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto queue = asQueue(interpreter->compute(frame, args->get(1)));
  return RulpFactory::createList(queue->getValueList());
}


XRLOADER_IMPL_BEGIN(XRQueueLoader)

auto queueClass = AS_CLASS(frame->getEntry(A_QUEUE)->getValue());
RulpUtil::setMember(queueClass, F_MBR_QUEUE_INIT      , _queue_init       , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_PUSH_BACK , _queue_push_back  , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_PUSH_FRONT, _queue_push_front , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_POP_BACK  , _queue_pop_back   , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_POP_FRONT , _queue_pop_front  , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_PEEK_BACK , _queue_peek_back  , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_PEEK_FRONT, _queue_peek_front , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_GET       , _queue_get        , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_SIZE_OF   , _queue_size_of    , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_IS_EMTPY  , _queue_is_empty   , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_CLEAR     , _queue_clear      , RAccessType::PRIVATE);
RulpUtil::setMember(queueClass, F_MBR_QUEUE_TO_LIST   , _queue_to_list    , RAccessType::PRIVATE);

XRLOADER_IMPL_END;
STATIC_LOADER_REGISTER(XRQueueLoader, A_XR_QUEUE_LOADER);

} // namespace lfc