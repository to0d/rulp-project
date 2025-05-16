#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_limits, test_limit_1_list)
{
  run_rulp_script("data/rulp_load_limits/test_limit_1_list.rulp");
}

TEST(rulp_load_limits, test_limit_2_int_max_min)
{
  run_rulp_script("data/rulp_load_limits/test_limit_2_int_max_min.rulp");
}

TEST(rulp_load_limits, test_limit_3_long_max_min)
{
  run_rulp_script("data/rulp_load_limits/test_limit_3_long_max_min.rulp");
}

