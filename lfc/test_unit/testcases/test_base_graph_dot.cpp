#include "unitest_base.h"
#include "lfc/base/graph/graph_dot.h"

using namespace lfc;
    

TEST(base_graph_dot, build_simple_graph_dot_graph_1)
{
  //     0
  //    /|\
  //   / | \
  //  5--6--1
  //  |\  \ |
  //  | \  \|
  //  4--3--2   
  simple_graph graph = {
      {1,5,6}
    , {2,6}
    , {3,6}
    , {4,5}
    , {5}
    , {6}
    , {}
    }
  ;

  DotUtil DOT_Util("SG");

  build_simple_graph_dot_graph(graph, &DOT_Util, true);
  
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_graph/build_simple_graph_dot_graph_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_graph/build_simple_graph_dot_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  test_lines(DOT_Util.dump(), "data_base/base_graph/build_simple_graph_dot_graph_1.txt");

}

TEST(base_graph_dot, build_simple_graph_dot_graph_2)
{
  //     0
  //    /|\
  //   / | \
  //  5--6--1
  //  |\  \ |
  //  | \  \|
  //  4--3--2   
  simple_graph graph = {
      {1,5,6}
    , {2,6}
    , {3,6}
    , {4,5}
    , {5}
    , {6}
    , {}
    }
  ;

  DotUtil DOT_Util("SG");

  build_simple_graph_dot_graph(graph, &DOT_Util, false);
  
  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/base_graph/build_simple_graph_dot_graph_2.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/base_graph/build_simple_graph_dot_graph_2.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  test_lines(DOT_Util.dump(), "data_base/base_graph/build_simple_graph_dot_graph_2.txt");

}