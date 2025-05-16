// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRLONG_H__
#define __RULP_LANG_IRLONG_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRLong : virtual public IRObject {

public:

  virtual RLong asLong() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRLONG_H__