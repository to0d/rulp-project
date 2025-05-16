#include "unitest_base.h"
#include "lfc/base/graph/graph_visit.h"

using namespace lfc;

TEST(base_graph_visit, visit_graph_bfs_1)
{
  //  0
  // / \
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<int> input = {0};
  std::vector<int> output;

  int count = visit_graph_bfs(input
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
  );

  EXPECT_EQ(3, count);
  EXPECT_STREQ("{1,2,3}", lfc::to_string(output).c_str());
}

TEST(base_graph_visit, visit_graph_bfs_2)
{
  //  0
  // / \
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<int> input = {0};
  std::vector<int> output;

  int count = visit_graph_bfs(input
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
    , false
  );


  EXPECT_EQ(3, count);
  EXPECT_STREQ("{1,2,3}", lfc::to_string(output).c_str());
}

TEST(base_graph_visit, visit_graph_bfs_3)
{
  //  0
  // / \
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<int> input = {0};
  std::vector<int> output;

  int count = visit_graph_bfs(input
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
    , true
  );


  EXPECT_EQ(4, count);
  EXPECT_STREQ("{0,1,2,3}", lfc::to_string(output).c_str());
}

TEST(base_graph_visit, visit_graph_dfs_1)
{
  //  0
  // / \
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<int> input = {0};
  std::vector<int> output;

  int count = visit_graph_dfs(input
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
    ,
    true
  );

  EXPECT_EQ(4, count);
  EXPECT_STREQ("{0,1,3,2}", lfc::to_string(output).c_str());
}

TEST(base_graph_visit, visit_graph_dfs_2)
{
  //  0
  // / \
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<int> input = {0};
  std::vector<int> output;

  int count = visit_graph_dfs(input
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
    ,
    false
  );

  EXPECT_EQ(3, count);
  EXPECT_STREQ("{1,3,2}", lfc::to_string(output).c_str());
}

TEST(base_graph_visit, visit_graph_by_topological_sorting_1)
{
  //  0
  // / 
  // 1 2
  // \ / 
  //  3
  std::vector<std::vector<int>> graph = {{1}, {3}, {3}, {}};
  std::vector<int> all_nodes = {0, 1, 2, 3,};
  std::vector<int> output;

  int count = visit_graph_by_topological_sorting(all_nodes
    , [&](int n){
      output.push_back(n);
      return false;
    }
    , [=](int n){
      return graph[n];
    }
  );

  EXPECT_EQ(4, count);
  EXPECT_STREQ("{0,2,1,3}", lfc::to_string(output).c_str());
}

