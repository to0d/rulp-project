// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_PARSER_H__
#define __RULP_LANG_PARSER_H__
#include <vector>
#include "rulp/lang/base.h"
#include "rulp/lang/base.h"
#include "rulp/object/IRObject.h"
#include "rulp/parse/IRTokener.h"
#include "rulp/runtime/IRTokenPool.h"

namespace lfc {

class IRParser{

public:
  virtual ~IRParser() = default;

  virtual std::vector<IRObject*> parse(StrConstRef line) = 0;

  virtual IRTokener* getTokener() const = 0;

  virtual IRTokenPool* getContext() const = 0;

  virtual void setContext(IRTokenPool* context) = 0;

  virtual void setTokener(IRTokener* tokener) = 0;  

  virtual void setSupportComment(bool supportComment) = 0;

  virtual void setSupportNumber(bool supportNumber) = 0;

  virtual void registerPrefix(StrConstRef prefix, StrConstRef nameSpace) = 0;


};

} // namespace lfc
#endif //__RULP_LANG_PARSER_H__