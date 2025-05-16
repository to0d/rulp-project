// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRINTERPRETER_H__
#define __RULP_XIMPL_RUNTIME_XRINTERPRETER_H__
#include <vector>
#include <map>
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {


class XRInterpreter : virtual public IRInterpreter{
  
  class TLS : virtual public IRTLS {
    
    friend class XRInterpreter;

  public:
    TLS() = default;
    virtual ~TLS() = default;

  public:

    virtual int getCallLevel() const override {
      return level;
    }

  protected:

    int level = 0;

  };


public:
  
  XRInterpreter();
  
  virtual ~XRInterpreter();

public:

  virtual IRObject* compute(IRFrame* frame, IRObject* obj) override;

  virtual void compute(StrConstRef input, RResultListener listener) override;

  virtual IRDebugger* getActiveDebugger() override {return null;}

  virtual IRFrame* getMainFrame() const override;

  virtual int getMaxCallLevel() const override {return maxCallLevel;}

  virtual IRObject* getObject(StrConstRef name) const override;

  virtual int getCallId() const override;

  virtual IRTLS* getTLS() override;

  virtual RInput getInput() const override;

  virtual ROutput getOut() const override;

  virtual void setInput(RInput in) override;

  virtual void setOutput(ROutput out) override;

  virtual void write(StrConstRef line) override;

  virtual std::string read() override;

  virtual IRTokenPool* getContext() override ;

  virtual IRParser* getParser() override;


public:

  void setMainFrame(IRFrame* frame);

  void setSystemFrame(IRFrame* frame);

  void setRootFrame(IRFrame* frame);

  void setContext(IRTokenPool* context);

  void setTokener(IRTokener* tokener);

  void setParser(IRParser* parser);

protected:

  void _callLevel(int level);

protected:

  IRFrame* rootFrame = NULL;
  IRFrame* systemFrame = NULL;
  IRFrame* mainFrame = NULL;

  int callId = 0; 
  int maxCallLevel = 0;

  TLS tls;

protected:

  IRTokenPool*  context = NULL;
  IRTokener*  tokener = NULL;
  IRParser*   parser  = NULL;

private:

  RInput  input;
  ROutput output;

};



} // namespace lfc

#endif //__RULP_XIMPL_RUNTIME_XRINTERPRETER_H__