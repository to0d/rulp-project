#include "unitest_base.h"
#include "unitest_rulp.h"
#include "rulp/utils/RulpFactory.h"
#include "runtime/XRTokenPool.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_RulpFactory, createContext_1)
{
  auto RC = RulpFactory::createTokenPool();
  EXPECT_TRUE(RC != NULL);
  RULP_FREE(RC);
}

TEST(rulp_utils_RulpFactory, createTokener_1)
{
  auto TK = RulpFactory::createTokener();
  EXPECT_TRUE(TK != NULL);
  RULP_FREE(TK);
}

TEST(rulp_utils_RulpFactory, createParser_1)
{
  auto parser = RulpFactory::createParser();
  EXPECT_TRUE(parser != NULL);
  RULP_FREE(parser);
}

#define TEST_FACTORY_CREATE_GLOBAL_OBJECT(expr, str) {\
  auto obj = expr; \
  EXPECT_TRUE(obj != NULL); \
  EXPECT_TRUE(IS_GLOBAL_OBJECT(obj)); \
  EXPECT_STREQ(str, lfc::to_string(obj).c_str()); \
  RULP_FREE(obj);}

#define TEST_FACTORY_CREATE_NEW_OBJECT(expr, str) {\
  auto obj = (expr); \
  EXPECT_TRUE(obj != NULL); \
  EXPECT_FALSE(IS_GLOBAL_OBJECT(obj)); \
  EXPECT_STREQ(str, lfc::to_string(obj).c_str()); \
  RULP_FREE(obj);}


TEST(rulp_utils_RulpFactory, create_1_global)
{
  RULP_AUTO_DUMP("data/rulp_lang_utils/factory_create_1_global_ginfo.txt");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createAtom("nil"), "nil");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createList(), "'()");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createExpression(), "()");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createExpressionEarly({}), "()");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createInteger(0), "0");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createInteger(128), "128");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createInteger(-127), "-127");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createLong(0), "0L");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createLong(128), "128L");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createLong(-127), "-127L");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createFloat(0), "0.0");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createDouble(0), "0.0D");
  TEST_FACTORY_CREATE_GLOBAL_OBJECT(RulpFactory::createString(""), "");
}

TEST(rulp_utils_RulpFactory, create_1_new)
{
  RULP_AUTO_DUMP("data/rulp_lang_utils/factory_create_1_new_ginfo.txt");
  auto context = RulpFactory::createTokenPool();
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createAtom("abc"), "abc");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createAtom(context->createRName("ns", "pre", "sub", "full1")), "full1");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createList({O_Nil, O_Nil}), "'(nil nil)");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createExpression({O_Nil, O_Nil}), "(nil nil)");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createExpressionEarly({O_Nil, O_Nil}), "$(nil nil)");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createInteger(129), "129");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createInteger(-128), "-128");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createLong(129), "129L");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createLong(-128), "-128L");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createFloat(1), "1.000000");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createFloat(-1), "-1.000000");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createDouble(1), "1.000000D");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createDouble(-1), "-1.000000D");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createString("xyz"), "xyz");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createMember(O_Nil, "xyz", O_Nil), "nil::xyz");
  TEST_FACTORY_CREATE_NEW_OBJECT(RulpFactory::createVar("var1"), "var1:\"nil\"");
  RULP_FREE(context);
}



