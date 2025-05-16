// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_GRAPH_UTILS_H__
#define __LFC_GRAPH_UTILS_H__


#include "lfc/base/graph/graph_simple.h"
#include <vector>
namespace lfc {


// graph: Undirected graph
bool fill_graph_coloring(const simple_graph& graph, int color_num, std::vector<int>& colors);


} // namespace lfc
#endif // __LFC_GRAPH_H__
