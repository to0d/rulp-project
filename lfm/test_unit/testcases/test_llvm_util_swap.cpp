#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;

TEST(llvm_util_swap, swap_llvm_call_inst_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_util_swap/swap_llvm_call_inst_1_input.ll", "foo");
  bool rc = swap_llvm_call_inst(F, 0, 1);
  EXPECT_EQ(true, rc);

  EXPECT_TRUE(verify_module(M.get()));

  std::vector<std::string> output_lines = dump_llvm_module(M.get());

  SAVE_TXT_FILE("data_base/llvm_util_swap/swap_llvm_call_inst_1_output.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE_IGNORE_TAIL_BLANK("data_base/llvm_util_swap/swap_llvm_call_inst_1_output.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}


TEST(llvm_util_swap, swap_llvm_call_inst_2)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_util_swap/swap_llvm_call_inst_2_input.ll", "foo");
  bool rc = swap_llvm_call_inst(F, 0, 1);
  EXPECT_EQ(true, rc);

  EXPECT_TRUE(verify_module(M.get()));

  std::vector<std::string> output_lines = dump_llvm_module(M.get());

  SAVE_TXT_FILE("data_base/llvm_util_swap/swap_llvm_call_inst_2_output.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE_IGNORE_TAIL_BLANK("data_base/llvm_util_swap/swap_llvm_call_inst_2_output.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}


TEST(llvm_util_swap, swap_llvm_call_inst_3)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_util_swap/swap_llvm_call_inst_3_input.ll", "foo");
  bool rc = swap_llvm_call_inst(F, 0, 1);
  EXPECT_EQ(true, rc);

  EXPECT_TRUE(verify_module(M.get()));

  std::vector<std::string> output_lines = dump_llvm_module(M.get());

  SAVE_TXT_FILE("data_base/llvm_util_swap/swap_llvm_call_inst_3_output.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE_IGNORE_TAIL_BLANK("data_base/llvm_util_swap/swap_llvm_call_inst_3_output.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util_swap, swap_llvm_call_inst_4)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_util_swap/swap_llvm_call_inst_4_input.ll", "foo");
  bool rc = swap_llvm_call_inst(F, 0, 1);
  EXPECT_EQ(true, rc);

  EXPECT_TRUE(verify_module(M.get()));

  std::vector<std::string> output_lines = dump_llvm_module(M.get());

  SAVE_TXT_FILE("data_base/llvm_util_swap/swap_llvm_call_inst_4_output.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE_IGNORE_TAIL_BLANK("data_base/llvm_util_swap/swap_llvm_call_inst_4_output.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}
