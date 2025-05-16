#include "unitest_base.h"


TEST(base_macro, MIN_1)
{
  EXPECT_EQ(1, MIN(1, 2));
}


TEST(base_macro, MAX_1)
{
  EXPECT_EQ(2, MAX(1, 2));
}


TEST(base_macro, ROUND_1)
{
  EXPECT_EQ(0, ROUND(4, 5));
  EXPECT_EQ(5, ROUND(5, 5));
  EXPECT_EQ(5, ROUND(6, 5));
}


TEST(base_macro, TIMES_OF_1)
{
  EXPECT_EQ(1, TIMES_OF(4, 5));
  EXPECT_EQ(1, TIMES_OF(5, 5));
  EXPECT_EQ(2, TIMES_OF(10, 5));
  EXPECT_EQ(3, TIMES_OF(11, 5));
}


TEST(base_macro, ROUND_UP_1)
{
  EXPECT_EQ(5, ROUND_UP(4, 5));
  EXPECT_EQ(5, ROUND_UP(5, 5));
  EXPECT_EQ(10, ROUND_UP(6, 5));
}


TEST(base_macro, CEIL_1)
{
  EXPECT_EQ(0, CEIL(4, 5));
  EXPECT_EQ(1, CEIL(5, 5));
  EXPECT_EQ(1, CEIL(6, 5));
}

TEST(base_macro, ROUND_DOWN_1)
{
  EXPECT_EQ(0, ROUND_DOWN(4, 5));
  EXPECT_EQ(5, ROUND_DOWN(5, 5));
  EXPECT_EQ(5, ROUND_DOWN(6, 5));
}


TEST(base_macro, STATIC_ASSERT_1)
{
  STATIC_ASSERT(1 == 1);
}