#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_macro, test_defmacro_1)
{
  run_rulp_script("data/rulp_script_macro/test_defmacro_1.rulp");
}

TEST(rulp_script_macro, test_defmacro_2)
{
  run_rulp_script("data/rulp_script_macro/test_defmacro_2.rulp");
}

TEST(rulp_script_macro, test_defmacro_3_iterator)
{
  run_rulp_script("data/rulp_script_macro/test_defmacro_3_iterator.rulp");
}

TEST(rulp_script_macro, test_defmacro_4_multi_body_expr)
{
  run_rulp_script("data/rulp_script_macro/test_defmacro_4_multi_body_expr.rulp");
}