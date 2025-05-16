// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IROBJECTITER_H__
#define __RULP_LANG_IROBJECTITER_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRObjectIterator : virtual public IRObject {

public:

  virtual boolean hasNext() const = 0;

  virtual IRObject* next() = 0;

  virtual IRObject* peek() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IROBJECTITER_H__