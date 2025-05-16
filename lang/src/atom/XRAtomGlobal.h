// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRATOM_GLOBAL
#define __RULP_LANG_XRATOM_GLOBAL
#include "rulp/object/IRAtom.h"
#include "rulp/lang/RName.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRAtomGlobal 
  : public AbsAtomObject
  , virtual public IRAtom 
{

public:

  XRAtomGlobal(){};
  XRAtomGlobal(const std::string atomName);
  XRAtomGlobal(const std::string atomName, RName* rName);
  virtual ~XRAtomGlobal() = default;

public:

  virtual const std::string& asString() const override;
  virtual std::string getName() const override;
  virtual RName* getRName() const override;
  virtual RType getType() const override;

  void setName(StrConstRef name);

private:
	std::string atomName;
	RName* rName = NULL;

};


} // namespace lfc
#endif //__RULP_LANG_XRATOM_GLOBAL