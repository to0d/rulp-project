#include "unitest_llvm.h"

using namespace std;
using namespace llvm;
using namespace lfc;

TEST(llvm_util, is_all_in_dom_path_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_util_dom/is_all_in_dom_path_1.ll", "foo"); 
  auto blocks = get_llvm_blocks(F, {"%1", "%11"});
  EXPECT_EQ(2, blocks.size());
  EXPECT_EQ(true, is_all_in_dom_path(blocks));

  blocks = get_llvm_blocks(F, {"%1", "%5"});
  EXPECT_EQ(2, blocks.size());
  EXPECT_EQ(true, is_all_in_dom_path(blocks));

  blocks = get_llvm_blocks(F, {"%1", "%5", "%11"});
  EXPECT_EQ(3, blocks.size());
  EXPECT_EQ(false, is_all_in_dom_path(blocks));
}

