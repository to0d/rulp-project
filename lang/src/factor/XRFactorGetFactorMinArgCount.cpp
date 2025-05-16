// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
// #include "rulp/runtime/IRFactorImpl.h"

// namespace lfc {
// XRFACTOR_IMPL_BEGIN(XRFactorGetFactorMinArgCount)

//   auto obj  = args->get(1);
//   auto type = TYPE_INDEX_OF(obj);

//   if (type == E_ATOM) {
//     auto name  = AS_ATOM(obj)->getName();
//     auto entry = frame->getEntry(name);
//     if (entry == null) {
//       throw RException("factor not found: " + name);
//     }

//     if(TYPE_INDEX_OF(entry->getObject()) != E_FACTOR) {
//       throw RException("not factor: " + name);
//     }


//   }

//   return toObject(type);

// XRFACTOR_IMPL_ARG(2, 2)
// XRFACTOR_IMPL_END
// STATIC_FACTOR_REGISTER(XRFactorGetFactorMinArgCount, F_TYPE_OF);

// } // namespace lfc