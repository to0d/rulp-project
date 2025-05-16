// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_ABSRINSTANCE
#define __RULP_CLASS_ABSRINSTANCE
#include "rulp/object/IRInstance.h"
#include "../subject/AbsRSubject.h"
namespace lfc {

class AbsRInstance 
  : public AbsRSubject
  , virtual public IRInstance
{

public:
  AbsRInstance();
  
  AbsRInstance(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame);

  virtual ~AbsRInstance() = default;

public:

  virtual StrConstRef asString() const override;

  virtual void deleteIt(IRInterpreter* interpreter, IRFrame* frame) override;

  virtual int getInstanceKey() const override {return 0;}

  virtual std::string getInstanceName() const override;

  virtual IRMember* getMember(StrConstRef name) override;

  virtual IRSubject* getParent() const override;

  virtual IRClass* getRClass() const override;

  virtual std::string getSubjectName() const override;

  virtual RType getType() const override;

  virtual void init(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override  ;
  
  virtual bool isError() const override { return false; }

public:

  void setRClass(IRClass* rClass);

protected:

  virtual void _delete() override;

protected:

	mutable std::string _toString;

	std::string instanceName;

	IRClass* rClass = null;

};

} // namespace lfc
#endif //__RULP_CLASS_ABSRINSTANCE