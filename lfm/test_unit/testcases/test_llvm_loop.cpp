#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/llvm/llvm_loop.h"

using namespace std;
using namespace llvm;
using namespace lfc;

TEST(llvm_loop, llvm_unroll_loop_in_cfg_graph_1)
{
  // set_global_trace(true);
  // set_llvm_loop_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1.ll", "foo"); // IR from TC241204A
  
  /****************************************/
  // Old CFG graph
  /****************************************/
  CFGUtil CFG_Util;
  CFG_Util.init(F);
  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%3, end={4:%43}, nodes={0:%3,1:%12,2:%18,3:%40,4:%43})", 
    lfc::to_string(graph).c_str());
  
  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph, &DOT_Util, nullptr, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1.dot.actual", dot_lines);
  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  /****************************************/
  // update ir
  /****************************************/
  EXPECT_TRUE(has_loop_in_cfg_graph(graph));
  EXPECT_FALSE(llvm_unroll_loop_in_cfg_graph(F, graph));
  
  /****************************************/
  // new CFG graph
  /****************************************/
  std::vector<std::string> output_lines = dump_llvm_module(M.get());
  SAVE_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());

  {
    CFGUtil CFG_Util;
    CFG_Util.init(F);
    auto graph = CFG_Util.get_cfg_root_graph();
    EXPECT_STREQ("CG(begin=0:%3, end={4:%43}, nodes={0:%3,1:%12,2:%18,3:%40,4:%43})", 
      lfc::to_string(graph).c_str());
    
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(graph, &DOT_Util, nullptr, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1_dst.dot.actual", dot_lines);
    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1_dst.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

}

