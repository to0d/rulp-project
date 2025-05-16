// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_STRING_FORMAT_H__
#define __LFC_BASE_STRING_FORMAT_H__

#include <string>
#include <stdio.h>
namespace lfc {

#define LFC_STR_FORMAT_BGN \
[&]()->std::string { \
    char buf[256]; \
    int len = snprintf(buf, sizeof(buf)-1, 

#define LFC_STR_FORMAT_END \
); \
    return std::string(buf, len); \
	}()

#define LFC_STR_FORMAT_BGN2 \
[&]()->std::string { \
    char buf[65535]; \
    int len = snprintf(buf, sizeof(buf)-1, 


} // namespace lfc
#endif // __LFC_BASE_STRING_UTIL_H__