#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;


TEST(llvm_dfg, get_all_dfg_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_dfg_nodes_1.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_dfg_nodes_2)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_dfg_nodes_2.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_dfg_nodes_3)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_dfg_nodes_3.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_3.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_3.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_dfg_nodes_5)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_dfg_nodes_5.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_5.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_5.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_dfg_nodes_6)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_dfg_nodes_6.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_6.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_dfg_nodes_6.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}


TEST(llvm_dfg, get_all_depend_on_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_depend_on_nodes_1.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);

  std::vector<std::string> dot_vars = {"%425"};
  std::vector<DFGNode*> dot_nodes;
  for(auto& pass_dump_dfg_dot_opt_dot_var : dot_vars){
    DFGNode* node = DFG_Util.get_node_by_var(pass_dump_dfg_dot_opt_dot_var);
    dot_nodes.push_back(node);
  }

  auto depend_on_nodes = DFGNode::get_all_depend_on_nodes(dot_nodes);
  std::copy(depend_on_nodes.begin(), depend_on_nodes.end(), std::back_inserter(dot_nodes));
  DFGNode::sort_dfg_nodes(dot_nodes);

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_depend_on_nodes_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_depend_on_nodes_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_depend_on_nodes_2)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_depend_on_nodes_2.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);

  std::vector<std::string> dot_vars = {"%425", "%268"};
  std::vector<DFGNode*> dot_nodes;
  for(auto& pass_dump_dfg_dot_opt_dot_var : dot_vars){
    DFGNode* node = DFG_Util.get_node_by_var(pass_dump_dfg_dot_opt_dot_var);
    dot_nodes.push_back(node);
  }

  auto depend_on_nodes = DFGNode::get_all_depend_on_nodes(dot_nodes);
  std::copy(depend_on_nodes.begin(), depend_on_nodes.end(), std::back_inserter(dot_nodes));
  DFGNode::sort_dfg_nodes(dot_nodes);

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_dfg_dot_graph(dot_nodes, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dfg/get_all_depend_on_nodes_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/get_all_depend_on_nodes_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_dfg, get_all_depend_by_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/get_all_depend_by_nodes_1.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);

  std::vector<std::string> dot_vars = {"%283"};
  std::vector<DFGNode*> dot_nodes;
  for(auto& pass_dump_dfg_dot_opt_dot_var : dot_vars){
    DFGNode* node = DFG_Util.get_node_by_var(pass_dump_dfg_dot_opt_dot_var);
    dot_nodes.push_back(node);
  }
  EXPECT_STREQ("{DFGNode(index=363, type=CALL, var_name=%283, inst_name=call, operand={%282,@simd_convert_to_relative_addr}, dpdon={362}, dpdby={364}, call_name=simd_convert_to_relative_addr, opd={362})}", 
    lfc::to_string(dot_nodes).c_str());  

  dot_nodes = DFGNode::get_all_depend_by_nodes(dot_nodes);

  EXPECT_STREQ("{\
DFGNode(index=364, type=STORE, var_name=, inst_name=store, operand={%283,%67}, dpdon={363}, dpdby={536}),\
DFGNode(index=536, type=LOAD, var_name=%411, inst_name=load, operand={%67}, dpdon={364}, dpdby={550}),\
DFGNode(index=550, type=CALL, var_name=%425, inst_name=call, operand={%410,%411,%412,%413,%414,%415,%416,%417,%418,%419,%420,%421,%422,%423,%424,4,@Gemm}, dpdon={535,536,537,538,539,540,541,542,543,544,545,546,547,548,549}, dpdby={}, call_name=Gemm, opd={535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,-1})}", 
    lfc::to_string(dot_nodes).c_str());  
}

TEST(llvm_dfg, build_dfg_cfg_dot_graph_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dfg/build_dfg_cfg_dot_graph_1.ll", "foo");
  DFGUtil DFG_Util;
  DFG_Util.init(F);
  std::vector<DFGNode*> dfg_nodes = DFG_Util.get_all_dfg_nodes();
  
  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_dfg_dot_graph(dfg_nodes, &DOT_Util);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_dfg/build_dfg_cfg_dot_graph_1_dfg.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/build_dfg_cfg_dot_graph_1_dfg.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  CFGUtil CFG_Util;
  CFG_Util.init(F);
  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%1, end={4:%20}, nodes={0:%1,1:%11,2:%16,3:%19,4:%20})", 
    lfc::to_string(graph).c_str());

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_dfg/build_dfg_cfg_dot_graph_1_cfg.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dfg/build_dfg_cfg_dot_graph_1_cfg.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

}