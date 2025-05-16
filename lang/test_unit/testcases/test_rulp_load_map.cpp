#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_map, test_map_1)
{
  run_rulp_script("data/rulp_load_map/test_map_1.rulp");
}

TEST(rulp_load_map, test_map_2_ls)
{
  run_rulp_script("data/rulp_load_map/test_map_2_ls.rulp");
}

TEST(rulp_load_map, test_map_3_property)
{
  run_rulp_script("data/rulp_load_map/test_map_3_property.rulp");
}

TEST(rulp_load_map, test_map_5_clear_and_is_empty)
{
  run_rulp_script("data/rulp_load_map/test_map_5_clear_and_is_empty.rulp");
}

TEST(rulp_load_map, test_map_6_size_of)
{
  run_rulp_script("data/rulp_load_map/test_map_6_size_of.rulp");
}

// TEST(rulp_load_map, test_map_7_ref_1)
// {
//   run_rulp_script("data/rulp_load_map/test_map_7_ref_1.rulp");
// }

TEST(rulp_load_map, test_map_8_has_key)
{
  run_rulp_script("data/rulp_load_map/test_map_8_has_key.rulp");
}
