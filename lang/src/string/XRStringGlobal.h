// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRSTRING_GLOBAL
#define __RULP_LANG_XRSTRING_GLOBAL
#include "rulp/lang/RGlobal.h"
#include "rulp/object/IRString.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRStringGlobal 
  : public AbsAtomObject
  , virtual public IRString 
{

public:

  XRStringGlobal();
  XRStringGlobal(StrConstRef value);

public:

  virtual const std::string& asString() const override;
  virtual RType getType() const override;

  std::string value;

};

} // namespace lfc
#endif //__RULP_LANG_XRINTEGER_GLOBAL