// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFRAME_ENTRY_H__
#define __RULP_XIMPL_RUNTIME_XRFRAME_ENTRY_H__
#include <vector>
#include <map>
#include <memory>
#include "rulp/runtime/IRFrameEntry.h"
#include "rulp/runtime/IRFrameLoader.h"
#include "rulp/object/IRMember.h"
#include "rulp/object/AbsAtomObject.h"

namespace lfc {

class XRFrameEntry 
  : public AbsAtomObject
  , virtual public IRFrameEntry
  , virtual public IRMember
{

 
public:
  XRFrameEntry(int entryId, IRFrame* frame, StrConstRef name, IRObject* object);
  
  virtual ~XRFrameEntry();

public:

  virtual const std::string& asString() const override;

  virtual const StrList* getAliasName() const override;

  virtual int getEntryId() const override;

  virtual IRFrame* getFrame() const override;

  virtual std::string getName() const override;

  virtual IRObject* getObject() const override;

  virtual RAccessType getAccessType() const override;

  virtual int getProperty() const override;

  virtual IRObject* getSubject() const override;

  virtual RType getType() const override;

  virtual IRObject* getValue() const override;

  virtual void setAccessType(RAccessType accessType) override;

  virtual void setProperty(int property) override;

public:

  void addAliasName(StrConstRef aliasName);

  virtual void setObject(IRObject* object) override;

private:

  mutable std::string _string;

  std::vector<std::string> *aliasNames = null;

  int entryId;

  IRFrame* frame = null;;

  std::string name;

  IRObject* object = null;

};



} // namespace lfc
#endif //__RULP_XIMPL_RUNTIME_XRFRAME_ENTRY_H__