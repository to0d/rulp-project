#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_system, test_sys_os_type_1)
{
  run_rulp_script("data/rulp_script_system/test_sys_os_type_1.rulp");
}

