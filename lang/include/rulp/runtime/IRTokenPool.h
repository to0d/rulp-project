// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRTOKENPOOL_H__
#define __RULP_RUNTIME_IRTOKENPOOL_H__

#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RName.h"
#include "rulp/lang/RType.h"
#include "rulp/lang/RToken.h"

namespace lfc {

class IRTokenPool {
 
public:
  virtual ~IRTokenPool() = default;

public:

  virtual Token* createToken(TokenType type, StrConstRef value, int pos) = 0;
  virtual RName* createRName(StrConstRef nameSpace, StrConstRef prefix, StrConstRef subName, StrConstRef fullName) = 0;

public:

  int getStringId(StrConstRef str);

};



} // namespace lfc
#endif //__RULP_RUNTIME_IRTOKENPOOL_H__