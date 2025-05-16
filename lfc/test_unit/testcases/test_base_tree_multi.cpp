#include "unitest_base.h"
#include "lfc/base/tree.h"

using namespace lfc;

#define VISIT_BTREE(in_tree, out_expect, F, C)         \
  std::vector<std::vector<int>> vec_tree = in_tree;    \
  std::string expect   = out_expect;                   \
  std::vector<std::string> lines;                      \
  int visit_count = F(0                                \
    , [&](int node, int level){                        \
    std::string out = "(";                             \
    out += lfc::to_string(level);                     \
    out += ":";                                        \
    out += lfc::to_string(node);                      \
    out += ")";                                        \
    lines.push_back(out);                              \
    return false;                                      \
    }                                                  \
    , [&](int node){                                   \
      return vec_tree[node];                           \
    }                                                  \
  );                                                   \
  EXPECT_STREQ(expect.c_str(), lfc::to_string(lines).c_str()); \
  EXPECT_EQ(C, visit_count)


TEST(base_tree, visit_tree_bfs_multi_1)
{
  //    0
  //  1 2 3
  //   /
  //  4
  std::vector<std::vector<int>> tree = {{1,2,3},{},{4},{},{}};
  VISIT_BTREE(tree, "{(0:0),(1:1),(1:2),(1:3),(2:4)}", visit_tree_bfs, 5);
}

TEST(base_tree, visit_tree_dfs_postorder_multi_1)
{
  //    0
  //  1 2 3
  //   /
  //  4
  std::vector<std::vector<int>> tree = {{1,2,3},{},{4},{},{}};
  VISIT_BTREE(tree, "{(1:1),(2:4),(1:2),(1:3),(0:0)}", visit_tree_dfs_postorder, 5);
}

TEST(base_tree, visit_tree_dfs_preorder_multi_1)
{
  //    0
  //  1 2 3
  //   /
  //  4
  std::vector<std::vector<int>> tree = {{1,2,3},{},{4},{},{}};
  VISIT_BTREE(tree, "{(0:0),(1:1),(2:4),(1:2),(1:3)}", visit_tree_dfs_preorder, 4);
}

TEST(base_tree, dump_tree_1)
{
  //    0
  //  1 2 3
  //   /
  //  4
  std::vector<std::vector<int>> tree = {{1,2,3},{},{4},{},{}};

  auto lines = dump_tree(0, 
                        [&](int idx){
                          return lfc::to_string(idx);
                        },
                        [&](int idx){return tree[idx];}
                      );

  test_lines(lines, "data_base/base_tree/dump_tree_1.txt");


}


