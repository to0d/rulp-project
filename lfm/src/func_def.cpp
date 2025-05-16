// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/llvm/func_def.h"
#include "lfc/base/to_string.h"

using namespace llvm;

namespace lfc {

FuncDef::FuncDef(const std::string& name, const std::vector<int>& input_indexs, const std::vector<int>& output_indexs){
  func_name = name;
  input_para_indexs = input_indexs;
  output_para_indexs = output_indexs;
};

FuncDef::FuncDef(const FuncDef& FD){
  this->func_name = FD.func_name;
  this->input_para_indexs = FD.input_para_indexs;
  this->output_para_indexs = FD.output_para_indexs;
}


LFC_TO_STRING_IMPL(FuncDef, FD){
  if( !FD )
    return "FD(null)";

  std::string out = "FD(";

  out += "name=";
  out += FD->func_name;

  out += ", input=";
  out += lfc::to_string(FD->input_para_indexs);

  out += ", output=";
  out += lfc::to_string(FD->output_para_indexs);

  out += ")";

  return out;
}

}// namespace lfc 