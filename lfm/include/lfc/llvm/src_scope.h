// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_SRC_SCOPE_H__
#define __LFC_LLVM_SRC_SCOPE_H__
#include <string>

#include "lfc/base/to_string_macro.h"
namespace lfc {

#define SS_IS_VALID_LINE_SCOPE(SS)        ((SS).start_line != -1 && (SS).end_line != -1)
#define SS_IS_SUB_OF(S1, S2)              ((S1).start_line >= (S2).start_line && (S1).end_line <= (S2).end_line)
#define SS_IS_INTERSECTION_OF(S1, S2)     is_ss_intersection_of(S1, S2) 


struct SrcScope {
  std::string   file_name;
  int  start_line   = -1;
  int  start_column = -1;
  int  end_line     = -1;
  int  end_column   = -1;

  SrcScope() {};

  SrcScope(const SrcScope& PCB);

};

bool is_ss_intersection_of(const SrcScope& S1, const SrcScope& S2);

} // namespace lfc
LFC_TO_STRING_DEF(SrcScope);
#endif // __LFC_LLVM_SRC_SCOPE_H__
