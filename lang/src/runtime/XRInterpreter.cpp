// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRInterpreter.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/lang/RException.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/to_string.h"
#include <iostream>
using namespace lfc;

namespace lfc {

static boolean TRACE = false;

XRInterpreter::XRInterpreter(){

}

XRInterpreter::~XRInterpreter(){

  mainFrame->release();

  RULP_DEC_REF(mainFrame);
  RULP_FREE(systemFrame);
  RULP_FREE(rootFrame);
  RULP_FREE(context);
  RULP_FREE(tokener);
  RULP_FREE(parser);
}

IRObject* XRInterpreter::compute(IRFrame* frame, IRObject* obj){

  _callLevel(tls.level++);
  
  try{
    IRObject* rst = RuntimeUtil::compute(obj, this, frame);
    tls.level--;
    return rst;
  }
  catch (RException& e) {
    tls.level--;
    throw;
  }
  
}

void XRInterpreter::compute(StrConstRef input, RResultListener listener) {
  IRParser* _parser = getParser();
  // List<IRObject> objs;

  RListHandler RLH;
  // synchronized (_parser) {
  std::vector<IRObject*> objs = _parser->parse(input);
  // RULP_AUTO_FREE(objs);
  // std::cout << "objs: " << TO_STR(objs) << "\n";
  // }

  for (auto obj : objs) {
    RLH.addResult(obj);
  }

  try {

    for (auto obj : objs) {
      auto rst = compute(mainFrame, obj);
      RULP_INC_REF(rst);

      if (listener != null) {
        listener(rst);
      }

      RULP_DEC_REF(rst);
    }

  } 
  catch (RExceptionResume& e) {
    throw;
  }
  catch (RExceptionI& e) {

    if (TRACE) {
      std::cerr << e.what() << std::endl;
    }

    if (!e.isHandle()) {
      throw RException("Unhandled internal exception: " + e.what());
    }

    RException newExp(e.getExceptionMessage());

    for (auto addMsg : e.getAdditionalMessages()) {
      newExp.addAdditionalMessage(addMsg);
    }

    throw newExp;

  } 
  catch (RExceptionError& e) {

    if (TRACE) {
      std::cout << e.what();
    }

    RException newExp(e.getError()->asString());
    std::cout << "inp: " << e.getError()->asString() << "\n";
    for (auto addMsg : e.getAdditionalMessages()) {
      newExp.addAdditionalMessage(addMsg);
    }

    throw newExp;
  }
}

IRFrame* XRInterpreter::getMainFrame() const {
  return mainFrame;
}

IRObject* XRInterpreter::getObject(StrConstRef name) const {

  auto entry = mainFrame->getEntry(name);
  return entry == null ? null : entry->getObject();
}

void XRInterpreter::setMainFrame(IRFrame* frame){
  RULP_INC_REF(frame);
  RULP_DEC_REF(this->mainFrame);
  this->mainFrame = frame;
}

void XRInterpreter::setSystemFrame(IRFrame* frame){
  this->systemFrame = frame;
}

void XRInterpreter::setRootFrame(IRFrame* frame){
  this->rootFrame = frame;
}


int XRInterpreter::getCallId() const {
  return callId;
}

IRTLS* XRInterpreter::getTLS() {
  return &tls;
}

void XRInterpreter::_callLevel(int level){
  // First level call
  if (level++ == 0) {
    callId++;
  }

  if (level > maxCallLevel) {
    maxCallLevel = level;
  }
}

RInput XRInterpreter::getInput() const { 
  return input; 
}

ROutput XRInterpreter::getOut() const { 
  return output; 
}

void XRInterpreter::setInput(lfc::function<std::string> in) {
  this->input = in;
}

void XRInterpreter::setOutput(lfc::function<void, const std::string&> out) {
  this->output = out;
}

void XRInterpreter::write(StrConstRef line) {
  if (output != null) {
    output(line);
  } 
  else {
    std::cout << line;
  }
}

std::string XRInterpreter::read(){
  if (input != null) {
    return input();
  }

  std::string line;
  std::getline(std::cin, line);

  return line;
}

IRTokenPool* XRInterpreter::getContext() {
  return context;
}

IRParser* XRInterpreter::getParser() {
  return parser;
}

void XRInterpreter::setContext(IRTokenPool* context) {
  this->context = context;
}

void XRInterpreter::setTokener(IRTokener* tokener){
  this->tokener = tokener;
}

void XRInterpreter::setParser(IRParser* parser) {
  this->parser = parser;
}

} // namespace lfc