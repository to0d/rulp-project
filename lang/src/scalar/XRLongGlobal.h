// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRLONG_GLOBAL
#define __RULP_LANG_XRLONG_GLOBAL
#include "rulp/object/IRLong.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRLongGlobal 
  : public AbsAtomObject
  , virtual public IRLong 
{

public:

  XRLongGlobal();
  XRLongGlobal(RLong value);

public:

  virtual RLong asLong() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

public:

  void setValue(long value);
  void setString(std::string str);

private:

  RLong value;
  std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRLONG_GLOBAL