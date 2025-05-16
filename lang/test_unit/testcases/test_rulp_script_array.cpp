#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_array, test_array_1)
{
  run_rulp_script("data/rulp_script_array/test_array_1.rulp");
}

TEST(rulp_script_array, test_array_2_add)
{
  run_rulp_script("data/rulp_script_array/test_array_2_add.rulp");
}

TEST(rulp_script_array, test_array_4_const)
{
  run_rulp_script("data/rulp_script_array/test_array_4_const.rulp");
}

TEST(rulp_script_array, test_make_array_1)
{
  run_rulp_script("data/rulp_script_array/test_make_array_1.rulp");
}

TEST(rulp_script_array, test_seta_1_array)
{
  run_rulp_script("data/rulp_script_array/test_seta_1_array.rulp");
}
