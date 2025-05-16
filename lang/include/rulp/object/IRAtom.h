// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRATOM_H__
#define __RULP_LANG_IRATOM_H__
#include "rulp/object/IRObject.h"
#include "rulp/lang/RName.h"
namespace lfc {

class IRAtom : virtual public IRObject {

public:
  virtual ~IRAtom() = default;

public:
  virtual std::string getName() const = 0;
  virtual RName* getRName() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRATOM_H__