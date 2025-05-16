// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRBLOB_REF
#define __RULP_LANG_XRBLOB_REF
#include "rulp/object/IRBlob.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRBlobRef 
  : public AbsRefObject
  , virtual public IRBlob
{

public:

  XRBlobRef(int length, const char* buf);

  XRBlobRef(int length);
  
  virtual ~XRBlobRef() = default;

public:

  virtual const std::string& asString() const override;

  virtual IRBlob* cloneBlob() const override;

  virtual char get(int index) const override;  
  
  virtual RType getType() const override;

  virtual char* getValue() const override;

  virtual int length() const override;

  virtual int read(int blob_pos, char* buf, int buf_len, int buf_pos, int len) override;

  virtual void set(int index, char value) override;

  virtual int write(int blob_pos, char* buf, int buf_len, int buf_pos, int len) override;

protected:

  virtual void  _delete() override;

  int _copy(int blob_pos, char* buf, int buf_len, int buf_pos, int len, boolean read);

private:

  char* blob_buf;
  int   blob_len;

  mutable std::string _string;
 
};

} // namespace lfc
#endif //__RULP_LANG_XRBLOB_REF