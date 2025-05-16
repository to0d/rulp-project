// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRBlobRef.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/lang/RException.h"
#include "lfc/base/to_string.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/to_string.h"
#include <string.h>
#include <math.h>

namespace lfc {

XRBlobRef::XRBlobRef(int length, const char* value)
: blob_buf(NULL)
, blob_len(length)
{
  blob_buf = new char[length];
  memcpy(blob_buf, value, length);
}

XRBlobRef::XRBlobRef(int length)
: blob_buf(NULL)
, blob_len(length)
{
  if(length > 0){
    blob_buf = new char[length];
    memset(blob_buf, 0, length);
  }  
}

void XRBlobRef::_delete() {
  LFC_FREE_ARRAY(blob_buf);
  blob_len = 0;
}

const std::string& XRBlobRef::asString() const {
  if(_string.empty() ){
    _string = RulpUtil::toString(this, MAX_TOSTRING_LEN);
  }

  return _string;
}

IRBlob* XRBlobRef::cloneBlob() const {
  RULP_INC_OBJ_CREATE_COUNT(T_BLOB);
  return new XRBlobRef(blob_len, blob_buf);
}

RType XRBlobRef::getType() const {
  return T_BLOB;
}

char XRBlobRef::get(int index) const {
  if (index < 0 || index >= length()) {
    throw RException("invalid index: " + TO_STR(index));
  }

  return blob_buf[index];
}

char* XRBlobRef::getValue() const {
  return blob_buf;
}

int XRBlobRef::length() const {
  return blob_len;
}

int XRBlobRef::_copy(int blob_pos, char* buf, int buf_len, int buf_pos, int len, boolean read){
  
  if (blob_pos < 0 || blob_pos >= length()) {
    throw RException("invalid blob index: " + TO_STR(blob_pos));
  }

  if (buf_pos < 0 || buf_pos >= buf_len) {
    throw RException("invalid buffer index: " + TO_STR(buf_pos));
  }

  int src_max_len = std::min(blob_len - blob_pos, len);
  int dst_max_len = buf_len - buf_pos;
  int cpy_len = std::min(src_max_len, dst_max_len);

  if (cpy_len > 0) {
    if (read) {
      memcpy(buf+buf_pos, blob_buf+blob_pos, cpy_len);
    } 
    else {
      memcpy(blob_buf+blob_pos, buf+buf_pos, cpy_len);
    }
  }

  return cpy_len;
}

int XRBlobRef::read(int blob_pos, char* buf, int buf_len, int buf_pos, int len){
  return _copy(blob_pos, buf, buf_len, buf_pos, len, true);
}

void XRBlobRef::set(int index, char value) {
  if (index < 0 || index >= length()) {
    throw RException("invalid index: " + TO_STR(index));
  }

  blob_buf[index] = value;
}

int XRBlobRef::write(int blob_pos, char* buf, int buf_len, int buf_pos, int len) {
  return _copy(blob_pos, buf, buf_len, buf_pos, len, false);
}

} // namespace lfc