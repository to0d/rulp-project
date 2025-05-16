#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_io, test_print_1)
{
  run_rulp_script("data/rulp_script_io/test_print_1.rulp");
}

TEST(rulp_script_io, test_print_2_class)
{
  run_rulp_script("data/rulp_script_io/test_print_2_class.rulp");
}

TEST(rulp_script_io, test_print_subject_1)
{
  run_rulp_script("data/rulp_script_io/test_print_subject_1.rulp");
}


TEST(rulp_script_io, test_open_text_file_1)
{
  run_rulp_script("data/rulp_script_io/test_open_text_file_1.rulp");
}

TEST(rulp_script_io, test_read_line_1)
{
  run_rulp_script("data/rulp_script_io/test_read_line_1.rulp");
}

TEST(rulp_script_io, test_save_txt_file_1)
{
  run_rulp_script("data/rulp_script_io/test_save_txt_file_1.rulp");
}

TEST(rulp_script_io, test_file_exist_1)
{
  run_rulp_script("data/rulp_script_io/test_file_exist_1.rulp");
}

TEST(rulp_script_io, test_file_is_folder_1)
{
  run_rulp_script("data/rulp_script_io/test_file_is_folder_1.rulp");
}

TEST(rulp_script_io, test_file_list_1)
{
  run_rulp_script("data/rulp_script_io/test_file_list_1.rulp");
}

TEST(rulp_script_io, test_file_mkdirs_1)
{
  run_rulp_script("data/rulp_script_io/test_file_mkdirs_1.rulp");
}

TEST(rulp_script_io, test_file_parent_1)
{
  run_rulp_script("data/rulp_script_io/test_file_parent_1.rulp");
}

TEST(rulp_script_io, test_format_1)
{
  run_rulp_script("data/rulp_script_io/test_format_1.rulp");
}
