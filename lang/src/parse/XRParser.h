// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_PARSE_XPARSER_H__
#define __RULP_XIMPL_PARSE_XPARSER_H__

#include "rulp/parse/IRParser.h"
#include "rulp/parse/IRTokener.h"
#include "rulp/lang/RName.h"
#include "lfc/base/trace_macro.h"
#include <vector>
#include <memory>
#include <map>

namespace lfc {


class XRParser : virtual public IRParser{

public:
  XRParser();

  virtual ~XRParser();

public:

  virtual std::vector<IRObject*> parse(StrConstRef line) override;

  virtual IRTokener* getTokener() const override { return m_tokener; }

  virtual IRTokenPool* getContext() const override { return context; }

  virtual void setContext(IRTokenPool* context) override { this->context = context; }

  virtual void setTokener(IRTokener* tokener) override { m_tokener = tokener; }

  virtual void registerPrefix(StrConstRef prefix, StrConstRef nameSpace) override;

  virtual void setSupportComment(bool supportComment) override;

  virtual void setSupportNumber(bool supportNumber) override;

  bool isSupportComment() { return supportComment; } 

  bool isSupportNumber() { return supportNumber; }

private:

  void _init();
  void _checkRecursion();
  int  _depth();
  int  _tokenPos();

  Token* _curToken();
  RName* _getRName(StrConstRef name);

  bool _ignoreBlank();
  bool _more();
  void _pullStack(int newDepth);
  void _pushStack(int addTokenCount);

  IRObject* _nextObject();

  IRObject* nextObject();

  bool matchArray(std::vector<IRObject*>& values);
  
  bool matchAttrList(std::vector<IRObject*>& values);
  
  bool matchList(std::vector<IRObject*>& values);
  
  bool matchSymbol(char symbol);

  bool nextAtom(std::string& atom);

private:

  IRTokener* m_tokener;
  IRTokenPool* context = NULL;

private:

  int lineIndex = 0;

  int linePos = 0;

  std::vector<std::string> lines;

  int operationCount = 0;

  std::map<std::string, std::string> prefixNameSpaceMap;

  int stackDepth = 0;

  bool supportComment = true;

  bool supportNumber = true;

  int tokenCount = 0;

  std::vector<int> tokenIndexs;

  std::vector<Token*> tokenList;
  
};

} // namespace lfc
TRACE_SUB_MODULE_DEF(rulp_xparse)
#endif //__RULP_XIMPL_PARSE_XPARSER_H__