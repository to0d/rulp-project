// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRVAR_REF
#define __RULP_LANG_XRVAR_REF
#include "rulp/object/IRVar.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {


class XRVarRef 
  : public AbsRefObject
  , virtual public IRVar
{
  
public:

  XRVarRef(StrConstRef varName);
  virtual ~XRVarRef();

public:

  virtual void addVarListener(var_change_listener listener) override;

  virtual void addVarListener(var_change_func func) override;

  virtual const std::string& asString() const override;

  virtual RType getType() const override;

	virtual std::string getName() const override;

	virtual IRObject* getValue() const override;

	virtual void setValue(IRObject* newVal) override;

protected:

  void fireValueChanged(IRObject* oldVal, IRObject* newVal);

  virtual void  _delete() override;

private:

  std::string varName;
  
  IRObject* value = O_Nil;

  mutable std::string _asString;

  std::vector<var_change_listener>* varListenerList = null;

};

} // namespace lfc
#endif //__RULP_LANG_XRVAR_REF