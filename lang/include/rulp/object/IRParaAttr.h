// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRPARAATTR_H__
#define __RULP_LANG_IRPARAATTR_H__
#include "rulp/object/IRObject.h"
#include "rulp/object/IRAtom.h"
namespace lfc {

class IRParaAttr 
  : virtual public IRObject
{

public:

  virtual std::string getParaName() const = 0;

  virtual IRAtom* getParaType() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRPARAATTR_H__