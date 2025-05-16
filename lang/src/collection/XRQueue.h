// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_IMPL_COLLECTION_XRQUEUE_H__
#define __RULP_IMPL_COLLECTION_XRQUEUE_H__
#include "rulp/collection/IRCollection.h"
#include "../class/XRDefInstance.h"
#include <deque>

namespace lfc {

class XRQueue
 : public XRDefInstance
 , virtual public IRCollection
{
public:

  XRQueue(IRClass* noClass);

  virtual ~XRQueue();

public:

	virtual void clear() override;

  virtual int getInstanceKey() const override;

	virtual boolean isEmpty() const override;

  virtual	int size() const override;

public:

  IRObject* get(int index);

  IRObject* peek_back();

  IRObject* peek_front();

  IRObject* pop_back();

  IRObject* pop_front();

  void push_back(IRObject* obj);

  void push_front(IRObject* obj);

  std::vector<IRObject*> getValueList();

protected:

  virtual void _delete() override;

private:

  std::deque<IRObject*> elementQueue;

};

} // namespace lfc
#endif //__RULP_IMPL_COLLECTION_XRQUEUE_H__