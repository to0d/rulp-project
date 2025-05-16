// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/xday.h"
#include <sstream>

using namespace lfc;

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorDayOfWeek)

if (args->size() != 2) {
  throw RException("Invalid parameters: " + args->asString());
}

ROH rst = interpreter->compute(frame, args->get(1));
auto dayString = AS_STR(rst)->asString();

return RulpFactory::createInteger(XDay::getDay(dayString).getDayOfWeek());

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDayOfWeek, F_DAY_OF_WEEK);

} // namespace lfc