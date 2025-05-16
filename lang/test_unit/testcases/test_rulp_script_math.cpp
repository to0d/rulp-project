#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_math, test_arithmetic_1_add_1)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_1_add_1.rulp");
}

TEST(rulp_script_math, test_arithmetic_1_add_2_str)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_1_add_2_str.rulp");
}

TEST(rulp_script_math, test_arithmetic_1_add_3_class)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_1_add_3_class.rulp");
}

TEST(rulp_script_math, test_arithmetic_2_sub)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_2_sub.rulp");
}

TEST(rulp_script_math, test_arithmetic_3_by_1)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_3_by_1.rulp");
}

TEST(rulp_script_math, test_arithmetic_3_by_2)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_3_by_2.rulp");
}

TEST(rulp_script_math, test_arithmetic_4_div_1)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_4_div_1.rulp");
}

TEST(rulp_script_math, test_arithmetic_4_div_2)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_4_div_2.rulp");
}

TEST(rulp_script_math, test_arithmetic_5_mod_1)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_5_mod_1.rulp");
}

TEST(rulp_script_math, test_arithmetic_5_mod_2)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_5_mod_2.rulp");
}

TEST(rulp_script_math, test_arithmetic_6_power_1)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_6_power_1.rulp");
}

TEST(rulp_script_math, test_arithmetic_6_power_2)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_6_power_2.rulp");
}

TEST(rulp_script_math, test_arithmetic_7_and)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_7_and.rulp");
}

TEST(rulp_script_math, test_arithmetic_8_or)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_8_or.rulp");
}

TEST(rulp_script_math, test_arithmetic_9_xor)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_9_xor.rulp");
}

TEST(rulp_script_math, test_arithmetic_a_not)
{
  run_rulp_script("data/rulp_script_math/test_arithmetic_a_not.rulp");
}

TEST(rulp_script_math, test_comparison_1_number)
{
  run_rulp_script("data/rulp_script_math/test_comparison_1_number.rulp");
}

TEST(rulp_script_math, test_random_1)
{
  run_rulp_script("data/rulp_script_math/test_random_1.rulp");
}

TEST(rulp_script_math, test_random_int_1)
{
  run_rulp_script("data/rulp_script_math/test_random_int_1.rulp");
}

TEST(rulp_script_math, test_random_float_1)
{
  run_rulp_script("data/rulp_script_math/test_random_float_1.rulp");
}

TEST(rulp_script_math, test_to_double_1)
{
  run_rulp_script("data/rulp_script_math/test_to_double_1.rulp");
}

TEST(rulp_script_math, test_to_float_1)
{
  run_rulp_script("data/rulp_script_math/test_to_float_1.rulp");
}

TEST(rulp_script_math, test_to_int_1)
{
  run_rulp_script("data/rulp_script_math/test_to_int_1.rulp");
}

TEST(rulp_script_math, test_to_long_1)
{
  run_rulp_script("data/rulp_script_math/test_to_long_1.rulp");
}
