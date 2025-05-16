// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRFRAME_ENTRY_H__
#define __RULP_RUNTIME_IRFRAME_ENTRY_H__
#include "rulp/object/IRMember.h"
namespace lfc {

class IRFrame;
class IRFrameEntry 
  : virtual public IRMember
{
public:
    
  virtual const StrList* getAliasName() const = 0;

  virtual int getEntryId() const = 0;

  virtual IRFrame* getFrame() const = 0;

  virtual std::string getName() const = 0;

  virtual IRObject* getObject() const = 0;

  virtual void setObject(IRObject* object) = 0;
};


} // namespace lfc
#endif //__RULP_RUNTIME_IRFRAME_ENTRY_H__