// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[dfg_match]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(dfg_match)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(dfg_match)
#include "lfc/llvm/dfg_match.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"

using namespace llvm;

namespace lfc {


std::string to_string(dfg_match_type t){
  switch(t){
    case dfg_match_type::INST_NAME : return "INST_NAME";
  default:  
    return "UNKNOWN";
  }
}

std::string to_string(DFGMatchPattern* DMP){
  if( !DMP )
    return "DMP(null)";

  std::string out = "SD(";

  out += "name=";
  out += DMP->match_name;

  out += ", type=";
  out += to_string(DMP->match_type);

  out += ", inst=";
  out += to_string(DMP->match_inst);

  out += ", action=";
  if(DMP->action_func == nullptr){
    out += "null";
  }
  else{
     out += "{}";
  }

  out += ")";

  return out;
}

bool DFGMatchUtil::match_node(DFGNode* node, const std::vector<std::string>& inst_names, int pos, std::vector<DFGNode*>& matched){
  if(node == NULL)
    return false;

  if(pos >= inst_names.size())
    return true;

  auto& inst_name = inst_names[pos];
  if(inst_name != "" && node->get_inst_name() != inst_name){
    return false;
  }

  matched.push_back(node);

  if( (pos+1) == inst_names.size())
    return true;

  for(auto* dpdon_node : node->get_depend_on_nodes()){
    if(match_node(dpdon_node, inst_names, pos+1, matched))
      return true;   
  }

  matched.pop_back();
  return false;
}

void DFGMatchUtil::add_match_pattern(const std::string& name, const std::vector<std::string>& match_inst, dmp_action_func action_func){
  DFGMatchPattern pattern;
  pattern.match_type  = dfg_match_type::INST_NAME;
  pattern.match_name  = name;
  pattern.match_inst  = match_inst;
  pattern.action_func = action_func;

  pattern_vec.push_back(pattern);
}

bool DFGMatchUtil::process_dfg_node(DFGNode* node){
  LFC_TRACE2("process_dfg_node: ",  lfc::to_string(*node));

  int size = pattern_vec.size();
  int pos = 0;

  for(auto& pattern: pattern_vec){
    bool match = false;
    std::vector<DFGNode*> matched;
    
    switch (pattern.match_type){
      case dfg_match_type::INST_NAME:
        match = match_node(node, pattern.match_inst, 0, matched);
        break;
      
      default:
        errs() << "match_type=" << to_string(pattern.match_type) << "\n";  
        llvm_unreachable("unsupport patten type");
    }

    if(match){
      LFC_TRACE2("match pattern found: ", to_string(&pattern));
      if(pattern.action_func != nullptr){
        match = pattern.action_func(matched);
      }
    }

    if(match){
      return true;
    }
  }

  return false;
}

}