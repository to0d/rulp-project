#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_other, test_alias_0)
{
  run_rulp_script("data/rulp_script_other/test_alias_0.rulp");
}

TEST(rulp_script_other, test_alias_1_var)
{
  run_rulp_script("data/rulp_script_other/test_alias_1_var.rulp");
}

TEST(rulp_script_other, test_alias_2_factor)
{
  run_rulp_script("data/rulp_script_other/test_alias_2_factor.rulp");
}

TEST(rulp_script_other, test_alias_3_macro)
{
  run_rulp_script("data/rulp_script_other/test_alias_3_macro.rulp");
}

TEST(rulp_script_other, test_can_cast_1)
{
  run_rulp_script("data/rulp_script_other/test_can_cast_1.rulp");
}

TEST(rulp_script_other, test_cmp_1)
{
  run_rulp_script("data/rulp_script_other/test_cmp_1.rulp");
}

TEST(rulp_script_other, test_cmp_2_const)
{
  run_rulp_script("data/rulp_script_other/test_cmp_2_const.rulp");
}

TEST(rulp_script_other, test_cmp_3_var)
{
  run_rulp_script("data/rulp_script_other/test_cmp_3_var.rulp");
}

TEST(rulp_script_other, test_cmp_4_member)
{
  run_rulp_script("data/rulp_script_other/test_cmp_4_member.rulp");
}

TEST(rulp_script_other, test_clone_1_obj)
{
  run_rulp_script("data/rulp_script_other/test_clone_1_obj.rulp");
}

TEST(rulp_script_other, test_clone_2_expr)
{
  run_rulp_script("data/rulp_script_other/test_clone_2_expr.rulp");
}

TEST(rulp_script_other, test_clone_3_class)
{
  run_rulp_script("data/rulp_script_other/test_clone_3_class.rulp");
}

TEST(rulp_script_other, test_clone_4_instance)
{
  run_rulp_script("data/rulp_script_other/test_clone_4_instance.rulp");
}

TEST(rulp_script_other, test_clone_5_array)
{
  run_rulp_script("data/rulp_script_other/test_clone_5_array.rulp");
}

TEST(rulp_script_other, test_clone_6_blob)
{
  run_rulp_script("data/rulp_script_other/test_clone_6_blob.rulp");
}

TEST(rulp_script_other, test_name_of_1)
{
  run_rulp_script("data/rulp_script_other/test_name_of_1.rulp");
}

TEST(rulp_script_other, test_type_of_1)
{
  run_rulp_script("data/rulp_script_other/test_type_of_1.rulp");
}

TEST(rulp_script_other, test_value_of_1)
{
  run_rulp_script("data/rulp_script_other/test_value_of_1.rulp");
}

TEST(rulp_script_other, test_value_of_2)
{
  run_rulp_script("data/rulp_script_other/test_value_of_2.rulp");
}

TEST(rulp_script_other, test_value_of_3)
{
  run_rulp_script("data/rulp_script_other/test_value_of_3.rulp");
}

TEST(rulp_script_other, test_value_of_4_frame)
{
  run_rulp_script("data/rulp_script_other/test_value_of_4_frame.rulp");
}

TEST(rulp_script_other, test_value_type_of_1)
{
  run_rulp_script("data/rulp_script_other/test_value_type_of_1.rulp");
}

TEST(rulp_script_other, test_do_when_obj_deleted_1)
{
  // run_rulp_script("data/rulp_script_other/test_do_when_obj_deleted_1.rulp");
}

TEST(rulp_script_other, test_empty_script_1)
{
  run_rulp_script("data/rulp_script_other/test_empty_script_1.rulp");
}
