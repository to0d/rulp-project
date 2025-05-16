#ifndef __LFC_TASK_H__
#define __LFC_TASK_H__
#include <vector>

namespace lfc {

/*****************************************************************/
// Dep utils
/*****************************************************************/
std::vector<std::vector<int>> 
build_next_dep_array(const std::vector<std::vector<int>>& pre_dep_arr);

std::vector<std::vector<int>> 
build_full_dep_array(const std::vector<std::vector<int>>& dep_arr);

std::vector<std::vector<int>> 
remove_full_dep_array(const std::vector<std::vector<int>>& dep_arr);

/*****************************************************************/
// Group utils
/*****************************************************************/
bool is_valid_task_dep_group_vec(const std::vector<std::vector<int>>& group_vec);

std::vector<std::vector<int>> 
build_dep_group_by_topological_sorting(const std::vector<std::vector<int>>& dep_arr);

std::vector<std::vector<int>> 
build_dep_group_by_weight( const std::vector<std::vector<int>>& dep_arr
                         , const std::vector<float>& weights
                         );

/*****************************************************************/
// Reorder utils
/*****************************************************************/
bool is_valid_reorder_vec(const std::vector<int>& reorder_vec);

bool is_nochange_reorder_vec(const std::vector<int>& reorder_vec);

bool is_valid_ordered_vec(const std::vector<int>& vec, int size, bool strict = false);

std::vector<int> make_vec(int size);

std::vector<int> apply_reorder_steps(const std::vector<int>& input_vec, const std::vector<std::vector<int>>& steps);

bool build_reorder_steps( const std::vector<int>& input_vec
                        , const std::vector<int>& expect_vec
                        , const std::vector<std::vector<int>>& dep_arr
                        , std::vector<std::vector<int>>& steps);

} // namespace lfc
#endif // __LFC_TASK_H__

