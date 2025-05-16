// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRCONST_REF
#define __RULP_LANG_XRCONST_REF
#include "rulp/object/IRConst.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class XRConstRef 
  : public AbsRefObject
  , virtual public IRConst 
{

public:

  XRConstRef(StrConstRef varName, IRObject* value);
  virtual ~XRConstRef() = default;

public:

  virtual const std::string& asString() const override;

  virtual std::string getName() const override;

  virtual IRObject* getValue() const override;
  
  virtual RType getType() const override;

protected:

  virtual void  _delete() override;

private:

  mutable std::string _asString;

  IRObject* value;

  const std::string varName;

};

} // namespace lfc
#endif //__RULP_LANG_XRCONST_REF