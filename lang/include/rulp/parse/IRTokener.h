// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRTOKENER_H__
#define __RULP_LANG_IRTOKENER_H__
#include "rulp/lang/base.h"
#include "rulp/lang/RToken.h"
#include "rulp/runtime/IRTokenPool.h"
namespace lfc {

class IRTokener{
public:
  virtual ~IRTokener() = default;

  virtual IRTokenPool* getContext() const = 0;

  virtual void setContext(IRTokenPool* context) = 0;
  
  virtual void setContent(StrConstRef content) = 0;
  
  virtual Token* next() = 0;
  
  virtual Token* peek() = 0;
};

} // namespace lfc
#endif //__RULP_LANG_IRTOKENER_H__
