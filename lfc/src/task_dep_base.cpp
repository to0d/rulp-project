#include "lfc/base/task.h"
#include "lfc/base/container.h"
#include <assert.h>
#include <algorithm>
#include <set>
#include <vector>

namespace lfc {
 
std::vector<std::vector<int>> 
build_next_dep_array(const std::vector<std::vector<int>>& prevous_array){
  std::vector<std::vector<int>> next_array(prevous_array.size());
  int index = 0;
  for(auto& previous_list : prevous_array){
    for(int previous_index: previous_list){
      next_array[previous_index].push_back(index);
    }
    ++index;
  }
  return next_array;
}

std::vector<std::vector<int>> 
build_full_dep_array(const std::vector<std::vector<int>>& dep_arr){
  std::vector<std::vector<int>> full_dep_arr;
  
  for(auto& dep_list : dep_arr){
    std::set<int> full_dep_set;
    for(int i : dep_list){
      full_dep_set.insert(i);
      std::copy(full_dep_arr[i].begin(), full_dep_arr[i].end(), std::inserter(full_dep_set, full_dep_set.begin()));
    }
    std::vector<int> full_dep_list = to_vector(full_dep_set);
    std::sort(full_dep_list.begin(), full_dep_list.end(), std::less<>());
    full_dep_arr.push_back(full_dep_list);
  }

  return full_dep_arr;
}

std::vector<std::vector<int>> 
remove_full_dep_array(const std::vector<std::vector<int>>& dep_arr){

  std::vector<std::vector<int>> full_dep_arr = build_full_dep_array(dep_arr);
  std::vector<std::vector<int>> single_dep_arr;
  
  for(auto& dep_list : full_dep_arr){       
    int size = dep_list.size();
    if(size <= 1){
      single_dep_arr.push_back(dep_list);
    }
    else{
      std::vector<int> dep = {dep_list[size - 1]};
      for(int i = size - 2; i >= 0; --i){
        bool find = false;
        for(int j = size - 1; j > i; --j){
          auto& j_dep = full_dep_arr[j];
          if(std::find(j_dep.begin(), j_dep.end(), i) != j_dep.end()){
            find = true;
            break;
          }
        }
        if( !find ){
          dep.push_back(dep_list[i]);
        }
      }
      std::reverse(dep.begin(), dep.end());
      single_dep_arr.push_back(dep);
    }
  }

  return single_dep_arr;
}


} // namespace lfc 


