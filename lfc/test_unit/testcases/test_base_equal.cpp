#include "unitest_base.h"
#include "lfc/base/equal.h"
#include "lfc/base/container.h"

using namespace lfc;

TEST(base_equal, equal_string_1)
{
  EXPECT_EQ(true,  lfc::equal(L"",L""));
  EXPECT_EQ(true,  lfc::equal(L"a",L"a"));
  EXPECT_EQ(false, lfc::equal(L"A",L"a"));
  EXPECT_EQ(true,  lfc::equal(L"abc",L"abc"));
  EXPECT_EQ(false, lfc::equal(L"aBc",L"abc"));

  EXPECT_EQ(true,  lfc::equal(L"A",L"a",true));
  EXPECT_EQ(true,  lfc::equal(L"aBc",L"abc",true));

  EXPECT_EQ(false, lfc::equal(L"A",L"a",false));
  EXPECT_EQ(false, lfc::equal(L"aBc",L"abc",false));
}

TEST(base_equal, equal_wstring_1)
{
  EXPECT_EQ(true,  lfc::equal(L"",L""));
  EXPECT_EQ(true,  lfc::equal(L"a",L"a"));
  EXPECT_EQ(false, lfc::equal(L"A",L"a"));
  EXPECT_EQ(true,  lfc::equal(L"abc",L"abc"));
  EXPECT_EQ(false, lfc::equal(L"aBc",L"abc"));

  EXPECT_EQ(true,  lfc::equal(L"A",L"a",true));
  EXPECT_EQ(true,  lfc::equal(L"aBc",L"abc",true));

  EXPECT_EQ(false, lfc::equal(L"A",L"a",false));
  EXPECT_EQ(false, lfc::equal(L"aBc",L"abc",false));
}

TEST(base_equal, equal_vector_1)
{
  EXPECT_EQ(true ,  lfc::equal(std::vector<int>({1,2}), std::vector<int>({1,2})));
  EXPECT_EQ(false,  lfc::equal(std::vector<int>({1,2}), std::vector<int>({2,1})));
  EXPECT_EQ(false,  lfc::equal(std::vector<int>({1,2}), std::vector<int>({1,2,3})));

  EXPECT_EQ(true ,  lfc::equal(std::vector<std::string>({"a","b"}), std::vector<std::string>({"a","b"})));
}

TEST(base_equal, equal_set_1)
{
  auto a = lfc::to_set(lfc::to_vector({"a", "b"}));
  auto b = lfc::to_set(lfc::to_vector({"b", "c"}));
  auto c = lfc::to_set(lfc::to_vector({"a", "b", "c"}));
  auto d = lfc::to_set(lfc::to_vector({"b", "a"}));

  EXPECT_EQ(false ,  lfc::equal(a, b));
  EXPECT_EQ(false ,  lfc::equal(a, c));
  EXPECT_EQ(true  ,  lfc::equal(a, d));
}