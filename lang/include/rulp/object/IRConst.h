// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRCONST_H__
#define __RULP_LANG_IRCONST_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRConst : virtual public IRObject {

public:

  virtual std::string getName() const = 0;

  virtual IRObject* getValue() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRCONST_H__