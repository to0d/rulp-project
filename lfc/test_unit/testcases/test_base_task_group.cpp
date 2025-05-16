#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(base_task, is_valid_simd_group_vec_1)
{
  EXPECT_EQ(false, lfc::is_valid_task_dep_group_vec({}));
  EXPECT_EQ(false, lfc::is_valid_task_dep_group_vec({{1}}));
  EXPECT_EQ(false, lfc::is_valid_task_dep_group_vec({{0, 2}}));
}

TEST(base_task, is_valid_simd_group_vec_2)
{
  EXPECT_EQ(true, lfc::is_valid_task_dep_group_vec({{0},{1},{2},{3}}));
  EXPECT_EQ(true, lfc::is_valid_task_dep_group_vec({{0,1},{2,3}}));
  EXPECT_EQ(true, lfc::is_valid_task_dep_group_vec({{0,1},{2,3},{4,5},{6,7,8,9,10,11},{12,13},{14},{15},{16,17,18,19}}));
}

TEST(base_task, make_dep_group_by_topological_sorting_1)
{
  EXPECT_STREQ("{{0,1},{2}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{},{0}}
    )).c_str());

  EXPECT_STREQ("{{0},{1,2},{3}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{0},{},{2}}
    )).c_str());
    
  EXPECT_STREQ("{{0,1},{2,3}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{},{0},{1}}
    )).c_str());
    
  EXPECT_STREQ("{{0,1},{2,3}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{},{0},{1}}
    )).c_str());

  EXPECT_STREQ("{{0},{1,2},{3,4}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{0},{},{2},{0}}
    )).c_str());

  EXPECT_STREQ("{{0,1},{2,3},{4,5},{6,7,8,9,10,11},{12,13},{14},{15},{16,17,18,19}}", 
    lfc::to_string(lfc::build_dep_group_by_topological_sorting(
              {{},{},{1},{},{3},{},{5},{},{1},{3},{5},{},{11,10,9,8,6,4,2},{},{13},{14,13},{15,14,13},{11},{12},{}}
    )).c_str());
}

TEST(base_task, make_dep_group_by_weight_1)
{
  EXPECT_STREQ("{{0},{1,2}}", 
    lfc::to_string(lfc::build_dep_group_by_weight(
              {{},{},{0}}, {1,2,2}
    )).c_str());

  EXPECT_STREQ("{{0,1},{2}}", 
    lfc::to_string(lfc::build_dep_group_by_weight(
              {{},{},{0}}, {2,2,1}
    )).c_str());
}
