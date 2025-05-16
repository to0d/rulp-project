#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_bool, test_bool_1)
{
  run_rulp_script("data/rulp_script_bool/test_bool_1.rulp");
}

TEST(rulp_script_bool, test_equal_1)
{
  run_rulp_script("data/rulp_script_bool/test_equal_1.rulp");
}