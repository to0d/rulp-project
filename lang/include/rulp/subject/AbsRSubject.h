// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_SUBJECT_ABSSUBJECT
#define __RULP_SUBJECT_ABSSUBJECT
#include "rulp/object/IRSubject.h"
#include "rulp/object/AbsRefObject.h"
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/ISubjectLoader.h"
namespace lfc {

class AbsRSubject 
  : public AbsRefObject
  , virtual public IRSubject
{

public:
  AbsRSubject(){};
  
  AbsRSubject(IRFrame* definedFrame):definedFrame(definedFrame) {};

  virtual ~AbsRSubject() = default;

public:

  virtual void addLoader(ISubjectLoader* loader) override;

  virtual int getLevel() const override;

  virtual IRMember* getMember(StrConstRef name) override;

  virtual IRFrame* getSubjectFrame() override;

  virtual boolean hasMember(StrConstRef name) const override;

  virtual boolean hasSubjectFrame() const override;

  virtual boolean isFinal() const override;

  virtual bool  isSubject() const override { return true; }

  virtual int getMemberCount() const override;

  virtual IRMember* getMember(int idx) const override;

  virtual void setFinal(boolean bFinal) override;

  virtual void setMember(StrConstRef name, IRMember* mbr) override;

public:

  void setSubjectFrame(IRFrame* subjectFrame);

  const std::vector<IRMember*>& listMembers() const;

protected:

  virtual void _delete() override;

  void _decMbrRef(IRMember* mbr);

  void _incMbrRef(IRMember* mbr);

  void _load();

protected:

	mutable int _subjectLevel = -1;

	boolean bFinal = false;

	IRFrame* definedFrame = null;

	std::vector<ISubjectLoader*>* loaderList = null;

	std::map<std::string, IRMember*>* memberMap = null;

  mutable std::vector<IRMember*>* memberList = null;

  mutable IRFrame* _subjectFrame = NULL;

};

} // namespace lfc
#endif //__RULP_SUBJECT_ABSSUBJECT