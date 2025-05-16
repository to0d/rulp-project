// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/RuleUtil.h"
#include "rulp/utils/StaticVar.h"

namespace lfc {

static StaticVar varTraceModel(A_M_TRACE, O_False);

boolean RuleUtil::isModelTrace()  {
  return varTraceModel.getBoolValue();
}

}