#include "unitest_base.h"

TEST(base_to_string, TO_STR_int_1)
{
  EXPECT_STREQ("1", TO_STR(1).c_str());
}

TEST(base_to_string, TO_STR_float_1)
{
  float v = 0.1;
  EXPECT_STREQ("0.100000", TO_STR(v).c_str());
}

TEST(base_to_string, TO_STR_double_1)
{
  double v = 0.1;
  EXPECT_STREQ("0.100000", TO_STR(v).c_str());
}

TEST(base_to_string, TO_STR_uint128_1)
{
  __uint128_t val = 9223372036854775808;
  EXPECT_STREQ("9223372036854775808", TO_STR(val).c_str());
}

TEST(base_to_string, TO_STR_vector_int_1)
{
  std::vector<int> arr1 = {0, 1, 2};
  EXPECT_STREQ("{0,1,2}", TO_STR(arr1).c_str());

  std::vector<std::string> arr2 = {"a", "b", "c"};
  EXPECT_STREQ("{a,b,c}", TO_STR(arr2).c_str());
}  

TEST(base_to_string, TO_STR_vector_int_2)
{
  std::vector<std::vector<int>> arr1 = {{0, 1, 2}, {3, 4}};
  EXPECT_STREQ("{{0,1,2},{3,4}}", TO_STR(arr1).c_str());

  std::vector<std::vector<std::string>> arr2 = {{"a", "b"}, {"c"}};
  EXPECT_STREQ("{{a,b},{c}}", TO_STR(arr2).c_str());
}

TEST(base_to_string, TO_STR_vector_int_3)
{
  std::vector<std::vector<std::vector<int>>> arr1 = {{{0, 1}, {2, 3}, {4, 5}}, {{6, 7}, {8, 9}}};
  EXPECT_STREQ("{{{0,1},{2,3},{4,5}},{{6,7},{8,9}}}", TO_STR(arr1).c_str());

  std::vector<std::vector<std::vector<std::string>>> arr2 = {{{"a"}, {"b"}}, {{"c"}}};
  EXPECT_STREQ("{{{a},{b}},{{c}}}", TO_STR(arr2).c_str());
}

TEST(base_to_string, TO_STR_vector_bool_1)
{
  std::vector<bool> arr1 = {false, true, true};
  EXPECT_STREQ("{0,1,1}", TO_STR(arr1).c_str());
}

TEST(base_to_string, TO_STR_char_1)
{
  char c = 'a';
  EXPECT_STREQ("a", TO_STR(c).c_str());
}

TEST(base_to_string, TO_STR_map_1)
{
  std::map<std::string, int> m1;
  m1["a"] = 1;
  m1["b"] = 2;
  m1["c"] = 3;

  EXPECT_STREQ("{a=1,b=2,c=3}", TO_STR(m1).c_str());
}

