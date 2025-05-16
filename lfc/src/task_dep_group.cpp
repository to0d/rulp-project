#include "lfc/base/task.h"
#include <assert.h>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>

namespace lfc {
 
bool is_valid_task_dep_group_vec(const std::vector<std::vector<int>>& group_vec){
  if(group_vec.empty())
    return false;

  int expect = 0;
  for(auto& group : group_vec){
    if(group.empty())
      return false;
    for(int idx : group) 
      if(idx != expect++)
        return false;
  }
  return true;
}

std::vector<std::vector<int>>
build_dep_group_by_topological_sorting(const std::vector<std::vector<int>>& dep_arr){
  std::vector<std::vector<int>> group_list, prevous_array = dep_arr, next_array;
  std::vector<int> cur_group, prevous_count_list;

  // create next index array 
  next_array = lfc::build_next_dep_array(prevous_array);
  
  // create previous count array
  for_each(prevous_array.begin(), prevous_array.end(), 
    [&prevous_count_list](std::vector<int>& list){prevous_count_list.push_back(list.size());});
  
  int size = prevous_array.size();
  for(int i = 0; i < size; ++i){
    if( prevous_count_list[i] == 0)
      cur_group.push_back(i);   
    else{
      for(int j : cur_group)
        for(int next : next_array[j])
          --prevous_count_list[next];
      group_list.push_back(cur_group);
      cur_group = {i};
    }
  }

  if(!cur_group.empty())
    group_list.push_back(cur_group);

  assert(is_valid_task_dep_group_vec(group_list));
  return group_list;
}

struct Group{
  int index;
  Group* front;
  Group* back;
  float weight;
  float value;
  bool removed;
  std::vector<int>   index_list;
  std::unordered_set<Group*> previous_list;
  std::unordered_set<Group*> next_list;
  Group() : front(NULL), back(NULL), weight(0), value(0), removed(false) {};
  bool has_next(Group* next){ return next_list.count(next)!= 0;}
  bool has_previous(Group* previous){ return next_list.count(previous)!= 0;}
  void update_value(){
    value = 0;
    if( front != NULL && !front->has_next(this))
      value = front->weight + weight;
  }
};

std::vector<std::vector<int>>
build_dep_group_by_weight(const std::vector<std::vector<int>>& array, const std::vector<float>& weights){
  int size = array.size();
  Group* group_base = new Group[size];
  std::vector<Group*> group_list;
  
  { 
    Group* front_node = NULL;
    for(int i = 0; i < size; ++i){
      Group& group = group_base[i];
      group.index = i;      
      group.index_list.push_back(i);
      group.weight = weights[i];

      for(int prevous_index: array[i]){
        Group& prevous_node = group_base[prevous_index];
        group.previous_list.insert(&prevous_node);
        prevous_node.next_list.insert(&group);
      }

      group.front = front_node;
      if( front_node != NULL ){
        front_node->back = &group;
        group.update_value();        
      }

      front_node = &group;
      group_list.push_back(&group);
    }
  }

#ifdef DEBUG
  std::cout << "\ninit group: \n" << to_string(group_list) << std::endl;
#endif

  while(group_list.size() > 1){
    std::sort(group_list.begin(), group_list.end(), 
                [](Group* a, Group* b){return a->value < b->value;});
#ifdef DEBUG
    std::cout << "sorted group: \n" << to_string(group_list) << std::endl;
#endif
    Group* group = group_list.back();
    group_list.pop_back();
    if( group->removed || group->value <= 0 )
      continue;

    Group* front = group->front, *back = group->back;
    if( front == NULL || front->has_next(group)){
      continue;
    }

    front->weight += group->weight;
    group->removed = true;

    for(Group* previous_group : group->previous_list){
      previous_group->next_list.erase(group);
      if(!front->has_previous(previous_group)){
        front->previous_list.insert(previous_group);
        previous_group->next_list.insert(front);
      }
    }

    for(Group* next_group : group->next_list){
      next_group->previous_list.erase(group);
      if(!front->has_next(next_group)){
        front->next_list.insert(next_group);
        next_group->previous_list.insert(front);
      }
    }

    std::copy( group->index_list.begin()
             , group->index_list.end()
             , std::back_inserter(front->index_list));

    front->back = back;
    if(back != NULL ){
      back->front = front;
      back->update_value();
    }

    front->update_value();
  }

  std::vector<std::vector<int>> group_array;

  for(int i = 0; i < size; ++i){
    Group& group = group_base[i];
    if(!group.removed){
      group_array.push_back(group.index_list);
    }
  }
 
  delete [] group_base;

  assert(is_valid_task_dep_group_vec(group_array));
  return group_array;
}

} // namespace lfc 


