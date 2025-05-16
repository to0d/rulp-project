// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRFRAME_POOL_H__
#define __RULP_RUNTIME_IRFRAME_POOL_H__
#include "rulp/runtime/IRFrame.h"
namespace lfc {

class IRFramePool 
{

public:

  virtual ~IRFramePool() = default;

public:
    
  virtual int allocateFrameId(IRFrame* frame) = 0;

  virtual void freeFrameId(int frameId) = 0;

  virtual int getFrameFreeIdCount() const = 0;
  
  virtual int getFrameMaxId() const = 0;

  virtual std::vector<IRFrame*> listGlobalFrames() const = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRFRAME_POOL_H__