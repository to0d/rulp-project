#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_collection, test_join_1_atom_list)
{
  run_rulp_script("data/rulp_script_collection/test_join_1_atom_list.rulp");
}

TEST(rulp_script_collection, test_join_2_list_list)
{
  run_rulp_script("data/rulp_script_collection/test_join_2_list_list.rulp");
}

TEST(rulp_script_collection, test_sort_1_atom)
{
  run_rulp_script("data/rulp_script_collection/test_sort_1_atom.rulp");
}

TEST(rulp_script_collection, test_sort_2_int)
{
  run_rulp_script("data/rulp_script_collection/test_sort_2_int.rulp");
}

TEST(rulp_script_collection, test_sort_3_cmp_func_1)
{
  run_rulp_script("data/rulp_script_collection/test_sort_3_cmp_func_1.rulp");
}

TEST(rulp_script_collection, test_sort_4_array)
{
  run_rulp_script("data/rulp_script_collection/test_sort_4_array.rulp");
}

TEST(rulp_script_collection, test_union_1_atom)
{
  run_rulp_script("data/rulp_script_collection/test_union_1_atom.rulp");
}

TEST(rulp_script_collection, test_union_2_list)
{
  run_rulp_script("data/rulp_script_collection/test_union_2_list.rulp");
}

TEST(rulp_script_collection, test_uniq_1_atom)
{
  run_rulp_script("data/rulp_script_collection/test_uniq_1_atom.rulp");
}

