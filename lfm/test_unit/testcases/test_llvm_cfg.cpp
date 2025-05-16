#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/base/graph/graph_utils.h"

using namespace std;
using namespace llvm;
using namespace lfc;


TEST(llvm_cfg, get_all_cfg_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/get_all_cfg_nodes_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%6, end={8:%582}, nodes={0:%6,1:%160,2:%324,3:%325,4:%328,5:%329,6:%334,7:%336,8:%582})", 
    lfc::to_string(graph).c_str());

  test_lines(graph->get_all_nodes(), "data_base/llvm_cfg/get_all_cfg_nodes_1.txt");
}


TEST(llvm_cfg, build_cfg_dot_graph_1)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%0, end={8:%22}, nodes={0:%0,1:%5,2:%8,3:%9,4:%12,5:%15,6:%18,7:%19,8:%22})", 
    lfc::to_string(graph).c_str());
  EXPECT_STREQ("{{1},{2,8},{3},{4,6},{5},{3},{7},{1},{}}", 
    lfc::to_string(make_link_simple_graph(graph)).c_str());

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

static bool is_call_inst(llvm::Instruction* I){
  assert(I);
  switch (I->getOpcode()){
  case Instruction::Call  :
    return true;
  default: break;
  }
  return false;
}

TEST(llvm_cfg, build_cfg_dot_graph_2)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, is_call_inst);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_cfg, build_cfg_dot_graph_3)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, nullptr, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_3.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_3.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_cfg, build_cfg_dot_graph_4)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, is_call_inst, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_4.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_4.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_cfg, build_cfg_dot_graph_5)
{
  // switch support
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_5.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();
  
  test_lines(graph->get_all_nodes(), "data_base/llvm_cfg/build_cfg_dot_graph_5.txt");

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, is_call_inst, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_5.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_5.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_cfg, build_cfg_dot_graph_6)
{
  // switch support
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_6.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();

  test_lines(graph->get_all_nodes(), "data_base/llvm_cfg/build_cfg_dot_graph_6.txt");

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, is_call_inst, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_6.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_6.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

// while(1)
TEST(llvm_cfg, build_cfg_dot_graph_7)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_7.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%1, end={}, nodes={0:%1,1:%5})", 
    lfc::to_string(graph).c_str());
  EXPECT_STREQ("{{1},{1}}", 
    lfc::to_string(make_link_simple_graph(graph)).c_str());

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_7.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_7.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

// multi end node
TEST(llvm_cfg, build_cfg_dot_graph_8)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_8.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();
  EXPECT_STREQ("CG(begin=0:%1, end={1:%3,2:%6}, nodes={0:%1,1:%3,2:%6})", 
    lfc::to_string(graph).c_str());
  EXPECT_STREQ("{{1,2},{},{}}", 
    lfc::to_string(make_link_simple_graph(graph)).c_str());

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph, &DOT_Util);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_8.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/build_cfg_dot_graph_8.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

}

TEST(llvm_cfg, clone_cfg_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto graph = CFG_Util.get_cfg_root_graph();

  auto new_cfg_nodes = CFG_Util.clone_cfg_nodes(graph->get_all_nodes());
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_cfg_nodes));

  test_lines(new_cfg_nodes, "data_base/llvm_cfg/clone_cfg_nodes_1.txt");
}


TEST(llvm_cfg, simplify_cfg_graph_1)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/build_cfg_dot_graph_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto root_graph = CFG_Util.get_cfg_root_graph();

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(root_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_1_before.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_1_before.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  auto new_graph = simplify_cfg_graph(root_graph, has_call_in_cfg_node);
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_graph->get_all_nodes()));
  EXPECT_TRUE(has_multi_branch_in_cfg_graph(new_graph));

// visit_graph_by_topological_sorting(new_graph->get_all_nodes(),  
// [](CFGNode* node){
//   std::cout << "visting: "<< lfc::to_string(node) << "\n";
//   return false;
// },
// [](CFGNode* node){
//     std::cout << "next: "<< lfc::to_string(node) << "\n";
//     std::vector<CFGNode*> child_nodes;
//     if(node->jump_true_node != NULL){
//       child_nodes.push_back(node->jump_true_node);
//     }
//     if(node->jump_false_node != NULL){
//       child_nodes.push_back(node->jump_false_node);
//     }
//     return child_nodes;
//   });

  EXPECT_TRUE(has_loop_in_cfg_graph(new_graph));

  test_lines(new_graph->get_all_nodes(), "data_base/llvm_cfg/simplify_cfg_graph_1.txt");

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(new_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_1_after.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_1_after.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }
}

TEST(llvm_cfg, simplify_cfg_graph_2)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/simplify_cfg_graph_2.ll", "foo"); // TC240529A
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto root_graph = CFG_Util.get_cfg_root_graph();

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(root_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_2_before.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_2_before.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  auto new_graph = simplify_cfg_graph(root_graph, has_call_in_cfg_node);
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_graph->get_all_nodes()));
  EXPECT_FALSE(has_multi_branch_in_cfg_graph(new_graph));
  EXPECT_FALSE(has_loop_in_cfg_graph(new_graph));

  test_lines(new_graph->get_all_nodes(), "data_base/llvm_cfg/simplify_cfg_graph_2.txt");

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(new_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_2_after.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_2_after.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }
}

TEST(llvm_cfg, simplify_cfg_graph_3)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/simplify_cfg_graph_3.ll", "foo"); // TC240412A
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto root_graph = CFG_Util.get_cfg_root_graph();

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(root_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_3_before.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_3_before.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  auto new_graph = simplify_cfg_graph(root_graph, has_call_in_cfg_node);
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_graph->get_all_nodes()));
  EXPECT_TRUE(has_multi_branch_in_cfg_graph(new_graph));
  EXPECT_FALSE(has_loop_in_cfg_graph(new_graph));

  test_lines(new_graph->get_all_nodes(), "data_base/llvm_cfg/simplify_cfg_graph_3.txt");

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(new_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_3_after.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_3_after.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }
}


TEST(llvm_cfg, simplify_cfg_graph_4)
{

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/simplify_cfg_graph_4.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto root_graph = CFG_Util.get_cfg_root_graph();

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(root_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_4_before.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_4_before.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  auto new_graph = simplify_cfg_graph(root_graph, has_call_in_cfg_node);
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_graph->get_all_nodes()));
  EXPECT_TRUE(has_multi_branch_in_cfg_graph(new_graph));
  EXPECT_FALSE(has_loop_in_cfg_graph(new_graph));

  test_lines(new_graph->get_all_nodes(), "data_base/llvm_cfg/simplify_cfg_graph_4.txt");

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(new_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_4_after.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_4_after.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

}

TEST(llvm_cfg, simplify_cfg_graph_5)
{
  // set_global_trace(true);
  // set_cfg_util_trace(true);

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/simplify_cfg_graph_3.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto root_graph = CFG_Util.get_cfg_root_graph();

  auto new_graph = simplify_cfg_graph(root_graph, has_call_in_cfg_node, true);
  EXPECT_TRUE(CFG_Util.verify_cfg_graph(new_graph->get_all_nodes()));
  EXPECT_FALSE(has_multi_branch_in_cfg_graph(new_graph));
  EXPECT_FALSE(has_loop_in_cfg_graph(new_graph));

  test_lines(new_graph->get_all_nodes(), "data_base/llvm_cfg/simplify_cfg_graph_5.txt");

  {
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_cfg_dot_graph(new_graph, &DOT_Util, is_call_inst, true);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_5_after.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_cfg/simplify_cfg_graph_5_after.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }
}

TEST(llvm_cfg, get_cfg_sub_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/get_cfg_sub_nodes_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto node = CFG_Util.find_cfg_node("%6");
  EXPECT_TRUE(node != NULL);
  EXPECT_STREQ("CN(index=0, type=B2, block=%6, end=br[%159:%160,%582], from={}, to={1:%160,8:%582}, switch={})", 
    lfc::to_string(node).c_str());

  auto nodes = CFG_Util.get_cfg_sub_nodes(get_cfg_child_at(node, 0), get_cfg_child_at(node, 1));
  EXPECT_STREQ("{%160,%324,%325,%328,%329,%334,%336}", 
    lfc::to_string(to_llvm_block_names(to_llvm_blocks(nodes))).c_str());
}


TEST(llvm_cfg, get_cfg_sub_nodes_2)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/get_cfg_sub_nodes_2.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto node = CFG_Util.find_cfg_node("%0");
  EXPECT_TRUE(node != NULL);
  EXPECT_STREQ("CN(index=0, type=B2, block=%0, end=br[%3:%4,%28], from={}, to={1:%4,10:%28}, switch={})", 
    lfc::to_string(node).c_str());

  auto nodes = CFG_Util.get_cfg_sub_nodes(get_cfg_child_at(node, 0), get_cfg_child_at(node, 1));
  EXPECT_STREQ("{%4,%8,%12,%14,%15,%16,%19,%22,%25}", 
    lfc::to_string(to_llvm_block_names(to_llvm_blocks(nodes))).c_str());
}


TEST(llvm_cfg, get_all_continuous_cfg_block_nodes_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/get_all_continuous_cfg_block_nodes_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);

  auto node = CFG_Util.find_cfg_node("%6");
  EXPECT_TRUE(node != NULL);
  EXPECT_STREQ("CN(index=0, type=B2, block=%6, end=br[%159:%160,%582], from={}, to={1:%160,8:%582}, switch={})", 
    lfc::to_string(node).c_str());

  auto nodes = CFG_Util.get_cfg_continuous_nodes(get_cfg_child_at(node, 0), get_cfg_child_at(node, 1));
  EXPECT_STREQ("{}", 
    lfc::to_string(to_llvm_block_names(to_llvm_blocks(nodes))).c_str());
}
