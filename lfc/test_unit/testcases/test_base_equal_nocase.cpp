#include "unitest_base.h"
#include "lfc/base/equal.h"

using namespace lfc;


TEST(base_equal, equal_nocase_1)
{
  std::string s1 ("Test Str");
  std::string s2 ("Test str");
  std::string s3 ("Test str nor");
  std::string s4 ("Test atr");

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(false, lfc::equal_nocase(s1,s3));
  EXPECT_EQ(false, lfc::equal_nocase(s1,s4));
}

TEST(base_equal, equal_nocase_2)
{
	std::wstring s1 (L"Test Str");
	std::wstring s2 (L"Test str");
	std::wstring s3 (L"Test str nor");
	std::wstring s4 (L"Test atr");

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(false, lfc::equal_nocase(s1,s3));
  EXPECT_EQ(false, lfc::equal_nocase(s1,s4));
}

TEST(base_equal, equal_nocase_3)
{
	std::string s1 ("abc");
  char s2 []  = "ABC";

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(true , lfc::equal_nocase(s2,s1));
}

TEST(base_equal, equal_nocase_4)
{
	std::wstring s1 (L"abc");
  wchar_t s2 []  = L"ABC";

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(true , lfc::equal_nocase(s2,s1));
}

TEST(base_equal, equal_nocase_5)
{
	std::string s1 ("abc");
  const char s2 []  = "ABC";

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(true , lfc::equal_nocase(s2,s1));
}

TEST(base_equal, equal_nocase_6)
{
	std::wstring s1 (L"abc");
  const wchar_t s2 []  = L"ABC";

  EXPECT_EQ(true , lfc::equal_nocase(s1,s2));
  EXPECT_EQ(true , lfc::equal_nocase(s2,s1));
}
