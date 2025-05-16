// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_xtoken]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_xtoken)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#define USE_LFC_NEW_TRACE
TRACE_SUB_MODULE_IMPL(rulp_xtoken)
#include "XRTokener.h"
#include "lfc/base/string/contant.h"
#include "lfc/base/string/util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "lfc/base/auto/auto_free.h"

using namespace lfc;
using namespace lfc;

static X_STATE_TYPE X_STATE_STRICT = {
  // CHAR - NUM - BLANK -- " ----- _ ---- . -- SYMBOL END --- ( ----- )
  { S4NAM, S5INT, S2BLK, S7STR, S4NAM, S_OT5, S_OT5, S1SKI, S_OT5, S_OT5 }, // S0INI
  { S4NAM, S5INT, S2BLK, S7STR, S4NAM, S_OT5, S_OT5, S1SKI, S_OT5, S_OT5 }, // S1SKI
  { S_OT4, S_OT4, S2BLK, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4 }, // S2BLK
  { S4NAM, S4NAM, S_OT1, S_OT1, S4NAM, S4NAM, S_OT1, S_OT1, S_OT1, S_OT1 }, // S4NAM
  { S4NAM, S5INT, S_OT2, S_OT2, S4NAM, S6FLO, S_OT2, S_OT2, S_OT2, S_OT2 }, // S5INT
  { S_OT3, S6FLO, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3 }, // S6FLO:float
  { S7STR, S7STR, S7STR, S_OT6, S7STR, S7STR, S7STR, S7STR, S7STR, S7STR }, // S7STR
};

static X_STATE_TYPE X_STATE2 = {
  // CHAR - NUM - BLANK -- " ----- _ ---- . -- SYMBOL END --- ( ----- )
  { S4NAM, S5INT, S2BLK, S7STR, S4NAM, S_OT5, S_OT5, S1SKI, S_OT5, S_OT5 }, // S0INI
  { S4NAM, S5INT, S2BLK, S7STR, S4NAM, S_OT5, S_OT5, S1SKI, S_OT5, S_OT5 }, // S1SKI
  { S_OT4, S_OT4, S2BLK, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4, S_OT4 }, // S2BLK
  { S4NAM, S4NAM, S_OT1, S_OT1, S4NAM, S4NAM, S_OT1, S_OT1, S_OT1, S_OT1 }, // S4NAM
  { S4NAM, S5INT, S_OT2, S_OT2, S4NAM, S6FLO, S_OT2, S_OT2, S_OT2, S_OT2 }, // S5INT
  { S_OT3, S6FLO, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3, S_OT3 }, // S6FLO:float
  { S7STR, S7STR, S7STR, S_OT6, S7STR, S7STR, S7STR, S_OT1, S_OT1, S_OT1 }, // S7STR
};


int XRTokener::getCharType(char c) {
  switch (c) {
    case EN_CHAR_NEWLINE: // '\n';
    case EN_CHAR_ENTER:   // '\r'
      return C07_END;
    
    case EN_CHAR_SPACE:   // blank
    case EN_CHAR_TAB:     // tab
      return C02_BLANK;

    case '"':
      return C03_STRING;

    case '(':
      return C09_LEFT;

    case ')':
      return C10_RIGHT;

    case '+':
    case '-':
    case '\'':
    case '\\':
    case '|':
    case ':':
    case ';':
    case ',':
    case '[':
    case ']':
    case '{':
    case '}':
    case '@':
    case '#':
    case '=':
    case '/':
    case '$':
    case '?':
    case '&':
    case '*':
    case '%':
    case '<':
    case '>':
    case '!':
    case '^':
    case '`':
    case EN_SEPARATION_DOT:
      return C06_OPERATOR;

    case '_':
      return C04_UNDERSCORE;

    case '.':
      return C05_PERIOD;
    
    case '~':
      return C00_CHAR;

    default:
      break;
  }
  
  switch (StringUtil::getCharType(c)) {
    case CharType::CN_CHAR:
    case CharType::CN_SYMBOL:
    case CharType::TW_ZHUYIN:
    case CharType::JP_SYMBOL:
    case CharType::ROMAN_NUM: return C00_CHAR;
    case CharType::NUMBER   : return C01_NUM;
    case CharType::EN_CHAR  : return C00_CHAR;
    default: break;
  }

  return CX_UNKNOWN;
}

XRTokener::XRTokener()
{
  this->state = &X_STATE_STRICT;
}

XRTokener::~XRTokener(){
}

void XRTokener::setContent(StrConstRef content){
  this->content = content;
  this->length  = content.length();
  this->curPos  = 0;
}

void XRTokener::set_strict_mode(bool strictMode){
  this->strictMode = strictMode;
  
  if (strictMode) {
    state = &X_STATE_STRICT;
  } else {
    state = &X_STATE2;
  }
}

Token* XRTokener::next(){
  auto token = peek();
  this->curPos = (token == NULL ? this->length : token->end_pos);
  return token;
}

Token* XRTokener::peek(){
  Token* token = NULL;
  if ((token = _scan(curPos)) == NULL) {
    return NULL;
  }
  return token;
}

Token* XRTokener::_scan(int begPos){
  int scanPos = begPos;
  int retPos = -1;
  int lastState = S_0INI;
  int curState = S_0INI;
  TokenType findTokenType = TokenType::TT_0BAD;
  
  char lastChar = 0;
  char stringBeginSymbol = 0;
  int escapeCount = 0;

  if (begPos >= length) {
    return NULL;
  }

  for (; findTokenType == TokenType::TT_0BAD && scanPos <= length; lastState = curState, scanPos++) {
    int charType;

    if (scanPos >= length) {
      charType = C07_END;
    } 
    else {

      lastChar = content[scanPos];
      charType = getCharType(lastChar);
      if (charType == CX_UNKNOWN) {

        // skip some char in a string " abc??def "
        if (lastState == S7STR) {
          continue;
        }

        // support any name
        if (lastState == S4NAM) {
          continue;
        }

        LFC_TRACE("lastChar=<", lastChar , ">, pos=", scanPos);
        assert(false && "unsupport char");
      }

    }

    curState = (*state)[lastState][charType];

    switch (curState) {
    case S_BAD:
      LFC_TRACE("lastChar=<", lastChar , ">, pos=", scanPos);
      assert(false && "invald DFA state in char");
      break;

    case S1SKI:
      ++begPos;
      break;

    // output token : Name without curChar
    case S_OT1:
      return context->createToken(TokenType::TT_3NAM, content.substr(begPos, scanPos - begPos), scanPos);

    // output token : integer( without curChar)
    case S_OT2:
      return context->createToken(TokenType::TT_5INT, content.substr(begPos, scanPos - begPos), scanPos);

    // output token : float( without curChar)
    case S_OT3:
      return context->createToken(TokenType::TT_6FLT, content.substr(begPos, scanPos - begPos), scanPos);

    // output token : Blank( without curChar)
    case S_OT4:
      return context->createToken(TokenType::TT_1BLK, content.substr(begPos, scanPos - begPos), scanPos);

    // output token : Symbol (with curChar)
    case S_OT5:

      retPos = scanPos + 1;
      if (retPos != (begPos + 1)){
        LFC_TRACE("lastChar=<", lastChar , ">, pos=", scanPos);
        assert(false && "invald DFA state in char");
      }

      findTokenType = TokenType::TT_2SYM;
      break;

    // output token : String with curChar
    case S_OT6:

      if (stringBeginSymbol == 0){
        LFC_TRACE("lastChar=<", lastChar , ">, pos=", scanPos);
         assert(false && "Null String Char");
      }

      // Start with " and new the lastChar is '
      if (stringBeginSymbol != lastChar) {

        // Continue scan to "StringBeginSymbol"
        curState = S7STR;

      } else {

        retPos = scanPos + 1;
        findTokenType = TokenType::TT_4STR;
      }

      break;

    case S7STR:

      if (stringBeginSymbol == 0) {
        stringBeginSymbol = lastChar;
      }

      // Escape char
      if (lastChar == '\\' && ((scanPos + 1) <= length)) {
        char nextChar = content[scanPos + 1];
        if (StringUtil::isEscapeChar(nextChar)) {
          ++escapeCount;
          ++scanPos;
        }
      }

      break;

    }// switch (curState)

  }

  if (findTokenType == TokenType::TT_0BAD) {
    switch (curState) {
      case S1SKI: // String end in \n or \r
        return NULL;
      default:
        findTokenType = TokenType::TT_0BAD;
        retPos = length;
    }
  }

  if (begPos >= retPos) {
    LFC_TRACE("begPos=", begPos , ", retPos=", retPos, ", scanPos=", scanPos);
    assert(false && "invaild length");
  }

  auto value = content.substr(begPos, retPos - begPos);
  if (escapeCount > 0) {
    value = StringUtil::removeEscape(value);
  }

  return context->createToken(findTokenType, value, retPos);

}


IRTokenPool* XRTokener::getContext() const {
  return context;
}

void XRTokener::setContext(IRTokenPool* context) {
  this->context = context;
}
