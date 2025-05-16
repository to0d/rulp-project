// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rcc-rtl]"
#define LFC_TRACE_STREAM llvm::errs()
#include "lfc/base/cmd/opt.h"

// rtl:　rulp to llvm ir

using namespace lfc;
using namespace std;

#define SO_ARG_TRACE            "--trace"

int main(int argc, const char* argv[]) {

  std::string   input_src_path  = argv[1];
  std::string   output_ir_path = "";
  bool trace = false;


  return 0;
}