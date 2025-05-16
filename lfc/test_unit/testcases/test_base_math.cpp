#include "unitest_base.h"
#include "lfc/base/math.h"
#include "lfc/base/to_string.h"
#include "help_test.h"

TEST(base_math, MATH_CEIL_1)
{
  EXPECT_STREQ("2.000000", TO_STR(MATH_CEIL(1.1)).c_str());
  EXPECT_STREQ("2.000000", TO_STR(MATH_CEIL(1.5)).c_str());
}

TEST(base_math, MATH_LOG_1)
{
  EXPECT_STREQ("0.000000", TO_STR(MATH_LOG(1)).c_str());
  EXPECT_STREQ("2.302585", TO_STR(MATH_LOG(10)).c_str());
}

TEST(base_math, MATH_EXP_1)
{
  EXPECT_STREQ("1.000000", TO_STR(MATH_EXP(0)).c_str());
  EXPECT_STREQ("2.718282", TO_STR(MATH_EXP(1)).c_str());
}