#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_class, test_class_1)
{
  run_rulp_script("data/rulp_script_class/test_class_1.rulp");
}

TEST(rulp_script_class, test_class_1_auto_delete)
{
  run_rulp_script("data/rulp_script_class/test_class_1_auto_delete.rulp");
}

TEST(rulp_script_class, test_class_1_delete)
{
  run_rulp_script("data/rulp_script_class/test_class_1_delete.rulp");
}

TEST(rulp_script_class, test_class_2_def_outside)
{
  run_rulp_script("data/rulp_script_class/test_class_2_def_outside.rulp");
}

TEST(rulp_script_class, test_class_3_access_control)
{
  run_rulp_script("data/rulp_script_class/test_class_3_access_control.rulp");
}

TEST(rulp_script_class, test_class_4_final)
{
  run_rulp_script("data/rulp_script_class/test_class_4_final.rulp");
}

TEST(rulp_script_class, test_class_5_static)
{
  run_rulp_script("data/rulp_script_class/test_class_5_static.rulp");
}

TEST(rulp_script_class, test_class_6_super_1)
{
  run_rulp_script("data/rulp_script_class/test_class_6_super_1.rulp");
}

TEST(rulp_script_class, test_class_6_super_2_inherit_init)
{
  run_rulp_script("data/rulp_script_class/test_class_6_super_2_inherit_init.rulp");
}

TEST(rulp_script_class, test_class_6_super_3)
{
  run_rulp_script("data/rulp_script_class/test_class_6_super_3.rulp");
}

TEST(rulp_script_class, test_class_7_overload_1)
{
  run_rulp_script("data/rulp_script_class/test_class_7_overload_1.rulp");
}

TEST(rulp_script_class, test_class_7_overload_2)
{
  run_rulp_script("data/rulp_script_class/test_class_7_overload_2.rulp");
}

TEST(rulp_script_class, test_class_7_overload_3_static_fun)
{
  run_rulp_script("data/rulp_script_class/test_class_7_overload_3_static_fun.rulp");
}

TEST(rulp_script_class, test_class_7_overload_4_same_name_fun)
{
  run_rulp_script("data/rulp_script_class/test_class_7_overload_4_same_name_fun.rulp");
}

TEST(rulp_script_class, test_class_8_init_1)
{
  run_rulp_script("data/rulp_script_class/test_class_8_init_1.rulp");
}

TEST(rulp_script_class, test_class_8_init_2)
{
  run_rulp_script("data/rulp_script_class/test_class_8_init_2.rulp");
}

TEST(rulp_script_class, test_class_9_delete_1)
{
  run_rulp_script("data/rulp_script_class/test_class_9_delete_1.rulp");
}

TEST(rulp_script_class, test_class_9_delete_2)
{
  run_rulp_script("data/rulp_script_class/test_class_9_delete_2.rulp");
}

TEST(rulp_script_class, test_class_b_bad_para)
{
  run_rulp_script("data/rulp_script_class/test_class_b_bad_para.rulp");
}

TEST(rulp_script_class, test_class_c_mbr_1)
{
  run_rulp_script("data/rulp_script_class/test_class_c_mbr_1.rulp");
}

TEST(rulp_script_class, test_class_c_mbr_2_const_var)
{
  run_rulp_script("data/rulp_script_class/test_class_c_mbr_2_const_var.rulp");
}

TEST(rulp_script_class, test_class_d_same_name)
{
  run_rulp_script("data/rulp_script_class/test_class_d_same_name.rulp");
}

TEST(rulp_script_class, test_class_e_polymorphism)
{
  run_rulp_script("data/rulp_script_class/test_class_e_polymorphism.rulp");
}

TEST(rulp_script_class, test_class_f_recursion)
{
  run_rulp_script("data/rulp_script_class/test_class_f_recursion.rulp");
}

TEST(rulp_script_class, test_has_member_1)
{
  run_rulp_script("data/rulp_script_class/test_has_member_1.rulp");
}

TEST(rulp_script_class, test_new_1_err_duplicate_obj)
{
  run_rulp_script("data/rulp_script_class/test_new_1_err_duplicate_obj.rulp");
}

TEST(rulp_script_class, test_new_2_no_instance_name)
{
  run_rulp_script("data/rulp_script_class/test_new_2_no_instance_name.rulp");
}



