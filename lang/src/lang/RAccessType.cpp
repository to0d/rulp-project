// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RAccessType.h"
#include "rulp/lang/RConstant.h"
#include "rulp/lang/RGlobal.h"
#include <cassert>
using namespace lfc;

namespace lfc {

RAccessType toAccessType(StrConstRef name){

  if(name == A_PUBLIC){
    return RAccessType::PUBLIC;
  }

  if(name == A_PRIVATE){
    return RAccessType::PRIVATE;
  }

  if(name == A_DEFAULT){
    return RAccessType::DEFAULT;
  }

  assert(false && "unknow RAccessType");
}

IRAtom* toObject(RAccessType type){
  switch (type){
  case RAccessType::PUBLIC:   return O_Public;
  case RAccessType::PRIVATE:  return O_Private;
  case RAccessType::DEFAULT:  return O_Default;  
  default:
    break;
  }
  return O_Nan;
}

} // namespace lfc

namespace lfc {

std::string to_string(lfc::RAccessType type){
  switch (type){
  case RAccessType::PUBLIC:   return "public";
  case RAccessType::PRIVATE:  return "private";
  case RAccessType::DEFAULT:  return "default";
  default:                    return "unknown";
  }
}

} // namespace lfc