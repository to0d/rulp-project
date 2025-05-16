#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_list, test_list_1_add)
{
  run_rulp_script("data/rulp_script_list/test_list_1_add.rulp");
}

TEST(rulp_script_list, test_list_2_add_all)
{
  run_rulp_script("data/rulp_script_list/test_list_2_add_all.rulp");
}

TEST(rulp_script_list, test_list_3_var)
{
  run_rulp_script("data/rulp_script_list/test_list_3_var.rulp");
}

TEST(rulp_script_list, test_list_of_1)
{
  run_rulp_script("data/rulp_script_list/test_list_of_1.rulp");
}

TEST(rulp_script_list, test_list_of_3_fun)
{
  // run_rulp_script("data/rulp_script_list/test_list_of_3_fun.rulp");
}

TEST(rulp_script_list, test_list_of_4_env_vars)
{
  run_rulp_script("data/rulp_script_list/test_list_of_4_env_vars.rulp");
}

TEST(rulp_script_list, test_list_of_5_usr_vars)
{
  run_rulp_script("data/rulp_script_list/test_list_of_5_usr_vars.rulp");
}

TEST(rulp_script_list, test_make_list_1)
{
  run_rulp_script("data/rulp_script_list/test_make_list_1.rulp");
}

TEST(rulp_script_list, test_remove_list_1_atom)
{
  run_rulp_script("data/rulp_script_list/test_remove_list_1_atom.rulp");
}

TEST(rulp_script_list, test_remove_all_list_1_string)
{
  run_rulp_script("data/rulp_script_list/test_remove_all_list_1_string.rulp");
}

TEST(rulp_script_list, test_reverse_1)
{
  run_rulp_script("data/rulp_script_list/test_reverse_1.rulp");
}

TEST(rulp_script_list, test_to_nonamed_list_1)
{
  run_rulp_script("data/rulp_script_list/test_to_nonamed_list_1.rulp");
}

TEST(rulp_script_list, test_to_named_list_1)
{
  run_rulp_script("data/rulp_script_list/test_to_named_list_1.rulp");
}

TEST(rulp_script_list, test_to_named_list_2_var)
{
  run_rulp_script("data/rulp_script_list/test_to_named_list_2_var.rulp");
}

TEST(rulp_script_list, test_to_named_list_3_vary)
{
  run_rulp_script("data/rulp_script_list/test_to_named_list_3_vary.rulp");
}

TEST(rulp_script_list, test_to_named_list_4_err_obj)
{
  run_rulp_script("data/rulp_script_list/test_to_named_list_4_err_obj.rulp");
}

TEST(rulp_script_list, test_to_named_list_5_array)
{
  run_rulp_script("data/rulp_script_list/test_to_named_list_5_array.rulp");
}

TEST(rulp_script_list, test_to_expr_1)
{
  run_rulp_script("data/rulp_script_list/test_to_expr_1.rulp");
}