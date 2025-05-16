#include "rulp/object/IRObject.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/lang/RException.h"
#include "unitest_base.h"
#include "unitest_rulp.h"
#include "help_test.h"
#include "parse/XRParser.h"
#include "lfc/base/to_string.h"

using namespace std;
using namespace lfc;

#define TEST_XRPARSER_1(input_str, expect_size, expect_type, expect_str) \
{ \
  auto context = RulpFactory::createTokenPool(); \
  auto tokener = RulpFactory::createTokener(); \
  tokener->setContext(context); \
  XRParser parser; \
  parser.setContext(context); \
  parser.setTokener(tokener); \
  auto objs = parser.parse(input_str); \
  EXPECT_STREQ(expect_str, TO_STR(objs).c_str()); \
  EXPECT_TRUE(expect_size == objs.size()); \
  for(auto obj : objs) { \
    EXPECT_TRUE(obj->getType() == expect_type); \
  } \
  RULP_FREE(objs); \
  RULP_FREE(tokener); \
  RULP_FREE(context); \
}


TEST(rulp_lang_parser, parse_object_1)
{
  RULP_AUTO_DUMP("data/rulp_lang_parser/parse_object_1_ginfo.txt");

  TEST_XRPARSER_1("true false", 2, T_BOOL, "{true,false}");

  TEST_XRPARSER_1("0", 1, T_INT, "{0}");
  TEST_XRPARSER_1("0 1 -127 128", 4, T_INT, "{0,1,-127,128}");

  TEST_XRPARSER_1("0.000 0.0", 2, T_FLOAT, "{0.0,0.0}");
  TEST_XRPARSER_1("0d 0D", 2, T_DOUBLE, "{0.0D,0.0D}");

  TEST_XRPARSER_1("0L", 1, T_LONG, "{0L}");
  TEST_XRPARSER_1("0L 1L -127L 128L", 4, T_LONG, "{0L,1L,-127L,128L}");

}

#define TEST_XRPARSER_2(input_str, expect_str) \
{ \
  auto context = RulpFactory::createTokenPool(); \
  auto tokener = RulpFactory::createTokener(); \
  tokener->setContext(context); \
  XRParser parser; \
  parser.setContext(context); \
  parser.setTokener(tokener); \
  auto objs = parser.parse(input_str); \
  EXPECT_STREQ(expect_str, TO_STR(objs).c_str()); \
  RULP_FREE(objs); \
  RULP_FREE(tokener); \
  RULP_FREE(context); \
}

TEST(rulp_lang_parser, parse_object_2_gc)
{
  RULP_AUTO_DUMP("data/rulp_lang_parser/parse_object_2_gc_ginfo.txt");

  TEST_XRPARSER_1("'()"     , 1, T_LIST, "{'()}");
  TEST_XRPARSER_1("'(1 2 3)", 1, T_LIST, "{'(1 2 3)}");

  TEST_XRPARSER_1("()"      , 1, T_EXPR, "{()}");
  TEST_XRPARSER_1("(1 2 3)" , 1, T_EXPR, "{(1 2 3)}");

  TEST_XRPARSER_1("$()"     , 1, T_EXPR, "{()}");
  TEST_XRPARSER_1("$(1 2 3)", 1, T_EXPR, "{$(1 2 3)}");
  
  TEST_XRPARSER_2("'(abc 129 0.1 0.1d true)",  "{'(abc 129 0.100000 0.100000D true)}");
  TEST_XRPARSER_2("'('(a) '(123) '(0.1))",  "{'('(a) '(123) '(0.100000))}");
  TEST_XRPARSER_2("'(-128L 129L)",  "{'(-128L 129L)}");
}


static std::string _parse_line(RulpTestBase* test, std::string input) {
  auto rstList = test->getParser()->parse(input);
  return RulpUtil::toString(rstList);
}


TEST(rulp_lang_parser, test_parser_1_special_char)
{ 
  // #TODO
  // RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_1_special_char.txt"
  //                          , [](auto test, auto input){return _parse_line(test, input);}
  //                          );
}

TEST(rulp_lang_parser, test_parser_2_operator)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_2_operator.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_3_number_1)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_3_number_1.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_3_number_2_hex)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_3_number_2_hex.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_4_vars)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_4_vars.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_5_expr)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_5_expr.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_5_list)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_5_list.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_6_comments)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_6_comments.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_7_multi_lines_1)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_7_multi_lines_1.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_7_multi_lines_2)
{ 
  // #TODO
//   RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_7_multi_lines_2.txt"
//                            , [](auto test, auto input){return _parse_line(test, input);}
//                            );
}

TEST(rulp_lang_parser, test_parser_7_multi_lines_3)
{ 
  // #TODO
//   RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_7_multi_lines_3.txt"
//                            , [](auto test, auto input){return _parse_line(test, input);}
//                            );
}

TEST(rulp_lang_parser, test_parser_8_special_escape_string)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_8_special_escape_string.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

static void _test_parse_line(RulpTestBase& test, std::string input, std::string expect) {

  try {
    auto rstList = test.getParser()->parse(input);
    EXPECT_STREQ(expect.c_str(), TO_STR(rstList).c_str());
    RULP_FREE(rstList);
  } 
  catch (RException e) {
    std::cout << e.what() << "\n";
    EXPECT_TRUE(false);
  }
}

TEST(rulp_lang_parser, test_parser_8_special_escape_string_2)
{ 
  RulpTestBase test;
  _test_parse_line(test, "abc\ndef", "{abc,def}");
  _test_parse_line(test, "abc\r\ndef", "{abc,def}");
  _test_parse_line(test, "abc\rdef", "{abcdef}");
}

TEST(rulp_lang_parser, test_parser_8_special_string)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_8_special_string.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_8_special_string_not_support)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_8_special_string_not_support.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_8_special_string2)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_8_special_string2.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_9_error)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_9_error.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_a_namespace)
{ 
  RulpTestBase test;
  test.getParser()->registerPrefix("nm", "https://github.com/to0d/nm#");
  test.run_action( "data/rulp_lang_parser/test_parser_a_namespace.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_b_number_a)
{ 
  RulpTestBase test;
  test.getParser()->setSupportNumber(false);
  test.run_action( "data/rulp_lang_parser/test_parser_b_number_a.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_b_number_b)
{ 
  RulpTestBase test;
  test.run_action( "data/rulp_lang_parser/test_parser_b_number_b.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_c_any)
{ 
  // #TODO
  // RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_c_any.txt"
  //                          , [](auto test, auto input){return _parse_line(test, input);}
  //                          );
}

TEST(rulp_lang_parser, test_parser_d_named)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_d_named.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_e_array)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_e_array.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}

TEST(rulp_lang_parser, test_parser_f_attr)
{ 
  RulpTestBase().run_action( "data/rulp_lang_parser/test_parser_f_attr.txt"
                           , [](auto test, auto input){return _parse_line(test, input);}
                           );
}
