// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRRRAY_VARY_H__
#define __RULP_LANG_XRRRAY_VARY_H__
#include "rulp/object/IRArray.h"
#include "../list/AbsRList.h"
#include "XRArrayConst.h"

namespace lfc {

class XRArrayVary 
  : public XRArrayConst
  , virtual public IRArray
{

protected:

  XRArrayVary() = default;

public:

  virtual ~XRArrayVary() = default;


public:

  static XRArrayVary* build(const std::vector<int>& sizes);

  virtual void add(IRObject* obj) override;

  virtual IRArray* cloneArray() const override;

  virtual bool isConst() const override {return false;}

  virtual void set(int index, IRObject* obj) override;

protected:

  void _add(IRObject* obj);

  void _set(int index, IRObject* obj);
 
};


} // namespace lfc
#endif //__RULP_LANG_XRRRAY_VARY_H__