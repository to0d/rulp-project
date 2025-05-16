#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/base/graph/graph_dot.h"

using namespace std;
using namespace llvm;
using namespace lfc;

static bool is_call_inst(llvm::Instruction* I){
  assert(I);
  switch (I->getOpcode()){
  case Instruction::Call  :
    return true;
  default: break;
  }
  return false;
}


TEST(llvm_register, register_allocation_cfg_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_register/register_allocation_1.ll", "foo");
  CFGUtil CFG_Util;
  CFG_Util.init(F);
  
  auto graph = CFG_Util.get_cfg_root_graph();
  test_lines(graph->get_all_nodes(), "data_base/llvm_register/register_allocation_1.txt");

  DotUtil DOT_Util(get_llvm_func_name(F));
  build_cfg_dot_graph(graph->get_all_nodes(), &DOT_Util, is_call_inst, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_register/register_allocation_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_register/register_allocation_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  std::vector<std::vector<std::string>> register_vec;
  EXPECT_TRUE(register_allocation_cfg(graph, nullptr, 0, register_vec));

  EXPECT_STREQ("{}", 
    lfc::to_string(register_vec).c_str());
}


TEST(llvm_register, register_allocation_by_fill_graph_coloring_1)
{

  // set_global_trace(true);
  // set_register_trace(true);

  // Example
  // 
  // int foo(int b, int c, int d, int f){
  //    
  //   while(b == 0){
  //     int a = b + c;  // 0
  //     d -= a;         // 1
  //     int e = d + f;  // 2
  //     if (e > 0) 
  //       f = 2*e;      // 3
  //     else {
  //       b = d + e;    // 4
  //       e = e - 1;    // 5
  //     }
  //     b = f + c;      // 6
  //   }
  //
  //   return b;         // 7
  // }
  std::vector<std::vector<std::string>> def_vars = {
      {"a"}
    , {"d"}
    , {"e"}
    , {"f"}
    , {"b"}
    , {"e"}
    , {"b"}
    , {}
  };
  std::vector<std::vector<std::string>> use_vars = {
      {"b", "c"}
    , {"a"}
    , {"d", "f"}
    , {"e"}
    , {"d", "e"}
    , {"e"}
    , {"f", "c"}
    , {"b"}
  };

  //     +-----------------------+
  //     v                       |
  //     0 -> 1 -> 2 -> 3 -----> 6 --> 7
  //                 \          ^
  //                  > 4 -> 5-/
  std::vector<std::vector<int>> graph = {
      {1}
    , {2}
    , {3,4}
    , {6}
    , {5}
    , {6}
    , {0, 7}
    , {}
    }
  ;

  {
    DotUtil DOT_Util("SG");

    build_simple_graph_dot_graph(graph, &DOT_Util, true);
    
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_register/register_allocation_2.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_register/register_allocation_2.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

    
  std::vector<std::vector<std::string>> register_vec;

  int pp_count = 8; // program point count
  int in_idx = 0, out_idx =7;
  int max_register_count = 4;
  
  EXPECT_TRUE(register_allocation_by_fill_graph_coloring(
                def_vars
              , use_vars
              , graph
              , pp_count
              , in_idx
              , out_idx
              , max_register_count
              , register_vec
              ));

  EXPECT_STREQ("{{a,b,d},{c},{f},{e}}", lfc::to_string(register_vec).c_str());

}


TEST(llvm_register, make_register_interference_graph_1){
  
  // set_global_trace(true);
  // set_register_trace(true);

  std::vector<std::vector<std::string>> in_vars = {
      {"b","c","f"}
    , {"a","c","f"}
    , {"c","d","f"}
    , {"c","e"}
    , {"c","d","e","f"}
    , {"c","e","f"}
    , {"c","f"}
    , {"b"}
  };
  
  
  std::vector<std::string> all_vars;
  simple_graph RIG = make_register_interference_graph(in_vars, all_vars);

  EXPECT_STREQ("{{2,5},{2,5},{3,4,5},{4,5},{5},{}}", lfc::to_string(RIG).c_str());
  EXPECT_STREQ("{a,b,c,d,e,f}", lfc::to_string(all_vars).c_str());

  {
    DotUtil DOT_Util("SSG");

    build_simple_graph_dot_graph(RIG, &DOT_Util, false, all_vars);
    
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_register/make_register_interference_graph_1.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_register/make_register_interference_graph_1.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }


}