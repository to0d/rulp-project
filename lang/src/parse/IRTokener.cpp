// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/parse/IRTokener.h"

#include "lfc/base/to_string.h"

namespace lfc {

char to_char(TokenType t) {
  switch (t) {
  case TokenType::TT_0BAD:
    return 'B';
  case TokenType::TT_1BLK:
    return 'X';
  case TokenType::TT_2SYM:
    return 'S';
  case TokenType::TT_7CBI:
    return 'C';
  case TokenType::TT_3NAM:
    return 'N';
  case TokenType::TT_4STR:
    return 'T';
  case TokenType::TT_5INT:
    return 'I';
  case TokenType::TT_6FLT:
    return 'F';
  default:
    return 'U';
  }
}

} // namespace lfc

namespace lfc {

LFC_TO_STRING_IMPL(lfc::Token, TK){
  if( !TK )
    return "TK(null)";

  std::string out = "TK(";

  out += "type=";
  out += lfc::to_string(lfc::to_char(TK->type));

  out += ", value=";
  out += TK->value;

  out += ", line=";
  out += lfc::to_string(TK->lineIndex);

  out += ", pos=";
  out += lfc::to_string(TK->end_pos);

  out += ")";

  return out;
}
  
} // namespace lfc