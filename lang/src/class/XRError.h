// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_CLASS_XRERROR_H__
#define __RULP_CLASS_XRERROR_H__
#include "rulp/object/IRError.h"
#include "rulp/class/AbsRInstance.h"
namespace lfc {

class XRError 
  : public AbsRInstance
  , virtual public IRError
{

public:
  
  XRError(IRClass* noClass, IRAtom* id, IRObject* value);

  virtual ~XRError();

public:

  virtual StrConstRef asString() const override;

  virtual IRAtom* getId() const override;
  
  virtual IRObject* getValue() const override;

  virtual bool isError() const override { return true; }

protected:

  virtual void _delete() override;

private:

	IRAtom* id = null;

	IRObject* value = null;

  mutable std::string _string;

};

} // namespace lfc
#endif //__RULP_CLASS_XRERROR_H__