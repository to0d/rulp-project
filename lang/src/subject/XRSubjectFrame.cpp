// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRSubjectFrame.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace lfc;
using namespace lfc;

namespace lfc {

void XRSubjectFrame::parentFrameRelease(IRFrame* _frame){
  if (this->parentFrame != null) {
    RULP_DEC_REF(this->parentFrame);
    this->parentFrame = null;
  }

  if (!this->isDeleted()) {
    this->setParentFrame(_frame->getParentFrame());
  }
}

class _SubjectParentFrameReleaseListener : public FrameListener {

public:

  _SubjectParentFrameReleaseListener(XRSubjectFrame* subjectFrame): subjectFrame(subjectFrame)
  {}

  virtual void doAction(IRFrame* _frame) override {
    subjectFrame->parentFrameRelease(_frame);
  }

private:

  XRSubjectFrame* subjectFrame;

};

void XRSubjectFrame::_delete() {
  LFC_FREE(parentFrameReleaseListener);
  XRFrame::_delete();
}

void XRSubjectFrame::_free_all_entries(){

  if (entryCacheMap != null) {
    
    std::vector<IRFrameEntry*> all_enties;

    for(auto it = entryCacheMap->begin(), end = entryCacheMap->end(); it != end; ++it){
      auto& name  = it->first;
      auto& entry = it->second;
      if(name != entry->getName()){
        assert(entry->getAliasName() != NULL && entry->getAliasName()->size() > 0);
      }
      else{
        all_enties.push_back(entry);
      }
    }


    for(auto entry : all_enties){
      RULP_FREE(entry);
    }
  
  }

  LFC_FREE(entryCacheMap);
  entryCacheMap = null;


  XRFrame::_free_all_entries();
}


IRObject* XRSubjectFrame::findLocalObject(StrConstRef name) {
  auto mbr = subject->getMember(name);
  if (mbr == null || mbr->getSubject() != this->subject) {
    return null;
  }

  return mbr->getValue();
}

IRFrameEntry* XRSubjectFrame::getEntry(StrConstRef name) {
  auto mbr = subject->getMember(name);
  if (mbr == null) {
    return XRFrame::getEntry(name);
  }

  // if(name == "?value"){
  //   std::cout << "\n";
  // }

  auto val = mbr->getValue();
  IRFrameEntry* entry = null;

  if (entryCacheMap == null) {
    entryCacheMap = new std::map<std::string, IRFrameEntry*>();
  } 
  else {
    entry = lfc::find(*entryCacheMap, name);
  }

  if (entry == null || entry->getObject() != val) {
    entry = createFrameEntry(name, val);
    (*entryCacheMap)[name] = entry;
  }

  return entry;
}

IRSubject* XRSubjectFrame::getSubject() {
  return subject;
}

IRFrameEntry* XRSubjectFrame::removeEntry(StrConstRef name) {
  throw RException("not support operation");
}

void XRSubjectFrame::setEntry(StrConstRef name, IRObject* obj) {
  auto mbr = subject->getMember(name);
  if (mbr != null) {
    throw RException("member " + name + " exist");
  }

  subject->setMember(name, RulpFactory::createMember(subject, name, obj));
}

void XRSubjectFrame::setEntryAliasName(IRFrameEntry* entry, StrConstRef aliasName) {
  throw RException("not support operation");
}


void XRSubjectFrame::setParentFrame(IRFrame* parentFrame) {
  if (parentFrame == null) {
    return;
  }

  if (parentFrame->isDeleted()) {
    setParentFrame(parentFrame->getParentFrame());
    return;
  }

  if(parentFrameReleaseListener == null){
    parentFrameReleaseListener = new _SubjectParentFrameReleaseListener(this);
  }

  parentFrame->addFrameReleaseListener(parentFrameReleaseListener);

  XRFrame::setParentFrame(parentFrame);
}

void XRSubjectFrame::setSubject(IRSubject* subject) {
  this->subject = subject;
}

} // namespace lfc