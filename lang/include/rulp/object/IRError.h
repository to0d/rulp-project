// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IERROR_H__
#define __RULP_LANG_IERROR_H__
#include "rulp/object/IRInstance.h"
namespace lfc {

class IRError : virtual public IRInstance {

public:
  virtual ~IRError() = default;

public:

  virtual IRAtom* getId() const = 0;

  virtual IRObject* getValue() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IERROR_H__