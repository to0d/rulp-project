// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_GRAPH_UTILS_H__
#define __LFC_GRAPH_UTILS_H__


#include "lfc/base/graph/graph_visit.h"
#include <vector>

namespace lfc {

template <typename _TNode, typename _F_next>
bool has_loop_in_graph(const std::vector<_TNode>& all_nodes, _F_next _next){
  int visit = visit_graph_by_topological_sorting(all_nodes, [](_TNode node){return false;}, _next);
  return visit != all_nodes.size();
}


} // namespace lfc

#endif // __LFC_GRAPH_H__
