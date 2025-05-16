// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRLISTVARY_H__
#define __RULP_LANG_XRLISTVARY_H__
#include "rulp/object/IRList.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRIterator.h"
#include "AbsRList.h"
#include "assert.h"

namespace lfc {

class XRListVary 
  : public AbsRList
  , virtual public IRList
  , virtual public IRExpr
{

public:

  XRListVary(RType type, std::string name);

  virtual ~XRListVary() = default;

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

  virtual void _delete() override;

private:

  std::vector<IRObject*>* elements = null;

  int element_size = 0;

};


} // namespace lfc
#endif //__RULP_LANG_XRLISTVARY_H__