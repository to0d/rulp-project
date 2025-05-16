#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(base_task, build_next_dep_array_1)
{
  EXPECT_STREQ("{}", 
    lfc::to_string(lfc::build_next_dep_array(
              {}
    )).c_str());

  EXPECT_STREQ("{{2},{},{}}", 
    lfc::to_string(lfc::build_next_dep_array(
              {{},{},{0}}
    )).c_str());

  EXPECT_STREQ("{{2},{3},{},{}}", 
    lfc::to_string(lfc::build_next_dep_array(
              {{},{},{0},{1}}
    )).c_str());

  EXPECT_STREQ("{{1,4},{},{3},{},{}}", 
    lfc::to_string(lfc::build_next_dep_array(
             {{},{0},{},{2},{0}}
    )).c_str());

  EXPECT_STREQ("{{},{2,8},{12},{4,9},{12},{6,10},{12},{},{12},{12},{12},{12,17},{18},{14,15,16},{15,16},{16},{},{},{},{}}", 
    lfc::to_string(lfc::build_next_dep_array(
             {{},{},{1},{},{3},{},{5},{},{1},{3},{5},{},{11,10,9,8,6,4,2},{},{13},{14,13},{15,14,13},{11},{12},{}}
    )).c_str());
}

TEST(base_task, build_full_dep_array_1)
{
  EXPECT_STREQ("{{},{0},{},{2}}", 
    lfc::to_string(build_full_dep_array({{},{0},{},{2}})).c_str());
  EXPECT_STREQ("{{},{0},{0,1}}", 
    lfc::to_string(build_full_dep_array({{},{0},{1}})).c_str());
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{4,7},{}}", 
    lfc::to_string(build_full_dep_array({{},{},{},{},{},{},{},{},{},{},{},{},{7,4},{}})).c_str());
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{4,7},{}}", 
    lfc::to_string(build_full_dep_array({{},{},{},{},{},{},{},{},{},{},{},{},{4,7},{}})).c_str());
}


TEST(base_task, remove_full_dep_array_1)
{
  EXPECT_STREQ("{{},{0},{},{2}}", 
    lfc::to_string(remove_full_dep_array({{},{0},{},{2}})).c_str());
  EXPECT_STREQ("{{},{0},{1}}", 
    lfc::to_string(remove_full_dep_array({{},{0},{0,1}})).c_str());
  EXPECT_STREQ("{{},{},{},{},{},{},{},{},{},{},{},{},{4,7},{}}", 
    lfc::to_string(remove_full_dep_array({{},{},{},{},{},{},{},{},{},{},{},{},{4,7},{}})).c_str());
}

