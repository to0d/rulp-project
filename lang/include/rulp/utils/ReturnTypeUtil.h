// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_RETURN_TYPE_UTIL_H__
#define __RULP_UTILS_RETURN_TYPE_UTIL_H__

#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRFrame.h"
namespace lfc {

class ReturnTypeUtil{
public:
  
  static IRAtom* returnTypeOf(IRObject* obj, IRFrame* frame);
};

} // namespace lfc
#endif //__RULP_UTILS_RETURN_TYPE_UTIL_H__