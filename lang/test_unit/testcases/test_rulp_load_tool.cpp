#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_tool, test_print_list_1)
{
  run_rulp_script("data/rulp_load_tool/test_print_list_1.rulp");
}

TEST(rulp_load_tool, test_print_list_2_frame)
{
  run_rulp_script("data/rulp_load_tool/test_print_list_2_frame.rulp");
}

TEST(rulp_load_tool, test_print_list_3_frame)
{
  run_rulp_script("data/rulp_load_tool/test_print_list_3_frame.rulp");
}

TEST(rulp_load_tool, test_print_list_4_vars)
{
  run_rulp_script("data/rulp_load_tool/test_print_list_4_vars.rulp");
}

TEST(rulp_load_tool, test_str_split_line_1)
{
  run_rulp_script("data/rulp_load_tool/test_str_split_line_1.rulp");
}

TEST(rulp_load_tool, test_to_one_line_1)
{
  run_rulp_script("data/rulp_load_tool/test_to_one_line_1.rulp");
}

TEST(rulp_load_tool, test_to_valid_path_1)
{
  run_rulp_script("data/rulp_load_tool/test_to_valid_path_1.rulp");
}

TEST(rulp_load_tool, test_string_1)
{
  run_rulp_script("data/rulp_load_tool/test_string_1.rulp");
}

TEST(rulp_load_tool, test_time_1)
{
  run_rulp_script("data/rulp_load_tool/test_time_1.rulp");
}
