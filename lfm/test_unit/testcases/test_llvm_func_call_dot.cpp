#include "unitest_llvm.h"
#include "unitest_base.h"
#include <iostream>

using namespace std;
using namespace llvm;
using namespace lfc;

TEST(llvm_func_call, build_dep_fc_dot_graph_1)
{
  std::vector<lfc::FuncDef> fd_list = {
    {"f1" , {0}, {1} },
    {"f2" , {0, 1}, {2}},
    {"f3" , {0, 1, 2}, {3}},
  };

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_1.ll", "foo"); // from TC240110A

  auto fc_list = FUNC_Util.load_func_call_list(F);
  auto dep_array = FUNC_Util.build_dep_array(fc_list);

  EXPECT_STREQ("{{},{0},{1,0}}", lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}


static std::vector<lfc::FuncDef> fd_list = {
    {"HPL_dcopy"  , {0, 1, 2, 3, 4}, {3} },
    {"HPL_dgemm"  , {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, {12} },
    {"HPL_dgemv"  , {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {10} },
    {"HPL_dtrsm"  , {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {10}},
    {"HPL_dscal"  , {0, 1, 2, 3}, {2}},
    {"HPL_dtrsv"  , {0, 1, 2, 3, 4, 5, 6, 7, 8}, {7} },
    {"HPL_idamax" , {0, 1, 2}, {}},
  };

TEST(llvm_func_call, build_dep_fc_dot_graph_2)
{

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_2.ll", "HPL_pdupdateNN"); // from HPL_pdupdateNN.c

  auto fc_list = FUNC_Util.load_func_call_list(F);
  test_lines(fc_list, "data_base/llvm_func_call/build_dep_fc_dot_graph_2.txt");

  auto dep_array = FUNC_Util.build_dep_array(fc_list);

  EXPECT_STREQ("{{},{0},{1,0},{2,1,0},{},{4,3,2,1,0},{5,4,3,2,1,0},{4},{7,6,5,4,3,2,1,0},{8,7,6,5,4,3,2,1,0}}", 
    lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_func_call, build_dep_fc_dot_graph_3)
{
  // set_global_trace(true);
  // set_func_util_trace(true);

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_2.ll", "HPL_pdupdateNN"); // from HPL_pdupdateNN.c

  auto fc_list = FUNC_Util.load_func_call_list(F);

  FUNC_Util.update_function(F);
  auto dep_array = FUNC_Util.build_dep_array2(fc_list);

  EXPECT_STREQ("{{},{0},{1,0},{2,1,0},{3,2,1,0},{4,3,2,1,0},{5,4,3,2,1,0},{6,5,4,3,2,1,0},{7,6,5,4,3,2,1,0},{8,7,6,5,4,3,2,1,0}}", 
    lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_3.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_3.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_func_call, build_dep_fc_dot_graph_4)
{
  // set_global_trace(true);
  // set_func_util_trace(true);

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_2.ll", "HPL_pdupdateNN"); // from HPL_pdupdateNN.c

  auto fc_list = FUNC_Util.load_func_call_list(F);
  FUNC_Util.update_function(F);
  auto dep_array = FUNC_Util.build_dep_array2(fc_list);

  EXPECT_STREQ("{{},{0},{1,0},{2,1,0},{3,2,1,0},{4,3,2,1,0},{5,4,3,2,1,0},{6,5,4,3,2,1,0},{7,6,5,4,3,2,1,0},{8,7,6,5,4,3,2,1,0}}", 
    lfc::to_string(dep_array).c_str());

  dep_array = remove_full_dep_array(dep_array);
  EXPECT_STREQ("{{},{0},{1},{2},{3},{4},{5},{6},{7},{8}}", 
    lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util, false, true);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_4.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_4.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_func_call, build_dep_fc_dot_graph_5)
{
  // set_global_trace(true);
  // set_func_util_trace(true);
  // set_dfg_util_trace(true);

  static std::vector<lfc::FuncDef> fd_list = {
    {"f1" , { }, {0} },
    {"f2" , { }, { } },
    {"f3" , {0}, { } },
  };

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_5.ll", "foo"); 

  auto fc_list = FUNC_Util.load_func_call_list(F);
  EXPECT_STREQ("{FC(name=f1, para={%1}, ret=%2, src_loc=-1),FC(name=f2, para={}, ret=%3, src_loc=-1),FC(name=f3, para={%1}, ret=, src_loc=-1)}", 
  lfc::to_string(fc_list).c_str());

  FUNC_Util.update_function(F);
  auto dep_array = FUNC_Util.build_dep_array2(fc_list);

  EXPECT_STREQ("{{},{},{1,0}}", 
    lfc::to_string(dep_array).c_str());

  dep_array = remove_full_dep_array(dep_array);
  EXPECT_STREQ("{{},{},{0,1}}", 
    lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util, true, false, true);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_5.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_5.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_func_call, build_dep_fc_dot_graph_6)
{
  // set_global_trace(true);
  // set_func_util_trace(true);
  // set_dfg_util_trace(true);

  static std::vector<lfc::FuncDef> fd_list = {
    {"f1" , { }, {0} },
    {"f2" , { }, { } },
    {"f3" , {0}, { } },
  };

  FuncUtil FUNC_Util(fd_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_6.ll", "foo"); 

  auto fc_list = FUNC_Util.load_func_call_list(F);
  EXPECT_STREQ("{FC(name=f1, para={%1}, ret=%2, src_loc=-1),FC(name=f2, para={}, ret=%6, src_loc=-1),FC(name=f3, para={%1}, ret=, src_loc=-1)}", 
  lfc::to_string(fc_list).c_str());

  FUNC_Util.update_function(F);
  auto dep_array = FUNC_Util.build_dep_array2(fc_list);

  EXPECT_STREQ("{{},{},{1,0}}", 
    lfc::to_string(dep_array).c_str());

  dep_array = remove_full_dep_array(dep_array);
  EXPECT_STREQ("{{},{},{0,1}}", 
    lfc::to_string(dep_array).c_str());

  DotUtil DOT_Util("foo");
  build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util, true, false, true);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_6.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_6.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(llvm_func_call, build_dep_fc_dot_graph_7)
{
  // set_global_trace(true);
  // set_func_util_trace(true);

  FuncUtil FUNC_Util(fd_list); 

  // data from HPL_pdmxswp2.c
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_7.ll", "HPL_pdmxswp"); 

  {
    DFGUtil DFG_Util;
    DFG_Util.init(F);
    std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_dfg_dot_graph(dot_nodes, &DOT_Util);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_7_1.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_7_1.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  {
    auto fc_list = FUNC_Util.load_func_call_list(F);
    FUNC_Util.update_function(F);
    auto dep_array = FUNC_Util.build_dep_array2(fc_list);

    EXPECT_STREQ("{{},{0}}", lfc::to_string(dep_array).c_str());

    dep_array = remove_full_dep_array(dep_array);
    EXPECT_STREQ("{{},{0}}", lfc::to_string(dep_array).c_str());

    DotUtil DOT_Util("foo");
    build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util, false, true);

    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_7_2.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_7_2.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }
}

TEST(llvm_dfg, build_dep_fc_dot_graph_8)
{
  std::vector<lfc::FuncDef> fd_list = {
    {"f1" , {0}, {0} },
  };

  FuncUtil FUNC_Util(fd_list); 

  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/build_dep_fc_dot_graph_8.ll", "foo");

  {
    DFGUtil DFG_Util;
    DFG_Util.init(F);
    std::vector<DFGNode*> dot_nodes = DFG_Util.get_all_dfg_nodes();
    DotUtil DOT_Util(get_llvm_func_name(F));
    build_dfg_dot_graph(dot_nodes, &DOT_Util);
    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_8_1.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_8_1.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

  {
    auto fc_list = FUNC_Util.load_func_call_list(F);
    FUNC_Util.update_function(F);
    auto dep_array = FUNC_Util.build_dep_array2(fc_list);

    EXPECT_STREQ("{{},{0}}", lfc::to_string(dep_array).c_str());

    dep_array = remove_full_dep_array(dep_array);
    EXPECT_STREQ("{{},{0}}", lfc::to_string(dep_array).c_str());

    DotUtil DOT_Util("foo");
    build_dep_fc_dot_graph(dep_array, fc_list, &DOT_Util, false, true);

    std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
    SAVE_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_8_2.dot.actual", dot_lines);

    EXPECT_STREQ(
      lfc::to_string(OPEN_TXT_FILE("data_base/llvm_func_call/build_dep_fc_dot_graph_8_2.dot")).c_str(), 
      lfc::to_string(dot_lines).c_str());
  }

}