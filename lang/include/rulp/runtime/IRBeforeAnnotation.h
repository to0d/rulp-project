// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRBEFOREANNOTATION_H__
#define __RULP_RUNTIME_IRBEFOREANNOTATION_H__

#include "rulp/object/IRList.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class IRBeforeAnnotation
{
public:

  virtual IRList* build(IRList* obj, IRInterpreter* interpreter, IRFrame* frame) = 0;

};


} // namespace lfc
#endif //__RULP_RUNTIME_IRBEFOREANNOTATION_H__