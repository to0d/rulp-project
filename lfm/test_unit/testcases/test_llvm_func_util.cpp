#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;

#define HPC_INST_SIMD_SYNC        "simd_synchronize"
#define HPC_INST_SIMD_GEMM_INIT   "simd_gemm_init"
#define HPC_INST_SIMD_GEMM        "Gemm"
#define HPC_INST_SIMD_DRE_INIT    "simd_dre_init"
#define HPC_INST_SIMD_DRE         "Dre"
#define HPC_INST_FINISH           "simd_major_finish"

static std::vector<FuncDef> inst_def_list = {
  {HPC_INST_SIMD_GEMM_INIT  , {2, 3}    , {}      },
  {HPC_INST_SIMD_GEMM       , {1, 2, 3} , {4, 5}  },
  {HPC_INST_SIMD_DRE_INIT   , {2, 3}    , {}      },
  {HPC_INST_SIMD_DRE        , {1, 2, 3} , {4, 5}  },
  {HPC_INST_SIMD_SYNC       , {}        , {}      },
  {HPC_INST_FINISH          , {}        , {}      },
};

TEST(llvm_func_util, load_func_call_list_1_inst)
{
  FuncUtil FUNC_Util(inst_def_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/load_func_call_list_1_inst.ll", "foo");
  test_lines(FUNC_Util.load_func_call_list(F), "data_base/llvm_func_util/load_func_call_list_1_inst.txt");
}

TEST(llvm_func_util, load_func_call_list_2)
{
  static std::vector<FuncDef> load_func_call_list_2 = {
    {"fun1", {0}, {}},
  };

  FuncUtil FUNC_Util(load_func_call_list_2); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/load_func_call_list_2.ll", "foo");
  test_lines(FUNC_Util.load_func_call_list(F), "data_base/llvm_func_util/load_func_call_list_2.txt");
}

TEST(llvm_func_util, build_dep_array_1)
{
  FuncUtil FUNC_Util(inst_def_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/build_dep_array_1.ll", "foo");
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{}}", 
    lfc::to_string(FUNC_Util.build_dep_array(FUNC_Util.load_func_call_list(F))).c_str());
}

TEST(llvm_func_util, build_dep_array2_1)
{
  // data came from TC240112B
  FuncUtil FUNC_Util(inst_def_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/build_dep_array2_1.ll", "foo");
  FUNC_Util.update_function(F);
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{},{4},{}}", 
    lfc::to_string(FUNC_Util.build_dep_array2(FUNC_Util.load_func_call_list(F))).c_str());  
}

TEST(llvm_func_util, build_dep_array2_2)
{
  // data came from TC240112B
  FuncUtil FUNC_Util(inst_def_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/build_dep_array2_2.ll", "foo");
  FUNC_Util.update_function(F);
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{7,4}}", 
    lfc::to_string(FUNC_Util.build_dep_array2(FUNC_Util.load_func_call_list(F))).c_str());  
}

TEST(llvm_func_util, build_dep_array2_3)
{
  // data came from TC240209A
  FuncUtil FUNC_Util(inst_def_list); 
  LOAD_LLVM_FUNCTION("data_base/llvm_func_util/build_dep_array2_3.ll", "foo");
  FUNC_Util.update_function(F);
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{7,4},{}}", 
    lfc::to_string(FUNC_Util.build_dep_array2(FUNC_Util.load_func_call_list(F))).c_str());  
}

TEST(llvm_func_util, get_func_params_1)
{
  FuncUtil FUNC_Util(inst_def_list); 
  EXPECT_STREQ("{1,2,3,4,5}", 
    lfc::to_string(FUNC_Util.get_func_params(HPC_INST_SIMD_GEMM)).c_str());  
}



