#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_stack, test_stack_1)
{
  run_rulp_script("data/rulp_load_stack/test_stack_1.rulp");
}

TEST(rulp_load_stack, test_stack_2_pass_in_macro)
{
  run_rulp_script("data/rulp_load_stack/test_stack_2_pass_in_macro.rulp");
}

TEST(rulp_load_stack, test_stack_3_pass_in_fun)
{
  run_rulp_script("data/rulp_load_stack/test_stack_3_pass_in_fun.rulp");
}

TEST(rulp_load_stack, test_stack_4_ls)
{
  run_rulp_script("data/rulp_load_stack/test_stack_4_ls.rulp");
}

TEST(rulp_load_stack, test_stack_5_final)
{
  run_rulp_script("data/rulp_load_stack/test_stack_5_final.rulp");
}

