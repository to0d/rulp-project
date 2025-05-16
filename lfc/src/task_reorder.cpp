#include "lfc/base/task.h"
#include "lfc/base/string/util.h"
#include "lfc/base/to_string.h"
#include <assert.h>
#include <set>
#include <vector>
namespace lfc {
 
bool is_valid_reorder_vec(const std::vector<int>& reorder_vec){
  int size = reorder_vec.size();
  std::vector<bool> used(size, false);

  for(int i : reorder_vec){
    if(i < 0 || i >= size || used[i])
      return false;
    used[i] = true;
  }

  return true;
}

bool is_nochange_reorder_vec(const std::vector<int>& reorder_vec){
  if(reorder_vec.empty())
    return true;

  int size = reorder_vec.size();
  for(int i =0;i < size; ++i){
    if( i != reorder_vec[i])
      return false;
  }

  return true;
}

bool is_valid_ordered_vec(const std::vector<int>& vec, int size, bool strict){
  if(vec.empty())
    return true;

  int last = -1;
  for(int val : vec){
    if(val < 0)
      return false;
    if(strict){
      if(val <= last)
        return false;
    }
    else{
      if(val < last)
        return false;
    }

    last = val;
  }

  return true;
}

std::vector<int> make_vec(int size){
  std::vector<int> vec;
  for(int i = 0; i < size; ++i){
    vec.push_back(i);
  }
  return vec;
}

std::vector<int>
apply_reorder_steps(const std::vector<int>& input_vec, const std::vector<std::vector<int>>& steps){
  std::vector<int> vec = input_vec;
  for(auto& step : steps){
    int a = step[0], b = step[1];
    int tmp = vec[a];
    vec[a] = vec[b];
    vec[b] = tmp;
  }
  return vec;
}


bool build_reorder_steps( const std::vector<int>& input_vec
                        , const std::vector<int>& expect_vec
                        , const std::vector<std::vector<int>>& dep_arr
                        , std::vector<std::vector<int>>& steps){

  int size = expect_vec.size();
  assert(dep_arr.size() == size);
  assert(is_valid_reorder_vec(input_vec));
  assert(is_valid_reorder_vec(expect_vec));

  if(is_nochange_reorder_vec(expect_vec)){
    return true;
  }

  std::vector<std::set<int>> full_dep_arr;
  for(auto& full_dep_list : build_full_dep_array(dep_arr)){
    std::set<int> full_dep_set;
    std::copy(full_dep_list.begin(), full_dep_list.end(), std::inserter(full_dep_set, full_dep_set.begin()));
    full_dep_arr.push_back(full_dep_set);
  }
  
  std::vector<int> cur_order = input_vec, reorder_pos_list;
  for(int i = 0; i < size; ++i){
    if(expect_vec[i] != i)
      reorder_pos_list.push_back(i);
  }

  int reorder_size = reorder_pos_list.size();
  for(int i = 0; i < reorder_size; ++i){

    // errs() << "cur_order: " << lfc::to_string(cur_order) << "\n";
    // errs() << "reorder_pos_list: " << lfc::to_string(reorder_pos_list) << "\n";

    int a_idx = reorder_pos_list[i], expect = expect_vec[a_idx];
    // errs() << "i=" << i << ", a_idx=" << a_idx << ", expect=" << expect << "\n";

    if(cur_order[a_idx] != expect){
 
      int b_pos = -1;
      for(int j = i + 1; j < reorder_size; j++){
        int b_idx = reorder_pos_list[j];
        if(cur_order[b_idx] == expect){
          b_pos = j;
          break;
        }
      }

      // errs() << "b_pos=" << b_pos << "\n";
      assert(b_pos != -1);

      int a_reorder = reorder_pos_list[i], b_reorder = reorder_pos_list[b_pos];
      // errs() << "a_reorder=" << a_reorder << ", b_reorder=" << b_reorder << "\n";
      assert(a_reorder < b_reorder);
      
      steps.push_back({a_reorder, b_reorder});
      // errs() << "steps: " << lfc::to_string(steps) << "\n";

      // swap dep info
      {
        auto tmp = full_dep_arr[b_reorder];
        full_dep_arr[b_reorder] = full_dep_arr[a_reorder];
        full_dep_arr[a_reorder] = tmp;
      }

      {
        int tmp = cur_order[b_reorder];
        cur_order[b_reorder] = cur_order[a_reorder];
        cur_order[a_reorder] = tmp;
      }
    }

  }
  
  return true;
}

} // namespace lfc


