#ifndef __LFC_TASK_DOT_H__
#define __LFC_TASK_DOT_H__

#include "lfc/base/dot.h"
#include <vector>

namespace lfc {

void build_dep_dot_graph(const std::vector<std::vector<int>>& dep_arr,  DotUtil* DOT_Util);

} // namespace lfc


#endif // __LFC_TASK_DOT_H__

