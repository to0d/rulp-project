// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RACCESSTYPE_H__
#define __RULP_LANG_RACCESSTYPE_H__
#include "rulp/lang/base.h"
#include "rulp/object/IRAtom.h"
#include "lfc/base/to_string_macro.h"
namespace lfc {

enum class RAccessType {
    DEFAULT
  , PUBLIC
  , PRIVATE
  , NIL
};

RAccessType toAccessType(StrConstRef name);

IRAtom* toObject(RAccessType type);

} // namespace lfc
namespace lfc {
std::string to_string(lfc::RAccessType type);
} // namespace lfc
#endif //__RULP_LANG_RACCESSTYPE_H__