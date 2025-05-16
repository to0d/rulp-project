// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_OBJ_ITER_ABSREFOBJITER_H__
#define __RULP_OBJ_ITER_ABSREFOBJITER_H__
#include "rulp/object/IRObjectIterator.h"
#include "rulp/object/AbsRefObject.h"

namespace lfc {

class AbsRefObjectIterator 
  : public AbsRefObject
  , virtual public IRObjectIterator
{

public:

  virtual RType getType() const override;

  virtual const std::string& asString() const override;

protected:
  
  mutable std::string _string;

};


} // namespace lfc
#endif //__RULP_OBJ_ITER_ABSREFOBJITER_H__