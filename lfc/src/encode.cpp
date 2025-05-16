#include "lfc/base/encode.h"
#include <sstream>
namespace lfc {

char to_hex_char(int value) {
  if (value >= 0 && value <= 9) {
    return '0' + value;
  } 
  else if (value >= 10 && value <= 15) {
    return 'A' + (value - 10);
  }
  return '?';  // 非法值
}

std::string EncodeUtil::convertBytesToHexString(const char* b, int pos, int len) {
  std::stringstream ss;

  for (int i = pos; i < pos + len; i++) {

    char c = b[i];
    char c1 = to_hex_char(c & 0xF);         // 低 4 位
    char c2 = to_hex_char((c >> 4) & 0xF);  // 高 4 位
    ss << c2 << c1;
  }

  return ss.str();

}

#define INT_MASK_0_BYTE   0xff
#define LENGTH_INT        4
#define LENGTH_LONG       8
#define LONG_MASK_0_BYTE  0xff

static_assert(sizeof(int)  == 4);
static_assert(sizeof(long long) == 8);
static_assert(sizeof(float) == 4);
static_assert(sizeof(double) == 8);

int EncodeUtil::encodeInt(int value, char* buf, int offset) {
  buf[offset++] = (char) ((value >> 24) & INT_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 16) & INT_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 8) & INT_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 0) & INT_MASK_0_BYTE);
  return LENGTH_INT;
}

int EncodeUtil::encodeLong(long long value, char* buf, int offset) {

  buf[offset++] = (char) ((value >> 56) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 48) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 40) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 32) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 24) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 16) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 8) & LONG_MASK_0_BYTE);
  buf[offset++] = (char) ((value >> 0) & LONG_MASK_0_BYTE);

  return LENGTH_LONG;
}

int32_t floatToRawIntBits(float value) {
  union {
      float f;
      int32_t i;
  } converter;
  converter.f = value;
  return converter.i;
}

int EncodeUtil::encodeFloat(float value, char* buf, int offset) {
  return encodeInt(floatToRawIntBits(value), buf, offset);
}

int EncodeUtil::encodeDouble(double value, char* buf, int offset) {
  long long* p = (long long*) &value;
  return encodeLong(*p, buf, offset);
}

} // namespace lfc