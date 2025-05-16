#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_runtime, test_compute_1)
{
  run_rulp_script("data/rulp_script_runtime/test_compute_1.rulp");
}

TEST(rulp_script_runtime, test_frame_of_1)
{
  run_rulp_script("data/rulp_script_runtime/test_frame_of_1.rulp");
}

TEST(rulp_script_runtime, test_system_frame_1)
{
  {
    RulpTestBase test;
    auto interpreter = test.getInterpreter();
    auto system_frame = SYSTEM_FRAME(interpreter);

    auto obj1 = system_frame->findLocalObject("?load-script");
    EXPECT_TRUE(obj1 != NULL);
  }
}

TEST(rulp_script_runtime, test_search_frame_of_1)
{
  run_rulp_script("data/rulp_script_runtime/test_search_frame_of_1.rulp");
}

TEST(rulp_script_runtime, test_runtime_call_count_1_fun)
{
  run_rulp_script("data/rulp_script_runtime/test_runtime_call_count_1_fun.rulp");
}

TEST(rulp_script_runtime, test_run_1)
{
  // run_rulp_script("data/rulp_script_runtime/test_run_1.rulp");
}

TEST(rulp_script_runtime, test_run_2)
{
  // run_rulp_script("data/rulp_script_runtime/test_run_2.rulp");
}