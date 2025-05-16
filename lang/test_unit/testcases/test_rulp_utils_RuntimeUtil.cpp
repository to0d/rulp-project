#include "unitest_base.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/lang/RGlobal.h"
#include "runtime/XRFrame.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_RuntimeUtil, compute_1)
{

#define TEST_COMPUTE_1(x) \
  { \
    IRObject* obj = (x); \
    XRFrame frame(""); \
    auto rst = RuntimeUtil::compute(obj, NULL, &frame); \
    EXPECT_TRUE(rst == obj); \
  }

  TEST_COMPUTE_1(O_INT_0);
  TEST_COMPUTE_1(O_INT_1);
  TEST_COMPUTE_1(O_LONG_0);
  TEST_COMPUTE_1(O_FLOAT_0);
  TEST_COMPUTE_1(O_DOUBLE_0);
  TEST_COMPUTE_1(O_True);
  TEST_COMPUTE_1(O_False);
  XRFrame TF("");
  TEST_COMPUTE_1(&TF);
  TEST_COMPUTE_1(O_EMPTY_EXPR);
  TEST_COMPUTE_1(O_EMPTY_LIST);
  TEST_COMPUTE_1(O_EMPTY_STR);
}

// TEST(rulp_utils_RuntimeUtil, compute_2)
// {

// }