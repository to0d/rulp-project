// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_GRAPH_DOT_H__
#define __LFC_GRAPH_DOT_H__


#include "lfc/base/dot.h"
#include "lfc/base/graph/graph_simple.h"
#include <vector>
#include <set>

namespace lfc {


void build_simple_graph_dot_graph(const simple_graph& graph, DotUtil* DOT_Util, bool is_directed, const std::vector<std::string>& names = {});


} // namespace lfc
#endif // __LFC_GRAPH_DOT_H__
