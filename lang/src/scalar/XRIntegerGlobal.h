// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRINTEGER_GLOBAL
#define __RULP_LANG_XRINTEGER_GLOBAL
#include "rulp/object/IRInteger.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRIntegerGlobal 
  : public AbsAtomObject
  , virtual public IRInteger 
{

public:

  XRIntegerGlobal();
  XRIntegerGlobal(int value);

public:

  virtual int asInteger() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

public:

  void setValue(int value);
  void setString(std::string str);

private:

  int value;
  std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRINTEGER_GLOBAL