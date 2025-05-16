#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_attr, test_attribute_of_0_ls)
{
  run_rulp_script("data/rulp_script_attr/test_attribute_of_0_ls.rulp");
}

TEST(rulp_script_attr, test_attribute_of_1_fun)
{
  run_rulp_script("data/rulp_script_attr/test_attribute_of_1_fun.rulp");
}

TEST(rulp_script_attr, test_attribute_of_2)
{
  run_rulp_script("data/rulp_script_attr/test_attribute_of_2.rulp");
}

TEST(rulp_script_attr, test_is_const_0)
{
  run_rulp_script("data/rulp_script_attr/test_is_const_0.rulp");
}

TEST(rulp_script_attr, test_is_const_1)
{
  run_rulp_script("data/rulp_script_attr/test_is_const_1.rulp");
}

TEST(rulp_script_attr, test_is_const_2_list)
{
  run_rulp_script("data/rulp_script_attr/test_is_const_2_list.rulp");
}

TEST(rulp_script_attr, test_is_const_3_array)
{
  run_rulp_script("data/rulp_script_attr/test_is_const_3_array.rulp");
}

TEST(rulp_script_attr, test_is_recursive_0)
{
  run_rulp_script("data/rulp_script_attr/test_is_recursive_0.rulp");
}

TEST(rulp_script_attr, test_is_recursive_1)
{
  run_rulp_script("data/rulp_script_attr/test_is_recursive_1.rulp");
}

TEST(rulp_script_attr, test_is_stable_0)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_0.rulp");
}

TEST(rulp_script_attr, test_is_stable_1_fun_simple)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_1_fun_simple.rulp");
}

TEST(rulp_script_attr, test_is_stable_2_fun_recursion_cycle)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_2_fun_recursion_cycle.rulp");
}

TEST(rulp_script_attr, test_is_stable_2_fun_recursion_self)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_2_fun_recursion_self.rulp");
}

TEST(rulp_script_attr, test_is_stable_3_fun_list)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_3_fun_list.rulp");
}

TEST(rulp_script_attr, test_is_stable_4_max)
{
  run_rulp_script("data/rulp_script_attr/test_is_stable_4_max.rulp");
}

TEST(rulp_script_attr, test_rt_of_0)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_0.rulp");
}

TEST(rulp_script_attr, test_rt_of_1_value)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_1_value.rulp");
}

TEST(rulp_script_attr, test_rt_of_2_factor)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_2_factor.rulp");
}

TEST(rulp_script_attr, test_rt_of_3_var)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_3_var.rulp");
}

TEST(rulp_script_attr, test_rt_of_4_expr_1)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_4_expr_1.rulp");
}

TEST(rulp_script_attr, test_rt_of_4_expr_2)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_4_expr_2.rulp");
}

TEST(rulp_script_attr, test_rt_of_5_fun)
{
  run_rulp_script("data/rulp_script_attr/test_rt_of_5_fun.rulp");
}

TEST(rulp_script_attr, test_stmt_count_of_0_attr)
{
  run_rulp_script("data/rulp_script_attr/test_stmt_count_of_0_attr.rulp");
}

TEST(rulp_script_attr, test_stmt_count_of_0_func)
{
  run_rulp_script("data/rulp_script_attr/test_stmt_count_of_0_func.rulp");
}

TEST(rulp_script_attr, test_stmt_count_of_1_expr)
{
  run_rulp_script("data/rulp_script_attr/test_stmt_count_of_1_expr.rulp");
}

TEST(rulp_script_attr, test_stmt_count_of_1_fun)
{
  run_rulp_script("data/rulp_script_attr/test_stmt_count_of_1_fun.rulp");
}
