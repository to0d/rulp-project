// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRINTEGER_REF
#define __RULP_LANG_XRINTEGER_REF
#include "rulp/object/IRInteger.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRIntegerRef 
  : public AbsRefObject
  , virtual public IRInteger 
{

public:

  XRIntegerRef();
  XRIntegerRef(int value);

public:

  virtual int asInteger() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

private:

  int value;
  mutable std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRINTEGER_REF