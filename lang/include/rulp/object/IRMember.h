// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRMEMBER_H__
#define __RULP_LANG_IRMEMBER_H__
#include "rulp/object/IRObject.h"
#include "rulp/lang/RAccessType.h"
namespace lfc {

class IRMember : virtual public IRObject {

public:

  virtual RAccessType getAccessType() const = 0;

  virtual std::string getName() const = 0;

  virtual int getProperty() const = 0;

  virtual IRObject* getSubject() const = 0;

  virtual IRObject* getValue() const = 0;

  virtual void setAccessType(RAccessType accessType) = 0;

  virtual void setProperty(int property) = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRMEMBER_H__