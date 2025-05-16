// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRFRAME_PROTECTED_H__
#define __RULP_XIMPL_RUNTIME_XRFRAME_PROTECTED_H__
#include "XRFrame.h"

namespace lfc {

class XRFrameProtected 
  : public XRFrame
  , virtual public IRFrame{

public:

  XRFrameProtected(StrConstRef frameName) : XRFrame(frameName) {};

  virtual ~XRFrameProtected() = default;

public:

  virtual IRFrameEntry* createFrameEntry(StrConstRef name, IRObject* object) override;

  virtual IRFrameEntry* removeEntry(StrConstRef name) override;

  virtual void decRef() override;
  
  virtual int getRef() const override;
  
  virtual void incRef() override;
  
  // virtual bool isDeleted() const override;

protected:

  // virtual void _delete() override;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRFRAME_PROTECTED_H__