// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRLONG_REF
#define __RULP_LANG_XRLONG_REF
#include "rulp/object/IRLong.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRLongRef 
  : public AbsRefObject
  , virtual public IRLong 
{

public:

  XRLongRef();
  XRLongRef(RLong value);

public:

  virtual RLong asLong() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

private:

  RLong value;
  mutable std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRLONG_REF