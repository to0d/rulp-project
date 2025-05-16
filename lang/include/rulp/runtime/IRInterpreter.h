// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRINTERPRETER_H__
#define __RULP_RUNTIME_IRINTERPRETER_H__

#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRTokenPool.h"
#include "rulp/runtime/IRDebugger.h"
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRTLS.h"
#include "rulp/parse/IRParser.h"
#include "lfc/base/function.h"
namespace lfc {

typedef lfc::function<std::string>              RInput;
typedef lfc::function<void, const std::string&> ROutput;
typedef lfc::function<void, IRObject*>          RResultListener;

#define MAIN_FRAME(interpreter)                 (interpreter)->getMainFrame()
#define SYSTEM_FRAME(interpreter)               (interpreter)->getMainFrame()->getParentFrame()
#define ROOT_FRAME(interpreter)                 (interpreter)->getMainFrame()->getParentFrame()->getParentFrame()
class IRInterpreter{
 
public:
  IRInterpreter() = default;
  
  virtual ~IRInterpreter() = default;

public:

  // void addObject(IRObject obj) throws RException;

  virtual IRObject* compute(IRFrame* frame, IRObject* obj) = 0;

  // void compute(String input) throws RException;

  virtual void compute(StrConstRef input, RResultListener listener) = 0;

  // void endDebug();

  virtual IRDebugger* getActiveDebugger() = 0;

  virtual int getCallId() const = 0;

  virtual IRFrame* getMainFrame() const = 0;

  virtual int getMaxCallLevel() const = 0;

  virtual IRObject* getObject(StrConstRef name) const = 0;

  virtual IRTokenPool* getContext() = 0 ;

  virtual IRParser* getParser() = 0;

  virtual IRTLS* getTLS() = 0;


public:

  virtual RInput getInput() const = 0;

  virtual ROutput getOut() const = 0;

  virtual void setInput(RInput in) = 0;

  virtual void setOutput(ROutput out) = 0;

  virtual void write(StrConstRef line) = 0;

  virtual std::string read() = 0;

  // void startDebug();
};


} // namespace lfc
#endif //__RULP_RUNTIME_IRINTERPRETER_H__