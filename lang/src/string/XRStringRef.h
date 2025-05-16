// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRSTRING_REF
#define __RULP_LANG_XRSTRING_REF
#include "rulp/lang/RGlobal.h"
#include "rulp/object/IRString.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRStringRef 
  : public AbsRefObject
  , virtual public IRString
{

public:

  XRStringRef();

  XRStringRef(StrConstRef value);

  virtual ~XRStringRef();

public:

  virtual const std::string& asString() const override;

  virtual RType getType() const override;

private:

  std::string value;

};

} // namespace lfc
#endif //__RULP_LANG_XRSTRING_REF