// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRDOUBLE_REF
#define __RULP_LANG_XRDOUBLE_REF
#include "rulp/object/IRDouble.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRDoubleRef 
  : public AbsRefObject
  , virtual public IRDouble 
{

public:

  XRDoubleRef(double value);
  virtual ~XRDoubleRef() = default;

public:

  virtual double asDouble() const override;
  
  virtual const std::string& asString() const override;
  
  virtual RType getType() const override;

private:

  double value;
  mutable std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRDOUBLE_REF