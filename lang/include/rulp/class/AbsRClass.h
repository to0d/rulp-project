// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_ABSRCLASS
#define __RULP_CLASS_ABSRCLASS
#include "rulp/object/IRClass.h"
#include "../subject/AbsRSubject.h"
namespace lfc {

class AbsRClass 
  : public AbsRSubject
  , virtual public IRClass
{

public:
  AbsRClass(StrConstRef className, IRFrame* definedFrame, IRClass* superClass);

  virtual ~AbsRClass() = default;

public:

  virtual StrConstRef asString() const override;

  virtual StrConstRef getClassName() const override;

  virtual IRAtom* getClassTypeAtom() const override;

  virtual IRSubject* getParent() const override;

  virtual std::string getSubjectName() const override;

  virtual IRClass* getSuperClass() const override;

  virtual RType getType() const override;

  virtual boolean isConst() const override;

protected:

  virtual void _delete() override;

protected:

  std::string className = null;

	IRAtom* classTypeAtom = null;

	IRClass* superClass = null;

};

} // namespace lfc
#endif //__RULP_CLASS_ABSRCLASS