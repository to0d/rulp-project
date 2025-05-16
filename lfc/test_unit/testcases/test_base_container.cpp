#include "unitest_base.h"
#include "lfc/base/equal.h"
#include "lfc/base/container.h"
#include "lfc/base/to_string.h"

using namespace lfc;


TEST(base_container, remove_first_of_1)
{ 
  std::vector<std::string> vec = {"a", "b", "c"};
  std::string a = "a";

  EXPECT_EQ( 0, lfc::erase_first_of(vec, a));
  EXPECT_STREQ("{b,c}", TO_STR(vec).c_str());

  EXPECT_EQ(-1, lfc::erase_first_of(vec, a));
  EXPECT_STREQ("{b,c}", TO_STR(vec).c_str());
}

TEST(base_container, copy_to_vector_1)
{ 
  std::vector<std::string> a = {"a", "b", "c"};
  std::vector<std::string> b = {"d"};
  
  copy_to(a, b);
  EXPECT_STREQ("{d,a,b,c}", TO_STR(b).c_str());

}

TEST(base_container, copy_to_map_1)
{ 
  std::map<std::string, int> a;
  a["a"] = 1;
  a["b"] = 2;
  a["c"] = 3;
  
  std::map<std::string, int> b;
  b["a"] = 3;
  b["d"] = 4;

  copy_to(a, b);
  EXPECT_STREQ("{a=1,b=2,c=3,d=4}", TO_STR(b).c_str());
}

TEST(base_container, find_1)
{
  std::vector<std::string> vec = {"a", "b", "c"};
  std::string a = "a";
  EXPECT_TRUE(find(vec, a));
}

TEST(base_container, find_2)
{
  std::vector<std::string> vec = {"a", "b", "c"};
  std::set<std::string> set = to_set(vec);
  std::string a = "a";
  EXPECT_TRUE(find(set, a));
}

TEST(base_container, to_vector_1)
{ 
  EXPECT_STREQ("{a,b,c}", TO_STR(lfc::to_vector({"a", "b", "c"})).c_str());
}

TEST(base_container, to_vector_2)
{
  EXPECT_STREQ("{1,2,3}", TO_STR(lfc::to_vector({1, 2, 3})).c_str());
}

TEST(base_container, to_vector_3)
{
  auto set = lfc::to_set(lfc::to_vector({"a", "b", "c"}));
  auto vec = lfc::to_vector(set);
  std::sort(vec.begin(), vec.end(), std::less<>());
  EXPECT_STREQ("{c,b,a}", TO_STR(vec).c_str());
}


TEST(base_container, to_set_1)
{
  EXPECT_STREQ("[c,b,a]", TO_STR(lfc::to_set(lfc::to_vector({"a", "b", "c"}))).c_str());
}

TEST(base_container, add_all_1)
{
  auto a = lfc::to_set(lfc::to_vector({"a", "b"}));
  auto b = lfc::to_set(lfc::to_vector({"b", "c"}));

  EXPECT_STREQ("1", TO_STR(lfc::add_all(a, b)).c_str());
  EXPECT_STREQ("[c,b,a]", TO_STR(a).c_str());
}

TEST(base_container, resize_to_1)
{
  std::vector<std::string> a = {"a", "b", "c"};

  EXPECT_STREQ("{a}", TO_STR(lfc::resize_to(a, 1)).c_str());
  EXPECT_STREQ("{a,b,c}", TO_STR(lfc::resize_to(a, 3)).c_str());
  EXPECT_STREQ("{a,b,c,,}", TO_STR(lfc::resize_to(a, 5)).c_str());

}

TEST(base_container, CT_RETAIN_ALL_1)
{
  auto a = CT_TO_SET(CT_TO_VECTOR({"a", "b"}));
  auto b = CT_TO_SET(CT_TO_VECTOR({"b", "c"}));
  CT_RETAIN_ALL(a, b);
  EXPECT_STREQ("{b}", TO_STR(CT_TO_VECTOR(a)).c_str());
}

TEST(base_container, CT_RETAIN_ALL_2)
{
  std::map<std::string, int> a;
  a["a"] = 1;
  a["c"] = 3;
  
  std::map<std::string, int> b;
  b["a"] = 3;
  b["d"] = 4;

  CT_RETAIN_ALL(a, b);
  EXPECT_STREQ("{a=1}", TO_STR(a).c_str());
}
