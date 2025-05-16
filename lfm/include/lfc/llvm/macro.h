// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_CONSTANT_H__
#define __LFC_LLVM_CONSTANT_H__

#define LLVM_INTRINSICS_DBG_DECLARE         "llvm.dbg.declare"
#define LLVM_INTRINSICS_DBG_VALUE           "llvm.dbg.value"
#define LLVM_DECLARE_MIN_VERSION_15         static_assert(__clang_major__ >= 15, "need llvm-15");
#define LLVM_META_DBG_CU                    "llvm.dbg.cu"
#define LLVM_META_MODULE_FLAGS              "llvm.module.flags"
#define LLVM_FLAG_DWARF_VERSION             "Dwarf Version"
#define LLVM_FLAG_DEBUG_INFO_VER            "Debug Info Version"
#define LLVM_NAME_NULL                      "null"

#endif // __LFC_LLVM_CONSTANT_H__