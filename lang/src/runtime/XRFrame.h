// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFRAME_H__
#define __RULP_XIMPL_RUNTIME_XRFRAME_H__
#include <vector>
#include <map>
#include <memory>
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRFrameLoader.h"
#include "rulp/runtime/IRInterpreter.h"
#include "rulp/object/AbsRefObject.h"

namespace lfc {

class XRFrame 
  : public AbsRefObject
  , virtual public IRFrame{

  struct EntryNode {
    IRFrameEntry* entry   = NULL;
    bool          isLocal = false;

    EntryNode() = default;
    EntryNode(const EntryNode& N): entry(N.entry), isLocal(N.isLocal) {};
  };

  typedef std::shared_ptr<EntryNode> EntryNodePtr;

public:
  XRFrame(StrConstRef frameName);
  
  virtual ~XRFrame();

public:

  virtual void addFrameReleaseListener(FrameListener* listener) override;

  virtual void addLoader(ISubjectLoader* loader) override;

  virtual void addSearchFrame(IRFrame* frame) override;

  virtual const std::string& asString() const override;

  virtual IRFrameEntry* createFrameEntry(StrConstRef name, IRObject* object) override;

  virtual RType getType() const override;

  virtual std::string getFrameName() const override;

  virtual int getLevel() const override;

  virtual IRMember* getMember(StrConstRef name) override;

  virtual IRSubject* getParent() const override;

  virtual IRFrameEntry* getEntry(StrConstRef name) override;

  virtual int getFrameId() const override {return frameId;}

  virtual IRFrame* getSubjectFrame() override;

  virtual std::string getSubjectName() const override;

  virtual IRFrame* getParentFrame() const override { return parentFrame; }

  virtual IRSubject* getSubject() override;

  virtual IRThreadContext* getThreadContext() const override { return threadContext; };

  virtual int getMemberCount() const override;

  virtual IRMember* getMember(int idx) const override;

  virtual IRObject* findLocalObject(StrConstRef name) override;

  virtual std::vector<IRFrame*>* getSearchFrameList() const override;

  virtual boolean hasMember(StrConstRef name) const override;

  virtual boolean hasSubjectFrame() const override;

  virtual boolean isFinal() const override { return bFinal; }

  virtual bool isSubject() const override { return true; }

  virtual const std::vector<IRFrameEntry*>& listEntries() const override;

  virtual void release() override;

  virtual IRFrameEntry* removeEntry(StrConstRef name) override;

  virtual void setEntry(StrConstRef name, IRObject* obj) override;

  virtual void setEntryAliasName(IRFrameEntry* entry, StrConstRef aliasName) override;
  
  virtual void setFinal(boolean bFinal) override { this->bFinal = bFinal; }

  virtual void setMember(StrConstRef name, IRMember* mbr) override;

  virtual void setThreadContext(IRThreadContext* context) override { this->threadContext = context; }

public: 

  void setParentFrame(IRFrame* parentFrame);

  void setFrameId(int frameId) {
		this->frameId = frameId;
	}

protected:

  virtual void  _delete() override;

  virtual void _free_all_entries();

protected:

  EntryNodePtr _findNode(StrConstRef name);
  
  IRFrameEntry* _findLocalEntry(StrConstRef name);
  
  IRFrameEntry* _insertEntry(StrConstRef name, IRObject* obj);

  IRThreadContext* threadContext = null;

protected:

  std::map<std::string, IRFrameEntry*>  *entryMap = null;
  
  mutable std::vector<IRFrameEntry*>* _entryCacheList = null;
  
  std::map<std::string, EntryNodePtr> *_nodeCacheMap = null;
        
  int frameId = -1;
  
  IRFrameLoader* frameLoader = null;

  std::vector<IRFrame*>* searchFrameList = null;

  boolean bFinal = false;

  std::vector<FrameListener*>* frameReleaeListenerList = null;

protected:

  std::string frameName;

  IRFrame* parentFrame = NULL;
  
  mutable int _frameLevel = I_FRAME_NULL_ID;

  mutable IRSubject* _subject = null;;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRFRAME_H__