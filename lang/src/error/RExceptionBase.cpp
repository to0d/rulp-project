// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/error/RExceptionBase.h"
#include "lfc/base/auto/auto_free.h"
using namespace lfc;

namespace lfc {

RException::~RException(){
  LFC_FREE(additionalMessages);
}

RException::RException(const RException& E){
  this->fromObject        = E.fromObject;
  this->exceptionMessage  = E.exceptionMessage;
  if(E.additionalMessages != NULL){
    this->additionalMessages = new std::vector<std::string>(*E.additionalMessages);     
  }
}

RException::RException(RException&& E){
  this->fromObject          = E.fromObject;
  this->exceptionMessage    = E.exceptionMessage;
  this->additionalMessages  = E.additionalMessages;

  E.fromObject = NULL;
  E.exceptionMessage.clear();
  E.additionalMessages = NULL;
  E._message.clear();
}

RException::RException(IRObject* fromObject){
  this->fromObject = fromObject;
}

RException::RException(IRObject* fromObject, StrConstRef message){
  this->fromObject        = fromObject;
  this->exceptionMessage  = message;
}

RException::RException(StrConstRef message){
  this->exceptionMessage = message;
}

std::string RException::getExceptionMessage() const {
  return exceptionMessage;
}

std::string RException::getMessage() const{
  if(_message.empty()){
    _message = exceptionMessage;
    if (additionalMessages != null) {
      for (auto msg : *additionalMessages) {
        _message += "\n";
        _message += msg;
      }
    }
  }

  return _message;
}

void RException::addAdditionalMessage(StrConstRef message){
  if (additionalMessages == null) {
    additionalMessages = new std::vector<std::string>();
  }

  additionalMessages->push_back(message);
  _message.clear();
}

std::vector<std::string> RException::getAdditionalMessages(){
  if(additionalMessages == NULL )
    return {};

  return *additionalMessages;
}

IRObject* RException::getFromObject(){
  return fromObject;
}


} // namespace lfc