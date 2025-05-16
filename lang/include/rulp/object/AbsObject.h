// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ABSOBJECT_H__
#define __RULP_LANG_ABSOBJECT_H__
#include "rulp/object/IRObject.h"
#include <map>
namespace lfc {

class AbsObject : virtual public IRObject{

public:
  AbsObject() = default;

  virtual ~AbsObject();

  virtual void addAttribute(StrConstRef key);

  virtual boolean containAttribute(StrConstRef key);

  virtual IRObject* getAttributeValue(StrConstRef key);

  virtual const std::vector<std::string>& getAttributeKeyList();

  virtual int getAttributeCount() const;

  void removeAllAttributes();

  IRObject* removeAttribute(StrConstRef key);

  virtual void setAttribute(StrConstRef key, IRObject* value);


protected:

  std::vector<std::string>* _attributeKeyList = null;
  std::map<std::string, IRObject*>* attributeMap = null;

};


} // namespace lfc
#endif //__RULP_LANG_ABSOBJECT_H__