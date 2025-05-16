// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_FRAME_POOL_H__
#define __RULP_XIMPL_FRAME_POOL_H__
#include <stack>
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRFramePool.h"
namespace lfc {

class XRFramePool
  : virtual public IRFramePool
{

public:

  XRFramePool(int pool1Len);
  virtual ~XRFramePool();

public:

  virtual int allocateFrameId(IRFrame* frame) override;

  virtual void freeFrameId(int frameId) override;

  virtual int getFrameFreeIdCount() const override;
  
  virtual int getFrameMaxId() const override;

  virtual std::vector<IRFrame*> listGlobalFrames() const override;

  void reset();

private:

  int globalFrameMaxId = I_FRAME_ID_MIN;

  IRFrame** globalFramePool1 = NULL;

  std::vector<IRFrame*> globalFramePool2;

  std::stack<int> globalFreeFrameIdList;

  const int pool1Len;

};

} // namespace lfc
TRACE_SUB_MODULE_DEF(frame_tool)
#endif //__RULP_XIMPL_FRAME_POOL_H__