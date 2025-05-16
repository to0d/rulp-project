// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ABSRLIST
#define __RULP_LANG_ABSRLIST
#include "rulp/object/IRList.h"
#include "rulp/object/AbsRefObject.h"
namespace lfc {

class AbsRList 
  : public AbsRefObject
  , virtual public IRList
{

public:

  AbsRList(RType type, std::string name)
    : type(type)
    , name(name) 
  {}
  
  AbsRList(RType type)
    : type(type) 
  {}
  
  virtual ~AbsRList() = default;

public:

  virtual RType getType() const override;

  virtual const std::string& getNamedName() const override;

  virtual const std::string& asString() const override;

  virtual IRIteratorPtr iterator() const override;

protected:
  
  mutable std::string _string;
  std::string name;
  RType type;

};

} // namespace lfc
#endif //__RULP_LANG_ABSRLIST