// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <sstream>
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[trace_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(trace_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#define USE_LFC_NEW_TRACE
TRACE_SUB_MODULE_IMPL(trace_util)
#include "rulp/lang.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/utils/TraceUtil.h"
#include "rulp/utils/LCOUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/string.h"
#include "lfc/base/math.h"
#include "lfc/base/trace.h"
#include "lfc/base/container.h"
#include <cstring>
#include <queue>

using namespace lfc;
using namespace lfc;
namespace lfc {

static std::map<std::string, IROptInfoTracer*> optTracerMap;

static std::vector<std::string> optTracerNameList;

static const std::string SEP_LINE1 = "==========================================================================================================================\n";

static const std::string SEP_LINE2 = "--------------------------------------------------------------------------------------------------------------------------\n";

static const std::string SEP_LINE3 = "..........................................................................................................................\n";

static void _printObjectCreateCount(std::stringstream& ss) {

  ss << "Object create count:\n";
  ss << SEP_LINE1;
	ss << LFC_STR_FORMAT_BGN 
          "%12s: %12s %12s %12s\n"
        , "RType"
        , "Create"
        , "Delete"
        , "Exist" 
        LFC_STR_FORMAT_END;
  ss << SEP_LINE2;

  for(auto t : ALL_RTYPE){
    int createCount = RULP_GET_OBJ_CREATE_COUNT(t);
    if (createCount == 0) {
      continue;
    }

    int deleteCount = RULP_GET_OBJ_DELETE_COUNT(t);

    ss << LFC_STR_FORMAT_BGN 
          "%12s: %12d %12d %12d\n"
          , lfc::to_string(t).c_str()
          , createCount
          , deleteCount
          , createCount - deleteCount 
          LFC_STR_FORMAT_END;
  }

  ss << LFC_STR_FORMAT_BGN "%12s: %12d %12d\n", "interpreter", RulpFactory::getInterpreterCount(), 0 LFC_STR_FORMAT_END;
  ss << LFC_STR_FORMAT_BGN "%12s: %12d %12d\n", "frameEntry", RulpFactory::getFrameEntryCreateCount(), 0 LFC_STR_FORMAT_END;
  ss << LFC_STR_FORMAT_BGN "%12s: %12d %12d\n", "lambda", RulpFactory::getLambdaCount(), 0 LFC_STR_FORMAT_END;

  ss << SEP_LINE1;
  ss << "\n";
}

static void _printTotalRunTimeInfo(std::stringstream& ss, IRInterpreter* interpreter) {

	ss << "Total runtime info:\n";
  ss << SEP_LINE1;
  ss << LFC_STR_FORMAT_BGN "%30s: %8s\n", "Name", "info" LFC_STR_FORMAT_END;
  ss << SEP_LINE2;
 
  ss << LFC_STR_FORMAT_BGN 
            "%30s: %8d\n"
          , "Interpreter call id"
          , interpreter->getCallId() 
        LFC_STR_FORMAT_END;
  
  ss << LFC_STR_FORMAT_BGN 
            "%30s: %8d %8d\n"
          , "Interpreter call level/max"
          , interpreter->getTLS()->getCallLevel()
          , interpreter->getMaxCallLevel()
        LFC_STR_FORMAT_END;

  ss << LFC_STR_FORMAT_BGN 
            "%30s: %8d\n"
          , "Frame max level"
          , RuntimeUtil::getFrameMaxLevel()
        LFC_STR_FORMAT_END;
  
  ss << LFC_STR_FORMAT_BGN 
            "%30s: %8d\n"
          , "Frame max id"
          , RGlobal::getFrameMaxId()
        LFC_STR_FORMAT_END;

  ss << LFC_STR_FORMAT_BGN 
            "%30s: %8d\n"
          , "Frame free id count"
          , RGlobal::getFrameFreeIdCount()
        LFC_STR_FORMAT_END;

  ss << SEP_LINE1;
  ss << "\n";
}

void TraceUtil::printOptimizeInfo(std::stringstream& ss, IRInterpreter* interpreter) {

  if (optTracerNameList.empty()) {
    return;
  }

  ss << SEP_LINE1;
  ss << LFC_STR_FORMAT_BGN "%10s: %s\n", "Name", "Status" LFC_STR_FORMAT_END;
  ss << SEP_LINE2;


  for (auto name : optTracerNameList) {
    auto tracer = optTracerMap[name];
    ss << LFC_STR_FORMAT_BGN "%10s: %s\n", name.c_str(), tracer->printInfo(interpreter).c_str() LFC_STR_FORMAT_END;
  }

  ss << SEP_LINE1;
}

static std::string _toTypeString(RRType* type) {
  return type->getName();
}

static void _printExpressionComputeCount(std::stringstream& ss) {

  ss << "Expression compute count:\n";
  ss << SEP_LINE1;
  ss << LFC_STR_FORMAT_BGN "%10s: %8s\n", "RType", "Count" LFC_STR_FORMAT_END;
  ss << SEP_LINE2;

  for (auto t : ALL_RTYPE) {

    int count = RuntimeUtil::getExprComputeCount(t->getIndex());
    if (count == 0) {
      continue;
    }

    ss << LFC_STR_FORMAT_BGN "%10s: %8d\n", _toTypeString(t).c_str(), count LFC_STR_FORMAT_END;
  }

  ss << SEP_LINE1;
  ss << "\n";
}

static std::vector<std::string> formatCounterTable(std::vector<DeCounter*>& counters, const int columnCount) {

  std::vector<std::string> lines;

  int maxTimeUnit = -1;

  // Find max unit
  for (auto counter : counters) {
    int unit = counter->getUnit();
    if (unit > maxTimeUnit) {
      maxTimeUnit = unit;
    }
  }

  const int rowCount = counters.size();
  int callCount  [rowCount][columnCount];
  int totalCount [columnCount];

  memset(&callCount, 0, sizeof(callCount));
  memset(&totalCount, 0, sizeof(totalCount));

  int maxValue = -1;

  // Expand all unit to max unit

  int row = 0;
  for (auto counter : counters) {

    while (counter->getUnit() < maxTimeUnit) {
      counter->expand();
    }

    for (int i = 0; i < columnCount; ++i) {

      int value = counter->getCount(i);
      callCount[row][i] = value;
      totalCount[i] += value;
      if (value > maxValue) {
        maxValue = value;
      }
    }

    row++;
  }

  int column = columnCount;

  for (; column > 0; --column) {
    if (totalCount[column - 1] != 0) {
      break;
    }
  }

  // Calculate the max value unit: x(value unit), y(max count value)
  // x^10 < Y ==> x = e^(log(y)/10)
  int valueUnit = (int) MATH_CEIL(MATH_EXP(MATH_LOG(maxValue) / 10));

  int maxTotalValue = -1;
  for (int i = 0; i < column; ++i) {
    int value = totalCount[i];
    if (value > maxTotalValue) {
      maxTotalValue = value;
    }
  }

  int maxValueUnit = (int) MATH_CEIL(MATH_EXP(MATH_LOG(maxTotalValue) / 10));
  double logOfMaxValueUnit = MATH_LOG(maxValueUnit);

  std::stringstream countHead;

  for (int i = 0; i < column; ++i) {

    int value = totalCount[i];
    if (value == 0) {
      countHead << '.' ;
    } 
    else if (value == 1) {
      countHead << '1' ;
    } 
    else {

      // Calculate value : x(value unit), y(count value), z(value)
      // X^Y = Z ==> Y = log(Y)/Log(X)
      int dv = (int) MATH_CEIL(MATH_LOG(value) / logOfMaxValueUnit) + 1;
      if (dv >= 10) {
        countHead << 'X';
      }
      else {
        countHead << TO_STR(dv);
      }
    }
  }

  countHead << LFC_STR_FORMAT_BGN 
                  " max=%d, unit=%d^x"
                , maxTotalValue
                , maxValueUnit
              LFC_STR_FORMAT_END;

  lines.push_back( LFC_STR_FORMAT_BGN 
                      "row=%d, column=%d(%d), value-max=%d, value-unit=%d^x"
                    , rowCount
                    , column
                    , maxTimeUnit
                    , maxValue
                    , valueUnit
                  LFC_STR_FORMAT_END);
  
  lines.push_back(countHead.str());

  double logOfvalueUnit = MATH_LOG(valueUnit);

  for (auto counter : counters) {

    std::stringstream valueLine;

    for (int i = 0; i < column; ++i) {

      int value = counter->getCount(i);
      if (value == 0) {
        valueLine << ' ';
      } 
      else if (value == 1) {
        valueLine << '1';
      } 
      else {        
        // Calculate value : x(value unit), y(count value), z(value)
        // X^Y = Z ==> Y = log(Y)/Log(X)
        int dv = (int) MATH_CEIL(MATH_LOG(value) / logOfvalueUnit) + 1;
        if (dv >= 10) {
          valueLine << 'X';
        } else {
          valueLine << TO_STR(dv);
        }
      }
    }

    lines.push_back(valueLine.str());
  }

  return lines;
}

static std::string _toRefString(IRObject* obj) {

  if (obj == null) {
    return "nil";
  }

  return TO_STR(obj->getRef());
}

static std::string _toTypeString(IRObject* obj) {

  if (IS_FUNC_LIST(obj)) {
    return "funcList";
  }

  return _toTypeString(obj->getType());
}

static int get_func_type_index(IRFunction* f){
  if(f->isList())
    return 2;
  
  if(f->isLambda())
    return 1;

  return 0;
}

static void _printCallableStatsInfo(std::stringstream& ss, IRInterpreter* interpreter) {

  std::vector<std::tuple<IRObject*, IRFrame*, DeCounter*>> ccList;

  // main frame
  {
    auto frame = MAIN_FRAME(interpreter);
    auto objCallMap = RuntimeUtil::getObjecCallCount(frame);
    for(auto it = objCallMap.begin(), end = objCallMap.end(); it != end; ++it){
      ccList.push_back(std::make_tuple(it->first, frame, it->second));
    }
  }

  // system frame
  {
    auto frame = SYSTEM_FRAME(interpreter);
    auto objCallMap  =  RuntimeUtil::getObjecCallCount(frame);
    for(auto it = objCallMap.begin(), end = objCallMap.end(); it != end; ++it){
      ccList.push_back(std::make_tuple(it->first, frame, it->second));
    }
  }

  // root frame
  {
    auto frame = ROOT_FRAME(interpreter);
    auto objCallMap  =  RuntimeUtil::getObjecCallCount(frame);
    for(auto it = objCallMap.begin(), end = objCallMap.end(); it != end; ++it){
      ccList.push_back(std::make_tuple(it->first, frame, it->second));
    }
  }

  std::sort(ccList.begin(), ccList.end(), [](auto& t1, auto& t2){

    int d = std::get<2>(t2)->getTotalCount() - std::get<2>(t1)->getTotalCount();
    if (d == 0) {
      d = STR_COMPARE(std::get<0>(t2)->asString(), std::get<0>(t1)->asString());
    }

    if (d == 0) {
      d = STR_COMPARE(std::get<1>(t2)->getFrameName(), std::get<1>(t1)->getFrameName());
    }

    if (d == 0) {
      d = std::get<0>(t2)->getType()->getIndex() - std::get<0>(t1)->getType()->getIndex();
    }

    if(d == 0 && std::get<0>(t2)->getType()->getIndex() == E_FUNC){
      d = get_func_type_index(AS_FUNC(std::get<0>(t2))) - get_func_type_index(AS_FUNC(std::get<0>(t1)));
    }

    if (d == 0) {
      d = std::get<2>(t2)->getMaxId() - std::get<2>(t1)->getMaxId();
    }

    return d < 0;
  });


  std::vector<DeCounter*> counters;
  for (auto& t : ccList) {
    counters.push_back(std::get<2>(t));
  }

  auto counterLines = formatCounterTable(counters, MAX_COUNTER_SIZE);
  int counterLineIndex = 0;

  ss << LFC_STR_FORMAT_BGN 
            "Callable stats info: callId=%d, %s\n"
          , interpreter->getCallId()
          , counterLines[counterLineIndex++].c_str()
        LFC_STR_FORMAT_END;
  
  ss << SEP_LINE1;
  ss << LFC_STR_FORMAT_BGN 
            "%8s %8s %6s %4s %-30s %s\n"
          , "Frame"
          , "RType"
          , "Count"
          , "Ref"
          , "Object"
          , counterLines[counterLineIndex++].c_str()
        LFC_STR_FORMAT_END;
  
  ss << SEP_LINE2;

  for(auto& t : ccList) {

    auto counter  = std::get<2>(t);
    auto frame    = std::get<1>(t);
    auto obj      = std::get<0>(t);

    auto objName = "" + obj->asString();
    if (objName.length() > 30) {
      objName = objName.substr(0, 30);
    }    

    ss << LFC_STR_FORMAT_BGN 
              "%8s %8s %6d %4s %-30s %s\n"
            , frame->getFrameName().c_str()
            , _toTypeString(obj).c_str()
            , counter->getTotalCount()
            , _toRefString(obj).c_str()
            , objName.c_str()
            , counterLines[counterLineIndex++].c_str()
          LFC_STR_FORMAT_END;
  }

  ss << SEP_LINE1;
  ss << "\n";
}

static std::string _getEntryAliasName(IRFrameEntry* entry) {

  std::string name = entry->getName();
  if (entry->getAliasName() != null && !entry->getAliasName()->empty()){
    name += TO_STR(*entry->getAliasName());
  }

  return name;
}

static void _printCallerAnnotation(std::stringstream& ss, IRInterpreter* interpreter) {

  std::vector<IRFrame*> allFrames;
  allFrames.push_back(ROOT_FRAME(interpreter));
  allFrames.push_back(SYSTEM_FRAME(interpreter));
  allFrames.push_back(MAIN_FRAME(interpreter));
  for(auto frame : RGlobal::listGlobalFrames()){
    allFrames.push_back(frame);
  }

  boolean outputHead = false;

  for (auto frame : allFrames) {

    std::vector<IRFrameEntry*> frameEntries;

    for (auto entry : frame->listEntries()) {
      auto obj = entry->getValue();
      if (IS_CALLABLE(obj)) {
        
        auto callObj = AS_CALL(obj);
        if (callObj->hasBeforeAnnotation() || callObj->hasAfterAnnotation()) {  
          frameEntries.push_back(entry);
        }
      }
    }

    if (frameEntries.empty()) {
      continue;
    }

    std::sort(frameEntries.begin(), frameEntries.end(), [](auto f1, auto f2){
      return f1->getEntryId() < f2->getEntryId();
    });

    for (auto entry : frameEntries) {
      auto callObj = AS_CALL(entry->getObject());

      if (!outputHead) {
        ss << "Caller annotation:\n";
        ss << SEP_LINE1;
        ss << LFC_STR_FORMAT_BGN 
                  "%-20s : %-8s %-8s %-10s %s\n"
                , "Name(alias)"
                , "EntryId"
                , "FrameId"
                , "Type"
                , "Annotation"
              LFC_STR_FORMAT_END;
        ss << SEP_LINE2;
        outputHead = true;
      }

      auto name = _getEntryAliasName(entry);
      auto entryFrame = entry->getFrame();

      std::string out = "";
      if (callObj->hasBeforeAnnotation()) {
        out += "before: " + TO_STR(callObj->listBeforeAnnotationAttr());
      }

      if (callObj->hasAfterAnnotation()) {
        if (!out.empty()) {
          out += ", ";
        }
        out += "after: " + TO_STR(callObj->listAfterAnnotationAttr());
      }

      ss << LFC_STR_FORMAT_BGN 
                "%-20s : %-8d %-8d %-10s %s\n"
              , name.c_str()
              , entry->getEntryId()
              , entryFrame == null ? -1 : entryFrame->getFrameId()
              , _toTypeString(callObj).c_str()
              , out.c_str()
            LFC_STR_FORMAT_END;
    }
  }

  if (outputHead) {
    ss << SEP_LINE1;
    ss << "\n";
  }
}

static std::string _toString(IRObject* obj) {

  switch (TYPE_INDEX_OF(obj)) {
  case E_VAR: {
    
    auto valueObj = AS_VAR(obj)->getValue();
    if (valueObj == null) {
      return "";
    }

    if (TYPE_INDEX_OF(valueObj) == E_NIL) {
      return _toTypeString(valueObj);
    }

    std::string out = _toTypeString(valueObj);
    out += ", ";
    out += _toString(valueObj); 

    return out;
  }

  case E_FUNC: {

    auto func = AS_FUNC(obj);
    std::string out;

    if(IS_FUNC_LIST(func)){
      out += "{}";
    }
    else {
      out += func->getSignature();
    }    
    
    out += " : frame=";
    // std::cout << "func: " << func->getName() << "\n";
    // std::cout << "func: " << func->getDefineFrame()->asString() << "\n";
    out += TO_STR(func->getDefineFrame());

    if (func->isList()) {
      out += ", type=list";
    }

    if (func->isLambda()) {
      out += ", type=lambda";
    }

    return out;
  }

  case E_TEMPLATE: {
    auto tp = AS_TEMPLATE(obj);
    std::string out = tp->getSignature();
    out += " : frame=";
    out += TO_STR(tp->getDefineFrame());

    return out;
  }

  case E_BLOB: {
    auto blob = AS_BLOB(obj);
    std::string out = "len=";
    out += TO_STR(blob->length());
    out += ", data=";
    out += RulpUtil::formatBlob(blob, 64);
    return out;
  }
  
//		case INSTANCE:
//			IRInstance instance = RulpUtil.asInstance(obj);
//			IRClass rclass = instance.getRClass();
//			return instance.getInstanceName() + " : class=" + (rclass == null ? "null" : rclass.getClassName());


  default:
    return RulpUtil::toString(obj, MAX_TOSTRING_LEN);
  }
}

std::string TraceUtil::printFrame(IRFrame* frame) {
  return printFrame(frame, null);
}

std::string TraceUtil::printFrame(IRFrame* frame, std::vector<IRObject*>* values) {

  std::stringstream ss;

  std::vector<IRFrameEntry*> frameEntries(frame->listEntries());

  std::sort(frameEntries.begin(), frameEntries.end(), [](auto f1, auto f2){
    return f1->getEntryId() < f2->getEntryId();
  });

  ss << LFC_STR_FORMAT_BGN 
            "id=%d, name=%s, lvl=%d, ref=%d/%d, entry=%d"
          , frame->getFrameId()
          , frame->getFrameName().c_str()
          , frame->getLevel()
          , frame->getRef()
          , frame->getMaxRef()
          , (int)frameEntries.size()
        LFC_STR_FORMAT_END;

  auto frameParent = frame->getParentFrame();
  if (frameParent != null) {
    ss << LFC_STR_FORMAT_BGN 
              ", pid=%d(%s)"
            , frameParent->getFrameId()
            , frameParent->getFrameName().c_str()
          LFC_STR_FORMAT_END;
  }

  auto frameSubject = frame->getSubject();
  if (frameSubject != null) {
    ss << LFC_STR_FORMAT_BGN
              ", subject=%s"
            , frameSubject->getSubjectName().c_str()
          LFC_STR_FORMAT_END;
  }

  auto frameThreadContext = frame->getThreadContext();
  if (frameThreadContext != null) {
    
    std::string out = "";
    out += TO_STR(frameThreadContext->isCompleted());
    out += "/";
    out += TO_STR(frameThreadContext->getResultCount());

    ss << LFC_STR_FORMAT_BGN ", thread=%s" , out.c_str() LFC_STR_FORMAT_END;
  }

  auto searchFrameList = frame->getSearchFrameList();
  if (searchFrameList != null) {
    ss << LFC_STR_FORMAT_BGN ", search=%s", TO_STR(*searchFrameList).c_str() LFC_STR_FORMAT_END;
  }

  ss << "\n";

  if (!frameEntries.empty()) {

    ss << SEP_LINE1;
    ss << LFC_STR_FORMAT_BGN 
              "%-20s : %-8s %-8s %-4s %-10s %-20s\n"
            , "Name(alias)"
            , "EntryId"
            , "FrameId"
            , "Ref"
            , "Type"
            , "Value" 
          LFC_STR_FORMAT_END;
    ss << SEP_LINE2;

    for (auto entry : frameEntries) {

      auto entryObj = entry->getObject();

      std::string name = _getEntryAliasName(entry);
      auto entryFrame = entry->getFrame();

      ss << LFC_STR_FORMAT_BGN 
                "%-20s : %-8d %-8d %-4s %-10s %-20s\n"
              , name.c_str()
              , entry->getEntryId()
              , (entryFrame == null ? -1 : (int)entryFrame->getFrameId())
              , _toRefString(entryObj).c_str()
              , _toTypeString(entryObj).c_str()
              , _toString(entryObj).c_str()
            LFC_STR_FORMAT_END;

      if (IS_FUNC_LIST(entryObj)) {
        for (auto func : AS_FUNC_LIST(entryObj)->getAllFuncList()) {
          ss << LFC_STR_FORMAT_BGN 
                    "%40s %-4s %-10s %s\n"
                  , ""
                  , _toRefString(func).c_str()
                  , _toTypeString(func).c_str()
                  , _toString(func).c_str()
                LFC_STR_FORMAT_END;
        }
      }

      if (values != null) {
        values->push_back(entryObj);
      }
    }

    ss << SEP_LINE1;
  }

  return ss.str();
}


class FrameTree {

public:

  FrameTree(const std::vector<IRFrame*>& globalFrames, IRInterpreter* interpreter);

  void _printFrame(IRFrame* frame, int level);

  std::string output();

private:

  std::set<IRFrame*> allFrames;
  std::map<IRFrame*, std::set<IRFrame*>> frameTreeMap;
  IRInterpreter* interpreter;
  std::stringstream ss;

};

FrameTree::FrameTree(const std::vector<IRFrame*>& globalFrames, IRInterpreter* interpreter) {
  for(auto frame: globalFrames)
    allFrames.insert(frame);
  allFrames.insert(MAIN_FRAME(interpreter));
  allFrames.insert(SYSTEM_FRAME(interpreter));
  allFrames.insert(ROOT_FRAME(interpreter));
  this->interpreter = interpreter;
}

void FrameTree::_printFrame(IRFrame* frame, int level) {

  for (int i = 0; i < level; i++) {
    ss << "    ";
  }

  ss << LFC_STR_FORMAT_BGN 
            "->FRAME(%s): id=%d, lvl=%d"
          , frame->getFrameName().c_str()
          , frame->getFrameId()
          , frame->getLevel()
        LFC_STR_FORMAT_END;
  
  auto frameSubject = frame->getSubject();
  if (frameSubject != null) {
    ss << LFC_STR_FORMAT_BGN 
              ", subject=%s"
            , frameSubject->getSubjectName().c_str()
          LFC_STR_FORMAT_END;
  }

  auto searchFrameList = frame->getSearchFrameList();
  if (searchFrameList != null) {
    ss << LFC_STR_FORMAT_BGN ", search=%s", TO_STR(*searchFrameList).c_str() LFC_STR_FORMAT_END;
  }

  ss << "\n";


  auto it = frameTreeMap.find(frame);
  auto& childFrames = it->second;
  if(it == frameTreeMap.end() || childFrames.empty()){
    return;
  }
  
  std::vector<IRFrame*> childFrameList = CT_TO_VECTOR(childFrames);
  std::sort(childFrameList.begin(), childFrameList.end(), [](auto f1, auto f2){
    return f1->getFrameId() < f2->getFrameId();
  });

  for (auto child : childFrameList) {
    _printFrame(child, level + 1);
  }

  frameTreeMap.erase(frame);
}

std::string FrameTree::output() {

  for (auto frame : allFrames) {

    auto parentFrame = frame->getParentFrame();
    if (parentFrame == null) {

      auto& childFrames = frameTreeMap[frame];
      // if (childFrames == null) {
      //   childFrames = new HashSet<>();
      //   frameTreeMap.put(frame, childFrames);
      // }
    }
    else if (!lfc::find(allFrames, parentFrame)) {
      throw RException( LFC_STR_FORMAT_BGN 
                            "Unlinked frame: frame=%s, parent=%s"
                          , frame->asString().c_str()
                          , parentFrame->asString().c_str()
                        LFC_STR_FORMAT_END);
    } 
    else {

      auto& childFrames = frameTreeMap[parentFrame];
      childFrames.insert(frame);
    }
  }

  _printFrame(ROOT_FRAME(interpreter), 0);  
  while (!frameTreeMap.empty()) {
    auto aFrame = frameTreeMap.begin()->first;
    _printFrame(aFrame, 0);
  }
  
  return ss.str();
}


std::string TraceUtil::outputFrameTree(IRInterpreter* interpreter) {

  return FrameTree(RGlobal::listGlobalFrames(), interpreter).output();
}

std::string TraceUtil::printSubject(IRSubject* subject) {
  return printSubject(subject, null);
}

std::string TraceUtil::printSubject(IRSubject* subject, std::vector<IRObject*>* values) {

  std::stringstream ss;

  auto subParent = subject->getParent();
  auto subFrame = subject->hasSubjectFrame() ? subject->getSubjectFrame() : null;

  std::vector<IRMember*> mbrs;
  for(int i = 0, mbr_size = subject->getMemberCount(); i < mbr_size; ++i){
    mbrs.push_back(subject->getMember(i));
  }

  std::sort(mbrs.begin(), mbrs.end(), [](auto m1, auto m2){
    return STR_COMPARE(m1->getName(), m2->getName()) < 0;
  });

  ss << LFC_STR_FORMAT_BGN 
            "name=%s, string=%s, lvl=%d, ref=%d/%d, parent=%s, final=%s, mbrs=%d"
          , subject->getSubjectName().c_str()
          , subject->asString().c_str()
          , subject->getLevel()
          , subject->getRef()
          , subject->getMaxRef()
          , subParent == null ? "null" : subParent->getSubjectName().c_str()
          , subject->isFinal() ? "true" : "false"
          , (int) mbrs.size()
        LFC_STR_FORMAT_END;

  if (subFrame != null) {
    ss << LFC_STR_FORMAT_BGN 
              ", frame=%d(%s)"
            , subFrame->getFrameId()
            , subFrame->getFrameName().c_str()
          LFC_STR_FORMAT_END;
  } 
  else {
    ss << ", frame=null";
  }

  ss << "\n";
  ss << SEP_LINE1;
  ss << LFC_STR_FORMAT_BGN 
            "%-30s : %-7s %-5s %-6s %-7s %-4s %-4s %-10s %s\n"
          , "Name"
          , "Access"
          , "Final"
          , "Static"
          , "Inherit"
          , "Prop"
          , "Ref"
          , "Type"
          , "Value"
          LFC_STR_FORMAT_END;
  ss << SEP_LINE2;

  for (auto mbr : mbrs) {

    auto value = mbr->getValue();

    ss << LFC_STR_FORMAT_BGN
              "%-30s : %-7s %-5s %-6s %-7s %-4d %-4s %-10s %s\n"
            , mbr->getName().c_str()
            , TO_STR(mbr->getAccessType()).c_str()
            , RulpUtil::isPropertyFinal(mbr) ? "Y" : ""
            , RulpUtil::isPropertyStatic(mbr) ? "Y" : ""
            , RulpUtil::isPropertyInherit(mbr) ? "Y" : ""
            , mbr->getProperty()
            , _toRefString(value).c_str()
            , _toTypeString(value).c_str()
            , _toString(value).c_str()
          LFC_STR_FORMAT_END;

    if (IS_FUNC_LIST(value)) {
      for (auto func : AS_FUNC_LIST(mbr->getValue())->getAllFuncList()) {
        ss << LFC_STR_FORMAT_BGN 
                  "%66s %-4s %-10s %s\n"
                , ""
                , _toRefString(func).c_str()
                , _toTypeString(func).c_str()
                , _toString(func).c_str()
              LFC_STR_FORMAT_END;
      }
    }

    if (values != null) {
      values->push_back(value);
    }
  }

  ss << SEP_LINE1;

  return ss.str();
}

std::string TraceUtil::printInterpreterInfo(IRInterpreter* interpreter) {

  std::stringstream ss;

  ss << "************ Interpreter Info: ************\n\n";

  /***********************************************/
  // total runtime info
  /***********************************************/
  _printTotalRunTimeInfo(ss, interpreter);

  /***********************************************/
  // Optimize info
  /***********************************************/
  ss << "Optimize info:\n";
  printOptimizeInfo(ss, interpreter);
  ss << "\n";

  /***********************************************/
  // Callable stats info
  /***********************************************/
  _printCallableStatsInfo(ss, interpreter);

  /***********************************************/
  // Annotation Builders
  /***********************************************/
  _printCallerAnnotation(ss, interpreter);

  /***********************************************/
  // Global frame list
  /***********************************************/
  std::vector<IRObject*> frameObjs;

  auto globalFrames = RGlobal::listGlobalFrames();
  ss << LFC_STR_FORMAT_BGN 
            "Global frame list: total=%d\n"
          , (int) globalFrames.size()
        LFC_STR_FORMAT_END;
  ss << "\n";

  ss << printFrame(MAIN_FRAME(interpreter), &frameObjs);
  ss << "\n";

  for (auto frame : globalFrames) {
    ss << "\n";
    ss << printFrame(frame, &frameObjs);
  }

  /***********************************************/
  // System var list
  /***********************************************/
  {
    std::vector<IRVar*> rootVars;
    for (auto frameEntry : SYSTEM_FRAME(interpreter)->listEntries()) {
      auto value = frameEntry->getValue();
      if (TYPE_INDEX_OF(value) == E_VAR) {
        rootVars.push_back(AS_VAR(value));
      }
    }

    std::sort(rootVars.begin(), rootVars.end(), [](auto v1, auto v2){
      return STR_COMPARE(v1->getName(), v2->getName()) < 0;
    });

    ss << "\n";
    ss << LFC_STR_FORMAT_BGN 
              "System var list: total=%d\n"
            , (int) rootVars.size()
          LFC_STR_FORMAT_END;
    ss << SEP_LINE1;
    ss << LFC_STR_FORMAT_BGN 
              "%-20s : %s\n"
            , "Var"
            , "Value"
          LFC_STR_FORMAT_END;
    ss << SEP_LINE2;

    for (auto var : rootVars) {
      ss << LFC_STR_FORMAT_BGN2 
                "%-20s : %s\n"
              , var->getName().c_str()
              , _toString(var->getValue()).c_str()
            LFC_STR_FORMAT_END;
    }

    ss << SEP_LINE1;
  }

  /***********************************************/
  // Frame tree
  /***********************************************/
  ss << "\n";
  ss << "Global frame tree:\n";
  ss << "\n";
  ss << outputFrameTree(interpreter);


  /***********************************************/
  // Global Subject list
  /***********************************************/
  ss << "\n";
  ss << "Global Subject list:\n";
  ss << "\n";

  std::vector<IRObject*> sortedObjs(frameObjs);
  std::sort(frameObjs.begin(), frameObjs.end(), [](auto o1, auto o2){
    return STR_COMPARE(o1->asString(), o2->asString()) < 0;
  });

  std::set<IRObject*> visitedObjs;
  std::queue<IRObject*> visitingObjs;
  for(auto obj : sortedObjs)
    visitingObjs.push(obj);

  while (!visitingObjs.empty()) {

    auto obj = visitingObjs.front();
    visitingObjs.pop();

    if (TYPE_INDEX_OF(obj) == E_FRAME) {
      continue;
    }

    if (!IS_SUBJECT(obj)) {
      continue;
    }

    if (visitedObjs.count(obj) != 0) {
      continue;
    }

    std::vector<IRObject*> subObjs;
    ss << printSubject(AS_SUBJECT(obj), &subObjs);
    ss << "\n";

    for(auto sub : subObjs)
      visitingObjs.push(sub);

    visitedObjs.insert(obj);
  }

	return ss.str();
}

std::string TraceUtil::printGlobalInfo(){

  std::stringstream ss;

  ss << "************** Global Info: **************\n\n";

  /***********************************************/
  // expression compute count
  /***********************************************/
  _printExpressionComputeCount(ss);

  /***********************************************/
  // object create count
  /***********************************************/
  _printObjectCreateCount(ss);

  return ss.str();
}

void TraceUtil::registerOptInfoTracer(StrConstRef name, IROptInfoTracer* tracer) {
  if (lfc::find(optTracerNameList, name)) {
    return;
  }

  optTracerNameList.push_back(name);
  optTracerMap[name] = tracer;
}

class LCOOptTracer : public IROptInfoTracer {
public:

  virtual std::string printInfo(IRInterpreter* interpreter) const override {
    return  LFC_STR_FORMAT_BGN 
                "rebuild=%d, arg=%d, pass=%d, hit=%d"
              , LCOUtil::getRebuildCount()
              , LCOUtil::getArgCount()
              , LCOUtil::getPassCount()
              , LCOUtil::getHitCount()
            LFC_STR_FORMAT_END;
  }

};


OPT_TRACE_REGISTER(LCOOptTracer, "LCO");

} // namespace lfc