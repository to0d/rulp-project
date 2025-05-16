#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;


TEST(rulp_script_func, test_fun_0_bad_para_1_dup_para_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_0_bad_para_1_dup_para_1.rulp");
}

TEST(rulp_script_func, test_fun_1_para_class)
{
  run_rulp_script("data/rulp_script_func/test_fun_1_para_class.rulp");
}

TEST(rulp_script_func, test_fun_1_para_convert)
{
  run_rulp_script("data/rulp_script_func/test_fun_1_para_convert.rulp");
}

TEST(rulp_script_func, test_fun_0_bad_para_1_undfine_type_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_0_bad_para_1_undfine_type_1.rulp");
}

TEST(rulp_script_func, test_fun_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_1.rulp");
}

TEST(rulp_script_func, test_fun_2_ref_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_2_ref_1.rulp");
}

TEST(rulp_script_func, test_fun_2_ref_2)
{
  run_rulp_script("data/rulp_script_func/test_fun_2_ref_2.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_arg_number)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_arg_number.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_arg_type_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_arg_type_1.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_arg_type_2)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_arg_type_2.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_cross_frame_1_override)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_cross_frame_1_override.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_cross_frame_1_override2)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_cross_frame_1_override2.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_cross_frame_2)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_cross_frame_2.rulp");
}

TEST(rulp_script_func, test_fun_3_overload_factor_1)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_factor_1.rulp");
}

IRObject* GetNull(IRList* _args, IRInterpreter* _interpreter, IRFrame* _frame) {
  return null;
}

TEST(rulp_script_func, test_fun_3_overload_null_arg)
{
  run_rulp_script("data/rulp_script_func/test_fun_3_overload_null_arg.rulp", [](auto interpreter){
    RuntimeUtil::addFactor(MAIN_FRAME(interpreter), "get-null", GetNull);
  });
}

TEST(rulp_script_func, test_fun_4_scope_a)
{
  run_rulp_script("data/rulp_script_func/test_fun_4_scope_a.rulp");
}

TEST(rulp_script_func, test_fun_4_scope_b)
{
  run_rulp_script("data/rulp_script_func/test_fun_4_scope_b.rulp");
}

TEST(rulp_script_func, test_fun_4_scope_c)
{
  run_rulp_script("data/rulp_script_func/test_fun_4_scope_c.rulp");
}

TEST(rulp_script_func, test_fun_4_scope_d)
{
  // run_rulp_script("data/rulp_script_func/test_fun_4_scope_d.rulp");
}

TEST(rulp_script_func, test_fun_5_pass_expr)
{
  run_rulp_script("data/rulp_script_func/test_fun_5_pass_expr.rulp");
}

TEST(rulp_script_func, test_fun_6_extend_body)
{
  run_rulp_script("data/rulp_script_func/test_fun_6_extend_body.rulp");
}

TEST(rulp_script_func, test_fun_7_pass_nil)
{
  run_rulp_script("data/rulp_script_func/test_fun_7_pass_nil.rulp");
}

TEST(rulp_script_func, test_fun_8_unmatch_atom_to_obj)
{
  run_rulp_script("data/rulp_script_func/test_fun_8_unmatch_atom_to_obj.rulp");
}

TEST(rulp_script_func, test_lambda_1)
{
  run_rulp_script("data/rulp_script_func/test_lambda_1.rulp");
}

TEST(rulp_script_func, test_lambda_2)
{
  run_rulp_script("data/rulp_script_func/test_lambda_2.rulp");
}

TEST(rulp_script_func, test_lambda_3)
{
  run_rulp_script("data/rulp_script_func/test_lambda_3.rulp");
}

TEST(rulp_script_func, test_lambda_4)
{
  run_rulp_script("data/rulp_script_func/test_lambda_4.rulp");
}

TEST(rulp_script_func, test_lambda_5)
{
  run_rulp_script("data/rulp_script_func/test_lambda_5.rulp");
}

TEST(rulp_script_func, test_lambda_6_extend_body)
{
  run_rulp_script("data/rulp_script_func/test_lambda_6_extend_body.rulp");
}