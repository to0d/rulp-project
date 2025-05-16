#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/base/file.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"

using namespace std;
using namespace llvm;
using namespace lfc;

TEST(llvm_util, has_llvm_common_var_1)
{
  EXPECT_EQ(true, lfc::has_llvm_common_var({"%1", "%2"}, {"%2"}));
  EXPECT_EQ(false, lfc::has_llvm_common_var({"%1", "%3"}, {"%2"}));
}

TEST(llvm_util, is_cxx_class_func_1)
{
  EXPECT_EQ(true, lfc::is_cxx_class_func("class::foo"));
}

TEST(llvm_util, get_ignored_block_1){

  LOAD_LLVM_FUNCTION("data_base/llvm_util_base/get_ignored_block_1.ll", "foo");
  auto br_list = get_all_llvm_instructions(F, Instruction::Br);
  test_lines(br_list, "data_base/llvm_util_base/get_ignored_block_1.txt");

  std::vector<BasicBlock*> dead_blocks;

  for(auto I : br_list){
    if(BranchInst* BI = dyn_cast<BranchInst>(I); BI){
      BasicBlock* BB = get_ignored_block(BI);
      if(BB){
        dead_blocks.push_back(BB);
      }
    }
  }

  EXPECT_STREQ("{%5}", lfc::to_string(to_llvm_block_names(dead_blocks)).c_str());
}

TEST(llvm_util, get_ignored_block_2){

  LOAD_LLVM_FUNCTION("data_base/llvm_cfg/simplify_cfg_graph_3.ll", "foo");
  auto br_list = get_all_llvm_instructions(F, Instruction::Br);
  test_lines(br_list, "data_base/llvm_util_base/get_ignored_block_2.txt");

  std::vector<BasicBlock*> dead_blocks;

  for(auto I : br_list){
    if(BranchInst* BI = dyn_cast<BranchInst>(I); BI){
      BasicBlock* BB = get_ignored_block(BI);
      if(BB){
        dead_blocks.push_back(BB);
      }
    }
  }

  EXPECT_STREQ("{%368,%485,%743}", lfc::to_string(to_llvm_block_names(dead_blocks)).c_str());
}

TEST(llvm_util, get_ignored_block_3){

  LOAD_LLVM_FUNCTION("data_base/llvm_util_base/get_ignored_block_3.ll", "foo");
  auto br_list = get_all_llvm_instructions(F, Instruction::Br);
  test_lines(br_list, "data_base/llvm_util_base/get_ignored_block_3.txt");

  std::vector<BasicBlock*> dead_blocks;

  for(auto I : br_list){
    if(BranchInst* BI = dyn_cast<BranchInst>(I); BI){
      BasicBlock* BB = get_ignored_block(BI);
      if(BB){
        dead_blocks.push_back(BB);
      }
    }
  }

  EXPECT_STREQ("{%5}", lfc::to_string(to_llvm_block_names(dead_blocks)).c_str());
}

TEST(llvm_util, has_llvm_inst_return_var_1){

  LOAD_LLVM_FUNCTION("data_base/llvm_util_base/has_llvm_inst_return_var_1.ll", "foo");

  std::vector<std::string> vars;

  for (auto& BB : *F){
    for(auto &I : BB){
      if(has_llvm_inst_return_var(&I)){
        vars.push_back(get_llvm_value_name(&I));
      }
    }
  }

  EXPECT_STREQ("{%5,%6,%7,%8,%9,%10,%12,%13,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%27,%28,%30,%31,%32,%33,%34,%36,%37,%38,%40}"
    , lfc::to_string(vars).c_str());
}