#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;

static vector<DbgDeclareVar> _get_all_block_ddv(Function *F) {
  std::vector<DbgDeclareVar> ddv_list;
  for(BasicBlock& B : *F){
    for(auto& DDV : get_block_ddv(&B))
      ddv_list.push_back(DDV);
  }
  return ddv_list;
}

TEST(llvm_dbg, get_block_ddv_1_release)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dbg/get_block_ddv_1_release.ll", "foo");
  EXPECT_STREQ("{}", 
    lfc::to_string(_get_all_block_ddv(F)).c_str());  
}

TEST(llvm_dbg, get_block_ddv_2_debug)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dbg/get_block_ddv_2_debug.ll", "foo");
  test_lines(_get_all_block_ddv(F), "data_base/llvm_dbg/get_block_ddv_2_debug.txt");
}

TEST(llvm_dbg, get_block_ddv_3)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dbg/get_block_ddv_3.ll", "foo");
  EXPECT_STREQ("{}", 
    lfc::to_string(_get_all_block_ddv(F)).c_str());  
}

TEST(llvm_dbg, remove_debug_info_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_dbg/remove_debug_info_1_src.ll", "foo");

  remove_debug_info(M.get());

  std::vector<std::string> output_lines = dump_llvm_module(M.get());
  SAVE_TXT_FILE("data_base/llvm_dbg/remove_debug_info_1_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dbg/remove_debug_info_1_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str()); 
}
