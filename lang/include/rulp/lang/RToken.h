// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RTOKEN_H__
#define __RULP_LANG_RTOKEN_H__
#include "rulp/lang/base.h"
namespace lfc {

enum TokenType{
  TT_0BAD,  // Bad
  TT_1BLK,  // symbol blank space
  TT_2SYM,  // other symbol
  TT_3NAM,  // simple string, ABC123, _123ABC,
  TT_4STR,  // in quotation marks, "abc123 "
  TT_5INT,  // integer, 0123
  TT_6FLT,  // float 123.5
  TT_7CBI,  // Combine Symbols "%%"
  TT_8FLE,  // float 11.0e+4, scientific expression
  TT_9END   // '\n'
}; 

char to_char(TokenType t);

struct Token {

  TokenType type    = TokenType::TT_0BAD;
  std::string value = "";
  int lineIndex     = -1;
  int end_pos       = -1;

};

} // namespace lfc
LFC_TO_STRING_DEF(lfc::Token);
#endif //__RULP_LANG_RTOKEN_H__