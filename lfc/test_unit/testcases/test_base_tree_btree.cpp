#include "unitest_base.h"
#include "lfc/base/tree/btree.h"

using namespace lfc;

#define VISIT_BTREE(in_tree, out_expect, F, C)                       \
  std::string tree_str = in_tree;                                    \
  std::string expect   = out_expect;                                 \
                                                                     \
  BTreeNode<int>* tree = make_btree(tree_str);                       \
  std::vector<std::string> lines;                                    \
                                                                     \
  int visit_count = F(tree, [&](auto node, int level){               \
    std::string out = "(";                                           \
    out += lfc::to_string(level);                                   \
    out += ":";                                                      \
    out += lfc::to_string(node->val);                               \
    out += ")";                                                      \
    lines.push_back(out);                                            \
    return false;                                                    \
  });                                                                \
                                                                     \
  EXPECT_STREQ(expect.c_str(), lfc::to_string(lines).c_str());      \
  EXPECT_EQ(C, visit_count);                                         \
  free_btree(tree);



TEST(base_tree, visit_tree_bfs_btree_1)
{
  VISIT_BTREE("{1,#,2,3}", "{(0:1),(1:2),(2:3)}", visit_tree_bfs, 3);
}

TEST(base_tree, visit_tree_dfs_preorder_btree_1)
{
  //   1 
  //  2 3
  // ## #4 
  VISIT_BTREE("{1,2,3,#,#,#,4}", "{(0:1),(1:2),(1:3),(2:4)}", visit_tree_dfs_preorder, 4);
}


TEST(base_tree, visit_tree_dfs_postorder_btree_1)
{
  //   1 
  //  2 3
  // ## #4 
  VISIT_BTREE("{1,2,3,#,#,#,4}", "{(1:2),(2:4),(1:3),(0:1)}", visit_tree_dfs_postorder, 4);
}

TEST(base_tree, visit_tree_dfs_inorder_btree_1)
{
  //   1 
  //  2 3
  // ## #4 
  VISIT_BTREE("{1,2,3,#,#,#,4}", "{(1:2),(0:1),(1:3),(2:4)}", visit_tree_dfs_inorder, 4);
}