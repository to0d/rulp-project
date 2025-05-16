// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRAFTERANNOTATION_H__
#define __RULP_RUNTIME_IRAFTERANNOTATION_H__

#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class IRAfterAnnotation
{
public:

  virtual IRObject* build(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRAFTERANNOTATION_H__