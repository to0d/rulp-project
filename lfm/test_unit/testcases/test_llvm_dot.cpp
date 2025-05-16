#include "unitest_llvm.h"
#include "unitest_base.h"

using namespace std;
using namespace llvm;
using namespace lfc;


TEST(llvm_dot, output_dot_graph_1)
{
  DotUtil DOT_Util("foo");

  DotNode* node_start = DOT_Util.add_node("start", "start");
  DOT_Util.set_node_attribute(node_start, DotAttr::RED);
  DOT_Util.set_node_attribute(node_start, DotAttr::ELLIPSE);

  DotNode* node_end = DOT_Util.add_node("end", "end");
  DOT_Util.set_node_attribute(node_end, DotAttr::RED);
  DOT_Util.set_node_attribute(node_end, DotAttr::ELLIPSE);

  DOT_Util.add_node("n1", "n1");
  DOT_Util.add_node("n2", "n2");

  DOT_Util.add_edge("start", "n1");
  auto e1 = DOT_Util.add_edge("n1", "n2");
  DOT_Util.set_edge_label(e1, "xxx");

  DOT_Util.add_edge("n2", "end");

  std::vector<std::string> dot_lines = DOT_Util.output_dot_graph();
  SAVE_TXT_FILE("data_base/llvm_dot/output_dot_graph_1.dot.actual", dot_lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE("data_base/llvm_dot/output_dot_graph_1.dot")).c_str(), 
    lfc::to_string(dot_lines).c_str());

  test_lines(DOT_Util.dump(), "data_base/llvm_dot/output_dot_graph_1.txt");
}

