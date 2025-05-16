#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/base/file.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"

using namespace std;
using namespace llvm;
using namespace lfc;

// no func body without struct
TEST(llvm_util, copy_llvm_function_1)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(copy_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_1_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_1_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// has func body without struct
TEST(llvm_util, copy_llvm_function_2)
{ 
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_2_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(copy_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_2_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_2_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// no func body with struct
TEST(llvm_util, copy_llvm_function_3)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_3_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_tgt.ll", context); 
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(copy_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_3_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_3_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// has func body with struct
TEST(llvm_util, copy_llvm_function_4)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_4_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_tgt.ll", context); 
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(copy_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_4_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_4_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// Opaque Pointers
TEST(llvm_util, copy_llvm_function_5)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_5_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_1_tgt.ll", context); 
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(copy_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_5_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_5_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}


TEST(llvm_util, copy_llvm_function_6)
{ 
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/copy_llvm_function_6_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  auto rst = copy_llvm_function("data_base/llvm_util_copy/copy_llvm_function_6_src.ll", DM.get(), {"__sdc_block_begin__", "__sdc_block_end__"});
  EXPECT_EQ(2, rst.size());

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_6_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/copy_llvm_function_6_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_1)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_1_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_1_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "fun1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_1_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_1_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// has func body with struct
TEST(llvm_util, replace_llvm_function_2)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_2_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_2_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_2_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_2_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_3)
{
  // TC240614F
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_3_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_3_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "simd_dre_executor_reshape") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_3_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_3_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// function with struct return type
TEST(llvm_util, replace_llvm_function_4)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_4_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_4_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_4_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_4_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// function with struct return para
TEST(llvm_util, replace_llvm_function_5)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_5_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_5_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_5_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_5_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// copy empty function
TEST(llvm_util, replace_llvm_function_6)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_6_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_6_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_6_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_6_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_7)
{
  // PHI
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_7_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_7_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_7_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_7_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_8)
{
  // global const array
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_8_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_8_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_8_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_8_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

// Opaque Pointers
TEST(llvm_util, replace_llvm_function_9)
{
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_9_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_9_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_9_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_9_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_10)
{
  // global const array
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_10_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_10_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_10_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_10_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_11)
{
  // same func in multi copied functions
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_11_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  auto rst = replace_llvm_function("data_base/llvm_util_copy/replace_llvm_function_11_src.ll", DM.get(), {"func1", "func2"});
  EXPECT_EQ(2, rst.size());

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_11_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_11_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_12)
{ 
  // switch support
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_12_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_12_tgt.ll", context); 
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_12_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_12_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}

TEST(llvm_util, replace_llvm_function_13)
{
  // global const array (llvm 15)
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_13_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_13_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_13_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_13_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}


TEST(llvm_util, replace_llvm_function_14)
{
  // static global const array (llvm-15)
  // set_global_trace(true);
  // set_llvm_util_trace(true);
  
  LLVMContext context;
  std::unique_ptr<Module> SM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_14_src.ll", context);
  EXPECT_TRUE(SM != NULL);
  std::unique_ptr<Module> DM = load_llvm_module("data_base/llvm_util_copy/replace_llvm_function_14_tgt.ll", context);
  EXPECT_TRUE(DM != NULL);

  EXPECT_TRUE(replace_llvm_function(SM.get(), DM.get(), "func1") != NULL);

  EXPECT_TRUE(verify_module(DM.get()));

  std::vector<std::string> output_lines = dump_llvm_module(DM.get());
  SAVE_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_14_dst.ll.actual", output_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_util_copy/replace_llvm_function_14_dst.ll")).c_str(), 
    lfc::to_string(output_lines).c_str());
}