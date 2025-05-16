// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_xparse]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_xparse)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(rulp_xparse)
#include "XRParser.h"
#include "XRTokener.h"
#include "lfc/base/trace.h"
#include "lfc/base/string/util.h"
#include "lfc/base/to_string.h"
#include "lfc/base/cast.h"
#include "lfc/base/string/format.h"
#include "lfc/base/auto/auto_free.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RValue.h"
#include "rulp/lang/RException.h"

using namespace lfc;
using namespace lfc;

XRParser::XRParser(){
}

XRParser::~XRParser(){
}

static constexpr int MAX_PARSE_COUNT = 65535 * 256;

static constexpr int MAX_STACK_DEPTH = 65535 * 256;

static constexpr int MAX_TOKEN_COUNT = 65535 * 256;

static bool _isBlankToken(Token* token) {
  return token->type == TokenType::TT_1BLK;
}

static bool _isEndToken(Token* token) {
  return token->type == TokenType::TT_9END;
}

static bool _isNameToken(Token* token, char c) {
  if(token != nullptr 
    && token->type == TokenType::TT_3NAM
    && token->value.size() == 1 && token->value[0] == c) {
    return true;
  }
  return false;
}

static bool _isSymbolToken(Token* token, char symbol) {
  if (token != nullptr 
      && token->type == TokenType::TT_2SYM 
      && token->value.size() == 1 && token->value[0] == symbol) {
    return true;
  }
  return false;
}


static bool _isSeparatorToken(Token* token) {
  if (token == nullptr) {
    return true;
  }

  switch (token->type) {
  case TokenType::TT_1BLK:
  case TokenType::TT_9END:
    return true;

  case TokenType::TT_2SYM:
    if(token->value.size() == 1){
      char c = token->value[0];
      switch (c) {
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case ',':
          return true;
      }
    }
    break;

  default:
    break;

  }

  return false;
}


static bool _isSupportIdentifierHeadToken(Token* token) {
  if (token == nullptr || token->value.empty()) {
    return false;
  }

  switch (token->type) {
  case TokenType::TT_3NAM: {
    switch (XRTokener::getCharType(token->value[0])) {
    case C00_CHAR:
    case C01_NUM:
    case C04_UNDERSCORE:
      return true;
    }

    break;
  }

  case TokenType::TT_2SYM:

    if(token->value.size() == 1){
      char c = token->value[0];
      switch (c) {
        case '$':
        case '_':
        case '?':
          return true;
      }
    }

    break;

  default:
     break;
  }

  return false;
}

RName* XRParser::_getRName(StrConstRef name) {

  int pos = STR_LAST_INDEX_OF(name, ':');
  if (pos == -1) {
    return nullptr;
  }

  std::string prefix = name.substr(0, pos);
  auto it = prefixNameSpaceMap.find(prefix);
  if(it == prefixNameSpaceMap.end()){
    return nullptr;
  }

  std::string nameSpace = it->second;
  std::string subName = name.substr(pos + 1);

  return context->createRName(nameSpace, prefix, subName, nameSpace + subName);
}

void XRParser::_checkRecursion(){
  operationCount++;
  assert(operationCount < MAX_PARSE_COUNT);
}

Token* XRParser::_curToken(){
  if (_tokenPos() >= tokenCount)
    return nullptr;

  Token* token = tokenList[_tokenPos()];
  linePos = token->end_pos;
  return token;
}

int XRParser::_depth(){

  if (stackDepth >= MAX_STACK_DEPTH) {
    LFC_TRACE4("lineIndex=", lineIndex , ", linePos=", linePos);
    assert(false && "out of Stack");
  }

  return stackDepth;
}

static std::string _getDoubleNumber(const std::string& name) {

  int len = name.length();
  if (len < 2) {
    return "";
  }

  char c = name[len - 1];
  if (c != 'D' && c != 'd') {
    return "";
  }

  int pointNum = 0;

  for (int pos = len - 2; pos >= 0; --pos) {

    c = name[pos];
    if (c < '0' || c > '9') {

      if (c == '.') {
        if (++pointNum > 1) {
          return "";
        }
      } else {
        return "";
      }
    }
  }

  return name.substr(0, len - 1);
}

static std::string _getLongNumber(const std::string& name) {

  int len = name.length();
  if (len < 2) {
    return "";
  }

  char c = name[len - 1];
  if (c != 'L' && c != 'l') {
    return "";
  }

  for (int pos = len - 2; pos >= 0; --pos) {

    c = name[pos];
    if (c < '0' || c > '9') {
      return "";
    }
  }

  return name.substr(0, len - 1);
}



bool XRParser::_ignoreBlank() {

  _checkRecursion();

  bool ignoreComment = false;

  while (_more()) {

    Token* token = _curToken();

    if (ignoreComment) {

      // ignore end tokens
      if (_isEndToken(token)) {
        this->lineIndex++;
        ignoreComment = false;
      }

      _pushStack(1);
      continue;

    } 

    // ignore blank tokens
    if (_isBlankToken(token)) {
      _pushStack(1);
      continue;
    }

    // ignore end tokens
    if (_isEndToken(token)) {
      this->lineIndex++;
      _pushStack(1);
      continue;
    }

    if (isSupportComment()) {

      // find symbol ";"
      if (token->type == TokenType::TT_2SYM && token->value == ";") {
        _pushStack(1);
        ignoreComment = true;
        continue;
      }
    }
  
    break;
  }

  return true;
}


void XRParser::_init() {
  this->operationCount = 0;
  this->stackDepth = 0;
  this->tokenCount = 0;
  this->lineIndex = 0;
  this->linePos = 0;
  this->lines.clear();
  this->tokenList.clear();
  this->tokenIndexs.clear();
  this->tokenIndexs.push_back(0);
}

bool XRParser::_more() {
  return _tokenPos() < tokenCount;
}

IRObject* XRParser::_nextObject() {

  IRObject* obj = nextObject();

  /******************************************/
  // Try match Array: []
  /******************************************/
  if (obj != nullptr) {
    std::vector<IRObject*> values;

    if (matchAttrList(values)) {
      for (auto attr : values) {
        AttrUtil::addAttribute(obj, attr->asString());        
      }
    }

    RULP_FREE(values);
  }

  return obj;
}

static IRInteger* _parse_integer(std::string str, int index, int pos){
  
  if(str[0] == '+'){
    str = str.substr(1);
  }
  
  if(!STR_IS_INT(str)){
    throw RExceptionParse("invalid int format: " + str, index, pos);
  }

  int val = TO_INT(str);
  if(val > RULP_MAX_INT || val < RULP_MIN_INT || TO_STR(val) != str ){
    throw RExceptionParse("invalid int format: " + str, index, pos);
  }

  return RulpFactory::createInteger(val);   
}


static IRLong* _parse_long(std::string str, int index, int pos){
  
  if(str[0] == '+'){
    str = str.substr(1);
  }
  
  if(!STR_IS_INT(str)){
    throw RExceptionParse("invalid long format: " + str, index, pos);
  }

  try
  {
    long long val = TO_LONG_LONG(str);
    if(val > RULP_MAX_LONG || val < RULP_MIN_LONG || TO_STR(val) != str ){
      throw RExceptionParse("invalid long format: " + str, index, pos);
    }

    return RulpFactory::createLong(val);
  }
  catch(const std::out_of_range& e)
  {
    throw RExceptionParse("out_of_range: " + str, index, pos);
  }
  
}

IRObject* XRParser::nextObject(){
  _checkRecursion();

  if (!_more()) {
    return NULL;
  }

  int depth = _depth();

  Token* token = _curToken();  
  _pushStack(1);

  switch (token->type) {
  case TT_2SYM:
    if(token->value == ","){
      return RulpFactory::createAtom(token->value);
    }
    break;
  default:
    break;
  }

  Token* next = _curToken();

  /******************************************/
  // Combine Symbols
  /******************************************/
  if (!_isSeparatorToken(next)) {

    if(token->type == TT_2SYM && token->value.length() == 1){

      char c = token->value[0]; 
      switch (c) {

        case '&': {
          /******************************************/
          // Try match var: &abc
          /******************************************/
          std::string atomName;;
          if (nextAtom(atomName)) {
            return RulpFactory::createVar(atomName, null);
          }
          break;
        }
        case '+':
        case '-':

          /******************************************/
          // Try match (+/-)number
          /******************************************/
          if (isSupportNumber()) {

            _pushStack(1);

            if (!_isSeparatorToken(next)) {

              switch (next->type) {

              // -123 or +123
              case TT_5INT: {
                std::string num_str = token->value + next->value;
                return _parse_integer(num_str, lineIndex, linePos);                
              }
              
                // -1.5 or +1.5
              case TT_6FLT: {
                std::string num_str = token->value + next->value;
                Token* next2 = _curToken();
                
                // +1.1d
                if (_isNameToken(next2, 'd') || _isNameToken(next2, 'D')) {
                  _pushStack(1);               
                  return RulpFactory::createDouble(TO_DOUBLE(num_str));
                }              
                
                if(!STR_IS_FLOAT(num_str)){
                  LFC_TRACE6("num_str=", num_str, ", index=", lineIndex, ", pos=", linePos);
                  assert(false && "invalid float format");
                }
                
                return RulpFactory::createFloat(TO_FLOAT(num_str));
              }

              default:

                auto longNum = _getLongNumber(next->value);                
                if (!longNum.empty()) {
                  std::string num_str = token->value + longNum;
                  return _parse_long(num_str, lineIndex, linePos);
                }

                auto doubleNum = _getDoubleNumber(next->value);
                if (!doubleNum.empty()) {
                  std::string num_str = token->value + doubleNum;
                  return RulpFactory::createDouble(TO_DOUBLE(num_str));
                }
                
                break;
              }
            }
          }

          break; // break switch cur_token value

        default:
          break;

      } // switch (c) {
    }

  }
  // non Combine Symbols
  else {

    switch (token->type) {
    /******************************************/
    // Try match integer
    /******************************************/
    case TT_5INT:

      if (isSupportNumber()) {
        auto num_str = token->value;
        return _parse_integer(num_str, lineIndex, linePos); 
      }

      break;

    /******************************************/
    // Try match float
    /******************************************/
    case TT_6FLT:

      if (isSupportNumber()) {

        if(!STR_IS_FLOAT(token->value)){
          LFC_TRACE6("token=", token, ", index=", lineIndex, ", pos=", linePos);
          assert(false && "invalid float format");
        }

        return RulpFactory::createFloat(TO_FLOAT(token->value));
      }

      break;

    /******************************************/
    // Try match string: "abc"
    /******************************************/
    case TT_4STR:
    {
      auto value = token->value;
      value = value.substr(1, value.length() - 2);
      return RulpFactory::createString(value);
    }

    default:
      break;
    }
  }

  /******************************************/
  // Try match hex: 0x1A or 0X001
  /******************************************/
  if (token->type == TokenType::TT_3NAM) {

    auto value = token->value;
    int len = value.length();

    if (len >= 3 && str_start_With(value, "0x") || str_start_With(value, "0X")) {

      boolean isHEX = true;
      int num = 0;

      for (int i = 2; isHEX && i < len; ++i) {

        char c = value[i];
        int n = 0;
        if (c >= '0' && c <= '9') {
          n = c - '0';
        } 
        else if (c >= 'a' && c <= 'f') {
          n = c - 'a' + 10;
        } 
        else if (c >= 'A' && c <= 'F') {
          n = c - 'A' + 10;
        } else {
          isHEX = false;
        }

        num = num * 16 + n;
      }

      if (isHEX) {
        return RulpFactory::createInteger(num);
      } 
      else {
        throw RException(
            LFC_STR_FORMAT_BGN 
              "invalid hex format: str=%s, index=%d, pos=%d"
              , value.c_str()
              , lineIndex
              , linePos
            LFC_STR_FORMAT_END);
      }
    }
  }

  /******************************************/
  // Try match double: float d
  /******************************************/
  if (token->type == TokenType::TT_6FLT && (_isNameToken(next, 'd') || _isNameToken(next, 'D'))) {
    _pushStack(1);
    return RulpFactory::createDouble(TO_DOUBLE(token->value));
  }

  /******************************************/
  // Try match List: '()
  /******************************************/
  _pullStack(depth);
  if (matchSymbol('\'') && _ignoreBlank()) {
    std::vector<IRObject*> list;
    if (matchList(list)) {
      if (list.empty()) {
        return O_EMPTY_LIST;
      } 
      else {
        return RulpFactory::createList(std::move(list));
      }
    }
  }

  /******************************************/
  // Try match List: $()
  /******************************************/
  _pullStack(depth);
  if (matchSymbol('$') && _ignoreBlank()) {
    std::vector<IRObject*> list;
    if (matchList(list)) {
      if (list.empty()) {
        return O_EMPTY_EXPR;
      } 
      else {
        return RulpFactory::createExpressionEarly(std::move(list));
      }
    }
  }

  /******************************************/
  // Try match Expression: ()
  /******************************************/
  _pullStack(depth);
  {
    std::vector<IRObject*> list;
    if (matchList(list)) {
      if (list.empty()) {
        return O_EMPTY_EXPR;
      } 
      else {
        return RulpFactory::createExpression(std::move(list));
      }
    }
  }

  /******************************************/
  // Try match Array: {}
  /******************************************/
  _pullStack(depth);
  {
    std::vector<IRObject*> arrayList;
    if (matchArray(arrayList)) {
      return RulpFactory::createConstArray(std::move(arrayList));
    }
  }

  /******************************************/
  // Try match atom: abc
  /******************************************/
  _pullStack(depth);
  {
    std::string atomName;
    if (nextAtom(atomName)) {

      if(atomName == A_TRUE){
        return O_True;
      }

      if(atomName == A_FALSE){
        return O_False;
      }

      // name:'(list)
      if (STR_END_WITH(atomName, ":'")) {

        int namedDepth = _depth();
        std::vector<IRObject*> list;
        if (matchList(list)) {
          std::string name = STR_TRIM(atomName.substr(0, atomName.length() - 2));
          if (name.length() == 0) {
            return RulpFactory::createList(std::move(list));
          }
          else {
            return RulpFactory::createNamedList(name, std::move(list));
          }
        }

        _pullStack(namedDepth);
      }

      // class::member
      int mPos = STR_INDEX_OF(atomName, F_O_MBR);
      if (mPos > 0 && mPos < (atomName.length() - 2)) {

        std::vector<std::string> names = STR_SPLIT_BY_STR(atomName, F_O_MBR);
        if (names.size() == 2) {
          return RulpFactory::createMember(RulpFactory::createAtom(names[0]), names[1], null);
        }
        // a::b::c ==>(:: (:: a b) c)
        else {

          int mbrSize = names.size();
          IRAtom* getMbr  = RulpFactory::createAtom(F_O_MBR);
          IRExpr* mbrExpr = RulpFactory::createExpression({ getMbr
                                                          , RulpFactory::createAtom(names[0])
                                                          , RulpFactory::createAtom(names[1])
                                                          });
          for (int i = 2; i < mbrSize; ++i) {
            mbrExpr = RulpFactory::createExpression({ getMbr
                                                    , mbrExpr
                                                    , RulpFactory::createAtom(names[i])
                                                    });
          }

          return mbrExpr;
        }
      }

      // pre:name
      RName* rName = _getRName(atomName);
      if (rName != null) {
        return RulpFactory::createAtom(rName);
      }

      // 100L
      auto longNum = _getLongNumber(atomName);
      if (!longNum.empty()) {
        return _parse_long(longNum, lineIndex, linePos);
      }

      // 0.11D
      auto doubleNum = _getDoubleNumber(atomName);
      if (!doubleNum.empty()) {
        return RulpFactory::createDouble(TO_DOUBLE(doubleNum));
      }

      return RulpFactory::createAtom(atomName);
    }
  }

  /******************************************/
  // Try match operator
  /******************************************/
  _pullStack(depth);
  std::string sym = "";
  while (_more() && (token = _curToken()) != null && !_isSeparatorToken(token)) {
    _pushStack(1);
    sym += token->value;
  }

  if (!sym.empty()) {
    return RulpFactory::createAtom(sym);
  }

  _pullStack(depth);
  return NULL;
}


template<typename T>
void _set(std::vector<T>& array, int index, T v) {
  if (index < array.size()) {
    array[index] = v;
  } 
  else {
    while (index > array.size()) {
      array.push_back(0);
    }
    array.push_back(v);
  }
}

void XRParser::_pullStack(int newDepth) {
  assert(newDepth >= 0);
  assert(newDepth <= _depth());
  this->stackDepth = newDepth;
}

void XRParser::_pushStack(int addTokenCount) {
  assert(addTokenCount >= 0);
  assert(stackDepth < (MAX_STACK_DEPTH - 1));

  int pos = _tokenPos() + addTokenCount;
  if (pos >= MAX_TOKEN_COUNT) {
    LFC_TRACE4("lineIndex=", lineIndex, ", linePos=", linePos);
    assert(false && "buffer overflow");
  }

  _set(tokenIndexs, ++stackDepth, pos);
}

int XRParser::_tokenPos() {
  return tokenIndexs[_depth()];
}

bool XRParser::matchArray(std::vector<IRObject*>& arrayList) {

  _checkRecursion();

  if (!_more()) {
    return false;
  }

  // save depth of option
  int depth = _depth();

  if (!matchSymbol('{')) {
    _pullStack(depth);
    return false;
  }

  _ignoreBlank();

  /* save depth of option */
  int depth2 = _depth();
  if (matchSymbol('}')) {
    return true;
  }

  _pullStack(depth2);

  std::vector<IRObject*> curElements;

  while (_ignoreBlank()) {

    if (matchSymbol(',')) {

      if (curElements.empty()) {
        arrayList.push_back(O_Nil);
      } 
      else if (curElements.size() == 1) {
        arrayList.push_back(curElements[0]);
      } 
      else {
        arrayList.push_back(RulpFactory::createList(std::move(curElements)));
      }

      curElements.clear();
      continue;
    }

    if (matchSymbol('}')) {

      if (curElements.size() == 1) {
        arrayList.push_back(curElements[0]);
      }
      else if (curElements.size() > 1) {
        arrayList.push_back(RulpFactory::createList(std::move(curElements)));
      }

      return true;
    }

    IRObject* nextObj = _nextObject();
    if (nextObj == NULL) {
      break; // invalid
    }

    curElements.push_back(nextObj);
  }

  _pullStack(depth);
  return false;
}

bool XRParser::matchAttrList(std::vector<IRObject*>& values) {

  _checkRecursion();

  if (!_more()) {
    return false;
  }

  // save depth of option
  int depth = _depth();

  if (!matchSymbol('[')) {
    _pullStack(depth);
    return false;
  }

  _ignoreBlank();

  /* save depth of option */
  int depth2 = _depth();
  if (matchSymbol(']')) {
    return false;
  } 

  _pullStack(depth2);


  IRObject* obj = nullptr;
  while (_ignoreBlank() && (obj = _nextObject()) != nullptr) {
    values.push_back(obj);
  }

  if (_ignoreBlank() && matchSymbol(']')) {
    return true;
  }

  values.clear();
  _pullStack(depth);
  return false;
}

bool XRParser::matchList(std::vector<IRObject*>& values)  {

  _checkRecursion();

  if (!_more()) {
    return false;
  }

  // save depth of option
  int depth = _depth();

  if (!matchSymbol('(')) {
    _pullStack(depth);
    return false;
  }

  _ignoreBlank();

  /* save depth of option */
  int depth2 = _depth();

  if (matchSymbol(')')) {
    return true;
  } 

  _pullStack(depth2);

  IRObject* obj = nullptr;
  while (_ignoreBlank() && (obj = _nextObject()) != nullptr) {
    values.push_back(obj);
  }

  if (_ignoreBlank() && matchSymbol(')')) {
    return true;
  }

  values.clear();
  _pullStack(depth);
  return false;
}

bool XRParser::matchSymbol(char symbol)  {

  _checkRecursion();

  if (_isSymbolToken(_curToken(), symbol)) {
    /* output symbol */
    _pushStack(1);
    return true;
  }

  return false;
}

bool XRParser::nextAtom(std::string& atom) {

  _checkRecursion();

  /* save depth of option */
  int depth = _depth();
  Token* token = nullptr;

  if ((token = _curToken()) != nullptr && _isSupportIdentifierHeadToken(token)) {

    _pushStack(1);

    std::string atomName = token->value;
    while (_more() && (token = _curToken()) != nullptr && token->value.size() > 0
        && !_isSeparatorToken(token)) {
      atomName += token->value;
      _pushStack(1);
    }

    atom = atomName;
    return true;
  }

  _pullStack(depth);
  return false;

}

std::vector<IRObject*> XRParser::parse(StrConstRef input_line){

  /****************************************************/
  // Main routine
  /****************************************************/
  _init();

  /****************************************************/
  // Scan all tokens
  /****************************************************/
  int parseLineindex = 0;
  for (auto newLine : STR_SPLIT_BY_CHAR(input_line, '\n')) {

    newLine = STR_TRIM(newLine);
    if (newLine.empty()) {
      continue;
    }

    m_tokener->setContent(newLine);
    Token* token = NULL;
    bool ignoreHeadSpace = true;

    while ((token = m_tokener->next()) != NULL) {

      token->lineIndex = parseLineindex;

      if (token->type == TokenType::TT_0BAD) {
        LFC_TRACE2("token=", TO_STR(token));
        assert(false && "bad token");
      }

      /********************************/
      // Skip space in the head
      /********************************/
      {
        if (ignoreHeadSpace && _isBlankToken(token)) {
          continue;
        }
        ignoreHeadSpace = false;
      }

      if (tokenCount >= MAX_TOKEN_COUNT) {
        LFC_TRACE4("token=", TO_STR(token), ", line=", parseLineindex);
        assert(false && "Too many token");
      }

      _set(tokenList, tokenCount++, token);
    }

    /****************************************************/
    // Remove tail space
    /****************************************************/
    while (tokenCount > 0 && _isBlankToken(tokenList[tokenCount - 1])) {
      --tokenCount;
    }

    _set(tokenList, tokenCount++, context->createToken(TokenType::TT_9END, "", -1));
    lines.push_back(newLine);
    ++parseLineindex;
  }

  if (tokenCount == 0) {
    return {};
  }

  /****************************************************/
  // Match rules
  /****************************************************/
  std::vector<IRObject*> list;

  while (_ignoreBlank() && _more()) {

    IRObject* obj = _nextObject();

    if (obj == NULL) {

      auto lastToken      = _curToken();
      int  lastLineIndex  = lastToken == NULL ? -1 : lastToken->lineIndex;
      auto lastLine       = lastLineIndex == -1 ? "" : lines[lastLineIndex];
    

      if(_isSymbolToken(lastToken, '(')){
        throw RExceptionParse( "miss match '(' in " + lastLine.substr(lastToken->end_pos - 1)
                             , lastToken->lineIndex
                             , lastToken->end_pos-1
                             );
      }
      else {
        throw RExceptionParse( "Bad Syntax at line " + lastLine
                             , lastToken->lineIndex
                             , lastToken->end_pos
                             );
      }

    }

    list.push_back(obj);

    // Clean stack
    int curTokenPos = _tokenPos();
    this->tokenIndexs.clear();
    this->tokenIndexs.push_back(curTokenPos);
    this->stackDepth = 0;
  }

  return list;
}

void XRParser::setSupportComment(bool supportComment){
  this->supportComment = supportComment;
}

void XRParser::setSupportNumber(bool supportNumber) {
  this->supportNumber = supportNumber;
}

void XRParser::registerPrefix(const std::string& prefix, const std::string& nameSpace) {
  prefixNameSpaceMap[prefix] = nameSpace;
}