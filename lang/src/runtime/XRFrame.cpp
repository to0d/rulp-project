// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFrame.h" 
#include "XRFrameEntry.h" 
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include "lfc/base/string/format.h"
#include <iostream>

using namespace lfc;

namespace lfc {

XRFrame::XRFrame(StrConstRef frameName){
  // std::cout << "create frame: name=" << frameName << ", addr=" << (void*) this << "\n";
  this->frameName = frameName;
}

XRFrame::~XRFrame(){

  // std::cout << "delete frame: name=" << frameName << ", addr=" << this << ", frameId=" << frameId << "\n";

  LFC_FREE(frameReleaeListenerList);
  LFC_FREE(searchFrameList);
  
}

void XRFrame::_free_all_entries(){
  // std::cout << "_free_all_entries: frame=" << this->getFrameName() << "\n";
  if (entryMap != null) {
    
    std::vector<IRFrameEntry*> all_enties;
    // std::vector<IRFrameEntry*> alias_enties;
    for(auto it = entryMap->begin(), end = entryMap->end(); it != end; ++it){
      auto& name  = it->first;
      auto& entry = it->second;

      // if(frameName == "main"){
      //   std::cout << "key=" << name;
      //   std::cout  << ", ref=" << entry->getObject()->getRef() << "\n";
      // }
      // std::cout << "key=" << name;
      // std::cout  << ", ref=" << entry->getObject()->getRef() << "\n";
      if(name != entry->getName()){
        assert(entry->getAliasName() != NULL && entry->getAliasName()->size() > 0);
        // std::cout << "is alias\n";
        // alias_enties.push_back(entry);
      }
      else{
        all_enties.push_back(entry);
      }
    }

    // for(auto entry : alias_enties){
    //   assert(lfc::find(all_enties, entry));
    // }

    for(auto entry : all_enties){
      // std::cout << "key=" << name;
      // std::cout  << ", ref=" << entry->getObject()->getRef() << "\n";
      auto obj = entry->getObject();
      if(obj != this){
        RULP_DEC_REF(obj);
      }
      
      RULP_FREE(entry);
    }
  
  }

  LFC_FREE(entryMap);
  LFC_FREE(_entryCacheList);
  LFC_FREE(_nodeCacheMap);

  entryMap = NULL;
  _entryCacheList = NULL;
  _nodeCacheMap = NULL;
}

void XRFrame::_delete(){

  // std::cout << "_delete frame: name=" << frameName << ", addr=" << this << ", frameId=" << frameId << "\n";

  _free_all_entries();

  if (this->parentFrame != null) {
    RULP_DEC_REF(this->parentFrame);
    this->parentFrame = null;
  }

  if (this->frameId != I_FRAME_NULL_ID) {
    O_FRAME_POOL->freeFrameId(frameId);
    this->frameId = I_FRAME_NULL_ID;
  }  

  AbsRefObject::_delete();
}

void XRFrame::addSearchFrame(IRFrame* frame){
  if (frame == null) {
    return;
  }

  if (searchFrameList == null) {

    // No need to create the frame list
    if (this == frame) {
      return;
    }

    searchFrameList = new std::vector<IRFrame*>();
    searchFrameList->push_back(frame); // new added frame has higher priority
    searchFrameList->push_back(this);
    return;
  }

  // No need to update the frame list
  if ((*searchFrameList)[0] == frame) {
    return;
  }

  // Remove old subject
  lfc::erase_first_of(*searchFrameList, frame);

  searchFrameList->insert(searchFrameList->begin(), frame);
}

void XRFrame::addLoader(ISubjectLoader* loader) {
  throw RException("not support operation");
}

void XRFrame::release(){

  // std::cout << "frame release: " << this->getFrameName() << "\n";
  
  if (frameReleaeListenerList != null) {
    for (auto listener : *frameReleaeListenerList) {
      listener->doAction(this);
    }
  }

  _free_all_entries();
}

void XRFrame::addFrameReleaseListener(FrameListener* listener){
  if (frameReleaeListenerList == null) {
    frameReleaeListenerList = new std::vector<FrameListener*>();
  }

  if(lfc::find(*frameReleaeListenerList, listener)){
    frameReleaeListenerList->push_back(listener);
  }
}

const std::string& XRFrame::asString() const {
  return frameName;
}

RType XRFrame::getType() const{
  return T_FRAME;
}

std::string XRFrame::getFrameName() const{ 
  return frameName;
}

int XRFrame::getLevel() const {
  if (_frameLevel == -1) {
    
    if(getParent() == NULL) {
      _frameLevel = 0;
    }
    else {
      _frameLevel = getParent()->getLevel() + 1;
    }

  }

  return _frameLevel;
}

IRSubject* XRFrame::getParent() const {
  return parentFrame;
}

std::string XRFrame::getSubjectName() const {
  return frameName;
}

boolean XRFrame::hasMember(StrConstRef name) const {
  if (name.empty() || _nodeCacheMap == null) {
    return false;
  }

  return _nodeCacheMap->find(name) != _nodeCacheMap->end();
}

void XRFrame::setParentFrame(IRFrame* parentFrame){
  RULP_INC_REF(parentFrame);
  RULP_DEC_REF(this->parentFrame);
  this->parentFrame = parentFrame;
}

XRFrame::EntryNodePtr XRFrame::_findNode(StrConstRef name) {
  XRFrame::EntryNodePtr entryNode = nullptr;
  if (_nodeCacheMap != NULL) { 
    auto it = _nodeCacheMap->find(name);
    if(it != _nodeCacheMap->end()){
      entryNode = it->second;
    }
  }
  else {
    _nodeCacheMap = new std::map<std::string, EntryNodePtr>();
  }

  return entryNode;
}

IRFrameEntry* XRFrame::_findLocalEntry(StrConstRef name) {
  IRFrameEntry* entry = NULL;
  if(entryMap != null){
    auto it = entryMap->find(name);
    if(it != entryMap->end()){
      entry = it->second;
    }
  }

  if (entry == null) {

    if(name == A_LOCAL){
      entry = _insertEntry(A_LOCAL, this);
    }
    else if(name == A_PARENT){
      entry = _insertEntry(A_PARENT, parentFrame);
      RULP_INC_REF(parentFrame);
    }
    else {
      if (frameLoader != null) {
        IRObject* obj = frameLoader->load(name);
        if (obj != null) {
          entry = _insertEntry(name, obj);
        }
      }
    }
    
  }

  return entry;
}

IRFrameEntry* XRFrame::_insertEntry(StrConstRef name, IRObject* obj) {

  auto localEntry = createFrameEntry(name, obj);
  if(entryMap == null) {
    entryMap = new std::map<std::string, IRFrameEntry*>();
  }

  (*entryMap)[name] = localEntry;

  if (_entryCacheList != null) {
    _entryCacheList->push_back(localEntry);
  }
  
  if (_nodeCacheMap != null) {
    _nodeCacheMap->erase(name);
  }

  return localEntry;
}

IRFrameEntry* XRFrame::getEntry(StrConstRef name) {
 
 auto entryNode = _findNode(name);

  if (entryNode == NULL) {

    auto localEntry = _findLocalEntry(name);
    if (localEntry == null) {

      if (parentFrame != null) {

        auto entry = parentFrame->getEntry(name);
        if (entry == null) {
          return null;
        }

        entryNode = EntryNodePtr(new XRFrame::EntryNode());
        entryNode->entry = entry;
        entryNode->isLocal = false;
        (*_nodeCacheMap)[name] = entryNode;

      } 
      else {
        return null;
      }

    } 
    else {

      entryNode = EntryNodePtr(new XRFrame::EntryNode());
      entryNode->isLocal = true;
      entryNode->entry = localEntry;
      (*_nodeCacheMap)[name] = entryNode;

    }

  }

  return entryNode->entry;
}

IRFrameEntry* XRFrame::createFrameEntry(StrConstRef name, IRObject* object) {
  return RulpFactory::createFrameEntry(this, name, object);
}

std::vector<IRFrame*>* XRFrame::getSearchFrameList() const {
  return searchFrameList;
}

void XRFrame::setEntry(StrConstRef name, IRObject* obj){
  auto localEntry = _findLocalEntry(name);

  // New entry
  if (localEntry == null) {
    localEntry = _insertEntry(name, obj);

    if(obj != this){
      RULP_INC_REF(obj);
    }
    
  }
  // Update entry
  else {

    auto oldObj = localEntry->getObject();
    localEntry->setObject(obj);
    
    if(obj != this){
      RULP_INC_REF(obj);
    }

    if(oldObj != this){
      RULP_DEC_REF(oldObj);
    }
  
  }
}

static std::vector<IRFrameEntry*> EMPTY_ENTRY_LIST;

const std::vector<IRFrameEntry*>& XRFrame::listEntries() const {

  // std::cout << "listEntries: frame=" << (void*) this << "\n";

  // if(this->getFrameId()  == -1){
  //   std::cout << "\n";
  // }

  // std::cout << "listEntries: frame=" << this->getFrameId() << "\n";

  if (entryMap == null || entryMap->empty()) {
    return EMPTY_ENTRY_LIST;
  }

  

  // std::cout << "listEntries: frame=" << this->getFrameName() << "\n";

  _entryCacheList = new std::vector<IRFrameEntry*>();
  for(auto it = entryMap->begin(); it != entryMap->end(); ++it){
    auto& name  = it->first;
    auto& entry = it->second;

    // std::cout << " entry name=" << name;

    // if(name == "type#class1"){
    //   // std::cout << "\n";
    //   continue;
    // }

    // ignore alias entries
    if (entry->getName() != name) {
      // std::cout << "\n";
      continue;
    }

    _entryCacheList->push_back(entry);
    // std::cout << "\n";
  }

  return *_entryCacheList;
}

int XRFrame::getMemberCount() const{
  return listEntries().size();
}

IRMember* XRFrame::getMember(int idx) const{
  return listEntries()[idx];
}

IRMember* XRFrame::getMember(StrConstRef name) {
  return getEntry(name);
}

IRFrame* XRFrame::getSubjectFrame() {
  return parentFrame;
}

boolean XRFrame::hasSubjectFrame() const {
  return parentFrame != null;
}

IRSubject* XRFrame::getSubject() {

  if (_subject == null) {

    if (parentFrame == null || parentFrame->getSubject() == parentFrame) {
      _subject = this;
    } 
    else {
      _subject = parentFrame->getSubject();
    }
  }

  return _subject;
}

IRObject* XRFrame::findLocalObject(StrConstRef name){

  IRFrameEntry* entry = NULL;
  if(entryMap != null){
    auto it = entryMap->find(name);
    if(it != entryMap->end()){
      return it->second->getObject();
    }
  }
  
  return null;
}

void XRFrame::setEntryAliasName(IRFrameEntry* entry, StrConstRef aliasName){
  // Check alias name
  auto localEntry = _findLocalEntry(aliasName);
  if (localEntry != null) {
    throw RException( LFC_STR_FORMAT_BGN 
                          "the name %s is already defined: %s"
                        , aliasName.c_str()
                        , localEntry->asString().c_str()
                      LFC_STR_FORMAT_END);
  }

  if(entryMap == null) {
    entryMap = new std::map<std::string, IRFrameEntry*>();
  }

  (*entryMap)[aliasName] = entry;

  if (_nodeCacheMap != null) {
    lfc::erase(*_nodeCacheMap, aliasName);
  }

  dynamic_cast<XRFrameEntry*>(entry)->addAliasName(aliasName);
}

IRFrameEntry* XRFrame::removeEntry(StrConstRef name){
  if (entryMap == null) {
    return null;
  }

  IRFrameEntry* entry = null;
  {
    auto it = entryMap->find(name);
    if(it == entryMap->end()){
      return null;
    } 

    entry = it->second;
    entryMap->erase(it);
  }

  if (_nodeCacheMap != null) {
    auto it = _nodeCacheMap->find(name);
    if(it != _nodeCacheMap->end()){
      _nodeCacheMap->erase(it);
    }
  }

  if (entry != null) {
    _entryCacheList = null;
  }

  RULP_DEC_REF(entry->getValue());
  return entry;
}

void XRFrame::setMember(StrConstRef name, IRMember* mbr){
  if (mbr == null || mbr->getValue() == null) {
    removeEntry(name);
  } 
  else {
    setEntry(name, mbr->getValue());
  }
}

} // namespace lfc