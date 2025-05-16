#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;

static std::vector<FuncCall> _get_all_func_call(Function *F) {
  std::vector<FuncCall> fc_list;
  for(BasicBlock& B : *F){
    for(auto& FC : load_block_func_call_list(&B))
      fc_list.push_back(FC);
  }
  return fc_list;
}

TEST(llvm_func_call, load_block_func_call_list_1)
{
  LOAD_LLVM_FUNCTION("data_base/llvm_func_call/load_block_func_call_list_1.ll", "foo");
  test_lines(_get_all_func_call(F), "data_base/llvm_func_call/load_block_func_call_list_1.txt");
}

