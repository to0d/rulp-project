// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_COLLECTION_UTIL_H__
#define __LFC_COLLECTION_UTIL_H__


#include "lfc/base/equal.h"
namespace lfc {

template <typename _IT1, typename _IT2, typename _F>
inline bool has_common_index(_IT1 _a_begin, _IT1 _a_end, _IT2 _b_begin, _IT2 _b_end, _F _f){
  if(_a_begin == _a_end || _b_begin == _b_end)
    return false;

  assert(_f(*_a_begin) <= _f(*(_a_end-1)));
  assert(_f(*_b_begin) <= _f(*(_b_end-1)));

  // Thus, if a's first (smallest) var is smaller than b's last (biggest) var
  //       or a's last (biggest) var is bigger than b's first (smallest) var
  //       there is no any common var
  if( _f(*_a_begin) > _f(*(_b_end-1)) || _f(*(_a_end-1)) < _f(*_b_begin) )
    return false;

  // check them one by one
  int v_i = -1, v_j = -1;
  auto a_pos = _a_begin, b_pos = _b_begin;
  while( a_pos < _a_end && b_pos < _b_end){
    if(v_i == -1)
      v_i = _f(*a_pos);

    if(v_j == -1)
      v_j = _f(*b_pos);

    if( v_i == v_j )
      return true;

    if( v_i < v_j ){
      ++a_pos;
      v_i = -1;
    }
    else{
      ++b_pos;
      v_j = -1;
    }
  }

  return false;
}


template<typename _IT, typename _Tv>
inline bool has_element(_IT _begin, _IT _end, const _Tv& val){
  for (_IT pos = _begin; pos != _end; ++pos){
    if (lfc::equal(*pos, val)){
      return true;
    }
  }

  return false;
}


template<typename _IT1, typename _IT2>
inline bool is_sub_of(_IT1 _begin1, _IT1 _end1, _IT2 _begin2, _IT2 _end2){
  for (_IT1 pos = _begin1; pos != _end1; ++pos){
    if (!has_element(_begin2,_end2,*pos)){
      return false;
    }
  }
  return true;
}


template<typename _IT1, typename _IT2>
inline bool has_common_element(_IT1 _begin1, _IT1 _end1, _IT2 _begin2, _IT2 _end2){
  return is_sub_of(_begin1, _end1, _begin2, _end2) 
      && is_sub_of(_begin2, _end2, _begin1, _end1);
}


template<typename _IT1, typename _IT2, typename _OT>
inline void union_of(_IT1 _begin1, _IT1 _end1, _IT2 _begin2, _IT2 _end2, _OT _out){
  for (_IT1 p1 = _begin1; p1 != _end1; ++p1){
    *_out = *p1;
  }

  for (_IT2 p2 = _begin2; p2 != _end2; ++p2){
    if (!has_element(_begin1, _end1, *p2)){
      *_out = *p2;
    }
  }
}


template<typename _IT1, typename _IT2, typename _OT>
inline void intersection_of(_IT1 _begin1, _IT1 _end1, _IT2 _begin2, _IT2 _end2, _OT _out){
  for (_IT1 p1 = _begin1; p1 != _end1; ++p1){
    if (has_element(_begin2, _end2, *p1)){
      *_out = *p1;
    }
  }
}

// all elements in C1, but not in C2
template<typename _IT1, typename _IT2, typename _OT>
inline void complement_of(_IT1 _begin1, _IT1 _end1, _IT2 _begin2, _IT2 _end2, _OT _out){
  for (_IT1 p1 = _begin1; p1 != _end1; ++p1){
    if (!has_element(_begin2, _end2, *p1)){
      *_out = *p1;
    }
  }
}


} // namespace lfc
#endif // __LFC_COLLECTION_UTIL_H__

