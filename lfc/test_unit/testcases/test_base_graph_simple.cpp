#include "unitest_base.h"
#include "lfc/base/graph/graph_simple.h"
#include "lfc/base/graph/graph_dot.h"

using namespace lfc;
    
TEST(base_graph_simple, getAllPathsSourceTarget_1)
{
  simple_graph graph = {{1,2},{3},{3},{}};

  DotUtil DOT_Util("SG");
  build_simple_graph_dot_graph(graph, &DOT_Util, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_1.dot.actual", dot_lines);
  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());


  EXPECT_STREQ( "{{0,1,3},{0,2,3}}"
              , lfc::to_string(getAllPathsSourceTarget(graph)).c_str());

  EXPECT_STREQ( "{{0,1,3},{0,2,3}}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 0, -1)).c_str());
  
  EXPECT_STREQ( "{}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 0, 0)).c_str());

  EXPECT_STREQ( "{{1,3}}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 1, 3)).c_str());

  EXPECT_STREQ( "{}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 1, 2)).c_str());
}

TEST(base_graph_simple, getAllPathsSourceTarget_2)
{
  simple_graph graph = {{4,3,1},{3,2,4},{3},{4},{}};

  DotUtil DOT_Util("SG");
  build_simple_graph_dot_graph(graph, &DOT_Util, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_2.dot.actual", dot_lines);
  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  EXPECT_STREQ( "{{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}"
              , lfc::to_string(getAllPathsSourceTarget(graph)).c_str());

  EXPECT_STREQ( "{{1,3,4},{1,2,3,4},{1,4}}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 1, 4)).c_str());
}

TEST(base_graph_simple, getAllPathsSourceTarget_3)
{
  simple_graph graph = {{0,1,2},{1,2},{0,2}};

  DotUtil DOT_Util("SG");
  build_simple_graph_dot_graph(graph, &DOT_Util, true);
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_3.dot.actual", dot_lines);
  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_graph/getAllPathsSourceTarget_3.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  EXPECT_STREQ( "{{0,1,2},{0,2}}"
              , lfc::to_string(getAllPathsSourceTarget(graph)).c_str());

  EXPECT_STREQ( "{{0},{0,1,2,0},{0,2,0}}"
              , lfc::to_string(getAllPathsSourceTarget(graph, 0, 0)).c_str());
}