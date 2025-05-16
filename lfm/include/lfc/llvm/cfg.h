// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_CFG_UTIL_H__
#define __LFC_CFG_UTIL_H__
#include <queue>
#include <set>
#include <map>

#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/base/graph/graph_simple.h"
#include "lfc/base/function.h"
#include "llvm/IR/Instructions.h"

namespace lfc {

enum class CFGType{ 
  BLOCK0 = 0  // default block(no successor)
, BLOCK1      // Unconditional jump block
, BLOCK2      // Conditional jump block
, BLOCK3      // Swtich jump block
};

std::string to_string(CFGType type);

struct CFGNode{
  int                   index;
  CFGType               type;
  llvm::Instruction*    inst              = NULL;
  llvm::BasicBlock*     block             = NULL;
  std::string           block_name        = "";
  llvm::Instruction*    block_end_inst    = NULL; // BranchInst* for BLOCK1 or BLOCK2
                                                  // SwitchInst* for BLOCK3
  std::vector<CFGNode*>     jump_from_nodes;
  std::vector<CFGNode*>     jump_to_nodes;
  std::vector<int64_t>      switch_values;

  CFGNode() = default;
  CFGNode(const CFGNode& N);
  CFGNode(CFGNode&& N);
  virtual ~CFGNode() = default;

  CFGNode& operator=(const CFGNode &N);
  CFGNode& operator=(CFGNode &&N);
};

class CFGUtil;
class CFGGraph{
public:
  virtual ~CFGGraph() = default;
  virtual const std::vector<CFGNode*>& get_all_nodes() const = 0;
  virtual CFGNode* get_begin_node() const = 0;
  virtual const std::vector<CFGNode*>& get_end_nodes() const = 0;
  virtual CFGUtil* get_cfg_util() const = 0;
};

class CFGUtil{
public:
  CFGUtil() = default;
  ~CFGUtil();
  void init(llvm::Function* F);

  CFGGraph* get_cfg_root_graph();
  CFGNode*  find_cfg_node(std::string block_name);

  std::vector<CFGNode*> clone_cfg_nodes(const std::vector<CFGNode*>& nodes);
  std::vector<CFGNode*> get_cfg_sub_nodes(CFGNode* begin, CFGNode* end);
  std::vector<CFGNode*> get_cfg_continuous_nodes(CFGNode* begin, CFGNode* end);
  bool verify_cfg_graph(const std::vector<CFGNode*>& nodes, CFGNode** begin_node = nullptr, std::vector<CFGNode*>* end_nodes = nullptr);

  CFGGraph* create_cfg_sub_graph(const std::vector<CFGNode*>& nodes);

private:
  class CFGUtilImpl* impl = NULL;
};

int visit_cfg_graph(CFGNode* begin, CFGNode* end, function<bool(CFGNode*)> func);
int visit_cfg_graph(CFGGraph* graph, function<bool(CFGNode*)> func);

bool has_call_in_cfg_node(const CFGNode* node);
bool has_loop_in_cfg_graph(CFGGraph* graph);
bool has_multi_branch_in_cfg_graph(CFGGraph* graph);

CFGGraph* simplify_cfg_graph(CFGGraph* graph, function<bool(CFGNode*)> func, bool remove_dead_block = false);
simple_graph make_link_simple_graph(CFGGraph* graph, std::map<CFGNode*, int>* index_map = nullptr);

void link_cfg_node(CFGNode* from, CFGNode* to);
CFGNode* get_cfg_child_at(CFGNode* node, int idx);

std::vector<llvm::BasicBlock*> to_llvm_blocks(std::vector<CFGNode*> nodes);

} // namespace lfc
LFC_TO_STRING_DEF(CFGNode);
LFC_TO_STRING_DEF(CFGGraph);
TRACE_SUB_MODULE_DEF(cfg_util)
#endif // __LFC_CFG_UTIL_H__

