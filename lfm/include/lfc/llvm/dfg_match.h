// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DFG_MATCH_UTIL_H__
#define __LFC_DFG_MATCH_UTIL_H__

#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/base/function.h"
#include "lfc/llvm/dfg.h"
#include "llvm/IR/Instructions.h"

namespace lfc {

typedef function<bool(std::vector<DFGNode*>)> dmp_action_func;

enum class dfg_match_type{ 
  INST_NAME = 0  // match inst name
};

struct DFGMatchPattern {

public:

  DFGMatchPattern() = default;

  DFGMatchPattern(const DFGMatchPattern& DM){
    this->match_type  = DM.match_type;
    this->match_name  = DM.match_name;
    this->match_inst  = DM.match_inst;
    this->action_func = DM.action_func;
  }

  dfg_match_type           match_type;
  std::string              match_name;
  std::vector<std::string> match_inst;
  dmp_action_func          action_func;
};

class DFGMatchUtil{

public:
  void add_match_pattern(const std::string& name, const std::vector<std::string>& match_inst, dmp_action_func action_func);
  bool process_dfg_node(DFGNode* node);

  static bool match_node(DFGNode* node, const std::vector<std::string>& inst_names, int pos, std::vector<DFGNode*>& matched);

private:
  std::vector<DFGMatchPattern> pattern_vec;
};

}

TRACE_SUB_MODULE_DEF(dfg_match)


#endif // __LFC_DFG_MATCH_UTIL_H__