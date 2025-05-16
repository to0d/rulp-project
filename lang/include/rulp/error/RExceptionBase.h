// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_ERROR_REXCEPTION_BASE_H__
#define __RULP_ERROR_REXCEPTION_BASE_H__
#include "rulp/lang/base.h"
#include "rulp/object/IRObject.h"
namespace lfc {

class RException {

public:
 
  RException() = default;
  RException(const RException& E);
  RException(RException&& E);
  RException(IRObject* fromObject);
  RException(IRObject* fromObject, StrConstRef message);
  RException(StrConstRef message);

  virtual ~RException();

public:
  
  virtual IRObject* getFromObject();
  virtual std::string getExceptionMessage() const;
  virtual std::string getMessage() const;
  
  virtual std::vector<std::string> getAdditionalMessages();  
  virtual void addAdditionalMessage(StrConstRef message);
  
  virtual std::string what() {return getMessage(); };

protected:
  
  IRObject*   fromObject = NULL;
  std::string exceptionMessage;
  std::vector<std::string>* additionalMessages = NULL;
  mutable std::string _message;
  
};

} // namespace lfc
#endif //__RULP_ERROR_REXCEPTION_H__