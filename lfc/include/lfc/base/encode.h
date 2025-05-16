#ifndef __LFC_ENCODE_H__
#define __LFC_ENCODE_H__


#include <vector>
#include <string>

namespace lfc {

class EncodeUtil {
public:

  static std::string convertBytesToHexString(const char* b, int pos, int len);
  
  static int encodeInt(int value, char* buf, int offset);

  static int encodeLong(long long value, char* buf, int offset);

  static int encodeFloat(float value, char* buf, int offset);

  static int encodeDouble(double value, char* buf, int offset);

};

} // namespace lfc

#endif // __LFC_ENCODE_H__

