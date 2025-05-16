// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRBOOLEAN_H__
#define __RULP_LANG_IRBOOLEAN_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRBoolean : virtual public IRObject {

public:

  virtual bool asBoolean() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRBOOLEAN_H__