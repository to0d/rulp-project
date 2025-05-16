#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_time, test_date_1)
{
  run_rulp_script("data/rulp_script_time/test_date_1.rulp");
}

TEST(rulp_script_time, test_day_of_week_1)
{
  run_rulp_script("data/rulp_script_time/test_day_of_week_1.rulp");
}

TEST(rulp_script_time, test_day_number_1)
{
  run_rulp_script("data/rulp_script_time/test_day_number_1.rulp");
}
