// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_TRACEUTIL_H__
#define __RULP_LANG_TRACEUTIL_H__
#include "lfc/base/trace_macro.h"
#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class IROptInfoTracer {

public:

  virtual std::string printInfo(IRInterpreter* interpreter) const = 0;

};

class TraceUtil {

public:

  static std::string printFrame(IRFrame* frame);

  static std::string printFrame(IRFrame* frame, std::vector<IRObject*>* values);

  static std::string printInterpreterInfo(IRInterpreter* interpreter);

  static std::string printGlobalInfo();

  static std::string printSubject(IRSubject* subject);

  static std::string printSubject(IRSubject* subject, std::vector<IRObject*>* values);

  static std::string outputFrameTree(IRInterpreter* interpreter);

  static void printOptimizeInfo(std::stringstream& ss, IRInterpreter* interpreter);

  static void registerOptInfoTracer(StrConstRef name, IROptInfoTracer* tracer);
};


template <typename TRACER> 
struct RegisterOptInfoTracer{
  RegisterOptInfoTracer(std::string name) {
    static TRACER tracer;
    TraceUtil::registerOptInfoTracer(name, &tracer);
  }
};

#define OPT_TRACE_REGISTER(tracer, name) \
  static lfc::RegisterOptInfoTracer<tracer> T0 (name);

} // namespace lfc
TRACE_SUB_MODULE_DEF(trace_util)
#endif //__RULP_LANG_TRACEUTIL_H__