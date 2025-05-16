#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_load_queue, test_queue_1)
{
  run_rulp_script("data/rulp_load_queue/test_queue_1.rulp");
}

TEST(rulp_load_queue, test_queue_2)
{
  run_rulp_script("data/rulp_load_queue/test_queue_2.rulp");
}

TEST(rulp_load_queue, test_queue_3)
{
  run_rulp_script("data/rulp_load_queue/test_queue_3.rulp");
}

TEST(rulp_load_queue, test_queue_4_ls)
{
  run_rulp_script("data/rulp_load_queue/test_queue_4_ls.rulp");
}

TEST(rulp_load_queue, test_queue_5_final)
{
  run_rulp_script("data/rulp_load_queue/test_queue_5_final.rulp");
}

TEST(rulp_load_queue, test_queue_6_property)
{
  run_rulp_script("data/rulp_load_queue/test_queue_6_property.rulp");
}

TEST(rulp_load_queue, test_queue_7_push_fun_obj)
{
  run_rulp_script("data/rulp_load_queue/test_queue_7_push_fun_obj.rulp");
}

TEST(rulp_load_queue, test_queue_8_no_name_queue)
{
  run_rulp_script("data/rulp_load_queue/test_queue_8_no_name_queue.rulp");
}
