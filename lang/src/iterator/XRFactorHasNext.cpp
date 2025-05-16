// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorHasNext)

  ROH obj = interpreter->compute(frame, args->get(1));
	return RulpFactory::createBoolean(AS_ITERATOR(obj.get())->hasNext());

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorHasNext, F_HAS_NEXT);

} // namespace lfc
