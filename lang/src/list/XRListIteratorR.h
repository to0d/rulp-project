// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRLIST_IT_R_H__
#define __RULP_LANG_XRLIST_IT_R_H__
#include "AbsRListIterator.h"


namespace lfc {

class XRListIteratorR 
  : public AbsRListIterator
  , virtual public IRList
  , virtual public IRExpr
{

public:

  XRListIteratorR(IRObject* list, IRIteratorPtr iter, RType type, std::string name);

  virtual ~XRListIteratorR() = default;

public:

  virtual void add(IRObject* obj) override;
 
  virtual int size() const override;
  
  virtual bool isConst() const override;
  
protected:

  virtual void  _delete() override;
  
  virtual boolean _scanTo(int toIndex) const override;

private:

  IRObject* list = null;

  IRIteratorPtr inputIterator = null;
  
  mutable int scanSize = 0;

};


} // namespace lfc
#endif //__RULP_LANG_XRLIST_IT_R_H__