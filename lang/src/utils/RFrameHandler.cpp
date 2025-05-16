// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/RFrameHandler.h"
#include "rulp/utils/RulpUtil.h"

using namespace lfc;

namespace lfc {

RFrameHandler::RFrameHandler(IRFrame* frame)
  : frame(frame) 
{
  if(frame != NULL ){
    RULP_INC_REF(frame);
  }
};

// RFrameHandler::RFrameHandler(const RFrameHandler& RH)
//   : frame(RH.frame) 
// {
//   if(frame != NULL ){
//     RULP_INC_REF(frame);
//   }
// }

// RFrameHandler::RFrameHandler(RFrameHandler&& RH)
//   : frame(RH.frame) 
// {
//   RH.frame = NULL;
// }

RFrameHandler::~RFrameHandler(){
  if(frame != NULL){
    frame->release();
    RULP_DEC_REF(frame);
    frame = NULL;
  }
}

IRFrame* RFrameHandler::get(){
  return frame;
}

// RFrameHandler& RFrameHandler::operator=(const RFrameHandler &RH){
//   RULP_DEC_REF(frame);
//   frame = RH.frame;
//   if(obj != NULL ){
//     RULP_INC_REF(obj);
//   }
//   return *this;
// }

// RFrameHandler& RFrameHandler::operator=(RFrameHandler &&RH){
//   RULP_DEC_REF(obj);
//   obj = RH.obj;
//   RH.obj = NULL;
//   return *this;
// }

RFrameHandler& RFrameHandler::operator=(IRFrame* frame){  

  if(this->frame != NULL){
    this->frame->release();
    RULP_DEC_REF(this->frame);
    this->frame = NULL;
  }

  this->frame = frame;
  if(frame != NULL ){
    RULP_INC_REF(frame);
  }
  return *this;
}

} // namespace lfc