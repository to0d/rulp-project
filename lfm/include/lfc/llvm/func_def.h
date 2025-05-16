// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNC_DEF_H__
#define __LFC_FUNC_DEF_H__

#include "lfc/llvm/func_call.h"
#include "lfc/base/to_string_macro.h"
#include <vector>

namespace lfc {

struct FuncDef {
  std::string      func_name;
  std::vector<int> input_para_indexs;
  std::vector<int> output_para_indexs;

  FuncDef() = default;
  FuncDef(const std::string& name, const std::vector<int>& input_indexs, const std::vector<int>& output_indexs);
  FuncDef(const FuncDef& FD);
};

}// namespace lfc

LFC_TO_STRING_DEF(FuncDef);

#endif // __LFC_FUNC_DEF_H__

