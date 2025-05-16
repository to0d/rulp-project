#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_base, test_get_1_list)
{
  run_rulp_script("data/rulp_load_base/test_get_1_list.rulp");
}

TEST(rulp_load_base, test_get_2_array_1)
{
  run_rulp_script("data/rulp_load_base/test_get_2_array_1.rulp");
}

TEST(rulp_load_base, test_get_2_array_2)
{
  run_rulp_script("data/rulp_load_base/test_get_2_array_2.rulp");
}

TEST(rulp_load_base, test_index_of_1)
{
  run_rulp_script("data/rulp_load_base/test_index_of_1.rulp");
}

TEST(rulp_load_base, test_inc_dec_1)
{
  run_rulp_script("data/rulp_load_base/test_inc_dec_1.rulp");
}

TEST(rulp_load_base, test_inc_dec_2)
{
  run_rulp_script("data/rulp_load_base/test_inc_dec_2.rulp");
}

TEST(rulp_load_base, test_max_1)
{
  run_rulp_script("data/rulp_load_base/test_max_1.rulp");
}

TEST(rulp_load_base, test_max_2_list)
{
  run_rulp_script("data/rulp_load_base/test_max_2_list.rulp");
}

TEST(rulp_load_base, test_min_1)
{
  run_rulp_script("data/rulp_load_base/test_min_1.rulp");
}

TEST(rulp_load_base, test_min_2_list)
{
  run_rulp_script("data/rulp_load_base/test_min_2_list.rulp");
}

TEST(rulp_load_base, test_println_1)
{
  run_rulp_script("data/rulp_load_base/test_println_1.rulp");
}

TEST(rulp_load_base, test_size_of_array_1)
{
  run_rulp_script("data/rulp_load_base/test_size_of_array_1.rulp");
}

TEST(rulp_load_base, test_size_of_array_2)
{
  run_rulp_script("data/rulp_load_base/test_size_of_array_2.rulp");
}

TEST(rulp_load_base, test_size_of_list_1)
{
  run_rulp_script("data/rulp_load_base/test_size_of_list_1.rulp");
}

