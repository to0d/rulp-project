// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XTOKENER_H__
#define __RULP_XIMPL_RUNTIME_XTOKENER_H__

#include <vector>
#include "rulp/parse/IRTokener.h"
#include "rulp/runtime/IRTokenPool.h"
#include "lfc/base/trace_macro.h"
namespace lfc {

constexpr int C00_CHAR = 0;       // character
constexpr int C01_NUM = 1;        // number
constexpr int C02_BLANK = 2;      // Symbol Blank " " or \t
constexpr int C03_STRING = 3;     // String ""
constexpr int C04_UNDERSCORE = 4; // Symbol _
constexpr int C05_PERIOD = 5;     // Symbol .
constexpr int C06_OPERATOR = 6;   // Symbol
constexpr int C07_END = 7;        // New line \r \n
constexpr int C09_LEFT = 8;       // Symbol (
constexpr int C10_RIGHT = 9;      // Symbol )
constexpr int CX_UNKNOWN = -1;    // unknown char

constexpr int S_0INI = 0;         // Init mode
constexpr int S_BAD = -99;        // bad mode
constexpr int S_OT1 = -1;         // output Name (without curChar)
constexpr int S_OT2 = -2;         // output integer (without curChar)
constexpr int S_OT3 = -3;         // output float (without curChar)
constexpr int S_OT4 = -4;         // output Blank (without curChar)
constexpr int S_OT5 = -5;         // output Symbol (with curChar)
// constexpr int SAANY = 7;          // any statement except "BLANK" or "END"
constexpr int S_OT6 = -6;         // output String with curChar
constexpr int S1SKI = 1;          // Skip mode
constexpr int S2BLK = 2;          // Blank mode
constexpr int S4NAM = 3;          // Name mode
constexpr int S5INT = 4;          // Integer mode
constexpr int S6FLO = 5;          // Float mode
constexpr int S7STR = 6;          // String mode

typedef int X_STATE_TYPE [7][10];

class XRTokener : virtual public IRTokener{
public:
  XRTokener();
  virtual ~XRTokener();

  virtual IRTokenPool* getContext() const override;

  virtual void setContext(IRTokenPool* context) override;

  virtual void setContent(StrConstRef content) override;
  
  void set_strict_mode (bool strictMode);

  bool is_strict_mode() { return strictMode;}

  virtual Token* next() override;
  
  virtual Token* peek() override;

public:

  static int getCharType(char c);

protected:
  Token* _scan(int begPos);

protected:
  
  std::string content;
  
  int curPos = 0;
  
  int length = 0;
  
  X_STATE_TYPE* state;
  
  bool strictMode = true;
  
  IRTokenPool* context = NULL;
};



} // namespace lfc
TRACE_SUB_MODULE_DEF(rulp_xtoken)
#endif //__RULP_XIMPL_RUNTIME_XTOKENER_H__