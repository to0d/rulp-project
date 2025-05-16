#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_set, test_set_1)
{
  run_rulp_script("data/rulp_load_set/test_set_1.rulp");
}

TEST(rulp_load_set, test_set_2_pass_in_macro)
{
  run_rulp_script("data/rulp_load_set/test_set_2_pass_in_macro.rulp");
}

TEST(rulp_load_set, test_set_3_pass_in_fun)
{
  run_rulp_script("data/rulp_load_set/test_set_3_pass_in_fun.rulp");
}

TEST(rulp_load_set, test_set_4)
{
  run_rulp_script("data/rulp_load_set/test_set_4.rulp");
}

TEST(rulp_load_set, test_set_5_ls)
{
  run_rulp_script("data/rulp_load_set/test_set_5_ls.rulp");
}

TEST(rulp_load_set, test_set_6_final)
{
  run_rulp_script("data/rulp_load_set/test_set_6_final.rulp");
}

TEST(rulp_load_set, test_set_7_property)
{
  run_rulp_script("data/rulp_load_set/test_set_7_property.rulp");
}

TEST(rulp_load_set, test_set_8_ref_a)
{
  // run_rulp_script("data/rulp_load_set/test_set_8_ref_a.rulp");
}

TEST(rulp_load_set, test_set_9)
{
  run_rulp_script("data/rulp_load_set/test_set_9.rulp");
}

TEST(rulp_load_set, test_set_a_size_of)
{
  run_rulp_script("data/rulp_load_set/test_set_a_size_of.rulp");
}
