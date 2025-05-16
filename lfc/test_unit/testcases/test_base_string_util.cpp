#include "unitest_base.h"
#include "lfc/base/string/util.h"
#include "lfc/base/function.h"
#include "help_test.h"

using namespace std;
using namespace lfc;

static std::string _test_getCharType(std::string input) {
  std::vector<int> types;
  for(char c  :input){
    types.push_back((int)StringUtil::getCharType(c));
  }
  return lfc::to_string(types);
}

TEST(base_string_util, STR_COMPARE_1)
{
  EXPECT_EQ(0 , STR_COMPARE("a", "a"));
  EXPECT_EQ(-1, STR_COMPARE("a", "b"));
  EXPECT_EQ(1 , STR_COMPARE("b", "a"));
  EXPECT_EQ(-1, STR_COMPARE("a", "xyz"));
  EXPECT_EQ(1 , STR_COMPARE("xyz", "a"));
}

TEST(base_string_util, string_util_get_char_type_1)
{
  _test("data_base/base_string/string_util_get_char_type_1.txt"
    , [](auto input){
      return _test_getCharType(input);
    }
  );
}

TEST(base_string_util, string_util_get_char_type_2)
{
  // #TODO how to support unicode
  _test("data_base/base_string/string_util_get_char_type_2.txt"
    , [](auto input){
      return _test_getCharType(input);
    }
  );
}

TEST(base_string_util, addEscape_1)
{
  EXPECT_STREQ("", StringUtil::addEscape("").c_str());
  EXPECT_STREQ("abc", StringUtil::addEscape("abc").c_str());
  EXPECT_STREQ("a\\\\c", StringUtil::addEscape("a\\c").c_str());
  EXPECT_STREQ("a\\\"c", StringUtil::addEscape("a\"c").c_str());
}

TEST(base_string_util, removeEscape_1)
{
  EXPECT_STREQ(""       , StringUtil::removeEscape("").c_str());
  EXPECT_STREQ(" "      , StringUtil::removeEscape(" ").c_str());
  EXPECT_STREQ(" a "    , StringUtil::removeEscape(" a ").c_str());
  EXPECT_STREQ("a\r\nb" , StringUtil::removeEscape("a\r\nb").c_str());
  EXPECT_STREQ("a\nb"   , StringUtil::removeEscape("a\\nb").c_str());
  EXPECT_STREQ("a\rb"   , StringUtil::removeEscape("a\\rb").c_str());
}

TEST(base_string_util, str_get_empty_head_1)
{
  EXPECT_STREQ("", lfc::str_get_empty_head("abc").c_str());
  EXPECT_STREQ("  ", lfc::str_get_empty_head("  abc").c_str());
  EXPECT_STREQ("\t", lfc::str_get_empty_head("\tabc").c_str());
}

TEST(base_string_util, STR_REPLACE_ALL_1)
{  
  EXPECT_STREQ("axd", TO_STR(STR_REPLACE_ALL("abcd", "bc", "x")).c_str());
  EXPECT_STREQ("axxd", TO_STR(STR_REPLACE_ALL("abcbcd", "bc", "x")).c_str());
  EXPECT_STREQ("axbd", TO_STR(STR_REPLACE_ALL("abbbd", "bb", "x")).c_str());
}

TEST(base_string_util, STR_SPLIT_BY_CHAR_1)
{  
  EXPECT_STREQ("{a,b,c}", TO_STR(STR_SPLIT_BY_CHAR("a|b|c", '|')).c_str());
}

TEST(base_string_util, STR_SPLIT_BY_MULTI_CHAR_1)
{  
  EXPECT_STREQ("{a,b}", TO_STR(STR_SPLIT_BY_MULTI_CHAR(" a*b ", " *")).c_str());
}

TEST(base_string_util, STR_SPLIT_BY_STR_1)
{  
  EXPECT_STREQ("{a,b,c}", TO_STR(STR_SPLIT_BY_STR("a::b::c", "::")).c_str());
}

TEST(base_string_util, str_is_integer_1)
{
  EXPECT_EQ(false,  lfc::str_is_integer("abc"));
  EXPECT_EQ(true,   lfc::str_is_integer("123"));
  EXPECT_EQ(true,   lfc::str_is_integer("+123"));
  EXPECT_EQ(true,   lfc::str_is_integer("-123"));
}

TEST(base_string_util, str_is_float_1)
{
  EXPECT_EQ(false,  lfc::str_is_float("abc"));
  EXPECT_EQ(true,   lfc::str_is_float("123"));
  EXPECT_EQ(true,   lfc::str_is_float("+123"));
  EXPECT_EQ(true,   lfc::str_is_float("-123"));
  EXPECT_EQ(true,   lfc::str_is_float("1.0"));
}

TEST(base_string_util, str_start_With_1)
{
  EXPECT_EQ(true,  lfc::str_start_With("abc", "a"));
  EXPECT_EQ(false, lfc::str_start_With("123", "23"));
}

TEST(base_string_util, str_end_with_1)
{
  EXPECT_EQ(false, lfc::str_end_with("abc", "a"));
  EXPECT_EQ(true,  lfc::str_end_with("123", "23"));
}

TEST(base_string_util, str_trim_1)
{
  EXPECT_STREQ("abc", lfc::str_trim("abc").c_str());
  EXPECT_STREQ("abc", lfc::str_trim(" abc").c_str());
  EXPECT_STREQ("abc", lfc::str_trim("abc ").c_str());
  EXPECT_STREQ("abc", lfc::str_trim(" abc ").c_str());
}

TEST(base_string_util, str_is_empty_1)
{
  EXPECT_EQ(true, lfc::str_is_empty(""));
  EXPECT_EQ(true, lfc::str_is_empty(" "));
  EXPECT_EQ(true, lfc::str_is_empty("\n"));
  EXPECT_EQ(true, lfc::str_is_empty("\r"));
}

TEST(base_string_util, ch_memrchr_1)
{
  EXPECT_STREQ(".z", lfc::ch_memrchr("xx.yy.z", '.', 6));
  EXPECT_STREQ(".yy.z", lfc::ch_memrchr("xx.yy.z", '.', 5));
}

TEST(base_string_util, ch_memrchr_2) 
{
  EXPECT_STREQ(".z",(char*) lfc::ch_memrchr("xx.yy.z", '.', 7));
  EXPECT_STREQ(NULL,(char*) lfc::ch_memrchr(NULL, '.', 7));
  EXPECT_STREQ(".z",(char*) lfc::ch_memrchr("xx.yy.z", '.', 6));
  EXPECT_STREQ(".yy.z",(char*) lfc::ch_memrchr("xx.yy.z", '.', 5));
  EXPECT_STREQ(".yy.z",(char*) lfc::ch_memrchr("xx.yy.z", '.', 4));
  EXPECT_STREQ(".yy.z",(char*) lfc::ch_memrchr("xx.yy.z", '.', 3));
  EXPECT_STREQ(NULL,(char*) lfc::ch_memrchr("xx.yy.z", '.', 2));
  EXPECT_STREQ(NULL,(char*) lfc::ch_memrchr("xx.yy.z", '.', 1));
  EXPECT_STREQ(NULL,(char*) lfc::ch_memrchr("xx.yy.z", '.', 0));
}

TEST(base_string_util, STR_INDEX_OF_1)
{
  EXPECT_EQ(-1, STR_INDEX_OF("abc", '.'));
  EXPECT_EQ(3 , STR_INDEX_OF("abc.x", '.'));
  EXPECT_EQ(3 , STR_INDEX_OF("abc.x.y", '.'));
}

TEST(base_string_util, STR_INDEX_OF_2)
{
  EXPECT_EQ(-1, STR_INDEX_OF("abc", "."));
  EXPECT_EQ(3 , STR_INDEX_OF("abc.x", "."));
  EXPECT_EQ(4 , STR_INDEX_OF("abc.x.y", "x.y"));
}

TEST(base_string_util, STR_LAST_INDEX_OF_1)
{
  EXPECT_EQ(-1, STR_LAST_INDEX_OF("abc", '.'));
  EXPECT_EQ(3 , STR_LAST_INDEX_OF("abc.x", '.'));
  EXPECT_EQ(5 , STR_LAST_INDEX_OF("abc.x.y", '.'));
}

TEST(base_string_util, STR_LAST_INDEX_OF_2)
{
  EXPECT_EQ(-1, STR_LAST_INDEX_OF("abc", "."));
  EXPECT_EQ(3 , STR_LAST_INDEX_OF("abc.x", "."));
  EXPECT_EQ(5 , STR_LAST_INDEX_OF("abc.x.y", "."));
}

TEST(base_string_util, STR_LAST_INDEX_OF_FROM_1)
{
  EXPECT_EQ(3 , STR_LAST_INDEX_OF_FROM("abc.x.y", '.', 4));
}

TEST(base_string_util, STR_LAST_INDEX_OF_FROM_2)
{
  EXPECT_EQ(3 , STR_LAST_INDEX_OF_FROM("abc.x.y", ".", 4));
}

TEST(base_string_util, trimHead_1)
{
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimHead(" abc"  , {' '}).c_str());
  EXPECT_STREQ("abc " , lfc::StringUtil::trimHead(" abc " , {' '}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimHead("  abc" , {' '}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimHead(" |abc" , {' ', '|'}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimHead(" | abc", {' ', '|'}).c_str());
}

TEST(base_string_util, trimTail_1)
{
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimTail("abc "  , {' '}).c_str());
  EXPECT_STREQ(" abc" , lfc::StringUtil::trimTail(" abc " , {' '}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimTail("abc  " , {' '}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimTail("abc |" , {' ', '|'}).c_str());
  EXPECT_STREQ("abc"  , lfc::StringUtil::trimTail("abc | ", {' ', '|'}).c_str());
}

TEST(base_string_util, STR_TO_UPPER_1)
{
  EXPECT_STREQ("ABC"  , STR_TO_UPPER("aBc").c_str());
}


TEST(base_string_util, test_matchFormat_1)
{
  EXPECT_TRUE(STR_MATCH("00000     00420042 0042...*", "00000     00420042 0042.... ........ ........   - .?.?.?..........        "));
}

TEST(base_string_util, test_matchFormat_2)
{
  std::vector<std::string> values;
  EXPECT_TRUE(lfc::StringUtil::matchFormat("%?.ol", "sql_fix_bug_73_usr.ol", values));
  EXPECT_STREQ("{sql_fix_bug_73_usr}"  , TO_STR(values).c_str());
}

TEST(base_string_util, test_matchFormat_3)
{
  // std::vector<std::string> values;
  // EXPECT_TRUE(lfc::StringUtil::matchFormat(" Start Service Job (STRSRVJOB JOB(%?)).*"
  //     , "   Start Service Job (STRSRVJOB JOB(096326/LIUYAN/SEPCB)). Then do Start Debug ", values));
  // EXPECT_STREQ("{096326/LIUYAN/SEPCB}"  , TO_STR(values).c_str());

  // EXPECT_FALSE(lfc::StringUtil::matchFormat("--[DBG][%?]%?;%?", "--[DBG][           @AUTO]@AUTO;"));

  // EXPECT_TRUE(lfc::StringUtil::matchFormat(" %%INCLUDE INCLIB(TEMDCO)*", "  %INCLUDE INCLIB(TEMDCO);"));
}

TEST(base_string_util, test_matchFormat_4)
{
  EXPECT_TRUE(STR_MATCH("Overview of the integrated file system%$", "Overview of the integrated file system"));
  EXPECT_FALSE(STR_MATCH("Overview of the integrated file system%$", "Overview of the integrated file system. . . . . . 2"));
}

TEST(base_string_util, test_matchFormat_5)
{
  // std::vector<std::string> values;
  // EXPECT_TRUE(lfc::StringUtil::matchFormat("*sectorSize*%|* %? *%dx", "sectorSize    |                 512              200x", values));
  // EXPECT_STREQ("{512}"  , TO_STR(values).c_str());
}

TEST(base_string_util, test_matchFormat_6)
{
  // std::vector<std::string> values;
  // EXPECT_TRUE(lfc::StringUtil::matchFormat(" Job %?/%?/%? started on *"
  //     , "      Job 204881/LIUYAN/TESTEST started on 11/22/14 at 21:48:23 in subsystem    ", values));
  // EXPECT_STREQ("{204881/LIUYAN/TESTEST}"  , TO_STR(values).c_str());
}

TEST(base_string_util, test_matchFormat_7)
{
  std::vector<std::string> values;
  
  EXPECT_TRUE(lfc::StringUtil::matchFormat("%?%n%?", "abc\nedf", values));
  EXPECT_STREQ("{abc,edf}"  , TO_STR(values).c_str());

  EXPECT_TRUE(lfc::StringUtil::matchFormat("%?%r%?", "abc\redf", values));
  EXPECT_STREQ("{abc,edf}"  , TO_STR(values).c_str());

  EXPECT_TRUE(lfc::StringUtil::matchFormat("%?%r%n%?", "abc\r\nedf", values));
  EXPECT_STREQ("{abc,edf}"  , TO_STR(values).c_str());
}
