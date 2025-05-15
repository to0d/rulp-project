#include <gtest/gtest.h>
#include "lfc/stl/limits.h"
#include <cmath>
#include <limits>

#define TEST_NUMERIC_LIMITS(name, type) \
  TEST(lfc_limits, name) { \
    EXPECT_EQ(lfc::numeric_limits<type>::min(), std::numeric_limits<type>::min()); \
    EXPECT_EQ(lfc::numeric_limits<type>::max(), std::numeric_limits<type>::max()); \
    EXPECT_EQ(lfc::numeric_limits<type>::epsilon(), std::numeric_limits<type>::epsilon()); \
  }

TEST_NUMERIC_LIMITS(test_bool               , bool)
TEST_NUMERIC_LIMITS(test_char               , char)
TEST_NUMERIC_LIMITS(test_signed_char        , signed char)
TEST_NUMERIC_LIMITS(test_unsigned_char      , unsigned char)
TEST_NUMERIC_LIMITS(test_short              , short)
TEST_NUMERIC_LIMITS(test_unsigned_short     , unsigned short)
TEST_NUMERIC_LIMITS(test_int                , int)
TEST_NUMERIC_LIMITS(test_unsigned_int       , unsigned int)
TEST_NUMERIC_LIMITS(test_long               , long)
TEST_NUMERIC_LIMITS(test_unsigned_long      , unsigned long)
TEST_NUMERIC_LIMITS(test_long_long          , long long)
TEST_NUMERIC_LIMITS(test_unsigned_long_long , unsigned long long)
TEST_NUMERIC_LIMITS(test_float              , float)
TEST_NUMERIC_LIMITS(test_double             , double)
TEST_NUMERIC_LIMITS(test_long_double        , long double)

