#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_iterator, test_make_list_iterator_1)
{
  run_rulp_script("data/rulp_script_iterator/test_make_list_iterator_1.rulp");
}

TEST(rulp_script_iterator, test_1_iterator_to_list)
{
  run_rulp_script("data/rulp_script_iterator/test_1_iterator_to_list.rulp");
}

