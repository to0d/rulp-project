// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_IMPL_COLLECTION_XMAP_H__
#define __RULP_IMPL_COLLECTION_XMAP_H__
#include "rulp/collection/IRCollection.h"
#include "../class/XRDefInstance.h"
namespace lfc {

struct RMapEntry {
	IRObject* key    = null;
  IRObject* value  = null;

  RMapEntry(IRObject* key, IRObject* value);

  void setValue(IRObject* value);
  
  void deleteEntry();

};

class XRMap
 : public XRDefInstance
 , virtual public IRCollection
{
public:

  XRMap(IRClass* noClass);

  virtual ~XRMap();

public:

  IRObject* get(IRObject* key);

  std::vector<IRObject*> getKeyList();

  std::vector<IRObject*> getValueList();

  boolean hasKey(IRObject* key);

  void put(IRObject* key, IRObject* value);  

public:

	virtual void clear() override;

  virtual int getInstanceKey() const override;

	virtual boolean isEmpty() const override;

  virtual	int size() const override;

protected:

  virtual void _delete() override;

private:

  std::map<std::string, RMapEntry*> uniqMap;

};


} // namespace lfc
#endif //__RULP_IMPL_COLLECTION_XMAP_H__