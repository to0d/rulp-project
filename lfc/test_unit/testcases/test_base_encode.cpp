#include "unitest_base.h"
#include "lfc/base/encode.h"

using namespace lfc;

static void _test_encode_int(int v, std::string expect) {
  char buf[10];
  int len = EncodeUtil::encodeInt(v, buf, 0);
  assert(len == 4);
  
  std::vector<int> rst;
  for(int i = 0; i < 4; ++i) {
    rst.push_back((int)buf[i]);
  }

  EXPECT_STREQ(expect.c_str(), TO_STR(rst).c_str());
}

TEST(base_encode, encode_int_1)
{
  _test_encode_int(1  , "{0,0,0,1}");
  _test_encode_int(100, "{0,0,0,100}");
  _test_encode_int(257, "{0,0,1,1}");
}

static void _test_encode_long(long long v, std::string expect) {
  char buf[10];
  int len = EncodeUtil::encodeLong(v, buf, 0);
  assert(len == 8);
  
  std::vector<int> rst;
  for(int i = 0; i < 8; ++i) {
    rst.push_back((int)buf[i]);
  }

  EXPECT_STREQ(expect.c_str(), TO_STR(rst).c_str());
}

TEST(base_encode, encode_long_1)
{
  _test_encode_long(1  , "{0,0,0,0,0,0,0,1}");
  _test_encode_long(100, "{0,0,0,0,0,0,0,100}");
  _test_encode_long(257, "{0,0,0,0,0,0,1,1}");
}

static void _test_encode_float(float v, std::string expect) {
  char buf[10];
  int len = EncodeUtil::encodeFloat(1.0f, buf, 0);
  assert(len == 4);
  
  std::vector<int> rst;
  for(int i = 0; i < 8; ++i) {
    rst.push_back((int)buf[i]);
  }

  EXPECT_STREQ(expect.c_str(), TO_STR(rst).c_str());
}

TEST(base_encode, encode_float_1)
{
  // _test_encode_float(0.0f, "{0,0,0,0,0,0,-120,-27}");
}
