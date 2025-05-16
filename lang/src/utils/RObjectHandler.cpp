// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/RObjectHandler.h"
#include "rulp/utils/RulpUtil.h"
#include <iostream>

using namespace lfc;

namespace lfc {

RObjectHandler::RObjectHandler(IRObject* obj)
  : obj(obj) 
{
  RULP_INC_REF(obj);
};

RObjectHandler::RObjectHandler(const RObjectHandler& RH)
  : obj(RH.obj) 
{
  RULP_INC_REF(obj);
}

RObjectHandler::RObjectHandler(RObjectHandler&& RH)
  : obj(RH.obj) 
{
  RH.obj = NULL;
}

RObjectHandler::~RObjectHandler(){
  RULP_DEC_REF(obj);
}

IRObject* RObjectHandler::get(){
  return obj;
}

RObjectHandler& RObjectHandler::operator=(const RObjectHandler &RH){
  RULP_DEC_REF(obj);
  obj = RH.obj;
  RULP_INC_REF(obj);
  return *this;
}

RObjectHandler& RObjectHandler::operator=(RObjectHandler &&RH){
  RULP_DEC_REF(obj);
  obj = RH.obj;
  RH.obj = NULL;
  return *this;
}

void RObjectHandler::set(IRObject* newObj) {
  // std::cout << "newObj=" << newObj->asString() << ", ptr=" <<newObj << "\n";
  RULP_DEC_REF(this->obj);
  this->obj = newObj;
  RULP_INC_REF(newObj);
}

RObjectHandler& RObjectHandler::operator=(IRObject* newObj){
  set(newObj);
  return *this;
}

} // namespace lfc