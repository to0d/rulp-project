// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_XIMPL_RUNTIME_XRTOKENPOOL_H__
#define __RULP_XIMPL_RUNTIME_XRTOKENPOOL_H__
#include <vector>
#include <map>
#include "rulp/lang/RToken.h"
#include "rulp/runtime/IRTokenPool.h"
namespace lfc {

class XRTokenPool : virtual public IRTokenPool{
public:
  XRTokenPool();
  virtual ~XRTokenPool();

public:

  virtual Token* createToken(TokenType type, StrConstRef value, int pos) override;
  virtual RName* createRName(StrConstRef nameSpace, StrConstRef prefix, StrConstRef subName, StrConstRef fullName) override;

public:

  int getStringId(StrConstRef str);

private:

  void _free_all();

private:
  
  std::vector<RName*> all_rnames;
  std::vector<Token*> all_tokens;
  Token END_TOKEN;

  std::map<std::string, int> str_id_map;
  int max_str_id = 1;

};

} // namespace lfc
#endif //__RULP_XIMPL_RUNTIME_XRTOKENPOOL_H__