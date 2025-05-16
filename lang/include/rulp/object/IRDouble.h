// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRDOUBLE_H__
#define __RULP_LANG_IRDOUBLE_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRDouble : virtual public IRObject {

public:

  virtual RDouble asDouble() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRDOUBLE_H__