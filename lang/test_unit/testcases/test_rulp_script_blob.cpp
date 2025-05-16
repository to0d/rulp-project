#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

TEST(rulp_script_blob, test_make_blob_1)
{
  run_rulp_script("data/rulp_script_blob/test_make_blob_1.rulp");
}

TEST(rulp_script_blob, test_make_blob_2)
{
  run_rulp_script("data/rulp_script_blob/test_make_blob_2.rulp");
}

TEST(rulp_script_blob, test_write_blob_1)
{
  run_rulp_script("data/rulp_script_blob/test_write_blob_1.rulp");
}

TEST(rulp_script_blob, test_to_blob_1)
{
  run_rulp_script("data/rulp_script_blob/test_to_blob_1.rulp");
}
