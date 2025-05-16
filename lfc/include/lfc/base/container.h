// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_CONTAINER_H__
#define __LFC_BASE_CONTAINER_H__
#include <set>
#include <vector>
#include <map>
#include <algorithm>


#define CT_TO_VECTOR          lfc::to_vector
#define CT_TO_SET             lfc::to_set
#define CT_RETAIN_ALL(a, b)   lfc::retainAll(a, b)

namespace lfc {

template <typename T>
inline void erase(std::set<T>& _set, const T& e){
  auto it = _set.find(e);
  if(it != _set.end()){
    _set.erase(it);
  }
}

template <typename _Ty1, typename _Ty2>
inline _Ty2 erase(std::map<_Ty1, _Ty2>& _map, const _Ty1& key){
  _Ty2 val;
  auto it = _map.find(key);
  if(it != _map.end()){
    val = it->second;
    _map.erase(it);
  }

  return val;
}

template <typename T>
inline int erase_first_of(std::vector<T>& vec, const T& e){
  int pos = 0;
  for(auto it = vec.begin(); it != vec.end(); ++it, ++pos){
    T& val = *it;
    if(val == e){
      it = vec.erase(it);
      return pos;
    }
  }
  return -1;
}

template <typename T>
inline void copy_to(const std::vector<T>& from, std::vector<T>& to){
  std::copy(from.begin(), from.end(), std::back_inserter(to));
}

template <typename T, typename V>
inline void copy_to(const std::map<T, V>& from, std::map<T, V>& to){
  for(auto it = from.begin(), end = from.end(); it != end; ++it){
    const T& k = it->first;
    const V& v = it->second;
    to[k] = v;
  }
}

template <typename T>
inline bool find(const std::vector<T>& vec, const T& e){
  return std::find(vec.begin(), vec.end(), e) != vec.end();
}

template <typename T>
inline bool find(const std::set<T>& set, const T& e){
  return set.count(e) != 0;
}

template <typename _Tx, typename _Ty>
inline _Ty* find(const std::map<_Tx, _Ty*> _map, const _Tx& key){
  auto it = _map.find(key);
  if (it == _map.end()){
    return NULL;
  }
  return it->second;
}

template <typename T>
inline int indexOf(const std::vector<T>& vec, const T& e){
  auto pos = std::find(vec.begin(), vec.end(), e);
  if(pos == vec.end())
    return -1;
  return pos - vec.begin();
}

template<typename _T>
inline std::vector<_T> to_vector(std::initializer_list<_T> il){
  std::vector<_T> vec;
  std::for_each(il.begin(), il.end(), [&](auto e){vec.push_back(e);});
  return std::move(vec);
}

template<typename _T>
inline std::vector<_T> to_vector(std::set<_T> set){
  std::vector<_T> vec;
  std::for_each(set.begin(), set.end(), [&](auto e){vec.push_back(e);});
  return std::move(vec);
}

template<typename _T>
inline std::set<_T> to_set(std::vector<_T> il){
  std::set<_T> set;
  std::for_each(il.begin(), il.end(), [&](auto e){set.insert(e);});
  return std::move(set);
}

template <typename T>
inline int add_all(std::set<T>& a, const std::set<T>& b){
  int count = 0;
  for(const T& e : b){
    if(!find(a, e)){
      a.insert(e);
      ++count;
    }
  }
  return count;
}

template<typename _T>
inline std::vector<_T> resize_to(const std::vector<_T>& v, int size){
  std::vector<_T> vec(size);
  
  int copy_size = size;
  if(copy_size > v.size()){
    copy_size = v.size();
  }

  for(int i = 0 ; i < copy_size; ++i){
    vec[i] = v[i];
  }

  for(int i = copy_size ; i < size; ++i){
    vec[i] = _T();
  }  

  return std::move(vec);
}

template <typename T>
inline void retainAll(std::set<T>& s1, std::set<T>& s2){
  auto it = s1.begin();
  while(it != s1.end()){
    const T& v = *it;
    if(s2.count(v) == 0){
      it = s1.erase(it);
    }
    else {
      it++;
    }
  }
}

template <typename T, typename V>
inline void retainAll(std::map<T, V>& m1, std::map<T, V>& m2){
  auto it = m1.begin();
  while(it != m1.end()){
    const T& k = it->first;
    if(m2.find(k) == m2.end()){
      it = m1.erase(it);
    }
    else {
      it++;
    }
  }
}

template<typename _T>
inline _T* toFixArray(const std::vector<_T>& vec){

  _T* arr = new _T[vec.size()];

  int idx = 0;
  for(auto& e : vec){
    arr[idx++] = e;
  }

  return arr;
}


} // namespace lfc
#endif // __LFC_BASE_CONTAINER_H__

