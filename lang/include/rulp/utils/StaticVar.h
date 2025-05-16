// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_STATICVAR_H__
#define __RULP_LANG_STATICVAR_H__
#include "rulp/lang/RGlobal.h"
#include "rulp/object/IRVar.h"

namespace lfc {

class StaticVar {

public:

  StaticVar(const std::string& varName, IRObject* value);
  ~StaticVar(); 

  StaticVar(const StaticVar&) = delete;
  StaticVar& operator=(const StaticVar&) = delete;

public:

  bool getBoolValue();
  IRObject* getValue();
  IRVar* getVar();
    
  void init(IRFrame* frame);
  void setBoolValue(bool newVal);

private:

  IRObject* curValue;
  IRObject* defaultValue;
  IRVar   * var;
  std::string varName;

};

}

#endif //__RULP_LANG_STATICVAR_H__