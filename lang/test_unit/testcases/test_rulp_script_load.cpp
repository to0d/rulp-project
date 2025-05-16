#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"

using namespace lfc;

class TestLoader : public IRLoader {
public:
  virtual void load(IRInterpreter* interpreter, IRFrame* frame) override {
    ++load_time;
  }

  int load_time = 0;
};

TEST(rulp_script_load, test_init_loader_1)
{
  TestLoader testLoader;
  RuntimeUtil::registryLoader(&testLoader, "xxx-loader");
  run_rulp_script("data/rulp_script_load/test_init_loader_1.rulp");
  RuntimeUtil::removeLoader("xxx-loader");
  EXPECT_EQ(1, testLoader.load_time);
}


TEST(rulp_script_load, test_load_1)
{
  run_rulp_script("data/rulp_script_load/test_load_1.rulp");
}

TEST(rulp_script_load, test_load_2_load_path)
{
  run_rulp_script("data/rulp_script_load/test_load_2_load_path.rulp");
}

TEST(rulp_script_load, test_load_3)
{
  run_rulp_script("data/rulp_script_load/test_load_3.rulp");
}

TEST(rulp_script_load, test_load_4_short_name)
{
  run_rulp_script("data/rulp_script_load/test_load_4_short_name.rulp");
}

TEST(rulp_script_load, test_load_err_1)
{
  run_rulp_script("data/rulp_script_load/test_load_err_1.rulp");
}