#include "unitest_base.h"
#include "parse/XRTokener.h"
#include "rulp/utils/RulpFactory.h"
#include "lfc/base/auto/auto_free.h"
#include "help_test.h"

using namespace std;
using namespace lfc;

static void _test_char_type(std::string input, std::string expect) {
  std::string out;
  for(char c  :input){
    out += lfc::to_string(XRTokener::getCharType(c));
  }
 
  EXPECT_STREQ(expect.c_str(), out.c_str());
}

TEST(rulp_lang_parser, test_get_char_type_1)
{
  _test_char_type("哈利·托特达夫", "-1-1-1-1-1-1-16-1-1-1-1-1-1-1-1-1-1-1-1"); // #TODO support uniq code
  _test_char_type("abc123\'\"  %?\n\r", "00011163226677");
  _test_char_type("~", "0"); 
}

static std::string _run_tokener(std::string input) {
  auto context = RulpFactory::createTokenPool();
  RULP_AUTO_FREE(context);
  XRTokener tokener;
  tokener.setContext(context);
  tokener.setContent(input);
    Token* token = NULL;
    std::vector<std::string> outs;
    while ((token = tokener.next()) != NULL) {
      outs.push_back(lfc::to_string(token));
    }
  return lfc::to_string(outs);
}


static std::string _run_tokener_not_strict(std::string input) {
  auto context = RulpFactory::createTokenPool();
  RULP_AUTO_FREE(context);
  XRTokener tokener;
  tokener.setContext(context);
  tokener.set_strict_mode(false);
  tokener.setContent(input);
    Token* token = NULL;
    std::vector<std::string> outs;
    while ((token = tokener.next()) != NULL) {
      outs.push_back(lfc::to_string(token));
    }
  return lfc::to_string(outs);
}

static void _test_tokener(std::string path) {
  _test(path
    , [&](auto input){
        return _run_tokener(input);
    }
  );

}

TEST(rulp_lang_parser, test_token_1)
{
  EXPECT_STREQ( "{TK(type=N, value=a, line=-1, pos=1),TK(type=X, value= , line=-1, pos=2),TK(type=N, value=b, line=-1, pos=3)}"
              , _run_tokener("a b").c_str());
}

TEST(rulp_lang_parser, test_token_2)
{
  _test_tokener("data/rulp_lang_parser/test_token_2.txt");
}

// #TODO support unicode char
// TEST(rulp_lang_parser, test_token_3_cn) 
// {
//   _test_tokener("data/rulp_lang_parser/test_token_3_cn.txt");
// }

TEST(rulp_lang_parser, test_token_4_strict)
{
  _test_tokener("data/rulp_lang_parser/test_token_4_strict.txt");
}

TEST(rulp_lang_parser, test_token_5_not_strict)
{
  // #TODO
  // old code:
  //    _test_token_not_strict("\")", "[N:1:0:1:\"]; [S:1:0:2:)];");
  EXPECT_STREQ( "{TK(type=B, value=\"), line=-1, pos=2)}"
              , _run_tokener("\")").c_str());
  EXPECT_STREQ( "{TK(type=S, value=(, line=-1, pos=1),TK(type=N, value=PU, line=-1, pos=3),TK(type=X, value= , line=-1, pos=4),TK(type=B, value=\"), line=-1, pos=6)}"
              , _run_tokener("(PU \")").c_str());
}

TEST(rulp_lang_parser, test_token_6_array)
{
  _test_tokener("data/rulp_lang_parser/test_token_6_array.txt");
}

TEST(rulp_lang_parser, test_token_7_operator)
{
  _test_tokener("data/rulp_lang_parser/test_token_7_operator.txt");
}

TEST(rulp_lang_parser, test_token_8_escape)
{
  _test_tokener("data/rulp_lang_parser/test_token_8_escape.txt");
}

TEST(rulp_lang_parser, test_token_9_attr)
{
  _test_tokener("data/rulp_lang_parser/test_token_9_attr.txt");
}

