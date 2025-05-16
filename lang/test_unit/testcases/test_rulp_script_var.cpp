#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_var, test_defconst_1)
{
  run_rulp_script("data/rulp_script_var/test_defconst_1.rulp");
}

TEST(rulp_script_var, test_defconst_2)
{
  run_rulp_script("data/rulp_script_var/test_defconst_2.rulp");
}

TEST(rulp_script_var, test_defconst_3)
{
  run_rulp_script("data/rulp_script_var/test_defconst_3.rulp");
}

TEST(rulp_script_var, test_defvar_1)
{
  run_rulp_script("data/rulp_script_var/test_defvar_1.rulp");
}

TEST(rulp_script_var, test_defvar_2_redefine)
{
  run_rulp_script("data/rulp_script_var/test_defvar_2_redefine.rulp");
}

TEST(rulp_script_var, test_defvar_3_override)
{
  run_rulp_script("data/rulp_script_var/test_defvar_3_override.rulp");
}

TEST(rulp_script_var, test_do_when_var_changed_1)
{
  run_rulp_script("data/rulp_script_var/test_do_when_var_changed_1.rulp");
}

TEST(rulp_script_var, test_ref_1)
{
  run_rulp_script("data/rulp_script_var/test_ref_1.rulp");
}

TEST(rulp_script_var, test_ref_1_return_1)
{
  run_rulp_script("data/rulp_script_var/test_ref_1_return_1.rulp");
}

TEST(rulp_script_var, test_ref_2_loop_1)
{
  run_rulp_script("data/rulp_script_var/test_ref_2_loop_1.rulp");
}

TEST(rulp_script_var, test_ref_2_loop_2)
{
  run_rulp_script("data/rulp_script_var/test_ref_2_loop_2.rulp");
}

TEST(rulp_script_var, test_ref_3_foreach_1)
{
  run_rulp_script("data/rulp_script_var/test_ref_3_foreach_1.rulp");
}

TEST(rulp_script_var, test_setq_1)
{
  run_rulp_script("data/rulp_script_var/test_setq_1.rulp");
}

TEST(rulp_script_var, test_setq_2_err_1)
{
  run_rulp_script("data/rulp_script_var/test_setq_2_err_1.rulp");
}

TEST(rulp_script_var, test_delete_1_remove_var)
{
  run_rulp_script("data/rulp_script_var/test_delete_1_remove_var.rulp");
}

TEST(rulp_script_var, test_delete_2_in_macro_do_body)
{
  run_rulp_script("data/rulp_script_var/test_delete_2_in_macro_do_body.rulp");
}

TEST(rulp_script_var, test_let_1)
{
  run_rulp_script("data/rulp_script_var/test_let_1.rulp");
}

TEST(rulp_script_var, test_let_2)
{
  run_rulp_script("data/rulp_script_var/test_let_2.rulp");
}

TEST(rulp_script_var, test_let_3)
{
  // run_rulp_script("data/rulp_script_var/test_let_3.rulp");
}

TEST(rulp_script_var, test_to_const_1)
{
  run_rulp_script("data/rulp_script_var/test_to_const_1.rulp");
}

TEST(rulp_script_var, test_to_const_2)
{
  run_rulp_script("data/rulp_script_var/test_to_const_2.rulp");
}

