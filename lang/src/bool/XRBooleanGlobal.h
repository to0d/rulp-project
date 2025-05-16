// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRBOOLEAN_GLOBAL
#define __RULP_LANG_XRBOOLEAN_GLOBAL
#include "rulp/object/AbsAtomObject.h"
#include "rulp/object/IRBoolean.h"
namespace lfc {

class XRBooleanGlobal 
  : public AbsAtomObject
  , virtual public IRBoolean 
{

public:

  XRBooleanGlobal(bool value);
  virtual ~XRBooleanGlobal() = default;

public:

  virtual bool asBoolean() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

public:

  void setString(std::string str);

private:

  bool value;
  std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRBOOLEAN_GLOBAL