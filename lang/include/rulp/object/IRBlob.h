// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRBLOB_H__
#define __RULP_LANG_IRBLOB_H__
#include "rulp/object/IRObject.h"
namespace lfc {

typedef uint8_t byte;

class IRBlob : virtual public IRObject {

public:

  virtual IRBlob* cloneBlob() const = 0;

  virtual char get(int index) const = 0;

  virtual char* getValue() const = 0;

  virtual int length() const = 0;

  virtual int read(int blob_pos, char* buf, int buf_len, int buf_pos, int length) = 0;

  virtual void set(int index, char value) = 0;

  virtual int write(int blob_pos, char* buf, int buf_len, int buf_pos, int length) = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRBLOB_H__