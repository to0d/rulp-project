#include "unitest_llvm.h"
#include "unitest_base.h"
#include "lfc/llvm/lva.h"

using namespace std;
using namespace llvm;
using namespace lfc;


TEST(llvm_lva, live_variables_analysis_1)
{
  // set_global_trace(true);
  // set_lva_trace(true);

  //   B0
  //   |
  //   v
  //   B1   <-+
  //   /\     |
  //  v  \    |
  // B2  |    |
  //  \  |    |
  //   v v    |
  //    B3 ---+
  //    |
  //    v
  //   EXIT
  std::vector<std::vector<std::string>> in_var, out_var;
    live_variables_analysis(
      // def_vars
        {
          {"i", "j", "a"}
        , {}
        , {"a"}
        , {"i"}
      } 
      // use_vars
      , {
          {"m", "n", "u1"}
        , {"i", "j"}
        , {"u2"}
        , {"u3"}
      } 
      // graph
      , {
          {1}
        , {2, 3}
        , {3}
        , {1}
      }
      , 4 // node_count
      , 0 // in_node_idx
      , 3 // out_node_idx
      , in_var
      , out_var);

  EXPECT_STREQ("{{m,n,u1,u2,u3},{i,j,u2,u3},{j,u2,u3},{j,u2,u3}}", 
    lfc::to_string(in_var).c_str());

  EXPECT_STREQ("{{i,j,u2,u3},{j,u2,u3},{j,u2,u3},{i,j,u2,u3}}", 
    lfc::to_string(out_var).c_str());
}


TEST(llvm_lva, live_variables_analysis_2)
{
  // set_global_trace(true);
  // set_lva_trace(true);

  // Example
  // 
  // int foo(int b, int c, int d, int f){
  //    
  //   while(b == 0){
  //     int a = b + c;  // 0
  //     d -= a;         // 1
  //     int e = d + f;  // 2
  //     if (e > 0) 
  //       f = 2*e;      // 3
  //     else {
  //       b = d + e;    // 4
  //       e = e - 1;    // 5
  //     }
  //     b = f + c;      // 6
  //   }
  //
  //   return b;         // 7
  // }
  std::vector<std::vector<std::string>> def_vars = {
      {"a"}
    , {"d"}
    , {"e"}
    , {"f"}
    , {"b"}
    , {"e"}
    , {"b"}
    , {}
  };
  std::vector<std::vector<std::string>> use_vars = {
      {"b", "c"}
    , {"a"}
    , {"d", "f"}
    , {"e"}
    , {"d", "e"}
    , {"e"}
    , {"f", "c"}
    , {"b"}
  };

  //     +-----------------------+
  //     v                       |
  //     0 -> 1 -> 2 -> 3 -----> 6 --> 7
  //                 \          ^
  //                  > 4 -> 5-/
  std::vector<std::vector<int>> graph = {
      {1}
    , {2}
    , {3,4}
    , {6}
    , {5}
    , {6}
    , {0, 7}
    , {}
    }
  ;

  int pp_count = 8; // program point count
  int in_idx = 0, out_idx =7;  

  std::vector<std::vector<std::string>> in_var, out_var;
    live_variables_analysis(
        def_vars
      , use_vars
      , graph
      , pp_count
      , in_idx
      , out_idx
      , in_var
      , out_var);

  EXPECT_STREQ("{{b,c,f},{a,c,f},{c,d,f},{c,e},{c,d,e,f},{c,e,f},{c,f},{b}}", 
    lfc::to_string(in_var).c_str());

  EXPECT_STREQ("{{a,c,f},{c,d,f},{c,d,e,f},{c,f},{c,e,f},{c,f},{b,c,f},{}}", 
    lfc::to_string(out_var).c_str());
}