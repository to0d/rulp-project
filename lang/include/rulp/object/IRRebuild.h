// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_OBJ_IRREBUILD_H__
#define __RULP_OBJ_IRREBUILD_H__

#include "rulp/runtime/IRFactor.h"
#include <string>

namespace lfc {

class IRRebuild : virtual public IRFactor {
public:

  virtual std::string getRebuildInformation() = 0;

};

} // namespace lfc
#endif //__RULP_OBJ_IRREBUILD_H__