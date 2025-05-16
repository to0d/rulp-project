// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/subject/AbsRSubject.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace lfc;
using namespace lfc;

namespace lfc {

void AbsRSubject::_decMbrRef(IRMember* mbr){
  if (mbr == null) {
    return;
  }

  auto obj = mbr->getValue();
  if (obj != null && obj != this) {
    RULP_DEC_REF(obj);
  }

  RULP_DEC_REF(mbr);
}

void AbsRSubject::_delete() {

  // std::cout << "AbsRSubject::_delete:"  << "\n";

  if (memberMap != null) {
    
    for(auto it = memberMap->begin(); it != memberMap->end(); ++it){
      IRMember* member = it->second;
      _decMbrRef(member);
    }

    memberMap->clear();

    LFC_FREE(memberMap);
  }

  if (_subjectFrame != null) {
    RULP_DEC_REF(_subjectFrame);
    _subjectFrame = null;
  }

  LFC_FREE(loaderList);
  LFC_FREE(memberList);
  memberList = null;
  loaderList = null;

  AbsRefObject::_delete();
}

void AbsRSubject::_incMbrRef(IRMember* mbr) {
  if (mbr == null) {
    return;
  }

  RULP_INC_REF(mbr);

  auto obj = mbr->getValue();
  if (obj != null && obj != this) {
    RULP_INC_REF(obj);
  }
}

void AbsRSubject::_load(){
  if (loaderList == null) {
    return;
  }

  std::vector<ISubjectLoader*> localLoaders(*loaderList);
  LFC_FREE(loaderList);

  for (auto loader : localLoaders) {
    loader->load(this);
  }
}

void AbsRSubject::addLoader(ISubjectLoader* loader) {
  if (loaderList == null) {
    loaderList = new std::vector<ISubjectLoader*>();
  }

  loaderList->push_back(loader);
}

int AbsRSubject::getLevel() const {
  if (_subjectLevel == -1) {

    if (getParent() == null) {
      _subjectLevel = 0;
    } else {
      _subjectLevel = getParent()->getLevel() + 1;
    }
  }

  return _subjectLevel;
}

boolean AbsRSubject::hasMember(StrConstRef name) const {
  if (name.empty() || memberMap == null) {
    return false;
  }

  return memberMap->find(name) != memberMap->end();
}

IRMember* AbsRSubject::getMember(StrConstRef name) {
  if (name.empty()) {
    return null;
  }

  //  std::cout << "getMember: '" << name << "', ptr=" << this << "\n";

  // if(memberMap != null){
  //   for(auto it = memberMap->begin(); it != memberMap->end(); ++it){
  //     std::cout << "mbr: '" << it->first << "'\n";
  //   }
  // }


  IRMember* mbr = null;
  if(memberMap != null){
    mbr = lfc::find(*memberMap, name);
  }

  if (mbr == null && loaderList != null) {
    _load();
    mbr = getMember(name);
  }

  return mbr;
}

IRFrame* AbsRSubject::getSubjectFrame() {
  if (_subjectFrame == null) {
    _subjectFrame = RulpFactory::createFrameSubject(this, definedFrame);
    RULP_INC_REF(_subjectFrame);
  }

  return _subjectFrame;
}

boolean AbsRSubject::hasSubjectFrame() const {
  return _subjectFrame != null;
}

boolean AbsRSubject::isFinal() const {
  return bFinal;
}

int AbsRSubject::getMemberCount() const {
  if (memberMap == null) {
    return 0;
  }

  return memberMap->size();
}

IRMember* AbsRSubject::getMember(int idx) const {
  return listMembers()[idx];
}

const std::vector<IRMember*>& AbsRSubject::listMembers() const {

  if (memberList == null){

    // std::cout << "listMembers: " << this->asString() << "\n";

    memberList = new std::vector<IRMember*>();
    for(auto it = memberMap->begin(); it != memberMap->end(); ++it){
      // std::cout << "key: " << it->first << "\n";
      memberList->push_back(it->second);
    }
  }
 
  return *memberList;
}

void AbsRSubject::setFinal(boolean bFinal) {
  this->bFinal = bFinal;
}

void AbsRSubject::setMember(StrConstRef name, IRMember* mbr) {
  if (name.empty()) {
    throw RException("member name is empty");
  }

  if(name == M_CLASS){
    throw RException("Can't set class");
  }

  // if(name == F_UNINIT){
  //    std::cout << "setMember:"  << "\n";
  // }

  // std::cout << "setMember: " << this->asString() << ", name=" << name << ", mbr=" << mbr->asString() << ", mbr_ptr=" << mbr << "\n";

  IRMember* oldMbr = null;

  if (memberMap != null) {
    auto it = memberMap->find(name);
    if(it != memberMap->end()){
      oldMbr = it->second;
      memberMap->erase(it);
    }
  }

  if (mbr != null) {

    // std::cout << "memberMap == null:"  << "\n";

    if (memberMap == null) {
      memberMap = new std::map<std::string, IRMember*>();
    }

    (*memberMap)[name] = mbr;

    _incMbrRef(mbr);
  }

  if(oldMbr != null){
    _decMbrRef(oldMbr);
  }

  if (memberMap !=null && memberMap->empty()) {
    LFC_FREE(memberMap);
    memberMap = null;
  }

  if(memberList !=null ){
    LFC_FREE(memberList);
    memberList = null;
  }  
}

void AbsRSubject::setSubjectFrame(IRFrame* subjectFrame) {
  this->_subjectFrame = subjectFrame;
}

} // namespace lfc