#include <gtest/gtest.h>
#include "lfc/stl/math.h"
#include <cmath>
#include <limits>
#include <type_traits>

TEST(lfc_math, test_abs_double_1)
{
  // PositiveNumbers
  EXPECT_DOUBLE_EQ(0.0, lfc::abs(0.0));
  EXPECT_DOUBLE_EQ(3.0, lfc::abs(3.0));
  EXPECT_DOUBLE_EQ(123.456, lfc::abs(123.456));
  
  // NegativeNumbers
  EXPECT_DOUBLE_EQ(3.0, lfc::abs(-3.0));
  EXPECT_DOUBLE_EQ(123.456, lfc::abs(-123.456));
  
  // SpecialCases
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::abs(DBL_MAX));
  EXPECT_DOUBLE_EQ(DBL_MAX, lfc::abs(-DBL_MAX));
  EXPECT_TRUE(std::isnan(lfc::abs(NAN)));
}

TEST(lfc_math, test_ceil_double_1)
{
  // PositiveNumbers
  EXPECT_DOUBLE_EQ(3.0, lfc::ceil(3.0));
  EXPECT_DOUBLE_EQ(4.0, lfc::ceil(3.1));
  EXPECT_DOUBLE_EQ(4.0, lfc::ceil(3.5));
  EXPECT_DOUBLE_EQ(4.0, lfc::ceil(3.9));
  EXPECT_DOUBLE_EQ(123457.0, lfc::ceil(123456.789));

  // NegativeNumbers
  EXPECT_DOUBLE_EQ(-2.0, lfc::ceil(-2.0));
  EXPECT_DOUBLE_EQ(-2.0, lfc::ceil(-2.1));
  EXPECT_DOUBLE_EQ(-2.0, lfc::ceil(-2.5));
  EXPECT_DOUBLE_EQ(-2.0, lfc::ceil(-2.9));
  EXPECT_DOUBLE_EQ(-123456.0, lfc::ceil(-123456.789));

  // Zero
  EXPECT_DOUBLE_EQ(0.0, lfc::ceil(0.0));
  EXPECT_DOUBLE_EQ(-0.0, lfc::ceil(-0.0));

  EXPECT_EQ(std::signbit(0.0), std::signbit(lfc::ceil(0.0)));
  EXPECT_EQ(std::signbit(-0.0), std::signbit(lfc::ceil(-0.0)));

  // SpecialValues
  EXPECT_TRUE(std::isinf(lfc::ceil(std::numeric_limits<double>::infinity())));
  EXPECT_GT(lfc::ceil(std::numeric_limits<double>::infinity()), 0);
  
  EXPECT_TRUE(std::isinf(lfc::ceil(-std::numeric_limits<double>::infinity())));
  EXPECT_LT(lfc::ceil(-std::numeric_limits<double>::infinity()), 0);
  
  EXPECT_TRUE(std::isnan(lfc::ceil(std::numeric_limits<double>::quiet_NaN())));

  // BoundaryValues
  EXPECT_DOUBLE_EQ(std::numeric_limits<double>::max(), 
                  lfc::ceil(std::numeric_limits<double>::max()));
  
  EXPECT_DOUBLE_EQ(std::numeric_limits<double>::lowest(), 
                  lfc::ceil(std::numeric_limits<double>::lowest()));
  
  EXPECT_DOUBLE_EQ(1.0, lfc::ceil(std::numeric_limits<double>::min()));
}

TEST(lfc_math, test_ceil_float_1)
{
  // Test float specialization
  EXPECT_FLOAT_EQ(3.0f, lfc::ceil(3.0f));
  EXPECT_FLOAT_EQ(4.0f, lfc::ceil(3.1f));
  EXPECT_FLOAT_EQ(-2.0f, lfc::ceil(-2.9f));
}

TEST(lfc_math, test_ceil_integral_1)
{
  // Integral types should return unchanged
  EXPECT_EQ(5, lfc::ceil(5));
  EXPECT_EQ(-3, lfc::ceil(-3));
  EXPECT_EQ(0, lfc::ceil(0));
  EXPECT_EQ(123456789LL, lfc::ceil(123456789LL));
}

TEST(lfc_math, test_ceil_edge_cases)
{
  // Values just below integer boundaries
  // EXPECT_DOUBLE_EQ(1.0, lfc::ceil(std::nextafter(1.0, 0.0))); // @TODO need fix
  EXPECT_DOUBLE_EQ(0.0, lfc::ceil(std::nextafter(0.0, -1.0)));
  EXPECT_DOUBLE_EQ(-1.0, lfc::ceil(std::nextafter(-1.0, -2.0)));

  // Large numbers that are exact integers
  constexpr double large = 1e15;
  EXPECT_DOUBLE_EQ(large, lfc::ceil(large));
  EXPECT_DOUBLE_EQ(-large, lfc::ceil(-large));
}

TEST(lfc_math, test_ceil_type_preservation)
{
  // Verify return types match input types
  static_assert(std::is_same_v<float, decltype(lfc::ceil(1.0f))>);
  static_assert(std::is_same_v<double, decltype(lfc::ceil(1.0))>);
  static_assert(std::is_same_v<long double, decltype(lfc::ceil(1.0L))>);
  static_assert(std::is_same_v<int, decltype(lfc::ceil(1))>);
}

TEST(lfc_math, test_floor_double_1)
{
  // PositiveNumbers
  EXPECT_DOUBLE_EQ(3.0, lfc::floor(3.0));
  EXPECT_DOUBLE_EQ(3.0, lfc::floor(3.1));
  EXPECT_DOUBLE_EQ(3.0, lfc::floor(3.5));
  EXPECT_DOUBLE_EQ(3.0, lfc::floor(3.9));
  EXPECT_DOUBLE_EQ(123456.0, lfc::floor(123456.789));

  // NegativeNumbers
  EXPECT_DOUBLE_EQ(-2.0, lfc::floor(-2.0));
  EXPECT_DOUBLE_EQ(-3.0, lfc::floor(-2.1));
  EXPECT_DOUBLE_EQ(-3.0, lfc::floor(-2.5));
  EXPECT_DOUBLE_EQ(-3.0, lfc::floor(-2.9));
  EXPECT_DOUBLE_EQ(-123457.0, lfc::floor(-123456.789));

  // Zero
  EXPECT_DOUBLE_EQ(0.0, lfc::floor(0.0));
  EXPECT_DOUBLE_EQ(-0.0, lfc::floor(-0.0));

  EXPECT_EQ(std::signbit(0.0), std::signbit(lfc::floor(0.0)));
  EXPECT_EQ(std::signbit(-0.0), std::signbit(lfc::floor(-0.0)));

  // SpecialValues
  EXPECT_TRUE(std::isinf(lfc::floor(std::numeric_limits<double>::infinity())));
  EXPECT_GT(lfc::floor(std::numeric_limits<double>::infinity()), 0);
  
  EXPECT_TRUE(std::isinf(lfc::floor(-std::numeric_limits<double>::infinity())));
  EXPECT_LT(lfc::floor(-std::numeric_limits<double>::infinity()), 0);
  
  EXPECT_TRUE(std::isnan(lfc::floor(std::numeric_limits<double>::quiet_NaN())));

  // BoundaryValues
  EXPECT_DOUBLE_EQ(std::numeric_limits<double>::max(), 
                  lfc::floor(std::numeric_limits<double>::max()));
  
  EXPECT_DOUBLE_EQ(std::numeric_limits<double>::lowest(), 
                  lfc::floor(std::numeric_limits<double>::lowest()));
  
  EXPECT_DOUBLE_EQ(0.0, lfc::floor(std::numeric_limits<double>::min()));
}

TEST(lfc_math, test_isinf_1) 
{
  // RegularNumbers
  EXPECT_FALSE(lfc::isinf(0.0));
  EXPECT_FALSE(lfc::isinf(1.0));
  EXPECT_FALSE(lfc::isinf(-1.0));
  EXPECT_FALSE(lfc::isinf(3.14159));

  // PositiveInfinity
  double pos_inf = std::numeric_limits<double>::infinity();
  EXPECT_TRUE(lfc::isinf(pos_inf));
  EXPECT_TRUE(lfc::isinf(1.0 / 0.0));
  EXPECT_TRUE(lfc::isinf(std::exp(800.0)));  // 可能生成+∞

  // NegativeInfinity
  double neg_inf = -std::numeric_limits<double>::infinity();
  EXPECT_TRUE(lfc::isinf(neg_inf));
  EXPECT_TRUE(lfc::isinf(-1.0 / 0.0));
  EXPECT_TRUE(lfc::isinf(std::log(0.0)));

  // NaN
  double nan = std::numeric_limits<double>::quiet_NaN();
  EXPECT_FALSE(lfc::isinf(nan));
  EXPECT_FALSE(lfc::isinf(0.0 / 0.0));
  EXPECT_FALSE(lfc::isinf(std::sqrt(-1.0)));

  // DifferentTypes
  EXPECT_TRUE(lfc::isinf(std::numeric_limits<float>::infinity()));
  EXPECT_TRUE(lfc::isinf(std::numeric_limits<double>::infinity()));
  // EXPECT_TRUE(lfc::isinf(std::numeric_limits<long double>::infinity()));

  // EdgeCases
  EXPECT_FALSE(lfc::isinf(std::numeric_limits<double>::max()));
  EXPECT_FALSE(lfc::isinf(std::numeric_limits<double>::min()));
  EXPECT_FALSE(lfc::isinf(std::numeric_limits<double>::denorm_min()));

  // SpecialOperations
  EXPECT_TRUE(lfc::isinf(std::pow(2.0, 1024.0)));  // 可能生成+∞
  EXPECT_TRUE(lfc::isinf(-std::pow(2.0, 1024.0))); // 可能生成-∞
}

TEST(lfc_math, test_isnan_1) 
{
  // RegularNumbers
  EXPECT_FALSE(lfc::isnan(0.0));
  EXPECT_FALSE(lfc::isnan(1.0));
  EXPECT_FALSE(lfc::isnan(-1.0));
  EXPECT_FALSE(lfc::isnan(3.14159));

  // ExplicitNan
  double nan1 = std::numeric_limits<double>::quiet_NaN();
  double nan2 = std::numeric_limits<float>::quiet_NaN();
  EXPECT_TRUE(lfc::isnan(nan1));
  EXPECT_TRUE(lfc::isnan(nan2));

  // GeneratedNan
  EXPECT_TRUE(lfc::isnan(0.0 / 0.0));
  EXPECT_TRUE(lfc::isnan(std::sqrt(-1.0)));
  EXPECT_TRUE(lfc::isnan(std::log(-1.0)));
  EXPECT_TRUE(lfc::isnan(std::acos(2.0)));

  // Infinity
  double inf = std::numeric_limits<double>::infinity();
  EXPECT_FALSE(lfc::isnan(inf));
  EXPECT_FALSE(lfc::isnan(-inf));

  // DifferentTypes
  EXPECT_TRUE(lfc::isnan(std::numeric_limits<float>::quiet_NaN()));
  EXPECT_TRUE(lfc::isnan(std::numeric_limits<double>::quiet_NaN()));
  EXPECT_TRUE(lfc::isnan(std::numeric_limits<long double>::quiet_NaN()));

  // EdgeCases
  EXPECT_FALSE(lfc::isnan(std::numeric_limits<double>::max()));
  EXPECT_FALSE(lfc::isnan(std::numeric_limits<double>::min()));
  EXPECT_FALSE(lfc::isnan(std::numeric_limits<double>::denorm_min()));
}

