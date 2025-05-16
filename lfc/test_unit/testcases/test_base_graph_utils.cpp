#include "unitest_base.h"
#include "lfc/base/graph/graph_utils.h"

using namespace lfc;


TEST(base_graph_utils, has_loop_in_graph_1)
{
  //  0
  // / 
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1}, {3}, {3}, {}};
  std::vector<int> all_nodes = {0, 1, 2, 3,};
  EXPECT_EQ(false, has_loop_in_graph(all_nodes, [=](int n){return graph[n];}));
}

TEST(base_graph_utils, has_loop_in_graph_2)
{
  //    0
  //   / ^
  //  v   \
  //  1 --> 2
  std::vector<std::vector<int>> graph = {{1}, {2}, {0}};
  std::vector<int> all_nodes = {0, 1, 2};
  EXPECT_EQ(true, has_loop_in_graph(all_nodes, [=](int n){return graph[n];}));
}

