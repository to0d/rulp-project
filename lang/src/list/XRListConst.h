// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRLISTCONST
#define __RULP_LANG_XRLISTCONST
#include "rulp/object/IRList.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRIterator.h"
#include "AbsRList.h"
#include "assert.h"

namespace lfc {

class XRListConst 
  : public AbsRList
  , virtual public IRList
  , virtual public IRExpr
{

public:

  XRListConst(RType type);

  XRListConst(RType type, std::string name, std::vector<IRObject*>&& elements, bool earlyExpresion);

  virtual ~XRListConst() = default;

public:

  virtual void add(IRObject* obj) override;

  virtual IRObject* get(int index) const override;
  
  virtual int size() const override;
  
  virtual bool isConst() const override;
  
  virtual bool isEarly() const override;
  
  virtual bool isEmpty() const override;

public:

  virtual IRIteratorPtr listIterator(int from) const override;

protected:

  virtual void  _delete() override;

private:

  std::vector<IRObject*> elements;
  bool earlyExpresion;

};


} // namespace lfc
#endif //__RULP_LANG_XRATOM