// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/llvm/src_scope.h"
#include "lfc/base/to_string.h"
namespace lfc {

using namespace lfc;

SrcScope::SrcScope(const SrcScope& S){
  this->file_name     = S.file_name;
  this->start_line    = S.start_line;
  this->start_column  = S.start_column;
  this->end_line      = S.end_line;
  this->end_column    = S.end_column;
}


bool is_ss_intersection_of(const SrcScope& S1, const SrcScope& S2){
  SS_IS_VALID_LINE_SCOPE(S1);
  SS_IS_VALID_LINE_SCOPE(S2);

  if(S1.start_line < S2.start_line){
    return is_ss_intersection_of(S1, S1);
  }

  return S1.start_line <= S2.end_line;
}


LFC_TO_STRING_IMPL(SrcScope, SS){
  if( !SS )
    return "SS(null)";

  std::string out = "SS(";

  out += "file=";
  out += SS->file_name;

  out += ", start_line=";
  out += std::to_string(SS->start_line);

  out += ", start_column=";
  out += std::to_string(SS->start_column);
  
  out += ", end_line=";
  out += std::to_string(SS->end_line);

  out += ", end_column=";
  out += std::to_string(SS->end_column);
  
  out += ")";

  return out;
}


} // namespace lfc