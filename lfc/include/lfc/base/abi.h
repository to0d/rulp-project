// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_ABI_H__
#define __LFC_ABI_H__

#include <string>

namespace lfc {

std::string demangle_func_name(const std::string& mangled_name);

}// namespace lfc

#endif // __LFC_ABI_H__

