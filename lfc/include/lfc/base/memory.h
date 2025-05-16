// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_MEMORY_H__
#define __LFC_MEMORY_H__

#include <string>
#include <vector>

namespace lfc {

std::vector<std::string> dump_memory_hex(void *address, int datasize);

} // namespace lfc

#endif //__LFC_MEMORY_H__