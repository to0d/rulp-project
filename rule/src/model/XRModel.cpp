// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRModel.h"
#include "rulp/utils/RuleUtil.h"
#include <iostream>

namespace lfc {

const RRunState MODEL_SSTATE[6][6] = {
// Completed(0), Runnable(1), Running(2), Halting(3), Failed(4), Partial(5)
  { Completed  , Completed  , Completed , Halting   , Failed   , Completed  }, /* Completed */
  { Runnable   , Runnable   , Running   , Halting   , Failed   , Runnable   }, /* Runnable  */
  { Running    , Running    , Running   , Halting   , Failed   , Running    }, /* Running   */
  { Halting    , Halting    , Halting   , Halting   , Halting  , Halting    }, /* Halting   */
  { Failed     , Failed     , Failed    , Failed    , Failed   , Failed     }, /* Failed    */
  { Partial    , Partial    , Partial   , Halting   , Failed   , Partial    }  /* Partial   */
};


XRModel::XRModel(StrConstRef modelName, IRClass* rclass, IRFrame* frame)
  : AbsRInstance(rclass, modelName, frame)
  
{
  // this.nodeGraph = new XRNodeGraph(this, entryTable);
  // this.modelCounter = new XRRModelCounter(this);
  // this.constraintUtil = new ModelConstraintUtil(this);
}

void XRModel::_setRunState(RRunState state, bool force) {
  RRunState newState;

  if (force) {
    newState = state;
  } 
  else {
    newState = MODEL_SSTATE[state][modelRunState];
  }

  if (modelRunState != newState) {
    if (RuleUtil::isModelTrace()) {
      std::printf( "Model State: %d ==> %d\n" 
                  , static_cast<int>(modelRunState)
                  , static_cast<int>(newState));
    }

    this->modelRunState = newState;
    // modelCounter.incStateChangeCount();

  //   if (modelStatsVar != nullptr) {
  //     // Assuming setValue is a method of whatever type modelStatsVar is
  //     static_cast<YourStatsVarType*>(modelStatsVar)->setValue(toObject(newState));
  //   }
  }
}

IRRule* XRModel::addRule(StrConstRef ruleName, IRList* condList, IRList* actionList) {

}

int XRModel::getPriority() {
  return modelPriority;
}

RRunState XRModel::getRunState() {
  return modelRunState;
}

RRunState XRModel::halt() {

  if (RuleUtil::isModelTrace()) {
    std::cout << "==> halt: " << std::endl;
  }

  counter.mcHalt++;

  RRunState _state = getRunState();
  switch (_state) {
    case RRunState::Completed:
    case RRunState::Runnable:
    case RRunState::Running:
    case RRunState::Partial:
      _setRunState(RRunState::Halting);
      return getRunState();

    case RRunState::Halting:
      return RRunState::Halting;

    case RRunState::Failed:
      return RRunState::Failed;

    default:
      throw RException("unknown state: " + std::to_string(static_cast<int>(getRunState())));
  }
}

int XRModel::start(int priority, int limit) {
  
}

}