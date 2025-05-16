// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_XRMEMBER_REF
#define __RULP_CLASS_XRMEMBER_REF
#include "rulp/object/IRMember.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRMemberRef 
  : public AbsRefObject
  , virtual public IRMember 
{

public:

  XRMemberRef(IRObject* subject, StrConstRef name, IRObject* value);

  virtual ~XRMemberRef();

public:

  virtual const std::string& asString() const override;

  virtual std::string getName() const override;
  
  virtual RType getType() const override;

  virtual RAccessType getAccessType() const override;

  virtual IRObject* getSubject() const override;

  virtual IRObject* getValue() const override;

  virtual int getProperty() const override;

  virtual void setAccessType(RAccessType accessType) override;

  virtual void setProperty(int property) override;

protected:

  virtual void _delete() override;

private:

  mutable std::string _string;
  RAccessType accessType = RAccessType::DEFAULT;
  std::string name;
  int property = 0;
  IRObject* subject;  
  IRObject* value;

};

} // namespace lfc
#endif //__RULP_CLASS_XRMEMBER_REF