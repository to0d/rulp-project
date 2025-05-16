#include "unitest_base.h"

using namespace std;
using namespace lfc;


TEST(base_task, is_valid_reorder_vec_1)
{
  EXPECT_EQ(false, lfc::is_valid_reorder_vec({-1}));
  EXPECT_EQ(false, lfc::is_valid_reorder_vec({1}));
  EXPECT_EQ(false, lfc::is_valid_reorder_vec({0, 2}));
}


TEST(base_task, is_valid_reorder_vec_2)
{
  EXPECT_EQ(true, lfc::is_valid_reorder_vec({}));
  EXPECT_EQ(true, lfc::is_valid_reorder_vec({0,1,2}));
  EXPECT_EQ(true, lfc::is_valid_reorder_vec({2,1,0}));
}

TEST(base_task, is_nochange_reorder_vec_1)
{
  EXPECT_EQ(true, lfc::is_nochange_reorder_vec({}));
  EXPECT_EQ(true, lfc::is_nochange_reorder_vec({0,1,2}));
  EXPECT_EQ(false, lfc::is_nochange_reorder_vec({0,2,1}));
}

TEST(base_task, is_valid_ordered_vec_1)
{
  EXPECT_EQ(true  , lfc::is_valid_ordered_vec({}, 0, false));
  EXPECT_EQ(true  , lfc::is_valid_ordered_vec({0,1,2}, 3, false));
  EXPECT_EQ(false , lfc::is_valid_ordered_vec({0,2,1}, 3, false));
}

TEST(base_task, make_vec_1)
{
  EXPECT_STREQ("{}", lfc::to_string(make_vec(0)).c_str());
  EXPECT_STREQ("{0}", lfc::to_string(make_vec(1)).c_str());
  EXPECT_STREQ("{0,1}", lfc::to_string(make_vec(2)).c_str());
}

TEST(base_task, apply_reorder_steps_1)
{
  EXPECT_STREQ("{0,2,1,3}", lfc::to_string(apply_reorder_steps(make_vec(4), {{1,2}})).c_str());
  EXPECT_STREQ("{0,3,1,2,4}", lfc::to_string(apply_reorder_steps(make_vec(5), {{1,2}, {1,3}})).c_str());
}

TEST(base_task, build_reorder_steps_1)
{
  std::vector<int> input_vec            = {0,1,2,3};
  std::vector<int> expect_vec           = {0,2,1,3};
  std::vector<std::vector<int>> dep_arr = {{},{0},{},{2}};
  std::vector<std::vector<int>> steps;

  EXPECT_EQ(true, lfc::build_reorder_steps(input_vec, expect_vec, dep_arr, steps));
  EXPECT_STREQ("{{1,2}}", lfc::to_string(steps).c_str());
}

TEST(base_task, build_reorder_steps_2)
{
  std::vector<int> input_vec            = {0,1,2,3,4};
  std::vector<int> expect_vec           = {0,3,1,2,4};
  std::vector<std::vector<int>> dep_arr = {{},{},{},{},{}};
  std::vector<std::vector<int>> steps;

  EXPECT_EQ(true, lfc::build_reorder_steps(input_vec, expect_vec, dep_arr, steps));
  EXPECT_STREQ("{{1,3},{2,3}}", lfc::to_string(steps).c_str());
}

TEST(base_task, build_reorder_steps_3)
{
  std::vector<int> input_vec            = {0,1,2,3,4,5};
  std::vector<int> expect_vec           = {0,2,1,4,3,5};
  std::vector<std::vector<int>> dep_arr = {{},{},{},{},{},{}};
  std::vector<std::vector<int>> steps;

  EXPECT_EQ(true, lfc::build_reorder_steps(input_vec, expect_vec, dep_arr, steps));
  EXPECT_STREQ("{{1,2},{3,4}}", lfc::to_string(steps).c_str());
}
