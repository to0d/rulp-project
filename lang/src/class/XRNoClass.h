// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_XRNOCLASS_H__
#define __RULP_CLASS_XRNOCLASS_H__
#include "rulp/object/IRClass.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRNoClass 
  : public AbsAtomObject
  , virtual public IRClass 
{

public:

  XRNoClass(StrConstRef className, IRFrame* definedFrame);
  virtual ~XRNoClass() = default;

public:

  virtual void addLoader(ISubjectLoader* loader) override;

  virtual const std::string& asString() const override;

  virtual StrConstRef getClassName() const override;

  virtual IRAtom* getClassTypeAtom() const override;

  virtual int getLevel() const override;

  virtual IRMember* getMember(StrConstRef name) override;

  virtual IRMember* getMember(int idx) const override;

  virtual int getMemberCount() const override;

  virtual IRSubject* getParent() const override;

  virtual IRFrame* getSubjectFrame() override;

  virtual std::string getSubjectName() const override;

  virtual IRClass* getSuperClass() const override;

  virtual RType getType() const override;

  virtual boolean hasMember(StrConstRef name) const override;

  virtual boolean hasSubjectFrame() const override;

  virtual boolean isConst() const override;

  virtual boolean isFinal() const override; 

  virtual IRInstance* newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;
 
  virtual void setFinal(boolean bFinal) override;

  virtual void setMember(StrConstRef name, IRMember* mbr) override;


protected:
  
  std::string className;

	IRAtom* classTypeAtom = NULL;

	IRFrame* definedFrame = NULL;

};

} // namespace lfc
#endif //__RULP_CLASS_XRNOCLASS_H__