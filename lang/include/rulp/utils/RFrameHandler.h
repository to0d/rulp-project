// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_RFRAME_HANDLER_H__
#define __RULP_UTILS_RFRAME_HANDLER_H__

#include "rulp/runtime/IRFrame.h"
namespace lfc {

#define AUTO_RLS_FRAME(x) RFH AUTO_NAME(AUTO_RLS) = (x)

class RFrameHandler {

public:

  RFrameHandler(){}
  RFrameHandler(IRFrame* frame);
//   RFrameHandler(const RFrameHandler& RH);
//   RFrameHandler(RFrameHandler&& RH);
  
  ~RFrameHandler();

  IRFrame* get();

//   RFrameHandler& operator=(const RFrameHandler &RH);
//   RFrameHandler& operator=(RFrameHandler &&RH);
  RFrameHandler& operator=(IRFrame* frame);

  operator IRFrame* () const {
    return frame;
  }

private:

  IRFrame* frame = NULL;

};

typedef RFrameHandler RFH;

} // namespace lfc
#endif //__RULP_UTILS_RFRAME_HANDLER_H__