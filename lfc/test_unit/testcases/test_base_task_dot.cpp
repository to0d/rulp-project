#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(base_task, build_dep_dot_graph_1)
{
  DotUtil DOT_Util("foo");
  build_dep_dot_graph({{},{},{1},{},{3},{},{5},{},{1},{3},{5},{},{11,10,9,8,6,4,2},{},{13},{14,13},{15,14,13},{11},{12},{}}, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_task/build_dep_dot_graph_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_task/build_dep_dot_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(base_task, build_dep_dot_graph_2)
{
  DotUtil DOT_Util("foo");
  build_dep_dot_graph({{},{0},{},{2}}, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_task/build_dep_dot_graph_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_task/build_dep_dot_graph_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}

TEST(base_task, build_dep_dot_graph_3)
{
  DotUtil DOT_Util("foo");
  build_dep_dot_graph({{},{},{0},{1}}, &DOT_Util);

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_task/build_dep_dot_graph_3.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_task/build_dep_dot_graph_3.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());
}
