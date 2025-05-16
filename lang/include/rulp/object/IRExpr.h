// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IREXPR_H__
#define __RULP_LANG_IREXPR_H__
#include "rulp/object/IRList.h"
namespace lfc {

class IRExpr : virtual public IRList {

public:

	virtual bool isEarly() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IREXPR_H__