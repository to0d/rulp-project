// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRPARAATTR_REF
#define __RULP_LANG_XRPARAATTR_REF
#include "rulp/object/IRParaAttr.h"
#include "rulp/lang/RGlobal.h"
#include "XRVarRef.h"
namespace lfc {

class XRParaAttr 
  : public XRVarRef
  , virtual public IRParaAttr
{

public:

  XRParaAttr(StrConstRef paraName, IRAtom* paraType);

public:

  virtual IRAtom* getParaType() const override;

	virtual std::string getParaName() const override;

private:

  IRAtom* paraType = NULL;

};

} // namespace lfc
#endif //__RULP_LANG_XRPARAATTR_REF