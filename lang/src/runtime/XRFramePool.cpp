// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[frame_tool]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(frame_tool)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(frame_tool)
#include "XRFramePool.h" 
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/trace.h"
using namespace lfc;
using namespace lfc;

namespace lfc {

XRFramePool::XRFramePool(int pool1Len)
  : pool1Len(pool1Len)
{
  reset();
}

XRFramePool::~XRFramePool(){
  LFC_FREE(globalFramePool1);
}

int XRFramePool::allocateFrameId(IRFrame* frame){
  int nextFrameId = -1;

  if (!globalFreeFrameIdList.empty()) {
    nextFrameId = globalFreeFrameIdList.top();
    globalFreeFrameIdList.pop();
  } else {
    nextFrameId = globalFrameMaxId++;
  }

  /*********************************************/
  // Allocate from pool1
  /*********************************************/
  if (nextFrameId < pool1Len) {
    
    if (globalFramePool1[nextFrameId] != null) {
      LFC_TRACE2("nextFrameId=", nextFrameId);
      assert(false && "Global frame pool 1 is not clear");
    }
    
    globalFramePool1[nextFrameId] = frame;
  }
  /*********************************************/
  // Allocate from pool2
  /*********************************************/
  else {

    int pool2Index = nextFrameId - pool1Len;

    if (pool2Index < globalFramePool2.size()) {

      if (globalFramePool2[pool2Index] != null) {
        LFC_TRACE2("nextFrameId=", nextFrameId);
        assert(false && "Global frame pool 2 is not clear");
      }

      globalFramePool2[pool2Index] = frame;
    } 
    else {

      while (globalFramePool2.size() < pool2Index) {
        globalFramePool2.push_back(null);
      }

      globalFramePool2.push_back(frame);
    }
  }

  return nextFrameId;
}

void XRFramePool::freeFrameId(int frameId){

  /*********************************************/
  // free to pool1
  /*********************************************/
  if (frameId < pool1Len) {

    if (globalFramePool1[frameId] == null) {
      // throw RException("Frame not found in pool1: " + frameId);
      return;
    }

    globalFramePool1[frameId] = null;

  }
  /*********************************************/
  // free to pool2
  /*********************************************/
  else {

    int pool2Index = frameId - pool1Len;

    if (pool2Index >= globalFramePool2.size()) {
      LFC_TRACE2("frameId=", frameId);
      assert(false && "Invalid frame id");
    }

    if (globalFramePool2[pool2Index] == null) {
      LFC_TRACE2("frameId=", frameId);
      assert(false && "Frame id not found");
    }

    globalFramePool2[pool2Index] = null;
  }

  globalFreeFrameIdList.push(frameId);

}

int XRFramePool::getFrameFreeIdCount() const {
  return globalFreeFrameIdList.size();
}

int XRFramePool::getFrameMaxId() const {
  return globalFrameMaxId;
}

std::vector<IRFrame*> XRFramePool::listGlobalFrames() const {
  std::vector<IRFrame*> frames;

  for(int i = 0; i < pool1Len; ++i){
    IRFrame* frame = globalFramePool1[i];
    if (frame != null) {
      frames.push_back(frame);
    }
  }

  for (IRFrame* frame : globalFramePool2) {
    if (frame != null) {
      frames.push_back(frame);
    }
  }

  return frames;
}

void XRFramePool::reset(){

  globalFrameMaxId = I_FRAME_ID_MIN;

  LFC_FREE(globalFramePool1);
  globalFramePool1 = new IRFrame* [pool1Len];
  for(int i = 0; i < pool1Len; ++i){
    globalFramePool1[i] = NULL;
  }

  globalFramePool2.clear();

  std::stack<int> tmp;
  globalFreeFrameIdList.swap(tmp);
}


} // namespace lfc