// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRDOUBLE_GLOBAL
#define __RULP_LANG_XRDOUBLE_GLOBAL
#include "rulp/object/IRDouble.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRDoubleGlobal 
  : public AbsAtomObject
  , virtual public IRDouble 
{

public:

  XRDoubleGlobal(double value);
  virtual ~XRDoubleGlobal() = default;

public:

  virtual double asDouble() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

public:

  void setString(std::string str);

private:

  double value;
  std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRDOUBLE_GLOBAL