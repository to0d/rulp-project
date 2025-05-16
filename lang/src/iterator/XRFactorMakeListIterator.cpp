// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorMakeListIterator)

  ROH obj = interpreter->compute(frame, args->get(1));
	return RulpFactory::createObjectIterator(AS_LIST(obj.get()));

XRFACTOR_IMPL_ARG(2, 2)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorMakeListIterator, F_MAKE_LIST_ITERATOR);

} // namespace lfc
