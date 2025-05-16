// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRTokenPool.h"
#include "rulp/utils/RulpFactory.h"
#include "lfc/base/auto/auto_free.h"

using namespace lfc;

namespace lfc {

XRTokenPool::XRTokenPool()
{
  END_TOKEN.type     = TokenType::TT_9END;
  END_TOKEN.value    = "";
  END_TOKEN.end_pos  = -1;

  str_id_map[""]     = 0;
}

XRTokenPool::~XRTokenPool(){
  _free_all();
}

void XRTokenPool::_free_all(){
  LFC_FREE_ARRAY(all_tokens);
  LFC_FREE_ARRAY(all_rnames);
}

Token* XRTokenPool::createToken(TokenType type, StrConstRef value, int pos){

  if(type == TokenType::TT_9END)
    return &END_TOKEN;  
  
  auto token = new Token;
  token->type     = type;
  token->value    = value;
  token->end_pos  = pos;

  all_tokens.push_back(token);
  return token;
}

RName* XRTokenPool::createRName(StrConstRef nameSpace, StrConstRef prefix, StrConstRef subName, StrConstRef fullName){
  auto rname = new RName(nameSpace, prefix, subName, fullName);
  all_rnames.push_back(rname);
  return rname;
}

int XRTokenPool::getStringId(StrConstRef str){
  auto it = str_id_map.find(str);
  if(it != str_id_map.end()){
    return it->second;
  }

  int id = max_str_id++;
  str_id_map[str] = id;
  return id;
}

} // namespace lfc