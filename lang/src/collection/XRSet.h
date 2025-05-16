// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_IMPL_COLLECTION_XSET_H__
#define __RULP_IMPL_COLLECTION_XSET_H__
#include "rulp/collection/IRCollection.h"
#include "../class/XRDefInstance.h"

namespace lfc {

class XRSet
 : public XRDefInstance
 , virtual public IRCollection
{
public:

  XRSet(IRClass* noClass);

  virtual ~XRSet();

public:

	virtual void clear() override;

  virtual int getInstanceKey() const override;

	virtual boolean isEmpty() const override;

  virtual	int size() const override;

public:

  void add(IRObject* obj);

  boolean has(IRObject* obj);

  std::vector<IRObject*> getValueList();

protected:

  virtual void _delete() override;

private:

  std::map<std::string, IRObject*> uniqMap;

};

} // namespace lfc
#endif //__RULP_IMPL_COLLECTION_XSET_H__