#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_namespace, test_namespace_1)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_1.rulp");
}

TEST(rulp_script_namespace, test_namespace_2)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_2.rulp");
}

TEST(rulp_script_namespace, test_namespace_3)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_3.rulp");
}

TEST(rulp_script_namespace, test_namespace_4)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_4.rulp");
}

TEST(rulp_script_namespace, test_namespace_5_err_duplicate_ns)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_5_err_duplicate_ns.rulp");
}

TEST(rulp_script_namespace, test_namespace_6_nested_1)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_6_nested_1.rulp");
}

TEST(rulp_script_namespace, test_namespace_6_nested_2)
{
  run_rulp_script("data/rulp_script_namespace/test_namespace_6_nested_2.rulp");
}
