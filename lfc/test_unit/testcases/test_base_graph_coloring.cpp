#include "unitest_base.h"
#include "lfc/base/graph/graph_coloring.h"

using namespace lfc;
    

TEST(base_graph_coloring, fill_graph_coloring_1)
{
  //     0
  //    /|\
  //   / | \
  //  5--6--1
  //  |\  \ |
  //  | \  \|
  //  4--3--2   
  std::vector<std::vector<int>> graph = {
      {1,5,6}
    , {2,6}
    , {3,6}
    , {4,5}
    , {5}
    , {6}
    , {}
    }
  ;
  
  std::vector<int> colors;
  EXPECT_EQ(true, fill_graph_coloring(graph, 3, colors));
  EXPECT_STREQ("{0,1,0,2,0,1,2}", lfc::to_string(colors).c_str());

}