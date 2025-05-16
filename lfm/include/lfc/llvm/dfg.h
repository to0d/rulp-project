// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DFG_UTIL_H__
#define __LFC_DFG_UTIL_H__

#include "lfc/base/macro.h"
#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "llvm/IR/Instructions.h"

#define DECLARE_SET_GET(_type, _name) \
  void JOINT_STR(set_, _name)(_type _name){this->_name = _name;} \
  _type JOINT_STR(get_, _name)() const {return _name;}

namespace lfc {

enum class DFGType{OTHER = 0, ARG, LOAD, STORE, CALL, RET, ALLOCA, CAST, MOP, IGNORE};

std::string to_string(DFGType type);

class DFGUtil;
class DFGUtilImpl;

class DFGNode{
  friend class DFGUtil;
  friend class DFGUtilImpl;
  friend std::string to_string(const DFGNode&); 
  friend std::string to_string(const DFGNode*);

public:
  DFGNode();
  DFGNode(DFGType type);
  DFGNode(const DFGNode& N);
  DFGNode(DFGNode&& N);

  DFGNode& operator=(const DFGNode &N);
  DFGNode& operator=(DFGNode &&N);

public:

  DECLARE_SET_GET(int, index);
  DECLARE_SET_GET(DFGType, type);
  DECLARE_SET_GET(std::string, call_name);
  DECLARE_SET_GET(std::string, var_name);
  DECLARE_SET_GET(std::string, inst_name);
  DECLARE_SET_GET(llvm::Instruction*, inst);
  DECLARE_SET_GET(llvm::BasicBlock*, block);
  DECLARE_SET_GET(std::vector<std::string>, operand_list);
  
public:

  std::vector<DFGNode*> get_depend_on_nodes() const;
  void add_depend_on_node(DFGNode* node);
  void remove_depend_on_node(DFGNode* node);
  bool has_depend_on_node(DFGNode* node) const;
  bool has_no_depend_on_node() const;

  std::vector<DFGNode*> get_depend_by_nodes() const;
  bool has_no_depend_by_node() const;

  int get_operand_count() const;
  std::string get_operand(int index) const;
  DFGNode* get_call_operand_node(int index) const;

  bool is_removed() const;
  void remove_node();

public:
  static std::vector<DFGNode*> get_dfg_nodes(const std::vector<DFGNode*>& nodes, DFGType type);
  static std::vector<DFGNode*> get_all_depend_on_nodes(const std::vector<DFGNode*>& nodes);
  static std::vector<DFGNode*> get_all_depend_by_nodes(const std::vector<DFGNode*>& nodes);
  static void remove_unused_dfg_nodes(std::vector<DFGNode*>& nodes);
  static void sort_dfg_nodes(std::vector<DFGNode*>& nodes);

private:
  static void _copy_dfg_node(const DFGNode& A, DFGNode& B);
  static void _move_dfg_node(DFGNode& A, DFGNode& B);

private:
  int                       index;
  DFGType                   type;

  llvm::Instruction*        inst;
  llvm::BasicBlock*         block;

  std::string               var_name;
  std::string               inst_name;
  std::string               call_name;

  std::vector<DFGNode*>     depend_on_nodes;
  std::vector<DFGNode*>     depend_by_nodes;
 
  std::vector<DFGNode*>     call_opd_nodes;
  std::vector<std::string>  operand_list;
};

class DFGUtil{
public:
  DFGUtil() = default;
  ~DFGUtil();
  void init(llvm::Function* F);
  void init(llvm::BasicBlock* B);
  std::vector<std::string> get_all_vars();
  std::vector<DFGNode*> get_all_dfg_nodes();
  DFGNode* get_node_by_var(const std::string& var_name);
  DFGNode* get_node_by_inst(llvm::Instruction* I);  

  std::vector<std::string> get_all_dfg_src_vars(const std::vector<DFGNode*>& nodes);
  std::vector<DFGNode*> clone_dfg_graph(const std::vector<DFGNode*>& nodes);
  std::vector<DFGNode*> simplify_link_node(const std::vector<DFGNode*>& nodes);
  std::vector<DFGNode*> simplify_const_in_call(const std::vector<DFGNode*>& nodes);

private:
  class DFGUtilImpl* impl = NULL;
};

} // namespace lfc
LFC_TO_STRING_DEF(DFGNode);
TRACE_SUB_MODULE_DEF(dfg_util)
#endif // __LFC_DFG_UTIL_H__

