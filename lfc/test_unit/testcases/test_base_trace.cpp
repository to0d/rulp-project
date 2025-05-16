#define LFC_TRACE_NAME   "[test_trace]"
#define LFC_TRACE_STREAM TS
#define LFC_TRACE_ENABLE true

#include <string>

class TestSteam{
public:

  void clear(){
    out = "";
  }

  std::string get_out(){
    return out;
  }

  std::string out;
};

inline TestSteam &operator<<(TestSteam &TS, const std::string &val) {
  TS.out += val;
  return TS;
}

inline TestSteam &operator<<(TestSteam &TS, const int &val) {
  TS.out += std::to_string(val);
  return TS;
}

TestSteam TS;

#define USE_LFC_NEW_TRACE
#include "unitest_base.h"

using namespace std;
using namespace lfc;

// template <typename _T1>
// void LFC_TRACE(const _T1& a1){
//   LFC_TRACE(a1);
// }

// template <typename _T1, typename _T2>
// void LFC_TRACE(const _T1& a1, const _T2& a2){
//   LFC_TRACE(a1, a2);
// }


TEST(base_trace, LFC_TRACE_1)
{
  TS.clear();

  LFC_TRACE("test1");
  LFC_TRACE("test2", 2);
  EXPECT_STREQ("\
[trace][test_trace] test1\n\
[trace][test_trace] test22\n", 
    TS.get_out().c_str());  
}


TEST(base_trace, LFC_TRACE_2)
{
  TS.clear();

  LFC_TRACE("test1");
  LFC_TRACE("test2", 2);
  EXPECT_STREQ("\
[trace][test_trace] test1\n\
[trace][test_trace] test22\n", 
    TS.get_out().c_str());  
}

