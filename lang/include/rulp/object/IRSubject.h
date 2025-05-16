// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_OBJECT_IRSUBJECT_H__
#define __RULP_OBJECT_IRSUBJECT_H__

#include "rulp/object/IRObject.h"
#include "rulp/object/IRMember.h"
#include "rulp/runtime/ISubjectLoader.h"
namespace lfc {

class IRFrame;
class IRSubject 
  : virtual public IRObject 
{
public:
 
  virtual void addLoader(ISubjectLoader* loader) = 0;

  virtual int getLevel() const = 0;

  virtual IRMember* getMember(StrConstRef name) = 0;

  virtual IRSubject* getParent() const = 0;

  virtual IRFrame* getSubjectFrame() = 0;

  virtual std::string getSubjectName() const = 0;

  virtual boolean hasMember(StrConstRef name) const = 0;

  virtual boolean hasSubjectFrame() const = 0 ;

  virtual boolean isFinal() const = 0;

  virtual int getMemberCount() const = 0;

  virtual IRMember* getMember(int idx) const = 0;

  virtual void setFinal(boolean bFinal) = 0;

  virtual void setMember(StrConstRef name, IRMember* mbr) = 0;

};


} // namespace lfc
#endif //__RULP_OBJECT_IRSUBJECT_H__