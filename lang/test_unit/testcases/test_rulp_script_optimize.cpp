#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_optimize, test_lco_2_fun_1)
{
  run_rulp_script("data/rulp_script_optimize/test_lco_2_fun_1.rulp");
}

TEST(rulp_script_optimize, test_lco_2_fun_2_has_para_type)
{
  run_rulp_script("data/rulp_script_optimize/test_lco_2_fun_2_has_para_type.rulp");
}

TEST(rulp_script_optimize, test_lco_4_recursion_1)
{
  run_rulp_script("data/rulp_script_optimize/test_lco_4_recursion_1.rulp");
}

TEST(rulp_script_optimize, test_lco_4_recursion_2)
{
  run_rulp_script("data/rulp_script_optimize/test_lco_4_recursion_2.rulp");
}

TEST(rulp_script_optimize, test_print_impl_1)
{
  run_rulp_script("data/rulp_script_optimize/test_print_impl_1.rulp");
}