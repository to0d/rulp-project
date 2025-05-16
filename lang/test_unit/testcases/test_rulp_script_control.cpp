#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"
#include "rulp/runtime/AbsAtomFactorAdapter.h"
#include "rulp/utils/RulpFactory.h"

using namespace lfc;

TEST(rulp_script_control, test_case_1)
{
  run_rulp_script("data/rulp_script_control/test_case_1.rulp");
}

TEST(rulp_script_control, test_case_2)
{
  run_rulp_script("data/rulp_script_control/test_case_2.rulp");
}

TEST(rulp_script_control, test_do_1)
{
  run_rulp_script("data/rulp_script_control/test_do_1.rulp");
}

TEST(rulp_script_control, test_do_2)
{
  run_rulp_script("data/rulp_script_control/test_do_2.rulp");
}

TEST(rulp_script_control, test_foreach_1)
{
  run_rulp_script("data/rulp_script_control/test_foreach_1.rulp");
}

TEST(rulp_script_control, test_foreach_2_from_fun)
{
  run_rulp_script("data/rulp_script_control/test_foreach_2_from_fun.rulp");
}

TEST(rulp_script_control, test_foreach_3_defvar)
{
  run_rulp_script("data/rulp_script_control/test_foreach_3_defvar.rulp");
}

TEST(rulp_script_control, test_foreach_4_array)
{
  run_rulp_script("data/rulp_script_control/test_foreach_4_array.rulp");
}

TEST(rulp_script_control, test_if_1)
{
  run_rulp_script("data/rulp_script_control/test_if_1.rulp");
}

TEST(rulp_script_control, test_if_2)
{
  run_rulp_script("data/rulp_script_control/test_if_2.rulp");
}

TEST(rulp_script_control, test_if_3)
{
  run_rulp_script("data/rulp_script_control/test_if_3.rulp");
}

TEST(rulp_script_control, test_if_4)
{
  run_rulp_script("data/rulp_script_control/test_if_4.rulp");
}

TEST(rulp_script_control, test_if_5_then)
{
  run_rulp_script("data/rulp_script_control/test_if_5_then.rulp");
}

TEST(rulp_script_control, test_loop_1)
{
  run_rulp_script("data/rulp_script_control/test_loop_1.rulp");
}

TEST(rulp_script_control, test_loop_2_continue_1)
{
  run_rulp_script("data/rulp_script_control/test_loop_2_continue_1.rulp");
}

TEST(rulp_script_control, test_loop_2_continue_2)
{
  run_rulp_script("data/rulp_script_control/test_loop_2_continue_2.rulp");
}

TEST(rulp_script_control, test_loop_3_break)
{
  run_rulp_script("data/rulp_script_control/test_loop_3_break.rulp");
}

TEST(rulp_script_control, test_loop_4_err_1)
{
  run_rulp_script("data/rulp_script_control/test_loop_4_err_1.rulp");
}

TEST(rulp_script_control, test_loop_5_return)
{
  run_rulp_script("data/rulp_script_control/test_loop_5_return.rulp");
}

TEST(rulp_script_control, test_loop_6_by)
{
  run_rulp_script("data/rulp_script_control/test_loop_6_by.rulp");
}

TEST(rulp_script_control, test_try_1_default)
{
  run_rulp_script("data/rulp_script_control/test_try_1_default.rulp");
}

TEST(rulp_script_control, test_try_2_user_define)
{
  run_rulp_script("data/rulp_script_control/test_try_2_user_define.rulp");
}

TEST(rulp_script_control, test_try_3_unhandle)
{
  run_rulp_script("data/rulp_script_control/test_try_3_unhandle.rulp");
}

class BadFactor 
  : public AbsAtomFactorAdapter
{

public:
  BadFactor() : AbsAtomFactorAdapter("bad_factor"){};

  virtual ~BadFactor() = default;

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override {
    return RulpUtil::throw_error(interpreter, frame, RulpFactory::createAtom("e1"), O_Nil, this);
  }
};

TEST(rulp_script_control, test_try_4_native_exception)
{
  // why this works in lab-238 2024/04/20
  
  // run_rulp_script("data/rulp_script_control/test_try_4_native_exception.rulp", [](auto interpreter){
  //   RuntimeUtil::addFrameObject(MAIN_FRAME(interpreter), new BadFactor());
  // });
}

TEST(rulp_script_control, test_try_5_try_return)
{
  run_rulp_script("data/rulp_script_control/test_try_5_try_return.rulp");
}