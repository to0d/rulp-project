#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"
#include "rulp/utils/RulpFactory.h"

using namespace lfc;

IRObject* f1(IRList* _args, IRInterpreter* _interpreter, IRFrame* _frame) {
  return RulpFactory::createAtom("A" + _args->get(2)->asString());
}

IRObject* f2(IRList* _args, IRInterpreter* _interpreter, IRFrame* _frame) {
  return RulpFactory::createAtom("B" + _args->get(2)->asString());
}

TEST(rulp_script_template, test_template_1)
{
  run_rulp_script("data/rulp_script_template/test_template_1.rulp", [](auto interpreter){
    RuntimeUtil::addTemplate(MAIN_FRAME(interpreter), "f1",
      RulpFactory::createFactor( "f1", f1, false), 3, {"a"});

    RuntimeUtil::addTemplate(MAIN_FRAME(interpreter), "f1", 
      RulpFactory::createFactor( "f1", f2, false), 3, {"b"});
  });
}

TEST(rulp_script_template, test_deftemplate_1)
{
  run_rulp_script("data/rulp_script_template/test_deftemplate_1.rulp");
}

TEST(rulp_script_template, test_deftemplate_2_mbr)
{
  run_rulp_script("data/rulp_script_template/test_deftemplate_2_mbr.rulp");
}

TEST(rulp_script_template, test_deftemplate_3_scope_a)
{
  run_rulp_script("data/rulp_script_template/test_deftemplate_3_scope_a.rulp");
}

TEST(rulp_script_template, test_deftemplate_4_ns)
{
  run_rulp_script("data/rulp_script_template/test_deftemplate_4_ns.rulp");
}

TEST(rulp_script_template, test_deftemplate_5_overwrite_1)
{
  run_rulp_script("data/rulp_script_template/test_deftemplate_5_overwrite_1.rulp");
}
