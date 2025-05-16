// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_GRAPH_SIMPLE_H__
#define __LFC_GRAPH_SIMPLE_H__


#include "lfc/base/dot.h"
#include "lfc/base/graph/graph_simple.h"
#include <vector>
#include <set>

namespace lfc {

typedef std::vector<std::vector<int>> simple_graph;
typedef std::vector<std::set<int>>    simple_set_graph;

simple_set_graph make_simple_set_graph(const simple_graph& graph, bool is_directed);
simple_graph     make_simple_graph_undirected(const simple_set_graph& graph);

std::vector<std::vector<int>> getAllPathsSourceTarget(const simple_graph& graph, int start = 0, int target = -1);

} // namespace lfc
#endif // __LFC_GRAPH_DOT_H__
