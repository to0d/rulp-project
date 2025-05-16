// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRLISTENER1_H__
#define __RULP_RUNTIME_IRLISTENER1_H__

#include "rulp/object/IRObject.h"
#include <memory>
namespace lfc {

template<typename T>
class IRListener1{ 
public:  
  
  virtual void doAction(T obj) = 0;

};

} // namespace lfc
#endif //__RULP_RUNTIME_IRLISTENER1_H__