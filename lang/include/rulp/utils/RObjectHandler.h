// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_ROBJ_HANDLER_H__
#define __RULP_UTILS_ROBJ_HANDLER_H__

#include "rulp/object/IRObject.h"
namespace lfc {

class RObjectHandler {

public:

  RObjectHandler() {};
  RObjectHandler(IRObject* obj);
  RObjectHandler(const RObjectHandler& RH);
  RObjectHandler(RObjectHandler&& RH);
  
  ~RObjectHandler();

  IRObject* get();

  void set(IRObject* ob);

  RObjectHandler& operator=(const RObjectHandler &RH);
  RObjectHandler& operator=(RObjectHandler &&RH);
  RObjectHandler& operator=(IRObject* obj);

  operator IRObject* () const {
    return obj;
  }

private:

  IRObject* obj = NULL;

};

typedef RObjectHandler ROH;


} // namespace lfc
#endif //__RULP_UTILS_ROBJ_HANDLER_H__