// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_SUBJECT_XRSUBJECT_FRAME_H__
#define __RULP_SUBJECT_XRSUBJECT_FRAME_H__
#include "rulp/runtime/IRFrame.h"
#include "../runtime/XRFrame.h"
namespace lfc {

class _SubjectParentFrameReleaseListener;
class XRSubjectFrame 
  : public XRFrame
  , virtual public IRFrame
{
  friend class _SubjectParentFrameReleaseListener;

public:

  XRSubjectFrame(StrConstRef frameName) : XRFrame(frameName) {};

  virtual ~XRSubjectFrame() = default;

public:

  virtual IRObject* findLocalObject(StrConstRef name) override;

  virtual IRFrameEntry* getEntry(StrConstRef name) override;

  virtual IRSubject* getSubject() override;

  virtual IRFrameEntry* removeEntry(StrConstRef name) override;

  virtual void setEntry(StrConstRef name, IRObject* obj) override;

  virtual void setEntryAliasName(IRFrameEntry* entry, StrConstRef aliasName) override;

public:

  void setParentFrame(IRFrame* parentFrame);

  void setSubject(IRSubject* subject);

  void parentFrameRelease(IRFrame* _frame);

protected:

  virtual void _delete() override;

  void _free_all_entries() override;

private:

  std::map<std::string, IRFrameEntry*>* entryCacheMap = null;

	IRSubject* subject = null;

  _SubjectParentFrameReleaseListener* parentFrameReleaseListener = null;
  
};

} // namespace lfc
#endif //__RULP_SUBJECT_XRSUBJECT_FRAME_H__