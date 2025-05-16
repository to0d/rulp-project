#include "unitest_base.h"
#include "lfc/base/equal.h"
#include "lfc/base/collection.h"
#include "lfc/base/to_string.h"

TEST(base_collection, has_common_index_1)
{ 
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {2};
  auto f = [](int v){return v;};

  EXPECT_EQ(true, lfc::has_common_index(a.begin(), a.end(), b.begin(), b.end(), f));
  EXPECT_EQ(true, lfc::has_common_index(b.begin(), b.end(), a.begin(), a.end(), f));
}

TEST(base_collection, has_common_index_2)
{ 
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {};
  auto f = [](int v){return v;};

  EXPECT_EQ(false, lfc::has_common_index(a.begin(), a.end(), b.begin(), b.end(), f));
  EXPECT_EQ(false, lfc::has_common_index(b.begin(), b.end(), a.begin(), a.end(), f));
}

TEST(base_collection, has_element_1)
{ 
  std::vector<std::wstring> vec = {L"a", L"b", L"c"};

  EXPECT_EQ(true , lfc::has_element(vec.begin(), vec.end(), L"a"));
  EXPECT_EQ(true , lfc::has_element(vec.begin(), vec.end(), L"b"));
  EXPECT_EQ(true , lfc::has_element(vec.begin(), vec.end(), L"c"));
  EXPECT_EQ(false, lfc::has_element(vec.begin(), vec.end(), L"d"));
}

TEST(base_collection, is_sub_of_1)
{ 
  std::vector<std::wstring> vec1 = {L"a", L"b", L"c"};
  std::vector<std::wstring> vec2 = {L"a", L"b", L"c"};
  
  EXPECT_EQ(true , lfc::is_sub_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
  EXPECT_EQ(true , lfc::is_sub_of(vec2.begin(), vec2.end(), vec1.begin(), vec1.end()));

  vec2.push_back(L"d");

  EXPECT_EQ(true , lfc::is_sub_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
  EXPECT_EQ(false, lfc::is_sub_of(vec2.begin(), vec2.end(), vec1.begin(), vec1.end()));
}

TEST(base_collection, has_common_element_1)
{ 
  std::vector<std::wstring> vec1 = {L"a", L"b", L"c"};
  std::vector<std::wstring> vec2 = {L"a", L"b", L"c"};
  std::vector<std::wstring> vec3 = {L"a", L"b"};

  EXPECT_EQ(true , lfc::has_common_element(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
  EXPECT_EQ(false, lfc::has_common_element(vec1.begin(), vec1.end(), vec3.begin(), vec3.end()));
}


TEST(base_collection, union_of_1)
{ 
  std::vector<std::string> v1 = {"a", "b"},  v2 = {"b", "c"}, v3;
  lfc::union_of(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

  EXPECT_STREQ("{a,b,c}", 
    lfc::to_string(v3).c_str());
}


TEST(base_collection, intersection_of_1)
{ 
  std::vector<std::string> v1 = {"a", "b"},  v2 = {"b", "c"}, v3;
  lfc::intersection_of(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

  EXPECT_STREQ("{b}", 
    lfc::to_string(v3).c_str());
}

TEST(base_collection, complement_of_1)
{ 
  std::vector<std::string> v1 = {"a", "b"},  v2 = {"b", "c"}, v3;
  lfc::complement_of(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

  EXPECT_STREQ("{a}", 
    lfc::to_string(v3).c_str());
}