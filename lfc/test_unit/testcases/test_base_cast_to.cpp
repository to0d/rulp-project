#include "unitest_base.h"
#include "lfc/base/cast.h"

using namespace lfc;

TEST(base_cast, TO_INT_1)
{
  EXPECT_EQ(1, TO_INT(std::string("1")));
}

TEST(base_cast, TO_LONG_1)
{
  EXPECT_EQ(1, TO_LONG(std::string("1")));
  EXPECT_EQ(2147483647, TO_LONG(std::string("2147483647")));                    // max long in 32bit
  EXPECT_EQ(9223372036854775807, TO_LONG(std::string("9223372036854775807")));  // max long in 64bit 
  EXPECT_EQ(9223372036854775807, TO_LONG(std::string("9223372036854775808")));  // #TODO why 2024/12/23
}

TEST(base_cast, TO_LONG_LONG_1)
{
  EXPECT_EQ(1, TO_LONG_LONG(std::string("1")));
  EXPECT_EQ(9223372036854775807, TO_LONG_LONG(std::string("9223372036854775807")));   // max long long in 64bit 
  EXPECT_EQ(-9223372036854775808, TO_LONG_LONG(std::string("-9223372036854775808"))); // min long long in 64bit 
}

TEST(base_cast, TO_UINT128_1)
{
  EXPECT_EQ(1, TO_UINT128(std::string("1")));

  __uint128_t v1 = 9223372036854775808;
  EXPECT_EQ(v1, TO_UINT128(std::string("9223372036854775808")));

  EXPECT_EQ(429503283210,  TO_UINT128(std::string("429503283210")));
}

TEST(base_cast, TO_FLOAT_1)
{
  EXPECT_EQ(1.0f, TO_FLOAT(std::string("1.0")));
}

TEST(base_cast, TO_DOUBLE_1)
{
  EXPECT_EQ(1, TO_DOUBLE(std::string("1.0")));
}

TEST(base_cast, TO_HEX_STR_1)
{
  EXPECT_STREQ("0000000000000001", TO_HEX_STR((uint64_t)1).c_str());
  EXPECT_STREQ("00000000000000FF", TO_HEX_STR((uint64_t)255).c_str());
}


TEST(base_cast, TO_BIT_STR_1)
{
  EXPECT_STREQ("00000000", TO_BIT_STR(0).c_str());
  EXPECT_STREQ("00000001", TO_BIT_STR(1).c_str());
  EXPECT_STREQ("11111111", TO_BIT_STR(255).c_str());
}

TEST(base_cast, HEX_STR_TO_BYTES_1)
{
  EXPECT_STREQ("{255}", TO_STR(HEX_STR_TO_BYTES("FF")).c_str());
  EXPECT_STREQ("{1,35,69,103,137,171,239}", TO_STR(HEX_STR_TO_BYTES("0123456789ABEF")).c_str());
}

