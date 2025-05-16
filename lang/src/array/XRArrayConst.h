// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_XRRRAY_CONST_H__
#define __RULP_LANG_XRRRAY_CONST_H__
#include "rulp/object/IRArray.h"
#include "../list/AbsRList.h"
#include "assert.h"

namespace lfc {

class XRArrayConst 
  : public AbsRefObject
  , virtual public IRArray
{

protected:

  XRArrayConst() = default;

public:

  virtual ~XRArrayConst() = default;

public:

  static XRArrayConst* build(std::vector<IRObject*>&& elements);

public:

  virtual void add(IRObject* obj) override;

  virtual const std::string& asString() const override;

  virtual IRArray* cloneArray() const override;

  virtual IRObject* get(int index) const override;

  virtual IRObject* get(const std::vector<int>& indexs) const override;

  virtual int getDimension() const override;

  virtual int getElementCount() const override;

  virtual RType getType() const override;

  virtual bool isConst() const override { return true; }

  virtual bool isEmpty() const override;

  virtual void set(int index, IRObject* obj) override;

  virtual int size() const override;

  virtual int size(int dim) const override;

protected:

  virtual void  _delete() override;

  IRObject* _get(const IRObject* arrayObj, const std::vector<int>& indexs, int from) const;

protected:

  std::vector<int> arraySize;

  std::vector<IRObject*> elements;

  int elementCount = 0;

  mutable std::string _string;
 
};


} // namespace lfc
#endif //__RULP_LANG_XRRRAY_CONST_H__