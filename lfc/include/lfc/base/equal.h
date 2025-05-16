// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_EQUAL__
#define __LFC_BASE_EQUAL__

#include "lfc/base/equal_nocase.h"
#include "lfc/base/cast.h"
#include <string>

namespace lfc {

  namespace _inner{  

    template<typename _Ty,typename Enable = void>
    struct equal_t{
      static bool equal(const _Ty& v1,const _Ty& v2){
        return v1 == v2;
      }
    };

    template <typename T> 
    struct equal_t<T, typename enable_if<is_one_of<T, std::string, std::wstring>::value>::type>{
      static bool equal(const T& v1,const T& v2){
        return (v1.length() == v2.length()) && std::equal(v1.begin(),v1.end(), v2.begin());
      }
    };

  }

  inline 
  bool equal(const std::string& s1 , const std::string& s2, bool not_case = false){
    if (not_case){
      return lfc::equal_nocase(s1,s2);
    }
    else{
      return _inner::equal_t<std::string>::equal(s1,s2);
    }
  }

  inline
  bool equal(const int& n1 , const int& n2){
    return n1 == n2;
  }

  inline
  bool equal(const std::wstring& s1 , const std::wstring& s2, bool not_case = false){
    if (not_case){
      return lfc::equal_nocase(s1,s2);
    }
    else{
      return _inner::equal_t<std::wstring>::equal(s1,s2);
    }
  }

  inline
  bool equal(const wchar_t& s1 , const wchar_t& s2, bool not_case = false){
    std::wstring ws1,ws2;
    ws1.push_back(s1);
    ws2.push_back(s2);
    return lfc::equal(ws1,ws2,not_case);
  }

  template<typename _Ty>
  bool equal(const std::vector<_Ty>& a , const std::vector<_Ty>& b){
    if(a == b)
      return true;

    int size = a.size();    
    if(size != b.size())
      return false;

    for(int i = 0; i < size; ++i){
      if(!lfc::equal(a[i], b[i])){
        return false;
      }
    }

    return true;
  }

  template<typename _Ty>
  bool equal(const std::set<_Ty>& a , const std::set<_Ty>& b){
    if(a == b)
      return true;

    int size = a.size();    
    if(size != b.size())
      return false;

    for(const _Ty& e : a){
      if(b.count(e) == 0){
        return false;
      }
    }

    return true;
  }
}

#endif // __LFC_BASE_EQUAL__
