// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRATOM_REF
#define __RULP_LANG_XRATOM_REF
#include "rulp/object/IRAtom.h"
#include "rulp/lang/RName.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRAtomRef 
  : public AbsRefObject
  , virtual public IRAtom 
{

public:

  XRAtomRef(const std::string atomName);
  XRAtomRef(const std::string atomName, RName* rName);
  virtual ~XRAtomRef();

public:

  virtual const std::string& asString() const override;
  virtual std::string getName() const override;
  virtual RName* getRName() const override;
  virtual RType getType() const override;

private:
	
  std::string atomName;
	RName* rName = NULL;

};


} // namespace lfc
#endif //__RULP_LANG_XRATOM_REF