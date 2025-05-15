#include <gtest/gtest.h>
#include "lfc/stl/algorithm.h"
#include <cmath>

TEST(lfc_algorithm, test_max_double_1)
{
  // PositiveNumbers
  EXPECT_DOUBLE_EQ(3.0, lfc::max(3.0, 2.0));
  EXPECT_DOUBLE_EQ(3.0, lfc::max(2.0, 3.0));
  EXPECT_DOUBLE_EQ(123.456, lfc::max(123.456, 123.455));
  EXPECT_DOUBLE_EQ(123.456, lfc::max(123.455, 123.456));
  
  // NegativeNumbers
  EXPECT_DOUBLE_EQ(-2.0, lfc::max(-2.0, -3.0));
  EXPECT_DOUBLE_EQ(-2.0, lfc::max(-3.0, -2.0));
  
  // MixedSigns
  EXPECT_DOUBLE_EQ(3.0, lfc::max(3.0, -5.0));
  EXPECT_DOUBLE_EQ(3.0, lfc::max(-5.0, 3.0));
  
  // EqualValues
  EXPECT_DOUBLE_EQ(3.0, lfc::max(3.0, 3.0));
  EXPECT_DOUBLE_EQ(-2.0, lfc::max(-2.0, -2.0));
  
  // SpecialCases
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::max(DBL_MAX, DBL_MAX/2));
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::max(DBL_MAX/2, DBL_MAX));
  EXPECT_DOUBLE_EQ(-DBL_MAX, lfc::max(-DBL_MAX, -DBL_MAX));
  
  // // NaN handling
  // EXPECT_TRUE(std::isnan(lfc::max(NAN, 3.0)));
  // EXPECT_TRUE(std::isnan(lfc::max(3.0, NAN)));
  // EXPECT_TRUE(std::isnan(lfc::max(NAN, NAN)));
}

TEST(lfc_algorithm, test_max_float_1)
{
  // Test float specialization
  EXPECT_FLOAT_EQ(3.0f, lfc::max(3.0f, 2.0f));
  EXPECT_FLOAT_EQ(3.0f, lfc::max(2.0f, 3.0f));
  EXPECT_FLOAT_EQ(-2.0f, lfc::max(-2.0f, -3.0f));
  
  // // NaN handling
  // EXPECT_TRUE(std::isnan(lfc::max(NAN, 3.0f)));
  // EXPECT_TRUE(std::isnan(lfc::max(3.0f, NAN)));
}

TEST(lfc_algorithm, test_max_integral_1)
{
  // Signed integers
  EXPECT_EQ(5, lfc::max(5, 3));
  EXPECT_EQ(5, lfc::max(3, 5));
  EXPECT_EQ(-3, lfc::max(-3, -5));
  EXPECT_EQ(-3, lfc::max(-5, -3));
  
  // Unsigned integers
  EXPECT_EQ(5u, lfc::max(5u, 3u));
  EXPECT_EQ(5u, lfc::max(3u, 5u));
    
  // Boundary values
  EXPECT_EQ(INT_MAX, lfc::max(INT_MAX, INT_MAX-1));
  EXPECT_EQ(INT_MAX, lfc::max(INT_MAX-1, INT_MAX));
  EXPECT_EQ(0, lfc::max(0, INT_MIN));
  EXPECT_EQ(0, lfc::max(INT_MIN, 0));
}

TEST(lfc_algorithm, test_mixed_types_1)
{
  // EXPECT_EQ(5, lfc::max(5, 3u));
  // EXPECT_EQ(5u, lfc::max(3u, 5));
}

TEST(lfc_algorithm, test_max_edge_cases)
{
  // Zero cases
  EXPECT_DOUBLE_EQ(0.0, lfc::max(0.0, -0.0));
  EXPECT_DOUBLE_EQ(0.0, lfc::max(-0.0, 0.0));
  
  // Infinity cases
  EXPECT_TRUE(std::isinf(lfc::max(std::numeric_limits<double>::infinity(), DBL_MAX)));
  EXPECT_TRUE(std::isinf(lfc::max(DBL_MAX, std::numeric_limits<double>::infinity())));
  EXPECT_DOUBLE_EQ(-DBL_MAX, lfc::max(-std::numeric_limits<double>::infinity(), -DBL_MAX));
  EXPECT_DOUBLE_EQ(-DBL_MAX, lfc::max(-DBL_MAX, -std::numeric_limits<double>::infinity()));
  
  // Denormal values
  EXPECT_DOUBLE_EQ(std::numeric_limits<double>::min(), 
                  lfc::max(std::numeric_limits<double>::min(), 0.0));
  EXPECT_DOUBLE_EQ(0.0, 
                  lfc::max(0.0, -std::numeric_limits<double>::min()));
}

TEST(lfc_algorithm, test_min_double_1)
{
  // PositiveNumbers
  EXPECT_DOUBLE_EQ(2.0, lfc::min(3.0, 2.0));
  EXPECT_DOUBLE_EQ(2.0, lfc::min(2.0, 3.0));
  EXPECT_DOUBLE_EQ(123.455, lfc::min(123.456, 123.455));
  EXPECT_DOUBLE_EQ(123.455, lfc::min(123.455, 123.456));
  
  // NegativeNumbers
  EXPECT_DOUBLE_EQ(-3.0, lfc::min(-2.0, -3.0));
  EXPECT_DOUBLE_EQ(-3.0, lfc::min(-3.0, -2.0));
  
  // MixedSigns
  EXPECT_DOUBLE_EQ(-5.0, lfc::min(3.0, -5.0));
  EXPECT_DOUBLE_EQ(-5.0, lfc::min(-5.0, 3.0));
  
  // EqualValues
  EXPECT_DOUBLE_EQ(3.0, lfc::min(3.0, 3.0));
  EXPECT_DOUBLE_EQ(-2.0, lfc::min(-2.0, -2.0));
  
  // SpecialCases
  EXPECT_DOUBLE_EQ(DBL_MAX/2, lfc::min(DBL_MAX, DBL_MAX/2));
  EXPECT_DOUBLE_EQ(DBL_MAX/2, lfc::min(DBL_MAX/2, DBL_MAX));
  EXPECT_DOUBLE_EQ(-DBL_MAX, lfc::min(-DBL_MAX, -DBL_MAX));
  
  // // NaN handling
  // EXPECT_TRUE(std::isnan(lfc::min(NAN, 3.0)));
  // EXPECT_TRUE(std::isnan(lfc::min(3.0, NAN)));
  // EXPECT_TRUE(std::isnan(lfc::min(NAN, NAN)));
}

TEST(lfc_algorithm, test_min_float_1)
{
  // Test float specialization
  EXPECT_FLOAT_EQ(2.0f, lfc::min(3.0f, 2.0f));
  EXPECT_FLOAT_EQ(2.0f, lfc::min(2.0f, 3.0f));
  EXPECT_FLOAT_EQ(-3.0f, lfc::min(-2.0f, -3.0f));
  
  // // NaN handling
  // EXPECT_TRUE(std::isnan(lfc::min(NAN, 3.0f)));
  // EXPECT_TRUE(std::isnan(lfc::min(3.0f, NAN)));
}

TEST(lfc_algorithm, test_min_integral_1)
{
  // Signed integers
  EXPECT_EQ(3, lfc::min(5, 3));
  EXPECT_EQ(3, lfc::min(3, 5));
  EXPECT_EQ(-5, lfc::min(-3, -5));
  EXPECT_EQ(-5, lfc::min(-5, -3));
  
  // Unsigned integers
  EXPECT_EQ(3u, lfc::min(5u, 3u));
  EXPECT_EQ(3u, lfc::min(3u, 5u));
    
  // Boundary values
  EXPECT_EQ(INT_MAX-1, lfc::min(INT_MAX, INT_MAX-1));
  EXPECT_EQ(INT_MAX-1, lfc::min(INT_MAX-1, INT_MAX));
  EXPECT_EQ(INT_MIN, lfc::min(0, INT_MIN));
  EXPECT_EQ(INT_MIN, lfc::min(INT_MIN, 0));
}

TEST(lfc_algorithm, test_min_mixed_types_1)
{
  // EXPECT_EQ(3, lfc::min(5, 3u));
  // EXPECT_EQ(3u, lfc::min(3u, 5));
}

TEST(lfc_algorithm, test_min_edge_cases)
{
  // Zero cases
  EXPECT_DOUBLE_EQ(0.0, lfc::min(0.0, -0.0));
  EXPECT_DOUBLE_EQ(0.0, lfc::min(-0.0, 0.0));
  
  // Infinity cases
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::min(std::numeric_limits<double>::infinity(), DBL_MAX));
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::min(DBL_MAX, std::numeric_limits<double>::infinity()));
  EXPECT_TRUE(std::isinf(lfc::min(-std::numeric_limits<double>::infinity(), -DBL_MAX)));
  EXPECT_TRUE(std::isinf(lfc::min(-DBL_MAX, -std::numeric_limits<double>::infinity())));
  
  // Denormal values
  EXPECT_DOUBLE_EQ(0.0, 
                  lfc::min(std::numeric_limits<double>::min(), 0.0));
  EXPECT_DOUBLE_EQ(-std::numeric_limits<double>::min(), 
                  lfc::min(0.0, -std::numeric_limits<double>::min()));
}