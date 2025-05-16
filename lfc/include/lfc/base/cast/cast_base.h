// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_CAST_BASE_H__
#define __LFC_CAST_BASE_H__
#include <map>
#include <string>

namespace lfc {

template <typename _Ty1, typename _Ty2, typename Enable = void>
struct _auto_cast_functor{
  static bool _cast(const _Ty1& in_value, _Ty2& out_value){
    return false;
  }
};

template <typename _Ty1, typename _Ty2>
struct _auto_cast_functor<_Ty1*, _Ty2>{
  static bool _cast(const _Ty1* in_value, _Ty2& out_value){
    assert(in_value != NULL);
    return _auto_cast_functor<_Ty1,_Ty2>::_cast(*in_value,out_value);
  }
};


template <typename _Ty>
struct _auto_cast_functor<_Ty, _Ty>{
  static bool _cast(const _Ty& in_value, _Ty& out_value){
    out_value = in_value;
    return true;
  }
};


template <typename _AKey,typename _AValue>
struct _auto_cast_functor<std::map<_AKey,_AValue>, std::wstring>{

  typedef _auto_cast_functor<_AKey,std::wstring>		key_caster;
  typedef _auto_cast_functor<_AValue,std::wstring>	value_caster;
  typedef std::map<_AKey,_AValue> map_type;

  static bool _cast(const map_type& _map,std::wstring& _result){
    typename map_type::const_iterator pos = _map.begin();

    for (; pos != _map.end(); ++pos){
      std::wstring key_str;
      std::wstring val_value;

      if (!key_caster::_cast(pos->first,key_str)
        ||!value_caster::_cast(pos->second,val_value)){
        return false;
      }
      _result += key_str + L"=" + val_value + L";"; 
    }

    return true;
  }
};

template <typename _AKey,typename _AValue>
struct _auto_cast_functor<std::wstring, std::map<_AKey,_AValue>>{
  typedef _auto_cast_functor<_AKey,std::wstring>		key_caster;
  typedef _auto_cast_functor<_AValue,std::wstring>	value_caster;
  typedef std::map<_AKey,_AValue> map_type;

  static bool _cast(const std::wstring& str, map_type& result_map){
    std::wstring temp = str;
    while(!temp.empty()){
      size_t posClause = temp.find_first_of(L';');

      std::wstring clause = temp.substr(0,posClause);
      temp = temp.substr(posClause + 1,temp.length());			

      size_t posPara = clause.find_first_of(L'=');
      std::wstring p = clause.substr(0,posPara);
      std::wstring v = clause.substr(posPara + 1,clause.length());

      if (!p.empty()){
        result_map[p] = v;
      }
    }

    return true;
  }
};


} // namespace lfc
#endif // __LFC_CAST_BASE_H__
