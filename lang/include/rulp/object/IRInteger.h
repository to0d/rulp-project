// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRINTEGER_H__
#define __RULP_LANG_IRINTEGER_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRInteger : virtual public IRObject {

public:

  virtual RInt asInteger() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRINTEGER_H__