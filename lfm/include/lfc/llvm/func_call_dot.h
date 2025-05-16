// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNC_CALL_DOT_H__
#define __LFC_FUNC_CALL_DOT_H__

#include "lfc/llvm/func_call.h"
#include "lfc/base/dot.h"

namespace lfc {

void build_dep_fc_dot_graph( const std::vector<std::vector<int>>& dep_arr
                           , const std::vector<FuncCall>& fc_list
                           , DotUtil* DOT_Util
                           , bool show_param = true
                           , bool show_loc = false
                           , bool show_rc = false
                           );


}// namespace lfc

#endif // __LFC_FUNC_CALL_DOT_H__

